#ifndef minitree_cxx
#define minitree_cxx

#include <algorithm>
#include <functional>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

#include <TStyle.h>

#include "MiniTree.h"
#include "HistCollection.h"
using namespace std;


HistCollection* build_histograms(const char* sample_name, const char* filename){
    HistCollection *hc = new HistCollection(sample_name);
    TFile *f = TFile::Open(filename);
    TTree *tree = (TTree*) f->Get("tree");
    MiniTree minitree(tree);
    minitree.Loop(hc);
    delete tree;
    f->Close();
    delete f;
    printf("Finished filling histograms for file %s\n", filename);
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

double delta_r2(double eta1, double eta2, double phi1, double phi2){
    return pow(eta1 - eta2, 2) + pow(phi1 - phi2, 2);
}

double isolation(int n, int i, function<double(int, int)> delta_r2_calculator){
    double min_iso = -1;
    for (int j=0; j<n; j++){
        if (i == j) continue;
        double curr_iso = delta_r2_calculator(i, j);
        if (curr_iso < min_iso || min_iso == -1){
            min_iso = curr_iso;
        }
    }
    if (min_iso == -1)
        return min_iso;
    else
        return sqrt(min_iso);
}

void MiniTree::Loop(HistCollection* hc){

    /* Define first a few little subroutines that will be used later in the
     * main loop.
     */
    auto lepton_delta_r2 = [this](int i, int j){
        return delta_r2(this->LepGood_eta[i], this->LepGood_eta[j],
                        this->LepGood_phi[i], this->LepGood_phi[j]);
    };
    auto lepton_isolation = [this, lepton_delta_r2](int i){
        return isolation(this->nLepGood, i, function<double(int, int)>(lepton_delta_r2));
    };
    auto mini_isolation_cut = [this, lepton_isolation](int i){
        /* Implement the mini-isolation cut which utilizes a dynamic isolation cone size
         * based on lepton pt
         */
        double r0 = 0.5;
        double pt0 = 7.5; // GeV

        double iso_cut = min(r0, pt0/this->LepGood_pt[i]);
        double isolation = lepton_isolation(i);
        return isolation > iso_cut;
    };

    if (fChain == 0) return;
    /* Main analysis code begins here
     *
     */
    set_branch_statuses(this);

    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;

        /* Main analysis code begins here
         *
         */
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

        if (nLepGood == 3){
            vector<double> isos = {lepton_isolation(0),
                                   lepton_isolation(1),
                                   lepton_isolation(2)};
            sort(isos.begin(), isos.end()); //Sorts ascending by default
            hc->trilepton_iso_1->Fill(isos[2]);
            hc->trilepton_iso_2->Fill(isos[1]);
            hc->trilepton_iso_3->Fill(isos[0]);
        }
    }
}
#endif // tree_cxx
