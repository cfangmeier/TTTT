#include <iostream>
#include <vector>
#include <utility>

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"
#include "log.hpp"

#include "MiniTreeDataSet.hpp"

using namespace std;
using namespace filval;
using namespace filval::root;

void print_pair(Pair<double, double> dp){
    pair<double, double> p = dp.get_value();
    cout << "(" << p.first << ", " << p.second << ")\n";
}

void test1(){
    double x = 12;
    double y = 12;

    ObservedValue<double> x_val("x", &x);
    ObservedValue<double> y_val("y", &y);

    Pair<double, double> dp(&x_val, &y_val);
    print_pair(dp);
    x = 2;
    y = 2;
    print_pair(dp);

    ContainerVector<double> cont("cont", &x_val);
    x = 12;
    cont.fill();
    x = 2;
    cont.fill();
    auto *container = cont.get_container();

    for( auto v: *container )
        cout << v << ", ";
    cout << endl;
}

void test2(){
    double x = 12;
    ObservedValue<double> x_val("x", &x);
    ContainerTH1D hist("h1", "Hist", &x_val, 20, 0, 20);
    hist.fill();
    hist.fill();
    hist.fill();
    x = 11;
    hist.fill();
    hist.fill();
    hist.fill();
    hist.fill();
    hist.fill();
    hist.fill();

    TH1D* h = (TH1D*) hist.get_container();
    TCanvas can("c1");
    h->Draw();
    can.Draw();
    can.SaveAs("outfile.png");
}

void test3(){
    TFile *f = TFile::Open("./data/TTTT_ext_treeProducerSusyMultilepton_tree.root");
    TTree *tree = (TTree*) f->Get("tree");
    MiniTreeDataSet mtds(tree);
    mtds.process();
    TCanvas can("c1");
    can.Clear();
    TH1* hist = ((ContainerTH1I*)mtds.get_container("nLepGood"))->get_container();
    hist->Draw();
    can.Draw();
    can.SaveAs("outfile.png");

    can.Clear();
    hist = ((ContainerTH1I*)mtds.get_container("nLepGood2"))->get_container();
    hist->Draw();
    can.Draw();
    can.SaveAs("outfile2.png");

    can.Clear();
    hist = ((ContainerTH1I*)mtds.get_container("nLepGood3"))->get_container();
    hist->Draw();
    can.Draw();
    can.SaveAs("outfile3.png");

    can.Clear();
    hist = ((ContainerTH1I*)mtds.get_container("avg_lepton_energy"))->get_container();
    hist->Draw();
    can.Draw();
    can.SaveAs("lepton_energy.png");

    can.Clear();
    TGraph* graph= ((ContainerTGraph*)mtds.get_container("nLepvsnJet"))->get_container();
    graph->Draw("A*");
    can.Draw();
    can.SaveAs("outfileGraph.png");

    delete tree;
    f->Close();
    delete f;
}
GenValue* lookup(const string& name){
    return GenValue::get_value(name);
}
Filter* lookup_filter(const string& name){
    return dynamic_cast<Filter*>(GenValue::get_value(name));
}

void enable_branches(MiniTreeDataSet* mt){
    mt->fChain->SetBranchStatus("*", false);
    mt->track_branch<int>("nJet");
    mt->track_branch<int>("nLepGood");
    mt->track_branch_ptr<float>("LepGood_pt");
    mt->track_branch_ptr<float>("LepGood_eta");
    mt->track_branch_ptr<float>("LepGood_phi");
    mt->track_branch_ptr<float>("LepGood_mass");
}

void declare_values(MiniTreeDataSet* mt){
    auto mean = Function<float(vector<float>)>("mean", [](vector<float> v){
            int n = 0;
            float sum = 0;
            for (float e : v){
                n++;
                sum += e;
            }
            return n>0 ? sum / n : 0;
            });

    auto pt_wrapper  = new WrapperVector<float>("nLepGood", "LepGood_pt");
    auto eta_wrapper = new WrapperVector<float>("nLepGood", "LepGood_eta");
    auto phi_wrapper = new WrapperVector<float>("nLepGood", "LepGood_phi");
    auto m_wrapper   = new WrapperVector<float>("nLepGood", "LepGood_mass");

    auto get_energy = Function<float(float,float,float,float)>("get_energy", [](float pt, float eta, float phi, float m){
        TLorentzVector t;
        t.SetPtEtaPhiM(pt, eta, phi, m);
        return t.E();
    });
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

void declare_containers(MiniTreeDataSet* mt){
    mt->add_container(new ContainerTH1I("nLepGood", "Lepton Multiplicity", lookup("nLepGood"), 10, 0, 10));

    mt->add_container(new ContainerTH1I("nLepGood2", "Lepton Multiplicity", lookup("nLepGood"), 10, 0, 10));
    mt->get_container("nLepGood2")->add_filter(lookup_filter("3<=nLepGood<5"));

    mt->add_container(new ContainerTH1I("nLepGood3", "Lepton Multiplicity", lookup("nLepGood"), 10, 0, 10));
    mt->get_container("nLepGood3")->add_filter(!(*lookup_filter("3<=nLepGood<5")));

    mt->add_container(new ContainerTGraph("nLepvsnJet", new Pair<int, int>("nLepGood", "nJet") ));

    mt->add_container(new ContainerTH1F("avg_lepton_energy", "Average Lepton Energy", lookup("avg_lepton_energy"), 50, 0, 500));
    mt->add_container(new ContainerTH1F("max_lepton_energy", "Maximum Lepton Energy", lookup("max_lepton_energy"), 50, 0, 500));

}

void run_analysis(){
    TFile *f = TFile::Open("./data/TTTT_ext_treeProducerSusyMultilepton_tree.root");
    TTree *tree = (TTree*) f->Get("tree");
    MiniTreeDataSet mt(tree);
    enable_branches(&mt);
    declare_values(&mt);
    declare_containers(&mt);
    mt.process();
}


int main(int argc, const char* argv[]){
    clog.rdbuf(new Log("mylog.txt"));
    /* run_analysis(); */
    clog << "hello log again" << endl;
}
