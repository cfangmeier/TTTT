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
#include "filval_root/filval_root.hpp"

#include "MiniTreeDataSet.hpp"
#include <TSystem.h>

#define PI 3.14159
#define W_MASS 80.385 // GeV/c^2
#define Z_MASS 91.188 // GeV/c^2
#define T_MASS 172.44 // GeV/c^2

using namespace std;
using namespace fv;
using namespace fv::root;

void enable_branches(MiniTreeDataSet& mt){
    mt.fChain->SetBranchStatus("*", false);

    mt.track_branch<int>("nLepGood");
    mt.track_branch_vec< int >("nLepGood", "LepGood_pdgId");
    mt.track_branch_vec<float>("nLepGood", "LepGood_pt");
    mt.track_branch_vec<float>("nLepGood", "LepGood_eta");
    mt.track_branch_vec<float>("nLepGood", "LepGood_phi");
    mt.track_branch_vec<float>("nLepGood", "LepGood_mass");
    mt.track_branch_vec< int >("nLepGood", "LepGood_charge");
    mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchId");
    mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchPdgId");
    mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchAny");
    mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchTau");
    mt.track_branch_vec< int >("nLepGood", "LepGood_mcPt");

    mt.track_branch<int>("nJet");
    mt.track_branch_vec<float>("nJet", "Jet_pt");
    mt.track_branch_vec<float>("nJet", "Jet_eta");
    mt.track_branch_vec<float>("nJet", "Jet_phi");
    mt.track_branch_vec<float>("nJet", "Jet_mass");
    mt.track_branch_vec<float>("nJet", "Jet_btagCMVA");
    mt.track_branch_vec< int >("nJet", "Jet_mcMatchFlav");
    mt.track_branch_vec< int >("nJet", "Jet_mcMatchId");
    mt.track_branch_vec< int >("nJet", "Jet_mcFlavour");


    mt.track_branch<int>("nGenPart");
    mt.track_branch_vec< int >("nGenPart", "GenPart_pdgId");
    mt.track_branch_vec< int >("nGenPart", "GenPart_motherIndex");
    mt.track_branch_vec< int >("nGenPart", "GenPart_motherId");
    mt.track_branch_vec<float>("nGenPart", "GenPart_pt");
    mt.track_branch_vec<float>("nGenPart", "GenPart_eta");
    mt.track_branch_vec<float>("nGenPart", "GenPart_phi");
    mt.track_branch_vec<float>("nGenPart", "GenPart_mass");
    mt.track_branch_vec< int >("nGenPart", "GenPart_status");

    mt.track_branch<int>("nBJetLoose40");
    mt.track_branch<int>("nBJetMedium40");
    mt.track_branch<int>("nBJetTight40");


    mt.track_branch<int>("nVert");

    mt.track_branch< int >("run" );
    mt.track_branch< int >("lumi");
    mt.track_branch< int >("evt" );
    mt.track_branch<float>("xsec");
}

struct Jet{
    TLorentzVector v;
    int            idx;
    int            pdgid;
    float          b_cmva;
    Jet() { }
    Jet(const TLorentzVector& v, int idx, int pdgid, float b_cmva)
      :v(v),idx(idx),pdgid(pdgid),b_cmva(b_cmva) { }

    static Jet reco(const TLorentzVector& v, int idx, float b_cmva){
        return Jet(v, idx, 0, b_cmva);
    }

    static Jet mc(const TLorentzVector& v, int idx, int pdgid){
        return Jet(v, idx, pdgid, 0);
    }
};

void declare_values(MiniTreeDataSet& mt){

    // Define Lorentz Vector(TLorentzVector) object from fields in ntuple
    lorentz_vectors("LepGood_pt", "LepGood_eta", "LepGood_phi", "LepGood_mass", "LepGood_4v");
    lorentz_vectors("GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "GenPart_4v");
    lorentz_vectors("Jet_pt",     "Jet_eta",     "Jet_phi",     "Jet_mass",     "Jet_4v"    );

    energies("GenPart_4v", "GenPart_energy");


    // Define a couple selections to be used in the top-mass reconstruction.
    auto& b_mva_filter = GenFunction::register_function<bool(Jet)>("b_mva_filter",
        FUNC(([cut=0.0](const Jet& j){
                return j.b_cmva > cut;
        })));
    auto& b_pdgid_filter = GenFunction::register_function<bool(Jet)>("b_pdgid_filter",
        FUNC(([](const Jet& j){
                return j.pdgid == 5 || j.pdgid==-5;
        })));
    auto& w_mass_filter = GenFunction::register_function<bool(Jet, Jet)>("w_mass_filter",
        FUNC(([win_l=W_MASS-10, win_h=W_MASS+10](const Jet& j1, const Jet& j2){
            float inv_mass = (j1.v + j2.v).M();
            return inv_mass > win_l && inv_mass < win_h;
        })));
    auto& dup_filter = GenFunction::register_function<bool(std::tuple<Jet,Jet>,Jet)>("dup_filter",
        FUNC(([](const std::tuple<Jet,Jet>& w, const Jet& b){
            int j0 = b.idx;
            int j1 = std::get<0>(w).idx;
            int j2 = std::get<1>(w).idx;
            return (j0 != j1) && (j0 != j2) && (j1 != j2);
        })));
    auto& qg_id_filter = GenFunction::register_function<bool(Jet, Jet)>("qg_id_filter",
        FUNC(([](const Jet& j1, const Jet& j2){
            // require both particles be either quarks(not Top) or gluons
            int id1 = abs(j1.pdgid);
            int id2 = abs(j2.pdgid);
            return ((id1 >=1 && id1 <= 5) || id1 == 21) &&
                   ((id2 >=1 && id2 <= 5) || id2 == 21);
        })));

    // Here is the calculation of the Top Reconstructed Mass from Jets
    auto jets = apply(GenFunction::register_function<std::vector<Jet>(std::vector<TLorentzVector>,std::vector<float>)>("build_reco_jets",
        FUNC(([](const std::vector<TLorentzVector>& vs, const std::vector<float>& b_cmvas){
            std::vector<Jet> jets;
            for(int i=0; i<vs.size(); i++){
                jets.push_back(Jet::reco(vs[i],i, b_cmvas[i]));
            }
            return jets;
        }))), fv::tuple(lookup<std::vector<TLorentzVector>>("Jet_4v"), lookup<std::vector<float>>("Jet_btagCMVA")), "reco_jets");


    auto b_jets = filter(b_mva_filter, jets, "reco_b_jets");
    auto w_dijets = tup_filter<Jet,Jet>(w_mass_filter, combinations<Jet,2>(jets, "reco_dijets"));

    auto top_cands = cart_product<std::tuple<Jet,Jet>, Jet>(w_dijets, b_jets);

    top_cands = tup_filter(dup_filter, top_cands);

    auto& t_mass = GenFunction::register_function<float(std::tuple<Jet,Jet>,Jet)>("t_mass",
        FUNC(([](const std::tuple<Jet,Jet>& w, const Jet& b){
            return (std::get<0>(w).v+std::get<1>(w).v+b.v).M();
        })));

    fv::map(t_mass, top_cands, "reco_top_mass");

    // Here is the calculation of the Top Reconstructed Mass from Generator-Level objects
    jets = apply(GenFunction::register_function<std::vector<Jet>(std::vector<TLorentzVector>,std::vector<int>)>("build_mcjets",
        FUNC(([](const std::vector<TLorentzVector>& vs, const std::vector<int>& pdgid){
            std::vector<Jet> jets;
            for(int i=0; i<vs.size(); i++){
                jets.push_back(Jet::mc(vs[i],i, pdgid[i]));
            }
            return jets;
        }))), fv::tuple(lookup<std::vector<TLorentzVector>>("GenPart_4v"), lookup<std::vector<int>>("GenPart_pdgId")), "mcjets");

    b_jets = filter(b_pdgid_filter, jets);

    w_dijets = tup_filter(qg_id_filter, combinations<Jet,2>(jets));
    w_dijets = tup_filter(w_mass_filter, w_dijets);

    top_cands = cart_product<std::tuple<Jet,Jet>, Jet>(w_dijets, b_jets);

    top_cands = tup_filter(dup_filter, top_cands);


    fv::map(t_mass, top_cands, "mc_top_mass");


    // calculation of di-jet inv-mass spectrum
    auto& inv_mass2 = GenFunction::register_function<float(Jet, Jet)>("inv_mass2",
        FUNC(([] (const Jet& j1, const Jet& j2){
            TLorentzVector sum = j1.v + j2.v;
            return (float)sum.M();
        })));
    fv::map(inv_mass2, lookup<std::vector<std::tuple<Jet,Jet>>>("reco_dijets"), "dijet_inv_mass");



    count<float>(GenFunction::register_function<bool(float)>("bJet_Selection",
        FUNC(([](float x){
            return x>0;
        }))), "Jet_btagCMVA",  "b_jet_count");

    auto &is_electron = GenFunction::register_function<bool(int)>("is_electron",
        FUNC(([](int pdgId) {
            return abs(pdgId) == 11;
        })));
    auto &is_muon = GenFunction::register_function<bool(int)>("is_muon",
        FUNC(([](int pdgId) {
            return abs(pdgId) == 13;
        })));
    auto &is_lepton = GenFunction::register_function<bool(int)>("is_lepton",
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

    /* auto& sum = GenFunction::register_function<float(std::vector<float>)>("sum", */
    /*     FUNC(([](const std::vector<float>& v){ */
    /*         return std::accumulate(v.begin(), v.end(), 0); */
    /*     }))); */

    /* auto sum_jet_pt = fv::apply(sum, lookup<std::vector<float>>("Jet_pt")) */

    /* fv::tuple(lookup<float>("nJet"), */
    /*           lookup<float>("nLepGood"), */
    /*           lookup<float>("Jet_phi"), */
    /*           lookup<std::vector<float>>("Jet_mass"), */

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

void declare_containers(MiniTreeDataSet& mt){

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

    mt.register_container<ContainerTH1<int>>("b_jet_count", "B-Jet Multiplicity", lookup<int>("b_jet_count"), 10, 0, 10);


    mt.register_container<ContainerTH1<int>>("jet_count_os_dilepton", "Jet Multiplicity - OS Dilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14)->add_filter(lookup_obs_filter("os-dilepton"));
    mt.register_container<ContainerTH1<int>>("jet_count_ss_dilepton", "Jet Multiplicity - SS Dilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14)->add_filter(lookup_obs_filter("ss-dilepton"));
    mt.register_container<ContainerTH1<int>>("jet_count_trilepton", "Jet Multiplicity - Trilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14)->add_filter(lookup_obs_filter("trilepton"));

    mt.register_container<ContainerTH1<int>>("nVert", "Number of Primary Vertices", lookup<int>("nVert"), 50, 0, 50);

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

    mt.register_container<Vector<vector< int >>>("LepGood_mcMatchId",        lookup<vector< int >>("LepGood_mcMatchId"));
    mt.register_container<Vector<vector< int >>>("LepGood_mcMatchPdgId",     lookup<vector< int >>("LepGood_mcMatchPdgId"));

    mt.register_container<Vector< int >>("run",                              lookup< int >("run") );
    mt.register_container<Vector< int >>("lumi",                             lookup< int >("lumi"));
    mt.register_container<Vector< int >>("evt",                              lookup< int >("evt") );
    mt.register_container<Vector<float>>("xsec",                             lookup<float>("xsec"));

    mt.register_container<Vector<std::vector< int >>>("Jet_mcMatchFlav",     lookup<std::vector< int >>("Jet_mcMatchFlav"));
    mt.register_container<Vector<std::vector< int >>>("Jet_mcMatchId",       lookup<std::vector< int >>("Jet_mcMatchId"));
    mt.register_container<Vector<std::vector< int >>>("Jet_mcFlavour",       lookup<std::vector< int >>("Jet_mcFlavour"));

    mt.register_container<Vector<std::vector<float>>>("Jet_pt",              lookup<std::vector<float>>("Jet_pt"));
    mt.register_container<Vector<std::vector<float>>>("Jet_eta",             lookup<std::vector<float>>("Jet_eta"));
    mt.register_container<Vector<std::vector<float>>>("Jet_phi",             lookup<std::vector<float>>("Jet_phi"));
    mt.register_container<Vector<std::vector<float>>>("Jet_mass",            lookup<std::vector<float>>("Jet_mass"));

}


void run_analysis(const std::string& input_filename, bool silent){
    gSystem->Load("libfilval.so");
    auto replace_suffix = [](const std::string& input, const std::string& new_suffix){
        return input.substr(0, input.find_last_of(".")) + new_suffix;
    };
    string log_filename = replace_suffix(input_filename, "_result.log");
    fv::util::Log::init_logger(log_filename, fv::util::LogPriority::kLogDebug);

    string output_filename = replace_suffix(input_filename, "_result.root");
    MiniTreeDataSet mt(input_filename, output_filename);

    enable_branches(mt);
    declare_values(mt);
    declare_containers(mt);

    mt.process(silent);
    mt.save_all();
}

int main(int argc, char * argv[])
{
    fv::util::ArgParser args(argc, argv);
    if(!args.cmdOptionExists("-f")) {
        cout << "Usage: ./main (-s) -f input_minitree.root" << endl;
        return -1;
    }
    bool silent = args.cmdOptionExists("-s");
    string input_filename = args.getCmdOption("-f");
    run_analysis(input_filename, silent);
}
