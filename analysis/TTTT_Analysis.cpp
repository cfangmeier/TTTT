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


void declare_values(MiniTreeDataSet& mt){

    energies(lorentz_vectors("LepGood_pt", "LepGood_eta", "LepGood_phi", "LepGood_mass", "LepGood_4v"), "LepGood_energy");
    energies(lorentz_vectors("GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "GenPart_4v"), "GenPart_energy");
    energies(lorentz_vectors("Jet_pt",     "Jet_eta",     "Jet_phi",     "Jet_mass",     "Jet_4v"    ), "Jet_energy");

    auto dijet_4v = cart_product<TLorentzVector, TLorentzVector>("Jet_4v", "Jet_4v", "di-jet_4v");

    auto& inv_mass = GenFunction::register_function<float(TLorentzVector, TLorentzVector)>("inv_mass",
        FUNC(([] (const TLorentzVector& v1, const TLorentzVector& v2){
            TLorentzVector sum = v1 + v2;
            return (float)sum.M();
        })));

    fv::map(inv_mass, dijet_4v, "di-jet_inv_mass");

    fv::pair<vector<float>,vector<float>>("LepGood_energy", "LepGood_pt", "LepGood_energy_LepGood_pt");
    fv::pair<vector<float>,vector<float>>("Jet_energy", "Jet_eta", "Jet_energy_vs_Jet_eta");

    max<float>("LepGood_energy", "LepGood_energy_max");
    min<float>("LepGood_energy", "LepGood_energy_min");
    range<float>("LepGood_energy", "LepGood_energy_range");
    mean<float>("LepGood_energy", "LepGood_energy_mean");

    count<float>(GenFunction::register_function<bool(float)>("bJet_Selection", FUNC(([](float x){return x>0;}))),
                                                             "Jet_btagCMVA",  "b_jet_count");

    auto &is_electron = GenFunction::register_function<bool(int)>("is_electron", FUNC(([](int pdgId)
        {
            return abs(pdgId) == 11;
        })));
    auto &is_muon = GenFunction::register_function<bool(int)>("is_muon", FUNC(([](int pdgId)
        {
            return abs(pdgId) == 13;
        })));
    auto &is_lepton = GenFunction::register_function<bool(int)>("is_lepton", FUNC(([ie=&is_electron, im=&is_muon](int pdgId)
        {
            return (*ie)(pdgId) || (*im)(pdgId);
        })));

    count<int>(is_electron, "GenPart_pdgId", "genEle_count");
    count<int>(is_muon,     "GenPart_pdgId", "genMu_count");
    count<int>(is_lepton,   "GenPart_pdgId", "genLep_count");

    count<int>(is_electron, "LepGood_pdgId", "recEle_count");
    count<int>(is_muon,     "LepGood_pdgId", "recMu_count");
    count<int>(is_lepton,   "LepGood_pdgId", "recLep_count");


    fv::pair<int, int>("genEle_count", "recEle_count", "genEle_count_v_recEle_count");
    fv::pair<int, int>("genMu_count", "recMu_count", "genMu_count_v_recMu_count");
    fv::pair<int, int>("genLep_count", "recLep_count", "genLep_count_v_recLep_count");

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

    mt.register_container(new ContainerTH1<int>("lepton_count", "Lepton Multiplicity", lookup<int>("nLepGood"), 8, 0, 8));

    mt.register_container(new ContainerTH1Many<float>("LepGood_energy_all", "Lepton Energy - All",
                                                      lookup<vector<float>>("LepGood_energy"), 50, 0, 500));
    mt.register_container(new ContainerTH1<float>("LepGood_energy_max", "Lepton Energy - Max",
                                                  lookup<float>("LepGood_energy_max"), 50, 0, 500,
                                                  "Lepton Energy Max(GeV)"));
    mt.register_container(new ContainerTH1<float>("LepGood_energy_min", "Lepton Energy - Min",
                                                  lookup<float>("LepGood_energy_min"), 50, 0, 500,
                                                  "Lepton Energy Min(GeV)"));
    mt.register_container(new ContainerTH1<float>("LepGood_energy_range", "Lepton Energy - Range",
                                                  lookup<float>("LepGood_energy_range"), 50, 0, 500,
                                                  "Lepton Energy Range(GeV)"));

    mt.register_container(new ContainerTH1Many<float>("Jet_pt", "Jet P_T",
                                                      lookup<vector<float>>("Jet_pt"), 50, 0, 500,
                                                      "Jet P_T"));
    mt.register_container(new ContainerTH1Many<float>("Jet_eta", "Jet Eta",
                                                      lookup<vector<float>>("Jet_eta"), 50, -3, 3,
                                                      "Jet Eta"));
    mt.register_container(new ContainerTH1Many<float>("Jet_phi", "Jet Phi",
                                                      lookup<vector<float>>("Jet_phi"), 20, -PI, PI,
                                                      "Jet Phi"));
    mt.register_container(new ContainerTH1Many<float>("Jet_mass", "Jet Mass",
                                                      lookup<vector<float>>("Jet_mass"), 50, 0, 200,
                                                      "Jet Mass"));

    mt.register_container(new ContainerTH1Many<float>("dijet_inv_mass", "Di-Jet Inv. Mass - All",
                                                      lookup<vector<float>>("di-jet_inv_mass"), 100, 0, 500,
                                                      "Di-Jet Mass"));
    mt.register_container(new ContainerTH1Many<float>("dijet_inv_mass_osdilepton", "Di-Jet Inv. Mass - OS Dilepton",
                                                      lookup<vector<float>>("di-jet_inv_mass"), 100, 0, 500,
                                                      "Di-Jet Mass"))->add_filter(lookup_obs_filter("os-dilepton"));
    mt.register_container(new ContainerTH1Many<float>("dijet_inv_mass_ssdilepton", "Di-Jet Inv. Mass - SS Dilepton",
                                                      lookup<vector<float>>("di-jet_inv_mass"), 100, 0, 500,
                                                      "Di-Jet Mass"))->add_filter(lookup_obs_filter("ss-dilepton"));
    mt.register_container(new ContainerTH1Many<float>("dijet_inv_mass_trilepton", "Di-Jet Inv. Mass - Trilepton",
                                                      lookup<vector<float>>("di-jet_inv_mass"), 100, 0, 500,
                                                      "Di-Jet Mass"))->add_filter(lookup_obs_filter("trilepton"));

    mt.register_container(new ContainerTH1Many<float>("Jet_energy", "Jet Energy",
                                                      lookup<vector<float>>("Jet_energy"), 100, 0, 400,
                                                      "Jet Energy"));
    mt.register_container(new ContainerTH2Many<float>("Jet_energy_vs_Jet_eta", "Jet Energy vs Jet Eta",
                                                      lookup<std::pair<vector<float>, vector<float>>>("Jet_energy_vs_Jet_eta"),
                                                      100, 0, 400, 50, -3, 3,
                                                      "Jet Energy", "Jet Eta"));

    mt.register_container(new ContainerTH2<int>("nLepvsnJet", "Number of Leptons vs Number of Jets",
                                              fv::pair<int, int>("nLepGood", "nJet"),
                                              7, 0, 7, 20, 0, 20,
                                              "Number of Leptons", "Number of Jets"));

    mt.register_container(new ContainerTH2Many<float>("LepGood_energy_vs_pt", "Lepton Energy vs Lepton Pt",
                                                      lookup<std::pair<std::vector<float>,std::vector<float>>>("LepGood_energy_LepGood_pt"),
                                                      50, 0, 500, 50, 0, 500,
                                                      "lepton energy","lepton Pt"));

    mt.register_container(new ContainerTH2<int>("genEle_count_v_recEle_count", "Number of Generated Electrons v. Number of Reconstructed Electrons",
                                                lookup<std::pair<int,int>>("genEle_count_v_recEle_count"),
                                                10, 0, 10, 10, 0, 10,
                                                "Generated Electrons","Reconstructed Electrons"));

    mt.register_container(new ContainerTH2<int>("genMu_count_v_recMu_count", "Number of Generated Muons v. Number of Reconstructed Muons",
                                                lookup<std::pair<int,int>>("genMu_count_v_recMu_count"),
                                                10, 0, 10, 10, 0, 10,
                                                "Generated Muons","Reconstructed Muons"));

    mt.register_container(new ContainerTH2<int>("genLep_count_v_recLep_count", "Number of Generated Leptons v. Number of Reconstructed Leptons (e & mu only)",
                                                lookup<std::pair<int,int>>("genLep_count_v_recLep_count"),
                                                10, 0, 10, 10, 0, 10,
                                                "Generated Leptons","Reconstructed Leptons"));

    mt.register_container(new ContainerTH1<int>("b_jet_count", "B-Jet Multiplicity", lookup<int>("b_jet_count"), 10, 0, 10));


    mt.register_container(new ContainerTH1<int>("jet_count_os_dilepton", "Jet Multiplicity - OS Dilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14))->add_filter(lookup_obs_filter("os-dilepton"));
    mt.register_container(new ContainerTH1<int>("jet_count_ss_dilepton", "Jet Multiplicity - SS Dilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14))->add_filter(lookup_obs_filter("ss-dilepton"));
    mt.register_container(new ContainerTH1<int>("jet_count_trilepton", "Jet Multiplicity - Trilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14))->add_filter(lookup_obs_filter("trilepton"));

    mt.register_container(new ContainerTH1<int>("nVert", "Number of Primary Vertices", lookup<int>("nVert"), 50, 0, 50));

    mt.register_container(new CounterMany<int>("GenPart_pdgId_counter", lookup<vector<int>>("GenPart_pdgId")));


    mt.register_container(new Vector<vector< int >>("GenPart_pdgId",          lookup<vector< int >>("GenPart_pdgId")));
    mt.register_container(new Vector<vector< int >>("GenPart_motherIndex",    lookup<vector< int >>("GenPart_motherIndex")));
    mt.register_container(new Vector<vector< int >>("GenPart_motherId",       lookup<vector< int >>("GenPart_motherId")));
    mt.register_container(new Vector<vector<float>>("GenPart_pt",             lookup<vector<float>>("GenPart_pt")));
    mt.register_container(new Vector<vector<float>>("GenPart_energy",         lookup<vector<float>>("GenPart_energy")));
    mt.register_container(new Vector<vector< int >>("GenPart_status",         lookup<vector< int >>("GenPart_status")));

    mt.register_container(new Vector<vector< int >>("LepGood_mcMatchId",      lookup<vector< int >>("LepGood_mcMatchId")));
    mt.register_container(new Vector<vector< int >>("LepGood_mcMatchPdgId",   lookup<vector< int >>("LepGood_mcMatchPdgId")));

    mt.register_container(new Vector< int >("run",  lookup< int >("run") ));
    mt.register_container(new Vector< int >("lumi", lookup< int >("lumi")));
    mt.register_container(new Vector< int >("evt",  lookup< int >("evt") ));
    mt.register_container(new Vector<float>("xsec", lookup<float>("xsec")));
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
        cout << "Usage: ./main -f input_minitree.root" << endl;
        return -1;
    }
    bool silent = args.cmdOptionExists("-s");
    string input_filename = args.getCmdOption("-f");
    run_analysis(input_filename, silent);
}
