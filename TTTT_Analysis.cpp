#include <iostream>
#include <vector>
#include <utility>

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"

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

    ObservedValue<double> x_val(&x);
    ObservedValue<double> y_val(&y);

    Pair<double, double> dp(&x_val, &y_val);
    print_pair(dp);
    x = 2;
    y = 2;
    print_pair(dp);

    ContainerVector<double> cont(&x_val, "cont");
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
    ObservedValue<double> x_val(&x);
    ContainerTH1D hist("h1", "Hist", 20, 0, 20, &x_val);
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

int main(int argc, const char* argv[]){
    test3();
}
