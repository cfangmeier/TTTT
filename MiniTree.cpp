#ifndef minitree_cxx
#define minitree_cxx

#include <cstdio>
#include <string>
#include <map>

#include <TStyle.h>

#include "MiniTree.h"
#include "HistCollection.h"


HistCollection* build_histograms(const char* sample_name, const char* filename){
    HistCollection *hc = new HistCollection(sample_name);
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

void set_branch_statuses(MiniTree *minitree){
    auto on = [minitree](const char* bname){
        minitree->fChain->SetBranchStatus(bname, true);
    };
    auto off = [minitree](const char* bname){
        minitree->fChain->SetBranchStatus(bname, false);
    };
    off("*");
    on("nLepGood");
    on("LepGood_pt");
    on("LepGood_eta");
    on("LepGood_phi");
    on("LepGood_mcPt");
    on("LepGood_charge");
    on("nJet");
    on("Jet_btagCMVA");
    on("Jet_pt");
    on("nGenTop");
}

void MiniTree::Loop(HistCollection* hc){
    
    // Implement the mini-isolation cut which utilizes a dynamic isolation cone size
    // based on lepton pt
    auto mini_isolation_cut = [this](int idx){
        double r0 = 0.5;
        double pt0 = 7.5; // GeV
        double r_cut2 = pow(min(r0, pt0/this->LepGood_pt[idx]), 2); 
        for (int j = 0; j < this->nLepGood; j++){
            if (j == idx) continue;
            double delta_r2 = pow(this->LepGood_eta[idx] - this->LepGood_eta[j], 2) + 
                              pow(this->LepGood_phi[idx] - this->LepGood_phi[j], 2);
            if (delta_r2 < r_cut2) return false;
        }
        return true;
    };
    
    if (fChain == 0) return;
    set_branch_statuses(this);

    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        
        // BEGIN ANALYSIS CODE
        hc->lepton_count->Fill(nLepGood);
        hc->top_quark_count->Fill(nGenTop);
        for(int i=0; i<nLepGood; i++){
            double delta_pt_val = LepGood_pt[i] - LepGood_mcPt[i];
            hc->delta_pt->Fill(delta_pt_val);
            hc->lepton_count_vs_delta_pt->Fill(nLepGood, delta_pt_val);
        }
        hc->jet_count->Fill(nJet);
        int b_jet_count = 0;
        for(int i=0; i<nJet; i++){
            hc->b_jet_discriminator->Fill(Jet_btagCMVA[i]);
            b_jet_count += (Jet_btagCMVA[i] > 0);
        }
        hc->b_jet_count->Fill(b_jet_count);
        
        for(int i=0; i<nJet; i++){
            hc->b_jet_pt_all->Fill(Jet_pt[i]);
            if (b_jet_count >= 3){
                hc->b_jet_pt_3_or_more->Fill(Jet_pt[i]);
            }
        }
        int lepton_count_pass_miniiso= 0;
        for(int i=0; i<nLepGood; i++){
            lepton_count_pass_miniiso += mini_isolation_cut(i);
        }
        hc->lepton_count_pass_miniiso->Fill(lepton_count_pass_miniiso);
        
        if (nLepGood == 3){
            hc->jet_count_trilepton->Fill(nJet);
        }
        if (nLepGood == 2 && (LepGood_charge[0] * LepGood_charge[1]) == 1){
            hc->jet_count_ss_dilepton->Fill(nJet);
        }
        if (nLepGood == 2 && (LepGood_charge[0] * LepGood_charge[1]) == -1){
            hc->jet_count_os_dilepton->Fill(nJet);
        }
    }
}
#endif // tree_cxx