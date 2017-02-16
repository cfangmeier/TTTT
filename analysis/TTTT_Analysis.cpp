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
#include <tuple>
#include <utility>
#include <limits>

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"

#include "MiniTreeDataSet.hpp"
#include <TSystem.h>

using namespace std;
using namespace fv;
using namespace fv::root;

void enable_branches(MiniTreeDataSet& mt){
    mt.fChain->SetBranchStatus("*", false);

    mt.track_branch<int>("nLepGood");
    mt.track_branch_vec<float>("nLepGood", "LepGood_pt");
    mt.track_branch_vec<float>("nLepGood", "LepGood_eta");
    mt.track_branch_vec<float>("nLepGood", "LepGood_phi");
    mt.track_branch_vec<float>("nLepGood", "LepGood_mass");
    mt.track_branch_vec<float>("nLepGood", "LepGood_mcPt");
    mt.track_branch_vec<int>("nLepGood", "LepGood_charge");

    mt.track_branch<int>("nJet");
    mt.track_branch_vec<float>("nJet", "Jet_pt");
    mt.track_branch_vec<float>("nJet", "Jet_eta");
    mt.track_branch_vec<float>("nJet", "Jet_phi");
    mt.track_branch_vec<float>("nJet", "Jet_mass");
    mt.track_branch_vec<float>("nJet", "Jet_btagCMVA");

    mt.track_branch<int>("nGenTop");
    mt.track_branch_vec<int>("nGenTop", "GenTop_pdgId");

    mt.track_branch<int>("nGenPart");
    mt.track_branch_vec<int>("nGenPart", "GenPart_pdgId");
    mt.track_branch_vec<int>("nGenPart", "GenPart_motherIndex");
    mt.track_branch_vec<float>("nGenPart", "GenPart_pt");
    mt.track_branch_vec<float>("nGenPart", "GenPart_eta");
    mt.track_branch_vec<float>("nGenPart", "GenPart_phi");
    mt.track_branch_vec<float>("nGenPart", "GenPart_mass");

/*
    GenPart_motherId                                                              : Int_t pdgId of the mother of the particle for Hard scattering particles, with ancestry and links
    GenPart_grandmotherId                                                         : Int_t pdgId of the grandmother of the particle for Hard scattering particles, with ancestry and links
    GenPart_sourceId                                                              : Int_t origin of the particle (heaviest ancestor) : 6=t, 25=h, 23/24=W/Z for Hard scattering particles, with ancestry and links
    GenPart_charge                                                                : Float_t charge for Hard scattering particles, with ancestry and links
    GenPart_status                                                                : Int_t status for Hard scattering particles, with ancestry and links
    GenPart_isPromptHard                                                          : Int_t isPromptHard for Hard scattering particles, with ancestry and links
    GenPart_pdgId                                                                 : Int_t pdgId for Hard scattering particles, with ancestry and links
    GenPart_pt                                                                    : Float_t pt for Hard scattering particles, with ancestry and links
    GenPart_eta                                                                   : Float_t eta for Hard scattering particles, with ancestry and links
    GenPart_phi                                                                   : Float_t phi for Hard scattering particles, with ancestry and links
    GenPart_mass                                                                  : Float_t mass for Hard scattering particles, with ancestry and links
    GenPart_motherIndex                                                           : Int_t index of the mother in the generatorSummary for Hard scattering particles, with ancestry and links
*/



    mt.track_branch<int>("ngenLep");
    mt.track_branch_vec<int>("ngenLep", "genLep_sourceId");
    mt.track_branch_vec<float>("ngenLep", "genLep_pt");

    mt.track_branch<int>("nVert");
}


void declare_values(MiniTreeDataSet& mt){

    energies(lorentz_vectors("LepGood_pt", "LepGood_eta", "LepGood_phi", "LepGood_mass", "LepGood_4v"), "LepGood_energy");
    energies(lorentz_vectors("GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "GenPart_4v"), "GenPart_energy");

    fv::pair<vector<float>,vector<float>>("LepGood_energy", "LepGood_pt", "LepGood_energy_LepGood_pt");

    max<float>("LepGood_energy", "LepGood_energy_max");
    min<float>("LepGood_energy", "LepGood_energy_min");
    range<float>("LepGood_energy", "LepGood_energy_range");
    mean<float>("LepGood_energy", "LepGood_energy_mean");

    count<float>(GenFunction::register_function<bool(float)>("bJet_Selection", FUNC(([](float x){return x>0;}))),
                     "Jet_btagCMVA",  "b_jet_count");

    filter("trilepton", FUNC(([nLepGood=lookup<int>("nLepGood")](){
                return dynamic_cast<Value<int>*>(nLepGood)->get_value() == 3;})));

    filter("os-dilepton", FUNC(([LepGood_charge=lookup<vector<int>>("LepGood_charge")](){
               auto& charges = LepGood_charge->get_value();
               return charges.size()==2 && (charges[0] != charges[1]);})));

    filter("ss-dilepton", FUNC(([LepGood_charge=lookup<vector<int>>("LepGood_charge")](){
               auto& charges = LepGood_charge->get_value();
               return charges.size()==2 && (charges[0] == charges[1]); })));

}

void declare_containers(MiniTreeDataSet& mt){
    mt.register_container(new ContainerTH1<int>("lepton_count", "Lepton Multiplicity", lookup<int>("nLepGood"), 8, 0, 8));
    mt.register_container(new ContainerTH1<int>("top_quark_count", "Top Quark Multiplicity", lookup<int>("nGenTop"), 8, 0, 8));

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


    mt.register_container(new ContainerTGraph("nLepvsnJet", "Number of Leptons vs Number of Jets",
                                              fv::pair<int, int>("nLepGood", "nJet") ));

    mt.register_container(new ContainerTH2Many<float>("LepGood_energy_vs_pt", "Lepton Energy vs Lepton Pt",
                                                      lookup<std::pair<std::vector<float>,std::vector<float>>>("LepGood_energy_LepGood_pt"),
                                                      50, 0, 500, 50, 0, 500,
                                                      "lepton energy","lepton Pt"));

    mt.register_container(new ContainerTH1<int>("b_jet_count", "B-Jet Multiplicity", lookup<int>("b_jet_count"), 10, 0, 10));


    mt.register_container(new ContainerTH1<int>("jet_count_os_dilepton", "Jet Multiplicity - OS Dilepton Events",
                                                lookup<int>("nJet"), 14, 0, 14));
    mt.get_container("jet_count_os_dilepton")->add_filter(lookup_filter("os-dilepton"));
    mt.register_container(new ContainerTH1<int>("jet_count_ss_dilepton", "Jet Multiplicity - SS Dilepton Events",
                lookup<int>("nJet"), 14, 0, 14));
    mt.get_container("jet_count_ss_dilepton")->add_filter(lookup_filter("ss-dilepton"));
    mt.register_container(new ContainerTH1<int>("jet_count_trilepton", "Jet Multiplicity - Trilepton Events",
                lookup<int>("nJet"), 14, 0, 14));
    mt.get_container("jet_count_trilepton")->add_filter(lookup_filter("trilepton"));

    mt.register_container(new ContainerTH1<int>("primary_vert_count", "Number of Primary Vertices",
                lookup<int>("nVert"), 50, 0, 50));

    mt.register_container(new CounterMany<int>("GenTop_pdg_id", lookup<vector<int>>("GenTop_pdgId")));
    mt.register_container(new CounterMany<int>("GenPart_pdg_id", lookup<vector<int>>("GenPart_pdgId")));

    mt.register_container(new Vector<vector<int>>("GenPart_pdgId", lookup<vector<int>>("GenPart_pdgId")));
    mt.register_container(new Vector<vector<int>>("GenPart_motherIndex", lookup<vector<int>>("GenPart_motherIndex")));
    mt.register_container(new Vector<vector<float>>("GenPart_pt", lookup<vector<float>>("GenPart_pt")));
    mt.register_container(new Vector<vector<float>>("GenPart_energy", lookup<vector<float>>("GenPart_energy")));
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
