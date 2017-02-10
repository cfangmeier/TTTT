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

#include "filval.hpp"
#include "filval_root.hpp"

#include "MiniTreeDataSet.hpp"

using namespace std;
using namespace fv;
using namespace fv::root;
using namespace fv::util;

GenValue* lookup(const string& name){
    return GenValue::get_value(name);
}
Filter* lookup_filter(const string& name){
    return dynamic_cast<Filter*>(GenValue::get_value(name));
}

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

    mt.track_branch<int>("ngenLep");
    mt.track_branch_vec<int>("ngenLep", "genLep_sourceId");
    mt.track_branch_vec<float>("ngenLep", "genLep_pt");

    mt.track_branch<int>("nVert");
}

void declare_values(MiniTreeDataSet& mt){
    auto& get_energy = GenFunction::register_function<float(float,float,float,float)>("get_energy",
            FUNC(([](float pt, float eta, float phi, float m){
                TLorentzVector t;
                t.SetPtEtaPhiM(pt, eta, phi, m);
                return t.E();
            })));

    new ZipMapFour<float, float>(get_energy, "LepGood_pt", "LepGood_eta", "LepGood_phi", "LepGood_mass",
                                 "lepton_energy");

    typedef tuple<float,float,float,float> PtEtaPhiM;
    auto& get_energy2 = GenFunction::register_function<float(PtEtaPhiM)>("get_energy",
            FUNC(([](PtEtaPhiM ptetaphim){
                float pt, eta, phi, m;
                tie(pt, eta, phi, m) = ptetaphim;
                TLorentzVector t;
                t.SetPtEtaPhiM(pt, eta, phi, m);
                return t.E();
            })));

    new Zip<float,float,float,float>(dynamic_cast<Value<vector<float>>*>(lookup("LepGood_pt")),
                                     dynamic_cast<Value<vector<float>>*>(lookup("LepGood_eta")),
                                     dynamic_cast<Value<vector<float>>*>(lookup("LepGood_phi")),
                                     dynamic_cast<Value<vector<float>>*>(lookup("LepGood_mass")),
                                     "lepton_kinematics");

    new Pair<vector<float>,vector<float>>("lepton_energy", "LepGood_pt", "lepton_energy_lepton_pt");

    new Max<float>("lepton_energy", "lepton_energy_max");
    new Min<float>("lepton_energy", "lepton_energy_min");
    new Range<float>("lepton_energy", "lepton_energy_range");
    new Mean<float>("lepton_energy", "lepton_energy_mean");

    new Count<float>(GenFunction::register_function<bool(float)>("bJet_Selection", FUNC(([](float x){return x>0;}))),
                     "Jet_btagCMVA",  "b_jet_count");

    


    new Filter("trilepton", FUNC(([nLepGood=lookup("nLepGood")](){
            return dynamic_cast<Value<int>*>(nLepGood)->get_value() == 3;})));

    new Filter("os-dilepton", FUNC(([LepGood_charge=lookup("LepGood_charge")](){
                    auto& charges = static_cast<Value<vector<int>>*>(LepGood_charge)->get_value();
                    return charges.size()==2 && (charges[0] != charges[1]);})));

    new Filter("ss-dilepton", FUNC(([LepGood_charge=lookup("LepGood_charge")](){
                    auto& charges = static_cast<Value<vector<int>>*>(LepGood_charge)->get_value();
                    return charges.size()==2 && (charges[0] == charges[1]);})));

}

void declare_containers(MiniTreeDataSet& mt){
    mt.register_container(new ContainerTH1<int>("lepton_count", "Lepton Multiplicity", lookup("nLepGood"), 8, 0, 8));
    mt.register_container(new ContainerTH1<int>("top_quark_count", "Top Quark Multiplicity", lookup("nGenTop"), 8, 0, 8));

    mt.register_container(new ContainerTH1Many<float>("lepton_energy_all", "Lepton Energy - All", lookup("lepton_energy"), 50, 0, 500));
    mt.register_container(new ContainerTH1<float>("lepton_energy_max", "Lepton Energy - Max", lookup("lepton_energy_max"), 50, 0, 500));
    mt.register_container(new ContainerTH1<float>("lepton_energy_min", "Lepton Energy - Min", lookup("lepton_energy_min"), 50, 0, 500));
    mt.register_container(new ContainerTH1<float>("lepton_energy_rng", "Lepton Energy - Range", lookup("lepton_energy_range"), 50, 0, 500));


    mt.register_container(new ContainerTGraph("nLepvsnJet", "Number of Leptons vs Number of Jets", new Pair<int, int>("nLepGood", "nJet") ));

    mt.register_container(new ContainerTH2Many<float>("lepton_energy_vs_pt", "Lepton Energy - Range", lookup("lepton_energy_lepton_pt"),
                                                50, 0, 500, 50, 0, 500));

    mt.register_container(new ContainerTH1<int>("b_jet_count", "B-Jet Multiplicity", lookup("b_jet_count"), 10, 0, 10));


    mt.register_container(new ContainerTH1<int>("jet_count_os_dilepton", "Jet Multiplicity - OS Dilepton Events", lookup("nJet"), 14, 0, 14));
    mt.get_container("jet_count_os_dilepton")->add_filter(lookup_filter("os-dilepton"));
    mt.register_container(new ContainerTH1<int>("jet_count_ss_dilepton", "Jet Multiplicity - SS Dilepton Events", lookup("nJet"), 14, 0, 14));
    mt.get_container("jet_count_ss_dilepton")->add_filter(lookup_filter("ss-dilepton"));
    mt.register_container(new ContainerTH1<int>("jet_count_trilepton", "Jet Multiplicity - Trilepton Events",     lookup("nJet"), 14, 0, 14));
    mt.get_container("jet_count_trilepton")->add_filter(lookup_filter("trilepton"));

    mt.register_container(new ContainerTH1<int>("primary_vert_count", "Number of Primary Vertices", lookup("nVert"), 50, 0, 50));

    mt.register_container(new CounterMany<int>("GenTop_pdg_id", lookup("GenTop_pdgId")));
}


void run_analysis(const std::string& input_filename, bool silent){
    auto replace_suffix = [](const std::string& input, const std::string& new_suffix){
        return input.substr(0, input.find_last_of(".")) + new_suffix;
    };
    string log_filename = replace_suffix(input_filename, "_result.log");
    Log::init_logger(log_filename, LogPriority::kLogDebug);

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
    ArgParser args(argc, argv);
    if(!args.cmdOptionExists("-f")) {
        cout << "Usage: ./main -f input_minitree.root" << endl;
        return -1;
    }
    bool silent = args.cmdOptionExists("-s");
    string input_filename = args.getCmdOption("-f");
    run_analysis(input_filename, silent);
}
