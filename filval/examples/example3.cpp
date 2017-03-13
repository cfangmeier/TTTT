#include <iostream>
#include <vector>
#include <utility>

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"

#include "filval/filval.hpp"

#include "MiniTreeDataSet.hpp"

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
