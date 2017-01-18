#ifndef minitree_cxx
#define minitree_cxx
#include <cstdio>
#include <string>
#include <map>

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "MiniTree.h"
#include "HistCollection.h"


HistCollection* build_histograms(const char* filename){
    HistCollection *hc = new HistCollection(filename);
    TFile *f = TFile::Open(filename);
    TTree *tree = (TTree*) f->Get("tree");
    MiniTree minitree(tree);
    minitree.Loop(hc);
    delete tree;
    f->Close();
    delete f;
    std::printf("Finished filling histograms for file %s\n", filename);
    return hc;
}


void MiniTree::Loop(HistCollection* hc){
    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        hc->lepton_count->Fill(nLepGood);
        for(int i=0; i<nLepGood; i++){
            double delta_pt_val = LepGood_pt[i] - LepGood_mcPt[i];
            hc->delta_pt->Fill(delta_pt_val);
            hc->lepton_count_vs_delta_pt->Fill(nLepGood, delta_pt_val);
        }
    }
}
#endif // tree_cxx