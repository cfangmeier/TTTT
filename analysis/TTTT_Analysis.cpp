/**
 * @file
 * @author  Caleb Fangmeier <caleb@fangmeier.tech>
 * @version 0.1
 *
 * @section LICENSE
 *
 *
 * MIT License
 *
 * Copyright (c) 2017 Caleb Fangmeier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @section DESCRIPTION
 * Main analysis routine file. This file declares the Histogram/Graph objects
 * that will end up in the final root file. It also declares the values that
 * are used to populate the histogram, as well as how these values are
 * calculated. See the Fil-Val documentation for how the system works.
 */
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <limits>

#include "filval/filval.hpp"
#include "filval/root/filval.hpp"

#include "analysis/common/obj_types.hpp"
#include "analysis/common/constants.hpp"
#include "analysis/selection.hpp"

#include "MiniTree.h"
#include <TSystem.h>

using namespace std;
using namespace fv;
using namespace fv::root;

void enable_extra_branches(TreeDataSet<MiniTree>& mt){
    mt.track_branch<int>("nBJetLoose40");
    mt.track_branch<int>("nBJetMedium40");
    mt.track_branch<int>("nBJetTight40");


    mt.track_branch< int >("run" );
    mt.track_branch< int >("lumi");
    mt.track_branch< int >("evt" );
    mt.track_branch<float>("xsec");
}


void declare_values(TreeDataSet<MiniTree>& mt){

    // Define a couple selections to be used in the top-mass reconstruction.
    auto& b_pdgid_filter = GenFunction::reg_func<bool(Particle)>("b_pdgid_filter",
        FUNC(([](const Particle& j){
                return j.genpart.pdgId == 5 || j.genpart.pdgId==-5;
        })));
    auto& w_mass_filter = GenFunction::reg_func<bool(Particle, Particle)>("w_mass_filter",
        FUNC(([win_l=W_MASS-10, win_h=W_MASS+10](const Particle& j1, const Particle& j2){
            float inv_mass = (j1.v + j2.v).M();
            return inv_mass > win_l && inv_mass < win_h;
        })));
    auto& dup_filter = GenFunction::reg_func<bool(std::tuple<Particle,Particle>,Particle)>("dup_filter",
        FUNC(([](const std::tuple<Particle,Particle>& w, const Particle& b){
            int j0 = b.idx;
            int j1 = std::get<0>(w).idx;
            int j2 = std::get<1>(w).idx;
            return (j0 != j1) && (j0 != j2) && (j1 != j2);
        })));
    auto& qg_id_filter = GenFunction::reg_func<bool(Particle, Particle)>("qg_id_filter",
        FUNC(([](const Particle& j1, const Particle& j2){
            // require both particles be either quarks(not Top) or gluons
            int id1 = abs(j1.genpart.pdgId);
            int id2 = abs(j2.genpart.pdgId);
            return ((id1 >=1 && id1 <= 5) || id1 == 21) &&
                   ((id2 >=1 && id2 <= 5) || id2 == 21);
        })));



    auto jets = lookup<std::vector<Particle>>("jets");
    auto leptons = lookup<std::vector<Particle>>("leptons");
    auto leading_jet = fv::reduce(leading_particle, jets, "leading_jet");
    fv::apply(particle_pt, fv::tuple(leading_jet), "leading_jet_pt");

    auto leading_lepton = fv::reduce(leading_particle, leptons);
    fv::apply(particle_pt, fv::tuple(leading_lepton), "leading_lepton_pt");
    fv::apply(lepton_relIso, fv::tuple(leading_lepton), "leading_lepton_relIso");

    auto b_jets = lookup<std::vector<Particle>>("b_jets");

    // Here is the calculation of the Top Reconstructed Mass from Particle
    auto w_dijets = tup_filter<Particle,Particle>(w_mass_filter, combinations<Particle,2>(jets, "reco_dijets"));

    auto top_cands = cart_product<std::tuple<Particle,Particle>, Particle>(w_dijets, b_jets);

    top_cands = tup_filter(dup_filter, top_cands);

    auto& t_mass = GenFunction::reg_func<float(std::tuple<Particle,Particle>,Particle)>("t_mass",
        FUNC(([](const std::tuple<Particle,Particle>& w, const Particle& b){
            return (std::get<0>(w).v+std::get<1>(w).v+b.v).M();
        })));

    fv::map(t_mass, top_cands, "reco_top_mass");

    // Here is the calculation of the Top Reconstructed Mass from Generator-Level objects
    jets = lookup<std::vector<Particle>>("mc_jets");

    b_jets = filter(b_pdgid_filter, jets);

    w_dijets = tup_filter(qg_id_filter, combinations<Particle,2>(jets));
    w_dijets = tup_filter(w_mass_filter, w_dijets);

    top_cands = cart_product<std::tuple<Particle,Particle>, Particle>(w_dijets, b_jets);

    top_cands = tup_filter(dup_filter, top_cands);


    fv::map(t_mass, top_cands, "mc_top_mass");


    // calculation of di-jet inv-mass spectrum
    auto& inv_mass2 = GenFunction::reg_func<float(Particle, Particle)>("inv_mass2",
        FUNC(([] (const Particle& j1, const Particle& j2){
            TLorentzVector sum = j1.v + j2.v;
            return (float)sum.M();
        })));
    fv::map(inv_mass2, lookup<std::vector<std::tuple<Particle,Particle>>>("reco_dijets"), "dijet_inv_mass");



    count<float>(GenFunction::reg_func<bool(float)>("bJet_Selection",
        FUNC(([](float x){
            return x>0;
        }))), "Jet_btagCMVA",  "b_jet_count");

    auto &is_electron = GenFunction::reg_func<bool(int)>("is_electron",
        FUNC(([](int pdgId) {
            return abs(pdgId) == 11;
        })));
    auto &is_muon = GenFunction::reg_func<bool(int)>("is_muon",
        FUNC(([](int pdgId) {
            return abs(pdgId) == 13;
        })));
    auto &is_lepton = GenFunction::reg_func<bool(int)>("is_lepton",
        FUNC(([ie=&is_electron, im=&is_muon](int pdgId) {
            return (*ie)(pdgId) || (*im)(pdgId);
        })));

    count<int>(is_electron, "GenPart_pdgId", "genEle_count");
    count<int>(is_muon,     "GenPart_pdgId", "genMu_count");
    count<int>(is_lepton,   "GenPart_pdgId", "genLep_count");

    count<int>(is_electron, "LepGood_pdgId", "recEle_count");
    count<int>(is_muon,     "LepGood_pdgId", "recMu_count");
    count<int>(is_lepton,   "LepGood_pdgId", "recLep_count");


    fv::pair<int, int>("genEle_count", "recEle_count", "genEle_count_v_recEle_count");
    fv::pair<int, int>("genMu_count",  "recMu_count",  "genMu_count_v_recMu_count");
    fv::pair<int, int>("genLep_count", "recLep_count", "genLep_count_v_recLep_count");

    /* auto& sum = GenFunction::reg_func<float(std::vector<float>)>("sum", */
    /*     FUNC(([](const std::vector<float>& v){ */
    /*         return std::accumulate(v.begin(), v.end(), 0); */
    /*     }))); */

    /* auto sum_jet_pt = fv::apply(sum, lookup<std::vector<float>>("Jet_pt")); */


    obs_filter("trilepton", FUNC(([nLepGood=lookup<int>("nLepGood")]()
        {
            return dynamic_cast<Value<int>*>(nLepGood)->get_value() == 3;
        })));

    obs_filter("os-dilepton", FUNC(([LepGood_charge=lookup<vector<int>>("LepGood_charge")]()
        {
            auto& charges = LepGood_charge->get_value();
            return charges.size()==2 && (charges[0] != charges[1]);
        })));

    obs_filter("ss-dilepton", FUNC(([LepGood_charge=lookup<vector<int>>("LepGood_charge")]()
        {
            auto& charges = LepGood_charge->get_value();
            return charges.size()==2 && (charges[0] == charges[1]);
        })));

}

void declare_containers(TreeDataSet<MiniTree>& mt){

    mt.register_container<ContainerTH1<int>>("lepton_count", "Lepton Multiplicity", lookup<int>("nLepGood"), 8, 0, 8);

    mt.register_container<ContainerTH1Many<float>>("Jet_pt_dist", "Jet P_T",
                                                      lookup<vector<float>>("Jet_pt"), 50, 0, 500,
                                                      "Jet P_T");
    mt.register_container<ContainerTH1Many<float>>("Jet_eta_dist", "Jet Eta",
                                                      lookup<vector<float>>("Jet_eta"), 50, -3, 3,
                                                      "Jet Eta");
    mt.register_container<ContainerTH1Many<float>>("Jet_phi_dist", "Jet Phi",
                                                      lookup<vector<float>>("Jet_phi"), 20, -PI, PI,
                                                      "Jet Phi");
    mt.register_container<ContainerTH1Many<float>>("Jet_mass_dist", "Jet Mass",
                                                      lookup<vector<float>>("Jet_mass"), 50, 0, 200,
                                                      "Jet Mass");

    mt.register_container<ContainerTH1Many<float>>("dijet_inv_mass", "Di-Jet Inv. Mass - All",
                                                      lookup<vector<float>>("dijet_inv_mass"), 100, 0, 500,
                                                      "Di-Jet Mass");
    mt.register_container<ContainerTH1Many<float>>("dijet_inv_mass_osdilepton", "Di-Jet Inv. Mass - OS Dilepton",
                                                      lookup<vector<float>>("dijet_inv_mass"), 100, 0, 500,
                                                      "Di-Jet Mass")->add_filter(lookup_obs_filter("os-dilepton"));
    mt.register_container<ContainerTH1Many<float>>("dijet_inv_mass_ssdilepton", "Di-Jet Inv. Mass - SS Dilepton",
                                                      lookup<vector<float>>("dijet_inv_mass"), 100, 0, 500,
                                                      "Di-Jet Mass")->add_filter(lookup_obs_filter("ss-dilepton"));
    mt.register_container<ContainerTH1Many<float>>("dijet_inv_mass_trilepton", "Di-Jet Inv. Mass - Trilepton",
                                                      lookup<vector<float>>("dijet_inv_mass"), 100, 0, 500,
                                                      "Di-Jet Mass")->add_filter(lookup_obs_filter("trilepton"));

    mt.register_container<ContainerTH1Many<float>>("reco_top_mass", "Reconstructed Top mass",
                                                      lookup<vector<float>>("reco_top_mass"), 100, 0, 500,
                                                      "Tri-jet invarient mass");
    /* mt.register_container<ContainerTH1Many<float>>("reco_top_pt", "Reconstructed Top Pt", */
    /*                                                   lookup<vector<float>>("reco_top_pt"), 100, 0, 500, */
    /*                                                   "Tri-jet Pt"); */

    mt.register_container<ContainerTH1Many<float>>("mc_top_mass", "Reconstructed MC Top mass",
                                                      lookup<vector<float>>("mc_top_mass"), 100, 0, 500,
                                                      "Tri-jet invarient mass");


    mt.register_container<ContainerTH2<int>>("nLepvsnJet", "Number of Leptons vs Number of Jets",
                                              fv::pair<int, int>("nLepGood", "nJet"),
                                              7, 0, 7, 20, 0, 20,
                                              "Number of Leptons", "Number of Jets");


    mt.register_container<ContainerTH2<int>>("genEle_count_v_recEle_count", "Number of Generated Electrons v. Number of Reconstructed Electrons",
                                                lookup<std::pair<int,int>>("genEle_count_v_recEle_count"),
                                                10, 0, 10, 10, 0, 10,
                                                "Generated Electrons","Reconstructed Electrons");

    mt.register_container<ContainerTH2<int>>("genMu_count_v_recMu_count", "Number of Generated Muons v. Number of Reconstructed Muons",
                                                lookup<std::pair<int,int>>("genMu_count_v_recMu_count"),
                                                10, 0, 10, 10, 0, 10,
                                                "Generated Muons","Reconstructed Muons");

    mt.register_container<ContainerTH2<int>>("genLep_count_v_recLep_count", "Number of Generated Leptons v. Number of Reconstructed Leptons (e & mu only)",
                                                lookup<std::pair<int,int>>("genLep_count_v_recLep_count"),
                                                10, 0, 10, 10, 0, 10,
                                                "Generated Leptons","Reconstructed Leptons");

    auto jet_count = mt.register_container<ContainerTH1<int>>("jet_count", "B-Jet Multiplicity", lookup<int>("nJet"), 15, 0, 15);
    mt.cut_set(jet_count,{
               {event_selection.trilepton, "jet_count_trilepton"},
               {event_selection.eem_trilepton, "jet_count_eem_trilepton"},
               {event_selection.mme_trilepton, "jet_count_mme_trilepton"},
               {event_selection.b_jet3, "jet_count_b_jet3"},
               {event_selection.z_mass_veto, "jet_count_z_mass_veto"},
               {event_selection.base_sel, "jet_count_base_selection"},
               {event_selection.eem_base_sel, "jet_count_eem_base_selection"},
               {event_selection.mme_base_sel, "jet_count_mme_base_selection"},
               });
    auto b_jet_count = mt.register_container<ContainerTH1<int>>("b_jet_count", "B-Jet Multiplicity", lookup<int>("b_jet_count"), 10, 0, 10);
    mt.cut_set(b_jet_count,{
               {event_selection.trilepton, "b_jet_count_trilepton"},
               {event_selection.eem_trilepton, "b_jet_count_eem_trilepton"},
               {event_selection.mme_trilepton, "b_jet_count_mme_trilepton"},
               {event_selection.b_jet3, "b_jet_count_b_jet3"},
               {event_selection.z_mass_veto, "b_jet_count_z_mass_veto"},
               {event_selection.base_sel, "b_jet_count_base_selection"},
               {event_selection.eem_base_sel, "b_jet_count_eem_base_selection"},
               {event_selection.mme_base_sel, "b_jet_count_mme_base_selection"},
               });


    mt.register_container<ContainerTH1<int>>("jet_count_os_dilepton", "Jet Multiplicity - OS Dilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14)->add_filter(lookup_obs_filter("os-dilepton"));
    mt.register_container<ContainerTH1<int>>("jet_count_ss_dilepton", "Jet Multiplicity - SS Dilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14)->add_filter(lookup_obs_filter("ss-dilepton"));


    mt.register_container<CounterMany<int>>("GenPart_pdgId_counter", lookup<vector<int>>("GenPart_pdgId"));


    mt.register_container<Vector<std::vector< int >>>("GenPart_pdgId",       lookup<std::vector< int >>("GenPart_pdgId"));
    mt.register_container<Vector<std::vector< int >>>("GenPart_motherIndex", lookup<std::vector< int >>("GenPart_motherIndex"));
    mt.register_container<Vector<std::vector< int >>>("GenPart_motherId",    lookup<std::vector< int >>("GenPart_motherId"));
    mt.register_container<Vector<std::vector<float>>>("GenPart_pt",          lookup<std::vector<float>>("GenPart_pt"));
    mt.register_container<Vector<std::vector<float>>>("GenPart_eta",         lookup<std::vector<float>>("GenPart_eta"));
    mt.register_container<Vector<std::vector<float>>>("GenPart_phi",         lookup<std::vector<float>>("GenPart_phi"));
    mt.register_container<Vector<std::vector<float>>>("GenPart_mass",        lookup<std::vector<float>>("GenPart_mass"));
    mt.register_container<Vector<std::vector<float>>>("GenPart_energy",      lookup<std::vector<float>>("GenPart_energy"));
    mt.register_container<Vector<std::vector< int >>>("GenPart_status",      lookup<std::vector< int >>("GenPart_status"));

    mt.register_container<Vector<vector< int >>>("LepGood_mcMatchPdgId",     lookup<vector< int >>("LepGood_mcMatchPdgId"));
    mt.register_container<Vector<vector< int >>>("LepGood_pdgId",     lookup<vector< int >>("LepGood_pdgId"));

    mt.register_container<Vector< int >>("run",                              lookup< int >("run") );
    mt.register_container<Vector< int >>("lumi",                             lookup< int >("lumi"));
    mt.register_container<Vector< int >>("evt",                              lookup< int >("evt") );
    mt.register_container<Vector<float>>("xsec",                             lookup<float>("xsec"));

    mt.register_container<Vector<std::vector< int >>>("Jet_mcMatchFlav",     lookup<std::vector< int >>("Jet_mcMatchFlav"));

    mt.register_container<Vector<std::vector<float>>>("Jet_pt",              lookup<std::vector<float>>("Jet_pt"));
    mt.register_container<Vector<std::vector<float>>>("Jet_eta",             lookup<std::vector<float>>("Jet_eta"));
    mt.register_container<Vector<std::vector<float>>>("Jet_phi",             lookup<std::vector<float>>("Jet_phi"));
    mt.register_container<Vector<std::vector<float>>>("Jet_mass",            lookup<std::vector<float>>("Jet_mass"));

    mt.register_container<ContainerTH1<float>>("leading_jet_pt", "Leading Jet Pt", lookup<float>("leading_jet_pt"), 100, 0, 500);
    mt.register_container<ContainerTH1<float>>("leading_lepton_pt", "Leading Lepton Pt", lookup<float>("leading_lepton_pt"), 100, 0, 500);
    mt.register_container<ContainerTH1<float>>("leading_lepton_relIso", "Leading Lepton Relative Isolation", lookup<float>("leading_lepton_relIso"), 100, 0, 0.05);
    mt.register_container<Vector<float>>("leading_lepton_relIso_all", lookup<float>("leading_lepton_relIso"));

    mt.register_container<PassCount>("trilepton_count",   event_selection.trilepton);
    mt.register_container<PassCount>("b_jet3_count",      event_selection.b_jet3);
    mt.register_container<PassCount>("z_mass_veto_count", event_selection.z_mass_veto);

    mt.register_container<PassCount>("J4_count", event_selection.J4);
    mt.register_container<PassCount>("J5_count", event_selection.J5);
    mt.register_container<PassCount>("J6_count", event_selection.J6);

    mt.register_container<PassCount>("SR4j_count", event_selection.SR4j);
    mt.register_container<PassCount>("SR5j_count", event_selection.SR5j);
    mt.register_container<PassCount>("SR6j_count", event_selection.SR6j);
}


void run_analysis(const std::string& input_filename, const std::string& data_label, bool silent){
    gSystem->Load("libfilval.so");
    auto replace_suffix = [](const std::string& input, const std::string& new_suffix){
        return input.substr(0, input.find_last_of(".")) + new_suffix;
    };
    string log_filename = replace_suffix(input_filename, "_result.log");
    fv::util::Log::init_logger(log_filename, fv::util::LogPriority::kLogDebug);

    string output_filename = replace_suffix(input_filename, "_result.root");
    TreeDataSet<MiniTree> mt(output_filename, input_filename, data_label);

    /* create_all_common_values(mt); */
    /* enable_extra_branches(mt); */
    /* declare_values(mt); */
    /* init_selection(); */
    /* declare_containers(mt); */
    mt.track_branch<int>("nJet");
    mt.track_branch_vec<float>("nJet", "Jet_pt");
    mt.track_branch_vec<float>("nJet", "Jet_eta");
    mt.track_branch_vec<float>("nJet", "Jet_phi");
    mt.track_branch_vec<float>("nJet", "Jet_mass");

    mt.register_container<ContainerTH1<int>>("jet_count", "Jet Multiplicity", lookup<int>("nJet"), 8, 0, 8);

    mt.register_container<ContainerTH1Many<float>>("Jet_pt_dist", "Jet P_T",
                                                      lookup<vector<float>>("Jet_pt"), 50, 0, 500,
                                                      "Jet P_T");
    mt.register_container<ContainerTH1Many<float>>("Jet_eta_dist", "Jet Eta",
                                                      lookup<vector<float>>("Jet_eta"), 50, -3, 3,
                                                      "Jet Eta");
    mt.register_container<ContainerTH1Many<float>>("Jet_phi_dist", "Jet Phi",
                                                      lookup<vector<float>>("Jet_phi"), 20, -PI, PI,
                                                      "Jet Phi");
    mt.register_container<ContainerTH1Many<float>>("Jet_mass_dist", "Jet Mass",
                                                      lookup<vector<float>>("Jet_mass"), 50, 0, 200,
                                                      "Jet Mass");

    mt.process(silent);
    mt.save_all();
}

int main(int argc, char * argv[])
{
    fv::util::ArgParser args(argc, argv);
    if(!args.cmdOptionExists("-l") || !args.cmdOptionExists("-f")) {
        cout << "Usage: ./main (-s) -l DATA_LABEL -f input_minitree.root" << endl;
        return -1;
    }
    bool silent = args.cmdOptionExists("-s");
    string input_filename = args.getCmdOption("-f");
    string data_label = args.getCmdOption("-l");
    run_analysis(input_filename, data_label, silent);
}
