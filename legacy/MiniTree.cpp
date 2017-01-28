#ifndef minitree_cxx
#define minitree_cxx

#include <algorithm>
#include <functional>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

#include <TStyle.h>
#include <TLorentzVector.h>

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
    printf("Finished filling histograms for file %s with %d events.\n",
            filename, hc->get_event_count());
    return hc;
}

/* HistCollection* load_histograms(const char* sample_name){ */
/*     string filename = string(sample_name) + "_histcollection.root"; */
/*     TFile *f = TFile::Open(filename.c_str()); */
/*     HistCollection *hc = new HistCollection(sample_name); */
/*     TFile *f = TFile::Open(filename); */
/*     TTree *tree = (TTree*) f->Get("tree"); */
/*     MiniTree minitree(tree); */
/*     minitree.Loop(hc); */
/*     delete tree; */
/*     f->Close(); */
/*     delete f; */
/*     printf("Finished filling histograms for file %s with %d events.\n", */
/*             filename, hc->get_event_count()); */
/*     return hc; */
/* } */

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
    on("Jet_eta");
    on("Jet_phi");
    on("nGenTop");
    on("ngenLep");
    on("genLep_sourceId");
    on("genLep_pt");
}

double delta_r2(double eta1, double phi1, double eta2, double phi2){
    return pow(eta1 - eta2, 2) + pow(phi1 - phi2, 2);
}

double isolation(int i, int n, function<double(int, int)> delta_r2_calculator){
    double min_iso = -1;
    for (int j=0; j<n; j++){
        if (i == j) continue;
        double curr_iso = delta_r2_calculator(i, j);
        if ((curr_iso < min_iso && curr_iso >= 0) || min_iso == -1){
            min_iso = curr_iso;
        }
    }
    if (min_iso == -1)
        return min_iso;
    else
        return sqrt(min_iso);
}

TLorentzVector g_vec1;
TLorentzVector g_vec2;
double diobject_mass(double pt1, double eta1, double phi1, double mass1,
                     double pt2, double eta2, double phi2, double mass2){
    g_vec1.SetPtEtaPhiM(pt1, eta1, phi1, mass1);
    g_vec2.SetPtEtaPhiM(pt2, eta2, phi2, mass2);
    g_vec1 += g_vec2;
    return g_vec1.M();
}

void MiniTree::Loop(HistCollection* hc){

    /* Define first a few little subroutines that will be used later in the
     * main loop.
     */
    // Functions to calculate the \delta R^2 between two objects
    auto lepton_lepton_delta_r2 = [this](int i, int j){
        return delta_r2(this->LepGood_eta[i], this->LepGood_phi[i],
                        this->LepGood_eta[j], this->LepGood_phi[j]);
    };
    auto lepton_jet_delta_r2 = [this](int i, int j){
        return delta_r2(this->LepGood_eta[i], this->LepGood_phi[i],
                        this->Jet_eta[j], this->Jet_phi[j]);
    };
    auto jet_jet_delta_r2 = [this](int i, int j){
        return delta_r2(this->Jet_eta[i], this->Jet_phi[i],
                        this->Jet_eta[j], this->Jet_phi[j]);
    };

    // Funtions to calculate isolation of objects
    auto lepton_lepton_isolation = [this, lepton_lepton_delta_r2](int i){
        if (i >= this->nLepGood) return -1.0;
        return isolation(i, this->nLepGood, function<double(int, int)>(lepton_lepton_delta_r2));
    };
    auto lepton_jet_isolation = [this, lepton_jet_delta_r2](int i){
        if (i >= this->nLepGood) return -1.0;
        return isolation(i, this->nJet, function<double(int, int)>(lepton_jet_delta_r2));
    };
    auto mini_isolation_cut = [this, lepton_jet_isolation](int i){
        /* Implement the mini-isolation cut which utilizes a dynamic isolation cone size
         * based on lepton pt
         */
        double r0 = 0.5;
        double pt0 = 7.5; // GeV

        double iso_cut = min(r0, pt0/this->LepGood_pt[i]);
        double isolation = lepton_jet_isolation(i);
        return isolation > iso_cut;
    };
    auto jet_jet_isolation = [this, jet_jet_delta_r2](int i){
        if (i >= this->nJet) return -1.0;
        return isolation(i, this->nJet, function<double(int, int)>(jet_jet_delta_r2));
    };
    auto dijet_mass = [this](int i, int j){
        if (i >= this->nJet || j >= this->nJet) return -1.0;
        return diobject_mass(this->Jet_pt[i], this->Jet_eta[i],
                             this->Jet_phi[i], this->Jet_mass[i],
                             this->Jet_pt[j], this->Jet_eta[j],
                             this->Jet_phi[j], this->Jet_mass[j]);
    };
    auto dilepton_mass = [this](int i, int j){
        if (i >= this->nLepGood || j >= this->nLepGood) return -1.0;
        return diobject_mass(this->LepGood_pt[i], this->LepGood_eta[i],
                             this->LepGood_phi[i], this->LepGood_mass[i],
                             this->LepGood_pt[j], this->LepGood_eta[j],
                             this->LepGood_phi[j], this->LepGood_mass[j]);
    };
    auto dijet_mass_set = [this, dijet_mass](){
        auto *mass_set = new vector<double>();
        for(int i=0; i<(this->nJet-1); i++){
            for(int j=i+1; j<this->nJet; j++){
                mass_set->push_back(dijet_mass(i, j));
            }
        }
        return mass_set;
    };

    auto nBJets = [this](float mva_cut = 0){
        int n = 0;
        for(int i=0; i<this->nJet; ++i)
            if(this->Jet_btagCMVA[i] > mva_cut) ++n;
        return n;
    };

    auto lepton_mass_window_pass = [this, dilepton_mass](double low, double high){
        for (int i=0; i<this->nLepGood, ++i){
            for (int j=0; j<this->nLepGood, ++j){
                double mass = dilepton_mass(i, j);
                if (low < mass && mass < high){
                    return false;
                }
            }
        }
        return true;
    }
    auto ss_dilepton_base_selection[this, nBJets, lepton_mass_window_pass](){
        if (this->nLepGood != 2) return false;
        if (this->LepGood_charge[0] != this->LepGood_charge[1]) return false;
        if (this->nJet < 4) return false;
        if (nBJets() < 3) return false;
        if (!lepton_mass_window_pass(70, 105)) return false;
        return true;
    }

    auto trilepton_base_selection[this](){
        if (nLepGood != 3) return false;
        if (nJet < 4) return false;
        if (nBJets() < 3) return false;
        if (!lepton_mass_window_pass(70, 105)) return false;
        return true;
    }

    if (fChain == 0) return;
    /* Set branch statuses so only used branches are loaded. This
     * can greatly reduce execution time.
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
        ++(*hc); // Increments event count
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
        if (lepton_count_pass_miniiso == nLepGood){
            hc->lepton_count_pass_miniiso_event->Fill(nLepGood);
        }

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
            vector<double> isos = {lepton_jet_isolation(0),
                                   lepton_jet_isolation(1),
                                   lepton_jet_isolation(2)};
            sort(isos.begin(), isos.end()); //Sorts ascending by default
            hc->trilepton_iso_1->Fill(isos[2]);
            hc->trilepton_iso_2->Fill(isos[1]);
            hc->trilepton_iso_3->Fill(isos[0]);
            vector<double> jet_isos = {jet_jet_isolation(0),
                                       jet_jet_isolation(1),
                                       jet_jet_isolation(2)};
            sort(jet_isos.begin(), jet_isos.end());
            hc->trilepton_jet_iso_1->Fill(jet_isos[2]);
            hc->trilepton_jet_iso_2->Fill(jet_isos[1]);
            hc->trilepton_jet_iso_3->Fill(jet_isos[0]);
        }

        vector<double> *mass_set = dijet_mass_set();
        for( double &mass : *mass_set ){
            hc->dijet_mass->Fill(mass);
        }
    }
    hc->lepton_count_pass_miniiso_ratio->Divide(hc->lepton_count_pass_miniiso_event,
                                                hc->lepton_count);
}
#endif // tree_cxx
