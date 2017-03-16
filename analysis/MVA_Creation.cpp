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

    mt.track_branch<int>("nLepGood");
    /* mt.track_branch_vec< int >("nLepGood", "LepGood_pdgId"); */
    /* mt.track_branch_vec<float>("nLepGood", "LepGood_pt"); */
    /* mt.track_branch_vec<float>("nLepGood", "LepGood_eta"); */
    /* mt.track_branch_vec<float>("nLepGood", "LepGood_phi"); */
    /* mt.track_branch_vec<float>("nLepGood", "LepGood_mass"); */
    /* mt.track_branch_vec< int >("nLepGood", "LepGood_charge"); */
    /* mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchId"); */
    /* mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchPdgId"); */
    /* mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchAny"); */
    /* mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchTau"); */
    /* mt.track_branch_vec< int >("nLepGood", "LepGood_mcPt"); */

    mt.track_branch<int>("nJet");
    /* mt.track_branch_vec<float>("nJet", "Jet_pt"); */
    /* mt.track_branch_vec<float>("nJet", "Jet_eta"); */
    /* mt.track_branch_vec<float>("nJet", "Jet_phi"); */
    /* mt.track_branch_vec<float>("nJet", "Jet_mass"); */
    /* mt.track_branch_vec<float>("nJet", "Jet_btagCMVA"); */
    /* mt.track_branch_vec< int >("nJet", "Jet_mcMatchFlav"); */
    /* mt.track_branch_vec< int >("nJet", "Jet_mcMatchId"); */
    /* mt.track_branch_vec< int >("nJet", "Jet_mcFlavour"); */


    mt.track_branch<int>("nGenPart");
    /* mt.track_branch_vec< int >("nGenPart", "GenPart_pdgId"); */
    /* mt.track_branch_vec< int >("nGenPart", "GenPart_motherIndex"); */
    /* mt.track_branch_vec< int >("nGenPart", "GenPart_motherId"); */
    /* mt.track_branch_vec<float>("nGenPart", "GenPart_pt"); */
    /* mt.track_branch_vec<float>("nGenPart", "GenPart_eta"); */
    /* mt.track_branch_vec<float>("nGenPart", "GenPart_phi"); */
    /* mt.track_branch_vec<float>("nGenPart", "GenPart_mass"); */
    /* mt.track_branch_vec< int >("nGenPart", "GenPart_status"); */

    mt.track_branch<int>("nBJetLoose40");
    mt.track_branch<int>("nBJetMedium40");
    mt.track_branch<int>("nBJetTight40");


    /* mt.track_branch<int>("nVert"); */

    /* mt.track_branch< int >("run" ); */
    /* mt.track_branch< int >("lumi"); */
    /* mt.track_branch< int >("evt" ); */
    /* mt.track_branch<float>("xsec"); */
}

void declare_values(MiniTreeDataSet& mt){

    /* auto data = fv::tuple(lookup<int>("nJet"), lookup<int>("nBJetLoose40"), lookup<int>("nBJetMedium40"), lookup<int>("nBJetTight40"), lookup<int>("nLepGood")); */

    auto event_number = mt.get_current_event_number();
    auto is_training = fv::apply(fv::GenFunction::register_function<bool(int)>("is_odd",
        FUNC(([](int n){
            return (n%2) == 1;
        }))), fv::tuple(event_number));

    auto is_signal = fv::bound(fv::GenFunction::register_function<bool()>("is_signal",
        FUNC(([mt=&mt](){
            const std::string& label = mt->get_current_event_label();
            return label == "signal";
        }))), "is_signal");

    auto weight = fv::constant<double>("1", 1);

    /* auto mva_data = fv::root::mva_data(data, is_training, is_signal, weight, "mva_data"); */
    /* mva_data->enable_logging([](std::tuple<std::tuple<int,int,int,int,int>,bool,bool,double> t) */
    /*     { */
    /*         std::tuple<int,int,int,int,int> data; */
    /*         bool is_training, is_signal; */
    /*         double weight; */
    /*         std::tie(data, is_training, is_signal, weight) = t; */
    /*         int nJet, nBJetLoose40, nBJetMedium40, nBJetTight40, nLepGood; */
    /*         std::tie(nJet, nBJetLoose40, nBJetMedium40, nBJetTight40, nLepGood) = data; */
    /*         std::stringstream ss; */
    /*         ss << "data("<<nJet<<","<<nBJetLoose40<<","<<nBJetMedium40<<","<<nBJetTight40<<","<<nLepGood<<")"<< std::endl */
    /*            <<"\tis_training:" << is_training<< std::endl */
    /*            <<"\tis_signal:  " << is_signal  << std::endl */
    /*            <<"\tweight:     " << weight     << std::endl; */
    /*         return ss.str(); */
    /*     }); */
    auto mva_data = fv::root::mva_data<int,int,int,int,int>(is_training, is_signal, weight,
            {"nJet",          lookup<int>("nJet")},
            {"nBJetLoose40",  lookup<int>("nBJetLoose40")},
            {"nBJetMedium40", lookup<int>("nBJetMedium40")},
            {"nBJetTight40",  lookup<int>("nBJetTight40")},
            {"nLepGood",      lookup<int>("nLepGood")}
            );
    GenValue::alias("mva_data", mva_data);

}

void declare_containers(MiniTreeDataSet& mt){

    auto mva_data = (MVAData<int,int,int,int,int>*)lookup<MVAData<int,int,int,int,int>::type>("mva_data");
    auto mva =  mt.register_container<MVA<int,int,int,int,int>>("my_mva", mva_data);
    mva->add_method("KNN", "H:nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim");
}


void create_mva(const std::string& output_filename, const std::vector<std::string>& sig_files, const std::vector<std::string>& bg_files, bool silent){
    gSystem->Load("libfilval.so");
    auto replace_suffix = [](const std::string& input, const std::string& new_suffix){
        return input.substr(0, input.find_last_of(".")) + new_suffix;
    };
    string log_filename = replace_suffix(output_filename, ".log");
    fv::util::Log::init_logger(log_filename, fv::util::LogPriority::kLogDebug);

    std::map<std::string, std::string> filenames_with_labels;
    for (const std::string& fname : sig_files){
        filenames_with_labels[fname] = "signal";
    }
    for (const std::string& fname : bg_files){
        filenames_with_labels[fname] = "background";
    }

    MiniTreeDataSet mt(output_filename, filenames_with_labels);

    enable_branches(mt);
    declare_values(mt);
    declare_containers(mt);

    mt.process(silent);
    mt.save_all();
}

int main(int argc, char * argv[])
{
    fv::util::ArgParser args(argc, argv);
    if(args.cmdOptionExists("-h")) {
        cout << "Usage: ./mva (-s) -out outfile.root -sig [signal_minitree.root]+ -bg [background_minitree.root]+" << endl;
        return 0;
    }
    bool silent = args.cmdOptionExists("-s");
    string output_filename = args.getCmdOption("-out");
    std::vector<std::string> sig_files;
    std::vector<std::string> bg_files;
    std::vector<std::string>* cur_flist = nullptr;

    for(int i=1; i<argc; i++){
        if (!strncmp(argv[i], "-sig", 4)){
            cur_flist = &sig_files;
        }
        else if (!strncmp(argv[i], "-bg", 3)){
            cur_flist = &bg_files;
            continue;
        }
        else if (!strncmp(argv[i], "-out", 4)){
            cur_flist = nullptr;
        }
        else if (cur_flist != nullptr){
            cur_flist->push_back(argv[i]);
        }
    }
    create_mva(output_filename, sig_files, bg_files, silent);
}
