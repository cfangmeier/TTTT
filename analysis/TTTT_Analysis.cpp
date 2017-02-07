#include <iostream>
#include <vector>
#include <utility>

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"
#include "filval/log.hpp"

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
    mt.track_branch<int>("nJet");
    mt.track_branch<int>("nLepGood");
    mt.track_branch_ptr<float>("LepGood_pt");
    mt.track_branch_ptr<float>("LepGood_eta");
    mt.track_branch_ptr<float>("LepGood_phi");
    mt.track_branch_ptr<float>("LepGood_mass");
}

void declare_values(MiniTreeDataSet& mt){
    auto& mean = GenFunction::register_function<float(vector<float>)>("mean", FUNC(([](vector<float> v){
            int n = 0;
            float sum = 0;
            for (float e : v){
                n++;
                sum += e;
            }
            return n>0 ? sum / n : 0;
            })));

    auto pt_wrapper  = new WrapperVector<float>("nLepGood", "LepGood_pt");
    auto eta_wrapper = new WrapperVector<float>("nLepGood", "LepGood_eta");
    auto phi_wrapper = new WrapperVector<float>("nLepGood", "LepGood_phi");
    auto m_wrapper   = new WrapperVector<float>("nLepGood", "LepGood_mass");
    /* auto dxy_wrapper   = new WrapperVector<float>("nLepGood", "LepGood_dxy"); */

    auto& get_energy = GenFunction::register_function<float(float,float,float,float)>("get_energy", FUNC(([](float pt, float eta, float phi, float m){
        TLorentzVector t;
        t.SetPtEtaPhiM(pt, eta, phi, m);
        return t.E();
    })));

    auto lepton_energy = new ZipMapFour<float, float>(get_energy, pt_wrapper, eta_wrapper, phi_wrapper, m_wrapper);
    GenValue::alias("lepton_energy", lepton_energy);

    GenValue::alias("avg_lepton_energy", new Reduce<float>(mean , "lepton_energy"));
    GenValue::alias("max_lepton_energy", new Max<float>("lepton_energy"));


    new Filter("nLepGood>=3", [nLepGood=lookup("nLepGood")](){
            return dynamic_cast<Value<int>*>(nLepGood)->get_value() >=3;});

    new Filter("nLepGood<=4", [nLepGood=lookup("nLepGood")](){
            return dynamic_cast<Value<int>*>(nLepGood)->get_value() <=4;});
    new RangeFilter<int>("3<=nLepGood<5", dynamic_cast<Value<int>*>(lookup("nLepGood")), 3, 5);
}

void declare_containers(MiniTreeDataSet& mt){
    mt.register_container(new ContainerTH1I("nLepGood", "Lepton Multiplicity", lookup("nLepGood"), 10, 0, 10));

    mt.register_container(new ContainerTH1I("nLepGood2", "Lepton Multiplicity", lookup("nLepGood"), 10, 0, 10));
    mt.get_container("nLepGood2")->add_filter(lookup_filter("3<=nLepGood<5"));

    mt.register_container(new ContainerTH1I("nLepGood3", "Lepton Multiplicity", lookup("nLepGood"), 10, 0, 10));
    mt.get_container("nLepGood3")->add_filter(!(*lookup_filter("3<=nLepGood<5")));

    /* mt.register_container(new ContainerTGraph("nLepvsnJet", new Pair<int, int>("nLepGood", "nJet") )); */

    mt.register_container(new ContainerTH1F("avg_lepton_energy", "Average Lepton Energy", lookup("avg_lepton_energy"), 50, 0, 500));
    mt.register_container(new ContainerTH1F("max_lepton_energy", "Maximum Lepton Energy", lookup("max_lepton_energy"), 50, 0, 500));

}

void run_analysis(const std::string& filename){
    TFile *f = TFile::Open(filename.c_str());
    TTree *tree = (TTree*) f->Get("tree");
    MiniTreeDataSet mt(tree);
    enable_branches(mt);
    declare_values(mt);
    declare_containers(mt);
    mt.process();
    mt.save_all();
    /* save_containers(mt); */
}

int main(int argc, char * argv[])
{
    Log::init_logger("log.txt", LogPriority::kLogDebug);
    ArgParser args(argc, argv);
    if(args.cmdOptionExists("-f")) {
        run_analysis(args.getCmdOption("-f"));
    }
    else {
        cout << "Usage: ./main -f input_minitree.root" << endl;
    }
    return 0;
}
