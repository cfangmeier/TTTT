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
 */
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 11 13:01:29 2017 by ROOT version 6.08/00
// from TTree tree/treeProducerSusyMultilepton
// found on file: TTTT_ext_treeProducerSusyMultilepton_tree.root
//////////////////////////////////////////////////////////

#ifndef minitree_h
#define minitree_h

#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MiniTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       evt;
   Int_t           isData;
   Float_t         xsec;
   Float_t         puWeight;
   Float_t         nTrueInt;
   Float_t         genWeight;
   Float_t         rho;
   Float_t         rhoCN;
   Int_t           nVert;
   Int_t           nJet25;
   Int_t           nJet25a;
   Int_t           nBJetLoose25;
   Int_t           nBJetMedium25;
   Int_t           nBJetTight25;
   Int_t           nJet30;
   Int_t           nJet30a;
   Int_t           nBJetLoose30;
   Int_t           nBJetMedium30;
   Int_t           nBJetTight30;
   Int_t           nJet40;
   Int_t           nJet40a;
   Int_t           nBJetLoose40;
   Int_t           nBJetMedium40;
   Int_t           nBJetTight40;
   Int_t           nLepGood20;
   Int_t           nLepGood15;
   Int_t           nLepGood10;
   Int_t           GenSusyMScan1;
   Int_t           GenSusyMScan2;
   Int_t           GenSusyMScan3;
   Int_t           GenSusyMScan4;
   Int_t           GenSusyMGluino;
   Int_t           GenSusyMGravitino;
   Int_t           GenSusyMStop;
   Int_t           GenSusyMSbottom;
   Int_t           GenSusyMStop2;
   Int_t           GenSusyMSbottom2;
   Int_t           GenSusyMSquark;
   Int_t           GenSusyMNeutralino;
   Int_t           GenSusyMNeutralino2;
   Int_t           GenSusyMNeutralino3;
   Int_t           GenSusyMNeutralino4;
   Int_t           GenSusyMChargino;
   Int_t           GenSusyMChargino2;
   Float_t         lheHT;
   Float_t         lheHTIncoming;
   Float_t         htJet25;
   Float_t         mhtJet25;
   Float_t         htJet40j;
   Float_t         htJet40ja;
   Float_t         htJet40;
   Float_t         htJet40a;
   Float_t         mhtJet40;
   Float_t         mhtJet40a;
   Int_t           nJet25NoTau;
   Int_t           nBJetLoose25NoTau;
   Int_t           nBJetMedium25NoTau;
   Int_t           nBJetCMVALoose25;
   Int_t           nBJetCMVAMedium25;
   Int_t           nBJetCMVATight25;
   Int_t           nSoftBLoose25;
   Int_t           nSoftBMedium25;
   Int_t           nSoftBTight25;
   Int_t           nJet30NoTau;
   Int_t           nBJetLoose30NoTau;
   Int_t           nBJetMedium30NoTau;
   Int_t           nJet40NoTau;
   Int_t           nBJetLoose40NoTau;
   Int_t           nBJetMedium40NoTau;
   Int_t           nBJetCMVALoose40;
   Int_t           nBJetCMVAMedium40;
   Int_t           nBJetCMVATight40;
   Float_t         mZ1;
   Float_t         mZ1SFSS;
   Float_t         minMllSFOS;
   Float_t         maxMllSFOS;
   Float_t         minMllAFOS;
   Float_t         maxMllAFOS;
   Float_t         minMllAFSS;
   Float_t         maxMllAFSS;
   Float_t         minMllAFAS;
   Float_t         maxMllAFAS;
   Float_t         m2l;
   Float_t         minDrllAFSS;
   Float_t         maxDrllAFSS;
   Float_t         minDrllAFOS;
   Float_t         maxDrllAFOS;
   Float_t         mZ2;
   Float_t         m3l;
   Float_t         m4l;
   Float_t         pt2l;
   Float_t         pt3l;
   Float_t         pt4l;
   Float_t         ht3l;
   Float_t         ht4l;
   Int_t           q3l;
   Int_t           q4l;
   Int_t           minMWjj;
   Int_t           minMWjjPt;
   Int_t           bestMWjj;
   Int_t           bestMWjjPt;
   Int_t           bestMTopHad;
   Int_t           bestMTopHadPt;
   Int_t           GenHiggsDecayMode;
   Float_t         absIP3DAval;
   Float_t         absIP3DAerr;
   Float_t         absIP3DBval;
   Float_t         absIP3DBerr;
   Float_t         absIP3DCval;
   Float_t         absIP3DCerr;
   Float_t         absIP3DDval;
   Float_t         absIP3DDerr;
   Float_t         absIP3DApvBCval;
   Float_t         absIP3DApvBCerr;
   Float_t         absIP3DBpvACval;
   Float_t         absIP3DBpvACerr;
   Float_t         absIP3DCpvABval;
   Float_t         absIP3DCpvABerr;
   Float_t         absIP3DApvBCDval;
   Float_t         absIP3DApvBCDerr;
   Float_t         absIP3DBpvACDval;
   Float_t         absIP3DBpvACDerr;
   Float_t         absIP3DCpvABDval;
   Float_t         absIP3DCpvABDerr;
   Float_t         absIP3DDpvABCval;
   Float_t         absIP3DDpvABCerr;
   Float_t         chi2pvtrksBCbutAval;
   Float_t         chi2pvtrksBCbutAdof;
   Float_t         chi2pvtrksACbutBval;
   Float_t         chi2pvtrksACbutBdof;
   Float_t         chi2pvtrksABbutCval;
   Float_t         chi2pvtrksABbutCdof;
   Float_t         chi2pvtrksBCDbutAval;
   Float_t         chi2pvtrksBCDbutAdof;
   Float_t         chi2pvtrksACDbutBval;
   Float_t         chi2pvtrksACDbutBdof;
   Float_t         chi2pvtrksABDbutCval;
   Float_t         chi2pvtrksABDbutCdof;
   Float_t         chi2pvtrksABCbutDval;
   Float_t         chi2pvtrksABCbutDdof;
   Int_t           nRecJet40;
   Int_t           nRecJet25;
   Int_t           nRecBJetMedium40;
   Int_t           nRecBJetMedium25;
   Int_t           nRecSplitJet40;
   Int_t           nRecSplitJet25;
   Int_t           nRecSplitBJetMedium40;
   Int_t           nRecSplitBJetMedium25;
   Int_t           hbheFilterNew50ns;
   Int_t           hbheFilterNew25ns;
   Int_t           hbheFilterIso;
   Float_t         Flag_badChargedHadronFilter;
   Float_t         Flag_badMuonFilter;
   Float_t         met_trkPt;
   Float_t         met_trkPhi;
   Int_t           HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v;
   Int_t           HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale;
   Int_t           HLT_DoubleElHT;
   Int_t           HLT_DoubleElHT_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v;
   Int_t           HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_Prescale;
   Int_t           HLT_TripleEl;
   Int_t           HLT_TripleEl_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v;
   Int_t           HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale;
   Int_t           HLT_MuEGHT;
   Int_t           HLT_MuEGHT_isUnprescaled;
   Int_t           HLT_BIT_HLT_IsoMu20_v;
   Int_t           HLT_BIT_HLT_IsoMu20_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_IsoMu20_v_Prescale;
   Int_t           HLT_BIT_HLT_IsoTkMu20_v;
   Int_t           HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_IsoTkMu20_v_Prescale;
   Int_t           HLT_BIT_HLT_IsoMu22_v;
   Int_t           HLT_BIT_HLT_IsoMu22_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_IsoMu22_v_Prescale;
   Int_t           HLT_BIT_HLT_IsoTkMu22_v;
   Int_t           HLT_BIT_HLT_IsoTkMu22_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_IsoTkMu22_v_Prescale;
   Int_t           HLT_SingleMu;
   Int_t           HLT_SingleMu_isUnprescaled;
   Int_t           HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v;
   Int_t           HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_Prescale;
   Int_t           HLT_DoubleMuEl;
   Int_t           HLT_DoubleMuEl_isUnprescaled;
   Int_t           HLT_BIT_HLT_TripleMu_12_10_5_v;
   Int_t           HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_TripleMu_12_10_5_v_Prescale;
   Int_t           HLT_BIT_HLT_TripleMu_5_3_3_v;
   Int_t           HLT_BIT_HLT_TripleMu_5_3_3_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_TripleMu_5_3_3_v_Prescale;
   Int_t           HLT_TripleMu;
   Int_t           HLT_TripleMu_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v;
   Int_t           HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_Prescale;
   Int_t           HLT_DoubleElMu;
   Int_t           HLT_DoubleElMu_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu30_TkMu11_v;
   Int_t           HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu30_TkMu11_v_Prescale;
   Int_t           HLT_DoubleMuNoIso;
   Int_t           HLT_DoubleMuNoIso_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_Mu8_SameSign_v;
   Int_t           HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_Mu8_SameSign_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v;
   Int_t           HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu20_Mu10_SameSign_v;
   Int_t           HLT_BIT_HLT_Mu20_Mu10_SameSign_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu20_Mu10_SameSign_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v;
   Int_t           HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_Prescale;
   Int_t           HLT_DoubleMuSS;
   Int_t           HLT_DoubleMuSS_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele25_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele25_WPTight_Gsf_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele25_WPTight_Gsf_v_Prescale;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_Prescale;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_Prescale;
   Int_t           HLT_BIT_HLT_Ele27_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_WPTight_Gsf_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele27_WPTight_Gsf_v_Prescale;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_Prescale;
   Int_t           HLT_BIT_HLT_Ele45_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_Prescale;
   Int_t           HLT_SingleEl;
   Int_t           HLT_SingleEl_isUnprescaled;
   Int_t           HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v;
   Int_t           HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_Prescale;
   Int_t           HLT_TripleMuA;
   Int_t           HLT_TripleMuA_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_Prescale;
   Int_t           HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_Prescale;
   Int_t           HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_Prescale;
   Int_t           HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_Prescale;
   Int_t           HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_Prescale;
   Int_t           HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_Prescale;
   Int_t           HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_Prescale;
   Int_t           HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_Prescale;
   Int_t           HLT_SOSHighMET;
   Int_t           HLT_SOSHighMET_isUnprescaled;
   Int_t           HLT_BIT_HLT_DoubleMu3_PFMET50_v;
   Int_t           HLT_BIT_HLT_DoubleMu3_PFMET50_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_DoubleMu3_PFMET50_v_Prescale;
   Int_t           HLT_SOSDoubleMuLowMET;
   Int_t           HLT_SOSDoubleMuLowMET_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_Prescale;
   Int_t           HLT_MuEG;
   Int_t           HLT_MuEG_isUnprescaled;
   Int_t           HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v;
   Int_t           HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_Prescale;
   Int_t           HLT_DoubleMuHT;
   Int_t           HLT_DoubleMuHT_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Int_t           HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale;
   Int_t           HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Int_t           HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale;
   Int_t           HLT_DoubleEl;
   Int_t           HLT_DoubleEl_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_Prescale;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_Prescale;
   Int_t           HLT_DoubleMu;
   Int_t           HLT_DoubleMu_isUnprescaled;
   Int_t           Flag_hcalLaserEventFilter;
   Int_t           Flag_trkPOG_logErrorTooManyClusters;
   Int_t           Flag_EcalDeadCellTriggerPrimitiveFilter;
   Int_t           Flag_trkPOGFilters;
   Int_t           Flag_trackingFailureFilter;
   Int_t           Flag_CSCTightHaloFilter;
   Int_t           Flag_HBHENoiseFilter;
   Int_t           Flag_HBHENoiseIsoFilter;
   Int_t           Flag_goodVertices;
   Int_t           Flag_trkPOG_manystripclus53X;
   Int_t           Flag_METFilters;
   Int_t           Flag_ecalLaserCorrFilter;
   Int_t           Flag_trkPOG_toomanystripclus53X;
   Int_t           Flag_CSCTightHalo2015Filter;
   Int_t           Flag_eeBadScFilter;
   Int_t           Flag_globalTightHalo2016Filter;
   Float_t         met_pt;
   Float_t         met_eta;
   Float_t         met_phi;
   Float_t         met_mass;
   Float_t         met_sumEt;
   Float_t         met_rawPt;
   Float_t         met_rawPhi;
   Float_t         met_rawSumEt;
   Float_t         met_genPt;
   Float_t         met_genPhi;
   Float_t         met_genEta;
   Float_t         met_jecUp_pt;
   Float_t         met_jecUp_eta;
   Float_t         met_jecUp_phi;
   Float_t         met_jecUp_mass;
   Float_t         met_jecUp_sumEt;
   Float_t         met_jecUp_rawPt;
   Float_t         met_jecUp_rawPhi;
   Float_t         met_jecUp_rawSumEt;
   Float_t         met_jecUp_genPt;
   Float_t         met_jecUp_genPhi;
   Float_t         met_jecUp_genEta;
   Float_t         met_jecDown_pt;
   Float_t         met_jecDown_eta;
   Float_t         met_jecDown_phi;
   Float_t         met_jecDown_mass;
   Float_t         met_jecDown_sumEt;
   Float_t         met_jecDown_rawPt;
   Float_t         met_jecDown_rawPhi;
   Float_t         met_jecDown_rawSumEt;
   Float_t         met_jecDown_genPt;
   Float_t         met_jecDown_genPhi;
   Float_t         met_jecDown_genEta;
   Int_t           nFatJet;
   Int_t           FatJet_id[7];   //[nFatJet]
   Int_t           FatJet_puId[7];   //[nFatJet]
   Float_t         FatJet_btagCSV[7];   //[nFatJet]
   Float_t         FatJet_btagCMVA[7];   //[nFatJet]
   Float_t         FatJet_rawPt[7];   //[nFatJet]
   Float_t         FatJet_mcPt[7];   //[nFatJet]
   Int_t           FatJet_mcFlavour[7];   //[nFatJet]
   Int_t           FatJet_partonFlavour[7];   //[nFatJet]
   Int_t           FatJet_hadronFlavour[7];   //[nFatJet]
   Int_t           FatJet_mcMatchId[7];   //[nFatJet]
   Float_t         FatJet_corr_JECUp[7];   //[nFatJet]
   Float_t         FatJet_corr_JECDown[7];   //[nFatJet]
   Float_t         FatJet_corr[7];   //[nFatJet]
   Float_t         FatJet_corr_JERUp[7];   //[nFatJet]
   Float_t         FatJet_corr_JERDown[7];   //[nFatJet]
   Float_t         FatJet_corr_JER[7];   //[nFatJet]
   Float_t         FatJet_pt[7];   //[nFatJet]
   Float_t         FatJet_eta[7];   //[nFatJet]
   Float_t         FatJet_phi[7];   //[nFatJet]
   Float_t         FatJet_mass[7];   //[nFatJet]
   Float_t         FatJet_prunedMass[7];   //[nFatJet]
   Float_t         FatJet_softDropMass[7];   //[nFatJet]
   Float_t         FatJet_tau1[7];   //[nFatJet]
   Float_t         FatJet_tau2[7];   //[nFatJet]
   Float_t         FatJet_tau3[7];   //[nFatJet]
   Float_t         FatJet_topMass[7];   //[nFatJet]
   Float_t         FatJet_minMass[7];   //[nFatJet]
   Float_t         FatJet_nSubJets[7];   //[nFatJet]
   Int_t           nDiscLep;
   Int_t           DiscLep_charge[1];   //[nDiscLep]
   Int_t           DiscLep_tightId[1];   //[nDiscLep]
   Int_t           DiscLep_eleCutIdCSA14_25ns_v1[1];   //[nDiscLep]
   Int_t           DiscLep_eleCutIdCSA14_50ns_v1[1];   //[nDiscLep]
   Int_t           DiscLep_eleCutIdSpring15_25ns_v1[1];   //[nDiscLep]
   Float_t         DiscLep_dxy[1];   //[nDiscLep]
   Float_t         DiscLep_dz[1];   //[nDiscLep]
   Float_t         DiscLep_edxy[1];   //[nDiscLep]
   Float_t         DiscLep_edz[1];   //[nDiscLep]
   Float_t         DiscLep_ip3d[1];   //[nDiscLep]
   Float_t         DiscLep_sip3d[1];   //[nDiscLep]
   Int_t           DiscLep_convVeto[1];   //[nDiscLep]
   Int_t           DiscLep_lostHits[1];   //[nDiscLep]
   Float_t         DiscLep_relIso03[1];   //[nDiscLep]
   Float_t         DiscLep_relIso04[1];   //[nDiscLep]
   Float_t         DiscLep_miniRelIso[1];   //[nDiscLep]
   Float_t         DiscLep_relIsoAn04[1];   //[nDiscLep]
   Int_t           DiscLep_tightCharge[1];   //[nDiscLep]
   Int_t           DiscLep_mcMatchId[1];   //[nDiscLep]
   Int_t           DiscLep_mcMatchAny[1];   //[nDiscLep]
   Int_t           DiscLep_mcMatchTau[1];   //[nDiscLep]
   Float_t         DiscLep_mcPt[1];   //[nDiscLep]
   Int_t           DiscLep_mediumMuonId[1];   //[nDiscLep]
   Int_t           DiscLep_ICHEPsoftMuonId[1];   //[nDiscLep]
   Int_t           DiscLep_ICHEPmediumMuonId[1];   //[nDiscLep]
   Int_t           DiscLep_pdgId[1];   //[nDiscLep]
   Float_t         DiscLep_pt[1];   //[nDiscLep]
   Float_t         DiscLep_eta[1];   //[nDiscLep]
   Float_t         DiscLep_phi[1];   //[nDiscLep]
   Float_t         DiscLep_mass[1];   //[nDiscLep]
   Float_t         DiscLep_mvaIdSpring15[1];   //[nDiscLep]
   Float_t         DiscLep_mvaTTH[1];   //[nDiscLep]
   Float_t         DiscLep_mvaSUSY[1];   //[nDiscLep]
   Float_t         DiscLep_mvaSoftT2tt[1];   //[nDiscLep]
   Float_t         DiscLep_mvaSoftEWK[1];   //[nDiscLep]
   Float_t         DiscLep_jetPtRatiov1[1];   //[nDiscLep]
   Float_t         DiscLep_jetPtRelv1[1];   //[nDiscLep]
   Float_t         DiscLep_jetPtRatiov2[1];   //[nDiscLep]
   Float_t         DiscLep_jetPtRelv2[1];   //[nDiscLep]
   Float_t         DiscLep_jetBTagCSV[1];   //[nDiscLep]
   Float_t         DiscLep_jetBTagCMVA[1];   //[nDiscLep]
   Float_t         DiscLep_jetDR[1];   //[nDiscLep]
   Float_t         DiscLep_r9[1];   //[nDiscLep]
   Float_t         DiscLep_mvaIdSpring16[1];   //[nDiscLep]
   Int_t           nGenPart;
   Int_t           GenPart_motherId[46];   //[nGenPart]
   Int_t           GenPart_grandmotherId[46];   //[nGenPart]
   Int_t           GenPart_sourceId[46];   //[nGenPart]
   Float_t         GenPart_charge[46];   //[nGenPart]
   Int_t           GenPart_status[46];   //[nGenPart]
   Int_t           GenPart_isPromptHard[46];   //[nGenPart]
   Int_t           GenPart_pdgId[46];   //[nGenPart]
   Float_t         GenPart_pt[46];   //[nGenPart]
   Float_t         GenPart_eta[46];   //[nGenPart]
   Float_t         GenPart_phi[46];   //[nGenPart]
   Float_t         GenPart_mass[46];   //[nGenPart]
   Int_t           GenPart_motherIndex[46];   //[nGenPart]
   Int_t           nDiscJet;
   Int_t           DiscJet_mcMatchFlav[5];   //[nDiscJet]
   Float_t         DiscJet_charge[5];   //[nDiscJet]
   Float_t         DiscJet_ctagCsvL[5];   //[nDiscJet]
   Float_t         DiscJet_ctagCsvB[5];   //[nDiscJet]
   Float_t         DiscJet_area[5];   //[nDiscJet]
   Float_t         DiscJet_qgl[5];   //[nDiscJet]
   Float_t         DiscJet_ptd[5];   //[nDiscJet]
   Float_t         DiscJet_axis2[5];   //[nDiscJet]
   Int_t           DiscJet_mult[5];   //[nDiscJet]
   Int_t           DiscJet_partonId[5];   //[nDiscJet]
   Int_t           DiscJet_partonMotherId[5];   //[nDiscJet]
   Float_t         DiscJet_nLeptons[5];   //[nDiscJet]
   Int_t           DiscJet_id[5];   //[nDiscJet]
   Int_t           DiscJet_puId[5];   //[nDiscJet]
   Float_t         DiscJet_btagCSV[5];   //[nDiscJet]
   Float_t         DiscJet_btagCMVA[5];   //[nDiscJet]
   Float_t         DiscJet_rawPt[5];   //[nDiscJet]
   Float_t         DiscJet_mcPt[5];   //[nDiscJet]
   Int_t           DiscJet_mcFlavour[5];   //[nDiscJet]
   Int_t           DiscJet_partonFlavour[5];   //[nDiscJet]
   Int_t           DiscJet_hadronFlavour[5];   //[nDiscJet]
   Int_t           DiscJet_mcMatchId[5];   //[nDiscJet]
   Float_t         DiscJet_corr_JECUp[5];   //[nDiscJet]
   Float_t         DiscJet_corr_JECDown[5];   //[nDiscJet]
   Float_t         DiscJet_corr[5];   //[nDiscJet]
   Float_t         DiscJet_corr_JERUp[5];   //[nDiscJet]
   Float_t         DiscJet_corr_JERDown[5];   //[nDiscJet]
   Float_t         DiscJet_corr_JER[5];   //[nDiscJet]
   Float_t         DiscJet_pt[5];   //[nDiscJet]
   Float_t         DiscJet_eta[5];   //[nDiscJet]
   Float_t         DiscJet_phi[5];   //[nDiscJet]
   Float_t         DiscJet_mass[5];   //[nDiscJet]
   Float_t         DiscJet_CorrFactor_L1[5];   //[nDiscJet]
   Float_t         DiscJet_CorrFactor_L1L2[5];   //[nDiscJet]
   Float_t         DiscJet_CorrFactor_L1L2L3[5];   //[nDiscJet]
   Float_t         DiscJet_CorrFactor_L1L2L3Res[5];   //[nDiscJet]
   Int_t           nSV;
   Float_t         SV_pt[20];   //[nSV]
   Float_t         SV_eta[20];   //[nSV]
   Float_t         SV_phi[20];   //[nSV]
   Float_t         SV_mass[20];   //[nSV]
   Int_t           SV_charge[20];   //[nSV]
   Int_t           SV_ntracks[20];   //[nSV]
   Float_t         SV_chi2[20];   //[nSV]
   Float_t         SV_ndof[20];   //[nSV]
   Float_t         SV_dxy[20];   //[nSV]
   Float_t         SV_edxy[20];   //[nSV]
   Float_t         SV_ip3d[20];   //[nSV]
   Float_t         SV_eip3d[20];   //[nSV]
   Float_t         SV_sip3d[20];   //[nSV]
   Float_t         SV_cosTheta[20];   //[nSV]
   Float_t         SV_mva[20];   //[nSV]
   Float_t         SV_jetPt[20];   //[nSV]
   Float_t         SV_jetEta[20];   //[nSV]
   Float_t         SV_jetDR[20];   //[nSV]
   Float_t         SV_jetBTagCSV[20];   //[nSV]
   Float_t         SV_jetBTagCMVA[20];   //[nSV]
   Int_t           SV_mcMatchNTracks[20];   //[nSV]
   Int_t           SV_mcMatchNTracksHF[20];   //[nSV]
   Float_t         SV_mcMatchFraction[20];   //[nSV]
   Int_t           SV_mcFlavFirst[20];   //[nSV]
   Int_t           SV_mcFlavHeaviest[20];   //[nSV]
   Float_t         SV_maxDxyTracks[20];   //[nSV]
   Float_t         SV_secDxyTracks[20];   //[nSV]
   Float_t         SV_maxD3dTracks[20];   //[nSV]
   Float_t         SV_secD3dTracks[20];   //[nSV]
   Int_t           nTauOther;
   Int_t           TauOther_charge[7];   //[nTauOther]
   Int_t           TauOther_decayMode[7];   //[nTauOther]
   Int_t           TauOther_idDecayMode[7];   //[nTauOther]
   Int_t           TauOther_idDecayModeNewDMs[7];   //[nTauOther]
   Float_t         TauOther_dxy[7];   //[nTauOther]
   Float_t         TauOther_dz[7];   //[nTauOther]
   Int_t           TauOther_idMVA[7];   //[nTauOther]
   Int_t           TauOther_idMVANewDM[7];   //[nTauOther]
   Int_t           TauOther_idCI3hit[7];   //[nTauOther]
   Int_t           TauOther_idAntiMu[7];   //[nTauOther]
   Int_t           TauOther_idAntiE[7];   //[nTauOther]
   Float_t         TauOther_isoCI3hit[7];   //[nTauOther]
   Int_t           TauOther_mcMatchId[7];   //[nTauOther]
   Int_t           TauOther_pdgId[7];   //[nTauOther]
   Float_t         TauOther_pt[7];   //[nTauOther]
   Float_t         TauOther_eta[7];   //[nTauOther]
   Float_t         TauOther_phi[7];   //[nTauOther]
   Float_t         TauOther_mass[7];   //[nTauOther]
   Int_t           TauOther_idMVAOldDMRun2[7];   //[nTauOther]
   Int_t           TauOther_idMVAOldDMRun2dR03[7];   //[nTauOther]
   Int_t           nLepGood;
   Float_t         LepGood_mvaIdSpring15[5];   //[nLepGood]
   Float_t         LepGood_mvaTTH[5];   //[nLepGood]
   Float_t         LepGood_mvaSUSY[5];   //[nLepGood]
   Float_t         LepGood_mvaSoftT2tt[5];   //[nLepGood]
   Float_t         LepGood_mvaSoftEWK[5];   //[nLepGood]
   Float_t         LepGood_jetPtRatiov1[5];   //[nLepGood]
   Float_t         LepGood_jetPtRelv1[5];   //[nLepGood]
   Float_t         LepGood_jetPtRatiov2[5];   //[nLepGood]
   Float_t         LepGood_jetPtRelv2[5];   //[nLepGood]
   Float_t         LepGood_jetBTagCSV[5];   //[nLepGood]
   Float_t         LepGood_jetBTagCMVA[5];   //[nLepGood]
   Float_t         LepGood_jetDR[5];   //[nLepGood]
   Float_t         LepGood_r9[5];   //[nLepGood]
   Float_t         LepGood_mvaIdSpring16[5];   //[nLepGood]
   Int_t           LepGood_charge[5];   //[nLepGood]
   Int_t           LepGood_tightId[5];   //[nLepGood]
   Int_t           LepGood_eleCutIdCSA14_25ns_v1[5];   //[nLepGood]
   Int_t           LepGood_eleCutIdCSA14_50ns_v1[5];   //[nLepGood]
   Int_t           LepGood_eleCutIdSpring15_25ns_v1[5];   //[nLepGood]
   Float_t         LepGood_dxy[5];   //[nLepGood]
   Float_t         LepGood_dz[5];   //[nLepGood]
   Float_t         LepGood_edxy[5];   //[nLepGood]
   Float_t         LepGood_edz[5];   //[nLepGood]
   Float_t         LepGood_ip3d[5];   //[nLepGood]
   Float_t         LepGood_sip3d[5];   //[nLepGood]
   Int_t           LepGood_convVeto[5];   //[nLepGood]
   Int_t           LepGood_lostHits[5];   //[nLepGood]
   Float_t         LepGood_relIso03[5];   //[nLepGood]
   Float_t         LepGood_relIso04[5];   //[nLepGood]
   Float_t         LepGood_miniRelIso[5];   //[nLepGood]
   Float_t         LepGood_relIsoAn04[5];   //[nLepGood]
   Int_t           LepGood_tightCharge[5];   //[nLepGood]
   Int_t           LepGood_mcMatchId[5];   //[nLepGood]
   Int_t           LepGood_mcMatchAny[5];   //[nLepGood]
   Int_t           LepGood_mcMatchTau[5];   //[nLepGood]
   Float_t         LepGood_mcPt[5];   //[nLepGood]
   Int_t           LepGood_mediumMuonId[5];   //[nLepGood]
   Int_t           LepGood_ICHEPsoftMuonId[5];   //[nLepGood]
   Int_t           LepGood_ICHEPmediumMuonId[5];   //[nLepGood]
   Int_t           LepGood_pdgId[5];   //[nLepGood]
   Float_t         LepGood_pt[5];   //[nLepGood]
   Float_t         LepGood_eta[5];   //[nLepGood]
   Float_t         LepGood_phi[5];   //[nLepGood]
   Float_t         LepGood_mass[5];   //[nLepGood]
   Int_t           LepGood_looseIdOnly[5];   //[nLepGood]
   Float_t         LepGood_chargedHadRelIso03[5];   //[nLepGood]
   Float_t         LepGood_chargedHadRelIso04[5];   //[nLepGood]
   Int_t           LepGood_softMuonId[5];   //[nLepGood]
   Int_t           LepGood_pfMuonId[5];   //[nLepGood]
   Int_t           LepGood_eleCutId2012_full5x5[5];   //[nLepGood]
   Int_t           LepGood_trackerLayers[5];   //[nLepGood]
   Int_t           LepGood_pixelLayers[5];   //[nLepGood]
   Int_t           LepGood_trackerHits[5];   //[nLepGood]
   Int_t           LepGood_lostOuterHits[5];   //[nLepGood]
   Float_t         LepGood_innerTrackValidHitFraction[5];   //[nLepGood]
   Float_t         LepGood_innerTrackChi2[5];   //[nLepGood]
   Float_t         LepGood_nStations[5];   //[nLepGood]
   Float_t         LepGood_caloCompatibility[5];   //[nLepGood]
   Float_t         LepGood_globalTrackChi2[5];   //[nLepGood]
   Float_t         LepGood_trkKink[5];   //[nLepGood]
   Float_t         LepGood_segmentCompatibility[5];   //[nLepGood]
   Float_t         LepGood_chi2LocalPosition[5];   //[nLepGood]
   Float_t         LepGood_chi2LocalMomentum[5];   //[nLepGood]
   Float_t         LepGood_glbTrackProbability[5];   //[nLepGood]
   Int_t           LepGood_TMOneStationTightMuonId[5];   //[nLepGood]
   Int_t           LepGood_trackHighPurityMuon[5];   //[nLepGood]
   Int_t           LepGood_isGlobalMuon[5];   //[nLepGood]
   Int_t           LepGood_isTrackerMuon[5];   //[nLepGood]
   Float_t         LepGood_sigmaIEtaIEta[5];   //[nLepGood]
   Float_t         LepGood_dEtaScTrkIn[5];   //[nLepGood]
   Float_t         LepGood_dPhiScTrkIn[5];   //[nLepGood]
   Float_t         LepGood_hadronicOverEm[5];   //[nLepGood]
   Float_t         LepGood_eInvMinusPInv[5];   //[nLepGood]
   Float_t         LepGood_eInvMinusPInv_tkMom[5];   //[nLepGood]
   Float_t         LepGood_etaSc[5];   //[nLepGood]
   Int_t           LepGood_mcMatchPdgId[5];   //[nLepGood]
   Float_t         LepGood_miniRelIsoCharged[5];   //[nLepGood]
   Float_t         LepGood_miniRelIsoNeutral[5];   //[nLepGood]
   Float_t         LepGood_jetNDauChargedMVASel[5];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1[5];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2[5];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2L3[5];   //[nLepGood]
   Float_t         LepGood_jetCorrFactor_L1L2L3Res[5];   //[nLepGood]
   Float_t         LepGood_ecalPFClusterIso[5];   //[nLepGood]
   Float_t         LepGood_hcalPFClusterIso[5];   //[nLepGood]
   Float_t         LepGood_dr03TkSumPt[5];   //[nLepGood]
   Float_t         LepGood_trackIso[5];   //[nLepGood]
   Float_t         LepGood_idEmuTTH[5];   //[nLepGood]
   Float_t         LepGood_idEmuRA5[5];   //[nLepGood]
   Float_t         LepGood_idIsoEmuRA5[5];   //[nLepGood]
   Int_t           LepGood_mcPrompt[5];   //[nLepGood]
   Int_t           LepGood_mcPromptTau[5];   //[nLepGood]
   Int_t           LepGood_mcPromptGamma[5];   //[nLepGood]
   Int_t           LepGood_mcGamma[5];   //[nLepGood]
   Float_t         LepGood_RelIsoMIV03[5];   //[nLepGood]
   Float_t         LepGood_RelIsoMIVCharged03[5];   //[nLepGood]
   Float_t         LepGood_RelIsoMIVNeutral03[5];   //[nLepGood]
   Float_t         LepGood_RelIsoMIV04[5];   //[nLepGood]
   Float_t         LepGood_RelIsoMIVCharged04[5];   //[nLepGood]
   Float_t         LepGood_RelIsoMIVNeutral04[5];   //[nLepGood]
   Float_t         LepGood_jetPtRelHv2[5];   //[nLepGood]
   Float_t         LepGood_isoRelH04[5];   //[nLepGood]
   Float_t         LepGood_jetBasedRelIsoCharged[5];   //[nLepGood]
   Int_t           LepGood_hasSV[5];   //[nLepGood]
   Float_t         LepGood_svSip3d[5];   //[nLepGood]
   Float_t         LepGood_svRedPt[5];   //[nLepGood]
   Float_t         LepGood_svMass[5];   //[nLepGood]
   Float_t         LepGood_svNTracks[5];   //[nLepGood]
   Float_t         LepGood_mcUCSXMatchId[5];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_pt[5];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_eta[5];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_phi[5];   //[nLepGood]
   Float_t         LepGood_jetLepAwareJEC_energy[5];   //[nLepGood]
   Int_t           nDiscJet_jecDown;
   Int_t           DiscJet_jecDown_mcMatchFlav[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_charge[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_ctagCsvL[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_ctagCsvB[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_area[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_qgl[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_ptd[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_axis2[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_mult[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_partonId[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_partonMotherId[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_nLeptons[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_id[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_puId[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_btagCSV[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_btagCMVA[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_rawPt[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_mcPt[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_mcFlavour[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_partonFlavour[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_hadronFlavour[5];   //[nDiscJet_jecDown]
   Int_t           DiscJet_jecDown_mcMatchId[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_corr_JECUp[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_corr_JECDown[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_corr[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_corr_JERUp[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_corr_JERDown[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_corr_JER[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_pt[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_eta[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_phi[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_mass[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_CorrFactor_L1[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_CorrFactor_L1L2[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_CorrFactor_L1L2L3[5];   //[nDiscJet_jecDown]
   Float_t         DiscJet_jecDown_CorrFactor_L1L2L3Res[5];   //[nDiscJet_jecDown]
   Int_t           nJet_jecUp;
   Int_t           Jet_jecUp_mcMatchFlav[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_charge[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_ctagCsvL[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_ctagCsvB[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_area[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_qgl[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_ptd[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_axis2[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_mult[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_partonId[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_partonMotherId[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_nLeptons[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_id[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_puId[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_btagCSV[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_btagCMVA[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_rawPt[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_mcPt[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_mcFlavour[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_partonFlavour[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_hadronFlavour[15];   //[nJet_jecUp]
   Int_t           Jet_jecUp_mcMatchId[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_corr_JECUp[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_corr_JECDown[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_corr[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_corr_JERUp[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_corr_JERDown[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_corr_JER[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_pt[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_eta[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_phi[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_mass[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_CorrFactor_L1[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_CorrFactor_L1L2[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_CorrFactor_L1L2L3[15];   //[nJet_jecUp]
   Float_t         Jet_jecUp_CorrFactor_L1L2L3Res[15];   //[nJet_jecUp]
   Int_t           nGenDHad;
   Float_t         GenDHad_charge[20];   //[nGenDHad]
   Int_t           GenDHad_status[20];   //[nGenDHad]
   Int_t           GenDHad_isPromptHard[20];   //[nGenDHad]
   Int_t           GenDHad_pdgId[20];   //[nGenDHad]
   Float_t         GenDHad_pt[20];   //[nGenDHad]
   Float_t         GenDHad_eta[20];   //[nGenDHad]
   Float_t         GenDHad_phi[20];   //[nGenDHad]
   Float_t         GenDHad_mass[20];   //[nGenDHad]
   Int_t           GenDHad_flav[20];   //[nGenDHad]
   Int_t           GenDHad_sourceId[20];   //[nGenDHad]
   Float_t         GenDHad_svMass[20];   //[nGenDHad]
   Float_t         GenDHad_svPt[20];   //[nGenDHad]
   Int_t           GenDHad_svCharge[20];   //[nGenDHad]
   Int_t           GenDHad_svNtracks[20];   //[nGenDHad]
   Float_t         GenDHad_svChi2[20];   //[nGenDHad]
   Float_t         GenDHad_svNdof[20];   //[nGenDHad]
   Float_t         GenDHad_svDxy[20];   //[nGenDHad]
   Float_t         GenDHad_svEdxy[20];   //[nGenDHad]
   Float_t         GenDHad_svIp3d[20];   //[nGenDHad]
   Float_t         GenDHad_svEip3d[20];   //[nGenDHad]
   Float_t         GenDHad_svSip3d[20];   //[nGenDHad]
   Float_t         GenDHad_svCosTheta[20];   //[nGenDHad]
   Float_t         GenDHad_svMva[20];   //[nGenDHad]
   Float_t         GenDHad_jetPt[20];   //[nGenDHad]
   Float_t         GenDHad_jetBTagCSV[20];   //[nGenDHad]
   Float_t         GenDHad_jetBTagCMVA[20];   //[nGenDHad]
   Int_t           nGenBHad;
   Float_t         GenBHad_charge[10];   //[nGenBHad]
   Int_t           GenBHad_status[10];   //[nGenBHad]
   Int_t           GenBHad_isPromptHard[10];   //[nGenBHad]
   Int_t           GenBHad_pdgId[10];   //[nGenBHad]
   Float_t         GenBHad_pt[10];   //[nGenBHad]
   Float_t         GenBHad_eta[10];   //[nGenBHad]
   Float_t         GenBHad_phi[10];   //[nGenBHad]
   Float_t         GenBHad_mass[10];   //[nGenBHad]
   Int_t           GenBHad_flav[10];   //[nGenBHad]
   Int_t           GenBHad_sourceId[10];   //[nGenBHad]
   Float_t         GenBHad_svMass[10];   //[nGenBHad]
   Float_t         GenBHad_svPt[10];   //[nGenBHad]
   Int_t           GenBHad_svCharge[10];   //[nGenBHad]
   Int_t           GenBHad_svNtracks[10];   //[nGenBHad]
   Float_t         GenBHad_svChi2[10];   //[nGenBHad]
   Float_t         GenBHad_svNdof[10];   //[nGenBHad]
   Float_t         GenBHad_svDxy[10];   //[nGenBHad]
   Float_t         GenBHad_svEdxy[10];   //[nGenBHad]
   Float_t         GenBHad_svIp3d[10];   //[nGenBHad]
   Float_t         GenBHad_svEip3d[10];   //[nGenBHad]
   Float_t         GenBHad_svSip3d[10];   //[nGenBHad]
   Float_t         GenBHad_svCosTheta[10];   //[nGenBHad]
   Float_t         GenBHad_svMva[10];   //[nGenBHad]
   Float_t         GenBHad_jetPt[10];   //[nGenBHad]
   Float_t         GenBHad_jetBTagCSV[10];   //[nGenBHad]
   Float_t         GenBHad_jetBTagCMVA[10];   //[nGenBHad]
   Int_t           nJet;
   Int_t           Jet_mcMatchFlav[15];   //[nJet]
   Float_t         Jet_charge[15];   //[nJet]
   Float_t         Jet_ctagCsvL[15];   //[nJet]
   Float_t         Jet_ctagCsvB[15];   //[nJet]
   Float_t         Jet_area[15];   //[nJet]
   Float_t         Jet_qgl[15];   //[nJet]
   Float_t         Jet_ptd[15];   //[nJet]
   Float_t         Jet_axis2[15];   //[nJet]
   Int_t           Jet_mult[15];   //[nJet]
   Int_t           Jet_partonId[15];   //[nJet]
   Int_t           Jet_partonMotherId[15];   //[nJet]
   Float_t         Jet_nLeptons[15];   //[nJet]
   Int_t           Jet_id[15];   //[nJet]
   Int_t           Jet_puId[15];   //[nJet]
   Float_t         Jet_btagCSV[15];   //[nJet]
   Float_t         Jet_btagCMVA[15];   //[nJet]
   Float_t         Jet_rawPt[15];   //[nJet]
   Float_t         Jet_mcPt[15];   //[nJet]
   Int_t           Jet_mcFlavour[15];   //[nJet]
   Int_t           Jet_partonFlavour[15];   //[nJet]
   Int_t           Jet_hadronFlavour[15];   //[nJet]
   Int_t           Jet_mcMatchId[15];   //[nJet]
   Float_t         Jet_corr_JECUp[15];   //[nJet]
   Float_t         Jet_corr_JECDown[15];   //[nJet]
   Float_t         Jet_corr[15];   //[nJet]
   Float_t         Jet_corr_JERUp[15];   //[nJet]
   Float_t         Jet_corr_JERDown[15];   //[nJet]
   Float_t         Jet_corr_JER[15];   //[nJet]
   Float_t         Jet_pt[15];   //[nJet]
   Float_t         Jet_eta[15];   //[nJet]
   Float_t         Jet_phi[15];   //[nJet]
   Float_t         Jet_mass[15];   //[nJet]
   Float_t         Jet_CorrFactor_L1[15];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2[15];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2L3[15];   //[nJet]
   Float_t         Jet_CorrFactor_L1L2L3Res[15];   //[nJet]
   Int_t           nJetNoTauIdx;
   Int_t           JetNoTauIdx[10];   //[nJetNoTauIdx]
   Int_t           nLHEweight;
   Int_t           LHEweight_id[111];   //[nLHEweight]
   Float_t         LHEweight_wgt[111];   //[nLHEweight]
   Int_t           nTauGood;
   Int_t           TauGood_charge[8];   //[nTauGood]
   Int_t           TauGood_decayMode[8];   //[nTauGood]
   Int_t           TauGood_idDecayMode[8];   //[nTauGood]
   Int_t           TauGood_idDecayModeNewDMs[8];   //[nTauGood]
   Float_t         TauGood_dxy[8];   //[nTauGood]
   Float_t         TauGood_dz[8];   //[nTauGood]
   Int_t           TauGood_idMVA[8];   //[nTauGood]
   Int_t           TauGood_idMVANewDM[8];   //[nTauGood]
   Int_t           TauGood_idCI3hit[8];   //[nTauGood]
   Int_t           TauGood_idAntiMu[8];   //[nTauGood]
   Int_t           TauGood_idAntiE[8];   //[nTauGood]
   Float_t         TauGood_isoCI3hit[8];   //[nTauGood]
   Int_t           TauGood_mcMatchId[8];   //[nTauGood]
   Int_t           TauGood_pdgId[8];   //[nTauGood]
   Float_t         TauGood_pt[8];   //[nTauGood]
   Float_t         TauGood_eta[8];   //[nTauGood]
   Float_t         TauGood_phi[8];   //[nTauGood]
   Float_t         TauGood_mass[8];   //[nTauGood]
   Int_t           TauGood_idMVAOldDMRun2[8];   //[nTauGood]
   Int_t           TauGood_idMVAOldDMRun2dR03[8];   //[nTauGood]
   Int_t           ngenLep;
   Int_t           genLep_motherId[10];   //[ngenLep]
   Int_t           genLep_grandmotherId[10];   //[ngenLep]
   Int_t           genLep_sourceId[10];   //[ngenLep]
   Float_t         genLep_charge[10];   //[ngenLep]
   Int_t           genLep_status[10];   //[ngenLep]
   Int_t           genLep_isPromptHard[10];   //[ngenLep]
   Int_t           genLep_pdgId[10];   //[ngenLep]
   Float_t         genLep_pt[10];   //[ngenLep]
   Float_t         genLep_eta[10];   //[ngenLep]
   Float_t         genLep_phi[10];   //[ngenLep]
   Float_t         genLep_mass[10];   //[ngenLep]
   Int_t           genLep_motherIndex[10];   //[ngenLep]
   Int_t           ngenTau;
   Int_t           genTau_motherId[3];   //[ngenTau]
   Int_t           genTau_grandmotherId[3];   //[ngenTau]
   Int_t           genTau_sourceId[3];   //[ngenTau]
   Float_t         genTau_charge[3];   //[ngenTau]
   Int_t           genTau_status[3];   //[ngenTau]
   Int_t           genTau_isPromptHard[3];   //[ngenTau]
   Int_t           genTau_pdgId[3];   //[ngenTau]
   Float_t         genTau_pt[3];   //[ngenTau]
   Float_t         genTau_eta[3];   //[ngenTau]
   Float_t         genTau_phi[3];   //[ngenTau]
   Float_t         genTau_mass[3];   //[ngenTau]
   Int_t           genTau_motherIndex[3];   //[ngenTau]
   Int_t           nJet_jecDown;
   Int_t           Jet_jecDown_mcMatchFlav[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_charge[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_ctagCsvL[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_ctagCsvB[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_area[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_qgl[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_ptd[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_axis2[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_mult[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_partonId[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_partonMotherId[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_nLeptons[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_id[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_puId[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_btagCSV[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_btagCMVA[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_rawPt[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_mcPt[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_mcFlavour[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_partonFlavour[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_hadronFlavour[15];   //[nJet_jecDown]
   Int_t           Jet_jecDown_mcMatchId[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_corr_JECUp[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_corr_JECDown[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_corr[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_corr_JERUp[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_corr_JERDown[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_corr_JER[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_pt[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_eta[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_phi[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_mass[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_CorrFactor_L1[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_CorrFactor_L1L2[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_CorrFactor_L1L2L3[15];   //[nJet_jecDown]
   Float_t         Jet_jecDown_CorrFactor_L1L2L3Res[15];   //[nJet_jecDown]
   Int_t           nGenTop;
   Int_t           GenTop_pdgId[2];   //[nGenTop]
   Float_t         GenTop_pt[2];   //[nGenTop]
   Float_t         GenTop_eta[2];   //[nGenTop]
   Float_t         GenTop_phi[2];   //[nGenTop]
   Float_t         GenTop_mass[2];   //[nGenTop]
   Float_t         GenTop_charge[2];   //[nGenTop]
   Int_t           GenTop_status[2];   //[nGenTop]
   Int_t           GenTop_isPromptHard[2];   //[nGenTop]
   Int_t           nLepOther;
   Int_t           LepOther_charge[8];   //[nLepOther]
   Int_t           LepOther_tightId[8];   //[nLepOther]
   Int_t           LepOther_eleCutIdCSA14_25ns_v1[8];   //[nLepOther]
   Int_t           LepOther_eleCutIdCSA14_50ns_v1[8];   //[nLepOther]
   Int_t           LepOther_eleCutIdSpring15_25ns_v1[8];   //[nLepOther]
   Float_t         LepOther_dxy[8];   //[nLepOther]
   Float_t         LepOther_dz[8];   //[nLepOther]
   Float_t         LepOther_edxy[8];   //[nLepOther]
   Float_t         LepOther_edz[8];   //[nLepOther]
   Float_t         LepOther_ip3d[8];   //[nLepOther]
   Float_t         LepOther_sip3d[8];   //[nLepOther]
   Int_t           LepOther_convVeto[8];   //[nLepOther]
   Int_t           LepOther_lostHits[8];   //[nLepOther]
   Float_t         LepOther_relIso03[8];   //[nLepOther]
   Float_t         LepOther_relIso04[8];   //[nLepOther]
   Float_t         LepOther_miniRelIso[8];   //[nLepOther]
   Float_t         LepOther_relIsoAn04[8];   //[nLepOther]
   Int_t           LepOther_tightCharge[8];   //[nLepOther]
   Int_t           LepOther_mcMatchId[8];   //[nLepOther]
   Int_t           LepOther_mcMatchAny[8];   //[nLepOther]
   Int_t           LepOther_mcMatchTau[8];   //[nLepOther]
   Float_t         LepOther_mcPt[8];   //[nLepOther]
   Int_t           LepOther_mediumMuonId[8];   //[nLepOther]
   Int_t           LepOther_ICHEPsoftMuonId[8];   //[nLepOther]
   Int_t           LepOther_ICHEPmediumMuonId[8];   //[nLepOther]
   Int_t           LepOther_pdgId[8];   //[nLepOther]
   Float_t         LepOther_pt[8];   //[nLepOther]
   Float_t         LepOther_eta[8];   //[nLepOther]
   Float_t         LepOther_phi[8];   //[nLepOther]
   Float_t         LepOther_mass[8];   //[nLepOther]
   Float_t         LepOther_mvaIdSpring15[8];   //[nLepOther]
   Float_t         LepOther_mvaTTH[8];   //[nLepOther]
   Float_t         LepOther_mvaSUSY[8];   //[nLepOther]
   Float_t         LepOther_mvaSoftT2tt[8];   //[nLepOther]
   Float_t         LepOther_mvaSoftEWK[8];   //[nLepOther]
   Float_t         LepOther_jetPtRatiov1[8];   //[nLepOther]
   Float_t         LepOther_jetPtRelv1[8];   //[nLepOther]
   Float_t         LepOther_jetPtRatiov2[8];   //[nLepOther]
   Float_t         LepOther_jetPtRelv2[8];   //[nLepOther]
   Float_t         LepOther_jetBTagCSV[8];   //[nLepOther]
   Float_t         LepOther_jetBTagCMVA[8];   //[nLepOther]
   Float_t         LepOther_jetDR[8];   //[nLepOther]
   Float_t         LepOther_r9[8];   //[nLepOther]
   Float_t         LepOther_mvaIdSpring16[8];   //[nLepOther]
   Int_t           nDiscJet_jecUp;
   Int_t           DiscJet_jecUp_mcMatchFlav[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_charge[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_ctagCsvL[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_ctagCsvB[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_area[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_qgl[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_ptd[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_axis2[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_mult[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_partonId[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_partonMotherId[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_nLeptons[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_id[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_puId[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_btagCSV[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_btagCMVA[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_rawPt[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_mcPt[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_mcFlavour[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_partonFlavour[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_hadronFlavour[5];   //[nDiscJet_jecUp]
   Int_t           DiscJet_jecUp_mcMatchId[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_corr_JECUp[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_corr_JECDown[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_corr[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_corr_JERUp[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_corr_JERDown[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_corr_JER[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_pt[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_eta[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_phi[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_mass[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_CorrFactor_L1[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_CorrFactor_L1L2[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_CorrFactor_L1L2L3[5];   //[nDiscJet_jecUp]
   Float_t         DiscJet_jecUp_CorrFactor_L1L2L3Res[5];   //[nDiscJet_jecUp]
   Int_t           ngenLepFromTau;
   Int_t           genLepFromTau_motherId[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_grandmotherId[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_sourceId[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_charge[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_status[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_isPromptHard[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_pdgId[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_pt[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_eta[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_phi[4];   //[ngenLepFromTau]
   Float_t         genLepFromTau_mass[4];   //[ngenLepFromTau]
   Int_t           genLepFromTau_motherIndex[4];   //[ngenLepFromTau]
   Int_t           nJetFwd;
   Float_t         JetFwd_area[6];   //[nJetFwd]
   Float_t         JetFwd_qgl[6];   //[nJetFwd]
   Float_t         JetFwd_ptd[6];   //[nJetFwd]
   Float_t         JetFwd_axis2[6];   //[nJetFwd]
   Int_t           JetFwd_mult[6];   //[nJetFwd]
   Int_t           JetFwd_partonId[6];   //[nJetFwd]
   Int_t           JetFwd_partonMotherId[6];   //[nJetFwd]
   Float_t         JetFwd_nLeptons[6];   //[nJetFwd]
   Int_t           JetFwd_id[6];   //[nJetFwd]
   Int_t           JetFwd_puId[6];   //[nJetFwd]
   Float_t         JetFwd_btagCSV[6];   //[nJetFwd]
   Float_t         JetFwd_btagCMVA[6];   //[nJetFwd]
   Float_t         JetFwd_rawPt[6];   //[nJetFwd]
   Float_t         JetFwd_mcPt[6];   //[nJetFwd]
   Int_t           JetFwd_mcFlavour[6];   //[nJetFwd]
   Int_t           JetFwd_partonFlavour[6];   //[nJetFwd]
   Int_t           JetFwd_hadronFlavour[6];   //[nJetFwd]
   Int_t           JetFwd_mcMatchId[6];   //[nJetFwd]
   Float_t         JetFwd_corr_JECUp[6];   //[nJetFwd]
   Float_t         JetFwd_corr_JECDown[6];   //[nJetFwd]
   Float_t         JetFwd_corr[6];   //[nJetFwd]
   Float_t         JetFwd_corr_JERUp[6];   //[nJetFwd]
   Float_t         JetFwd_corr_JERDown[6];   //[nJetFwd]
   Float_t         JetFwd_corr_JER[6];   //[nJetFwd]
   Float_t         JetFwd_pt[6];   //[nJetFwd]
   Float_t         JetFwd_eta[6];   //[nJetFwd]
   Float_t         JetFwd_phi[6];   //[nJetFwd]
   Float_t         JetFwd_mass[6];   //[nJetFwd]
   Int_t           JetFwd_mcMatchFlav[6];   //[nJetFwd]
   Float_t         JetFwd_charge[6];   //[nJetFwd]
   Float_t         JetFwd_ctagCsvL[6];   //[nJetFwd]
   Float_t         JetFwd_ctagCsvB[6];   //[nJetFwd]
   Int_t           nPhoGood;
   Float_t         PhoGood_etaSc[2];   //[nPhoGood]
   Int_t           PhoGood_idCutBased[2];   //[nPhoGood]
   Float_t         PhoGood_hOverE[2];   //[nPhoGood]
   Float_t         PhoGood_r9[2];   //[nPhoGood]
   Float_t         PhoGood_sigmaIetaIeta[2];   //[nPhoGood]
   Float_t         PhoGood_chHadIso04[2];   //[nPhoGood]
   Float_t         PhoGood_chHadIso[2];   //[nPhoGood]
   Float_t         PhoGood_phIso[2];   //[nPhoGood]
   Float_t         PhoGood_neuHadIso[2];   //[nPhoGood]
   Float_t         PhoGood_relIso[2];   //[nPhoGood]
   Int_t           PhoGood_mcMatchId[2];   //[nPhoGood]
   Float_t         PhoGood_mcPt[2];   //[nPhoGood]
   Int_t           PhoGood_pdgId[2];   //[nPhoGood]
   Float_t         PhoGood_pt[2];   //[nPhoGood]
   Float_t         PhoGood_eta[2];   //[nPhoGood]
   Float_t         PhoGood_phi[2];   //[nPhoGood]
   Float_t         PhoGood_mass[2];   //[nPhoGood]
   Float_t         PhoGood_genIso04[2];   //[nPhoGood]
   Float_t         PhoGood_genIso03[2];   //[nPhoGood]
   Float_t         PhoGood_chHadIsoRC04[2];   //[nPhoGood]
   Float_t         PhoGood_chHadIsoRC[2];   //[nPhoGood]
   Float_t         PhoGood_drMinParton[2];   //[nPhoGood]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_nTrueInt;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_rhoCN;   //!
   TBranch        *b_nVert;   //!
   TBranch        *b_nJet25;   //!
   TBranch        *b_nJet25a;   //!
   TBranch        *b_nBJetLoose25;   //!
   TBranch        *b_nBJetMedium25;   //!
   TBranch        *b_nBJetTight25;   //!
   TBranch        *b_nJet30;   //!
   TBranch        *b_nJet30a;   //!
   TBranch        *b_nBJetLoose30;   //!
   TBranch        *b_nBJetMedium30;   //!
   TBranch        *b_nBJetTight30;   //!
   TBranch        *b_nJet40;   //!
   TBranch        *b_nJet40a;   //!
   TBranch        *b_nBJetLoose40;   //!
   TBranch        *b_nBJetMedium40;   //!
   TBranch        *b_nBJetTight40;   //!
   TBranch        *b_nLepGood20;   //!
   TBranch        *b_nLepGood15;   //!
   TBranch        *b_nLepGood10;   //!
   TBranch        *b_GenSusyMScan1;   //!
   TBranch        *b_GenSusyMScan2;   //!
   TBranch        *b_GenSusyMScan3;   //!
   TBranch        *b_GenSusyMScan4;   //!
   TBranch        *b_GenSusyMGluino;   //!
   TBranch        *b_GenSusyMGravitino;   //!
   TBranch        *b_GenSusyMStop;   //!
   TBranch        *b_GenSusyMSbottom;   //!
   TBranch        *b_GenSusyMStop2;   //!
   TBranch        *b_GenSusyMSbottom2;   //!
   TBranch        *b_GenSusyMSquark;   //!
   TBranch        *b_GenSusyMNeutralino;   //!
   TBranch        *b_GenSusyMNeutralino2;   //!
   TBranch        *b_GenSusyMNeutralino3;   //!
   TBranch        *b_GenSusyMNeutralino4;   //!
   TBranch        *b_GenSusyMChargino;   //!
   TBranch        *b_GenSusyMChargino2;   //!
   TBranch        *b_lheHT;   //!
   TBranch        *b_lheHTIncoming;   //!
   TBranch        *b_htJet25;   //!
   TBranch        *b_mhtJet25;   //!
   TBranch        *b_htJet40j;   //!
   TBranch        *b_htJet40ja;   //!
   TBranch        *b_htJet40;   //!
   TBranch        *b_htJet40a;   //!
   TBranch        *b_mhtJet40;   //!
   TBranch        *b_mhtJet40a;   //!
   TBranch        *b_nJet25NoTau;   //!
   TBranch        *b_nBJetLoose25NoTau;   //!
   TBranch        *b_nBJetMedium25NoTau;   //!
   TBranch        *b_nBJetCMVALoose25;   //!
   TBranch        *b_nBJetCMVAMedium25;   //!
   TBranch        *b_nBJetCMVATight25;   //!
   TBranch        *b_nSoftBLoose25;   //!
   TBranch        *b_nSoftBMedium25;   //!
   TBranch        *b_nSoftBTight25;   //!
   TBranch        *b_nJet30NoTau;   //!
   TBranch        *b_nBJetLoose30NoTau;   //!
   TBranch        *b_nBJetMedium30NoTau;   //!
   TBranch        *b_nJet40NoTau;   //!
   TBranch        *b_nBJetLoose40NoTau;   //!
   TBranch        *b_nBJetMedium40NoTau;   //!
   TBranch        *b_nBJetCMVALoose40;   //!
   TBranch        *b_nBJetCMVAMedium40;   //!
   TBranch        *b_nBJetCMVATight40;   //!
   TBranch        *b_mZ1;   //!
   TBranch        *b_mZ1SFSS;   //!
   TBranch        *b_minMllSFOS;   //!
   TBranch        *b_maxMllSFOS;   //!
   TBranch        *b_minMllAFOS;   //!
   TBranch        *b_maxMllAFOS;   //!
   TBranch        *b_minMllAFSS;   //!
   TBranch        *b_maxMllAFSS;   //!
   TBranch        *b_minMllAFAS;   //!
   TBranch        *b_maxMllAFAS;   //!
   TBranch        *b_m2l;   //!
   TBranch        *b_minDrllAFSS;   //!
   TBranch        *b_maxDrllAFSS;   //!
   TBranch        *b_minDrllAFOS;   //!
   TBranch        *b_maxDrllAFOS;   //!
   TBranch        *b_mZ2;   //!
   TBranch        *b_m3l;   //!
   TBranch        *b_m4l;   //!
   TBranch        *b_pt2l;   //!
   TBranch        *b_pt3l;   //!
   TBranch        *b_pt4l;   //!
   TBranch        *b_ht3l;   //!
   TBranch        *b_ht4l;   //!
   TBranch        *b_q3l;   //!
   TBranch        *b_q4l;   //!
   TBranch        *b_minMWjj;   //!
   TBranch        *b_minMWjjPt;   //!
   TBranch        *b_bestMWjj;   //!
   TBranch        *b_bestMWjjPt;   //!
   TBranch        *b_bestMTopHad;   //!
   TBranch        *b_bestMTopHadPt;   //!
   TBranch        *b_GenHiggsDecayMode;   //!
   TBranch        *b_absIP3DAval;   //!
   TBranch        *b_absIP3DAerr;   //!
   TBranch        *b_absIP3DBval;   //!
   TBranch        *b_absIP3DBerr;   //!
   TBranch        *b_absIP3DCval;   //!
   TBranch        *b_absIP3DCerr;   //!
   TBranch        *b_absIP3DDval;   //!
   TBranch        *b_absIP3DDerr;   //!
   TBranch        *b_absIP3DApvBCval;   //!
   TBranch        *b_absIP3DApvBCerr;   //!
   TBranch        *b_absIP3DBpvACval;   //!
   TBranch        *b_absIP3DBpvACerr;   //!
   TBranch        *b_absIP3DCpvABval;   //!
   TBranch        *b_absIP3DCpvABerr;   //!
   TBranch        *b_absIP3DApvBCDval;   //!
   TBranch        *b_absIP3DApvBCDerr;   //!
   TBranch        *b_absIP3DBpvACDval;   //!
   TBranch        *b_absIP3DBpvACDerr;   //!
   TBranch        *b_absIP3DCpvABDval;   //!
   TBranch        *b_absIP3DCpvABDerr;   //!
   TBranch        *b_absIP3DDpvABCval;   //!
   TBranch        *b_absIP3DDpvABCerr;   //!
   TBranch        *b_chi2pvtrksBCbutAval;   //!
   TBranch        *b_chi2pvtrksBCbutAdof;   //!
   TBranch        *b_chi2pvtrksACbutBval;   //!
   TBranch        *b_chi2pvtrksACbutBdof;   //!
   TBranch        *b_chi2pvtrksABbutCval;   //!
   TBranch        *b_chi2pvtrksABbutCdof;   //!
   TBranch        *b_chi2pvtrksBCDbutAval;   //!
   TBranch        *b_chi2pvtrksBCDbutAdof;   //!
   TBranch        *b_chi2pvtrksACDbutBval;   //!
   TBranch        *b_chi2pvtrksACDbutBdof;   //!
   TBranch        *b_chi2pvtrksABDbutCval;   //!
   TBranch        *b_chi2pvtrksABDbutCdof;   //!
   TBranch        *b_chi2pvtrksABCbutDval;   //!
   TBranch        *b_chi2pvtrksABCbutDdof;   //!
   TBranch        *b_nRecJet40;   //!
   TBranch        *b_nRecJet25;   //!
   TBranch        *b_nRecBJetMedium40;   //!
   TBranch        *b_nRecBJetMedium25;   //!
   TBranch        *b_nRecSplitJet40;   //!
   TBranch        *b_nRecSplitJet25;   //!
   TBranch        *b_nRecSplitBJetMedium40;   //!
   TBranch        *b_nRecSplitBJetMedium25;   //!
   TBranch        *b_hbheFilterNew50ns;   //!
   TBranch        *b_hbheFilterNew25ns;   //!
   TBranch        *b_hbheFilterIso;   //!
   TBranch        *b_Flag_badChargedHadronFilter;   //!
   TBranch        *b_Flag_badMuonFilter;   //!
   TBranch        *b_met_trkPt;   //!
   TBranch        *b_met_trkPhi;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale;   //!
   TBranch        *b_HLT_DoubleElHT;   //!
   TBranch        *b_HLT_DoubleElHT_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_Prescale;   //!
   TBranch        *b_HLT_TripleEl;   //!
   TBranch        *b_HLT_TripleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale;   //!
   TBranch        *b_HLT_MuEGHT;   //!
   TBranch        *b_HLT_MuEGHT_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu22_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu22_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu22_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu22_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu22_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu22_v_Prescale;   //!
   TBranch        *b_HLT_SingleMu;   //!
   TBranch        *b_HLT_SingleMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_Prescale;   //!
   TBranch        *b_HLT_DoubleMuEl;   //!
   TBranch        *b_HLT_DoubleMuEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_12_10_5_v;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_12_10_5_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_5_3_3_v;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_5_3_3_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_5_3_3_v_Prescale;   //!
   TBranch        *b_HLT_TripleMu;   //!
   TBranch        *b_HLT_TripleMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_Prescale;   //!
   TBranch        *b_HLT_DoubleElMu;   //!
   TBranch        *b_HLT_DoubleElMu_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu30_TkMu11_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu30_TkMu11_v_Prescale;   //!
   TBranch        *b_HLT_DoubleMuNoIso;   //!
   TBranch        *b_HLT_DoubleMuNoIso_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu20_Mu10_SameSign_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu20_Mu10_SameSign_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu20_Mu10_SameSign_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_Prescale;   //!
   TBranch        *b_HLT_DoubleMuSS;   //!
   TBranch        *b_HLT_DoubleMuSS_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPTight_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPTight_Gsf_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Ele45_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_Prescale;   //!
   TBranch        *b_HLT_SingleEl;   //!
   TBranch        *b_HLT_SingleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v;   //!
   TBranch        *b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_Prescale;   //!
   TBranch        *b_HLT_TripleMuA;   //!
   TBranch        *b_HLT_TripleMuA_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_Prescale;   //!
   TBranch        *b_HLT_SOSHighMET;   //!
   TBranch        *b_HLT_SOSHighMET_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu3_PFMET50_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu3_PFMET50_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu3_PFMET50_v_Prescale;   //!
   TBranch        *b_HLT_SOSDoubleMuLowMET;   //!
   TBranch        *b_HLT_SOSDoubleMuLowMET_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_Prescale;   //!
   TBranch        *b_HLT_MuEG;   //!
   TBranch        *b_HLT_MuEG_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_Prescale;   //!
   TBranch        *b_HLT_DoubleMuHT;   //!
   TBranch        *b_HLT_DoubleMuHT_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale;   //!
   TBranch        *b_HLT_DoubleEl;   //!
   TBranch        *b_HLT_DoubleEl_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_Prescale;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_Prescale;   //!
   TBranch        *b_HLT_DoubleMu;   //!
   TBranch        *b_HLT_DoubleMu_isUnprescaled;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_trackingFailureFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_CSCTightHalo2015Filter;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_Flag_globalTightHalo2016Filter;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_eta;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_mass;   //!
   TBranch        *b_met_sumEt;   //!
   TBranch        *b_met_rawPt;   //!
   TBranch        *b_met_rawPhi;   //!
   TBranch        *b_met_rawSumEt;   //!
   TBranch        *b_met_genPt;   //!
   TBranch        *b_met_genPhi;   //!
   TBranch        *b_met_genEta;   //!
   TBranch        *b_met_jecUp_pt;   //!
   TBranch        *b_met_jecUp_eta;   //!
   TBranch        *b_met_jecUp_phi;   //!
   TBranch        *b_met_jecUp_mass;   //!
   TBranch        *b_met_jecUp_sumEt;   //!
   TBranch        *b_met_jecUp_rawPt;   //!
   TBranch        *b_met_jecUp_rawPhi;   //!
   TBranch        *b_met_jecUp_rawSumEt;   //!
   TBranch        *b_met_jecUp_genPt;   //!
   TBranch        *b_met_jecUp_genPhi;   //!
   TBranch        *b_met_jecUp_genEta;   //!
   TBranch        *b_met_jecDown_pt;   //!
   TBranch        *b_met_jecDown_eta;   //!
   TBranch        *b_met_jecDown_phi;   //!
   TBranch        *b_met_jecDown_mass;   //!
   TBranch        *b_met_jecDown_sumEt;   //!
   TBranch        *b_met_jecDown_rawPt;   //!
   TBranch        *b_met_jecDown_rawPhi;   //!
   TBranch        *b_met_jecDown_rawSumEt;   //!
   TBranch        *b_met_jecDown_genPt;   //!
   TBranch        *b_met_jecDown_genPhi;   //!
   TBranch        *b_met_jecDown_genEta;   //!
   TBranch        *b_nFatJet;   //!
   TBranch        *b_FatJet_id;   //!
   TBranch        *b_FatJet_puId;   //!
   TBranch        *b_FatJet_btagCSV;   //!
   TBranch        *b_FatJet_btagCMVA;   //!
   TBranch        *b_FatJet_rawPt;   //!
   TBranch        *b_FatJet_mcPt;   //!
   TBranch        *b_FatJet_mcFlavour;   //!
   TBranch        *b_FatJet_partonFlavour;   //!
   TBranch        *b_FatJet_hadronFlavour;   //!
   TBranch        *b_FatJet_mcMatchId;   //!
   TBranch        *b_FatJet_corr_JECUp;   //!
   TBranch        *b_FatJet_corr_JECDown;   //!
   TBranch        *b_FatJet_corr;   //!
   TBranch        *b_FatJet_corr_JERUp;   //!
   TBranch        *b_FatJet_corr_JERDown;   //!
   TBranch        *b_FatJet_corr_JER;   //!
   TBranch        *b_FatJet_pt;   //!
   TBranch        *b_FatJet_eta;   //!
   TBranch        *b_FatJet_phi;   //!
   TBranch        *b_FatJet_mass;   //!
   TBranch        *b_FatJet_prunedMass;   //!
   TBranch        *b_FatJet_softDropMass;   //!
   TBranch        *b_FatJet_tau1;   //!
   TBranch        *b_FatJet_tau2;   //!
   TBranch        *b_FatJet_tau3;   //!
   TBranch        *b_FatJet_topMass;   //!
   TBranch        *b_FatJet_minMass;   //!
   TBranch        *b_FatJet_nSubJets;   //!
   TBranch        *b_nDiscLep;   //!
   TBranch        *b_DiscLep_charge;   //!
   TBranch        *b_DiscLep_tightId;   //!
   TBranch        *b_DiscLep_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_DiscLep_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_DiscLep_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_DiscLep_dxy;   //!
   TBranch        *b_DiscLep_dz;   //!
   TBranch        *b_DiscLep_edxy;   //!
   TBranch        *b_DiscLep_edz;   //!
   TBranch        *b_DiscLep_ip3d;   //!
   TBranch        *b_DiscLep_sip3d;   //!
   TBranch        *b_DiscLep_convVeto;   //!
   TBranch        *b_DiscLep_lostHits;   //!
   TBranch        *b_DiscLep_relIso03;   //!
   TBranch        *b_DiscLep_relIso04;   //!
   TBranch        *b_DiscLep_miniRelIso;   //!
   TBranch        *b_DiscLep_relIsoAn04;   //!
   TBranch        *b_DiscLep_tightCharge;   //!
   TBranch        *b_DiscLep_mcMatchId;   //!
   TBranch        *b_DiscLep_mcMatchAny;   //!
   TBranch        *b_DiscLep_mcMatchTau;   //!
   TBranch        *b_DiscLep_mcPt;   //!
   TBranch        *b_DiscLep_mediumMuonId;   //!
   TBranch        *b_DiscLep_ICHEPsoftMuonId;   //!
   TBranch        *b_DiscLep_ICHEPmediumMuonId;   //!
   TBranch        *b_DiscLep_pdgId;   //!
   TBranch        *b_DiscLep_pt;   //!
   TBranch        *b_DiscLep_eta;   //!
   TBranch        *b_DiscLep_phi;   //!
   TBranch        *b_DiscLep_mass;   //!
   TBranch        *b_DiscLep_mvaIdSpring15;   //!
   TBranch        *b_DiscLep_mvaTTH;   //!
   TBranch        *b_DiscLep_mvaSUSY;   //!
   TBranch        *b_DiscLep_mvaSoftT2tt;   //!
   TBranch        *b_DiscLep_mvaSoftEWK;   //!
   TBranch        *b_DiscLep_jetPtRatiov1;   //!
   TBranch        *b_DiscLep_jetPtRelv1;   //!
   TBranch        *b_DiscLep_jetPtRatiov2;   //!
   TBranch        *b_DiscLep_jetPtRelv2;   //!
   TBranch        *b_DiscLep_jetBTagCSV;   //!
   TBranch        *b_DiscLep_jetBTagCMVA;   //!
   TBranch        *b_DiscLep_jetDR;   //!
   TBranch        *b_DiscLep_r9;   //!
   TBranch        *b_DiscLep_mvaIdSpring16;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_motherId;   //!
   TBranch        *b_GenPart_grandmotherId;   //!
   TBranch        *b_GenPart_sourceId;   //!
   TBranch        *b_GenPart_charge;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_isPromptHard;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_motherIndex;   //!
   TBranch        *b_nDiscJet;   //!
   TBranch        *b_DiscJet_mcMatchFlav;   //!
   TBranch        *b_DiscJet_charge;   //!
   TBranch        *b_DiscJet_ctagCsvL;   //!
   TBranch        *b_DiscJet_ctagCsvB;   //!
   TBranch        *b_DiscJet_area;   //!
   TBranch        *b_DiscJet_qgl;   //!
   TBranch        *b_DiscJet_ptd;   //!
   TBranch        *b_DiscJet_axis2;   //!
   TBranch        *b_DiscJet_mult;   //!
   TBranch        *b_DiscJet_partonId;   //!
   TBranch        *b_DiscJet_partonMotherId;   //!
   TBranch        *b_DiscJet_nLeptons;   //!
   TBranch        *b_DiscJet_id;   //!
   TBranch        *b_DiscJet_puId;   //!
   TBranch        *b_DiscJet_btagCSV;   //!
   TBranch        *b_DiscJet_btagCMVA;   //!
   TBranch        *b_DiscJet_rawPt;   //!
   TBranch        *b_DiscJet_mcPt;   //!
   TBranch        *b_DiscJet_mcFlavour;   //!
   TBranch        *b_DiscJet_partonFlavour;   //!
   TBranch        *b_DiscJet_hadronFlavour;   //!
   TBranch        *b_DiscJet_mcMatchId;   //!
   TBranch        *b_DiscJet_corr_JECUp;   //!
   TBranch        *b_DiscJet_corr_JECDown;   //!
   TBranch        *b_DiscJet_corr;   //!
   TBranch        *b_DiscJet_corr_JERUp;   //!
   TBranch        *b_DiscJet_corr_JERDown;   //!
   TBranch        *b_DiscJet_corr_JER;   //!
   TBranch        *b_DiscJet_pt;   //!
   TBranch        *b_DiscJet_eta;   //!
   TBranch        *b_DiscJet_phi;   //!
   TBranch        *b_DiscJet_mass;   //!
   TBranch        *b_DiscJet_CorrFactor_L1;   //!
   TBranch        *b_DiscJet_CorrFactor_L1L2;   //!
   TBranch        *b_DiscJet_CorrFactor_L1L2L3;   //!
   TBranch        *b_DiscJet_CorrFactor_L1L2L3Res;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_charge;   //!
   TBranch        *b_SV_ntracks;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_dxy;   //!
   TBranch        *b_SV_edxy;   //!
   TBranch        *b_SV_ip3d;   //!
   TBranch        *b_SV_eip3d;   //!
   TBranch        *b_SV_sip3d;   //!
   TBranch        *b_SV_cosTheta;   //!
   TBranch        *b_SV_mva;   //!
   TBranch        *b_SV_jetPt;   //!
   TBranch        *b_SV_jetEta;   //!
   TBranch        *b_SV_jetDR;   //!
   TBranch        *b_SV_jetBTagCSV;   //!
   TBranch        *b_SV_jetBTagCMVA;   //!
   TBranch        *b_SV_mcMatchNTracks;   //!
   TBranch        *b_SV_mcMatchNTracksHF;   //!
   TBranch        *b_SV_mcMatchFraction;   //!
   TBranch        *b_SV_mcFlavFirst;   //!
   TBranch        *b_SV_mcFlavHeaviest;   //!
   TBranch        *b_SV_maxDxyTracks;   //!
   TBranch        *b_SV_secDxyTracks;   //!
   TBranch        *b_SV_maxD3dTracks;   //!
   TBranch        *b_SV_secD3dTracks;   //!
   TBranch        *b_nTauOther;   //!
   TBranch        *b_TauOther_charge;   //!
   TBranch        *b_TauOther_decayMode;   //!
   TBranch        *b_TauOther_idDecayMode;   //!
   TBranch        *b_TauOther_idDecayModeNewDMs;   //!
   TBranch        *b_TauOther_dxy;   //!
   TBranch        *b_TauOther_dz;   //!
   TBranch        *b_TauOther_idMVA;   //!
   TBranch        *b_TauOther_idMVANewDM;   //!
   TBranch        *b_TauOther_idCI3hit;   //!
   TBranch        *b_TauOther_idAntiMu;   //!
   TBranch        *b_TauOther_idAntiE;   //!
   TBranch        *b_TauOther_isoCI3hit;   //!
   TBranch        *b_TauOther_mcMatchId;   //!
   TBranch        *b_TauOther_pdgId;   //!
   TBranch        *b_TauOther_pt;   //!
   TBranch        *b_TauOther_eta;   //!
   TBranch        *b_TauOther_phi;   //!
   TBranch        *b_TauOther_mass;   //!
   TBranch        *b_TauOther_idMVAOldDMRun2;   //!
   TBranch        *b_TauOther_idMVAOldDMRun2dR03;   //!
   TBranch        *b_nLepGood;   //!
   TBranch        *b_LepGood_mvaIdSpring15;   //!
   TBranch        *b_LepGood_mvaTTH;   //!
   TBranch        *b_LepGood_mvaSUSY;   //!
   TBranch        *b_LepGood_mvaSoftT2tt;   //!
   TBranch        *b_LepGood_mvaSoftEWK;   //!
   TBranch        *b_LepGood_jetPtRatiov1;   //!
   TBranch        *b_LepGood_jetPtRelv1;   //!
   TBranch        *b_LepGood_jetPtRatiov2;   //!
   TBranch        *b_LepGood_jetPtRelv2;   //!
   TBranch        *b_LepGood_jetBTagCSV;   //!
   TBranch        *b_LepGood_jetBTagCMVA;   //!
   TBranch        *b_LepGood_jetDR;   //!
   TBranch        *b_LepGood_r9;   //!
   TBranch        *b_LepGood_mvaIdSpring16;   //!
   TBranch        *b_LepGood_charge;   //!
   TBranch        *b_LepGood_tightId;   //!
   TBranch        *b_LepGood_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_LepGood_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_LepGood_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_LepGood_dxy;   //!
   TBranch        *b_LepGood_dz;   //!
   TBranch        *b_LepGood_edxy;   //!
   TBranch        *b_LepGood_edz;   //!
   TBranch        *b_LepGood_ip3d;   //!
   TBranch        *b_LepGood_sip3d;   //!
   TBranch        *b_LepGood_convVeto;   //!
   TBranch        *b_LepGood_lostHits;   //!
   TBranch        *b_LepGood_relIso03;   //!
   TBranch        *b_LepGood_relIso04;   //!
   TBranch        *b_LepGood_miniRelIso;   //!
   TBranch        *b_LepGood_relIsoAn04;   //!
   TBranch        *b_LepGood_tightCharge;   //!
   TBranch        *b_LepGood_mcMatchId;   //!
   TBranch        *b_LepGood_mcMatchAny;   //!
   TBranch        *b_LepGood_mcMatchTau;   //!
   TBranch        *b_LepGood_mcPt;   //!
   TBranch        *b_LepGood_mediumMuonId;   //!
   TBranch        *b_LepGood_ICHEPsoftMuonId;   //!
   TBranch        *b_LepGood_ICHEPmediumMuonId;   //!
   TBranch        *b_LepGood_pdgId;   //!
   TBranch        *b_LepGood_pt;   //!
   TBranch        *b_LepGood_eta;   //!
   TBranch        *b_LepGood_phi;   //!
   TBranch        *b_LepGood_mass;   //!
   TBranch        *b_LepGood_looseIdOnly;   //!
   TBranch        *b_LepGood_chargedHadRelIso03;   //!
   TBranch        *b_LepGood_chargedHadRelIso04;   //!
   TBranch        *b_LepGood_softMuonId;   //!
   TBranch        *b_LepGood_pfMuonId;   //!
   TBranch        *b_LepGood_eleCutId2012_full5x5;   //!
   TBranch        *b_LepGood_trackerLayers;   //!
   TBranch        *b_LepGood_pixelLayers;   //!
   TBranch        *b_LepGood_trackerHits;   //!
   TBranch        *b_LepGood_lostOuterHits;   //!
   TBranch        *b_LepGood_innerTrackValidHitFraction;   //!
   TBranch        *b_LepGood_innerTrackChi2;   //!
   TBranch        *b_LepGood_nStations;   //!
   TBranch        *b_LepGood_caloCompatibility;   //!
   TBranch        *b_LepGood_globalTrackChi2;   //!
   TBranch        *b_LepGood_trkKink;   //!
   TBranch        *b_LepGood_segmentCompatibility;   //!
   TBranch        *b_LepGood_chi2LocalPosition;   //!
   TBranch        *b_LepGood_chi2LocalMomentum;   //!
   TBranch        *b_LepGood_glbTrackProbability;   //!
   TBranch        *b_LepGood_TMOneStationTightMuonId;   //!
   TBranch        *b_LepGood_trackHighPurityMuon;   //!
   TBranch        *b_LepGood_isGlobalMuon;   //!
   TBranch        *b_LepGood_isTrackerMuon;   //!
   TBranch        *b_LepGood_sigmaIEtaIEta;   //!
   TBranch        *b_LepGood_dEtaScTrkIn;   //!
   TBranch        *b_LepGood_dPhiScTrkIn;   //!
   TBranch        *b_LepGood_hadronicOverEm;   //!
   TBranch        *b_LepGood_eInvMinusPInv;   //!
   TBranch        *b_LepGood_eInvMinusPInv_tkMom;   //!
   TBranch        *b_LepGood_etaSc;   //!
   TBranch        *b_LepGood_mcMatchPdgId;   //!
   TBranch        *b_LepGood_miniRelIsoCharged;   //!
   TBranch        *b_LepGood_miniRelIsoNeutral;   //!
   TBranch        *b_LepGood_jetNDauChargedMVASel;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2L3;   //!
   TBranch        *b_LepGood_jetCorrFactor_L1L2L3Res;   //!
   TBranch        *b_LepGood_ecalPFClusterIso;   //!
   TBranch        *b_LepGood_hcalPFClusterIso;   //!
   TBranch        *b_LepGood_dr03TkSumPt;   //!
   TBranch        *b_LepGood_trackIso;   //!
   TBranch        *b_LepGood_idEmuTTH;   //!
   TBranch        *b_LepGood_idEmuRA5;   //!
   TBranch        *b_LepGood_idIsoEmuRA5;   //!
   TBranch        *b_LepGood_mcPrompt;   //!
   TBranch        *b_LepGood_mcPromptTau;   //!
   TBranch        *b_LepGood_mcPromptGamma;   //!
   TBranch        *b_LepGood_mcGamma;   //!
   TBranch        *b_LepGood_RelIsoMIV03;   //!
   TBranch        *b_LepGood_RelIsoMIVCharged03;   //!
   TBranch        *b_LepGood_RelIsoMIVNeutral03;   //!
   TBranch        *b_LepGood_RelIsoMIV04;   //!
   TBranch        *b_LepGood_RelIsoMIVCharged04;   //!
   TBranch        *b_LepGood_RelIsoMIVNeutral04;   //!
   TBranch        *b_LepGood_jetPtRelHv2;   //!
   TBranch        *b_LepGood_isoRelH04;   //!
   TBranch        *b_LepGood_jetBasedRelIsoCharged;   //!
   TBranch        *b_LepGood_hasSV;   //!
   TBranch        *b_LepGood_svSip3d;   //!
   TBranch        *b_LepGood_svRedPt;   //!
   TBranch        *b_LepGood_svMass;   //!
   TBranch        *b_LepGood_svNTracks;   //!
   TBranch        *b_LepGood_mcUCSXMatchId;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_pt;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_eta;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_phi;   //!
   TBranch        *b_LepGood_jetLepAwareJEC_energy;   //!
   TBranch        *b_nDiscJet_jecDown;   //!
   TBranch        *b_DiscJet_jecDown_mcMatchFlav;   //!
   TBranch        *b_DiscJet_jecDown_charge;   //!
   TBranch        *b_DiscJet_jecDown_ctagCsvL;   //!
   TBranch        *b_DiscJet_jecDown_ctagCsvB;   //!
   TBranch        *b_DiscJet_jecDown_area;   //!
   TBranch        *b_DiscJet_jecDown_qgl;   //!
   TBranch        *b_DiscJet_jecDown_ptd;   //!
   TBranch        *b_DiscJet_jecDown_axis2;   //!
   TBranch        *b_DiscJet_jecDown_mult;   //!
   TBranch        *b_DiscJet_jecDown_partonId;   //!
   TBranch        *b_DiscJet_jecDown_partonMotherId;   //!
   TBranch        *b_DiscJet_jecDown_nLeptons;   //!
   TBranch        *b_DiscJet_jecDown_id;   //!
   TBranch        *b_DiscJet_jecDown_puId;   //!
   TBranch        *b_DiscJet_jecDown_btagCSV;   //!
   TBranch        *b_DiscJet_jecDown_btagCMVA;   //!
   TBranch        *b_DiscJet_jecDown_rawPt;   //!
   TBranch        *b_DiscJet_jecDown_mcPt;   //!
   TBranch        *b_DiscJet_jecDown_mcFlavour;   //!
   TBranch        *b_DiscJet_jecDown_partonFlavour;   //!
   TBranch        *b_DiscJet_jecDown_hadronFlavour;   //!
   TBranch        *b_DiscJet_jecDown_mcMatchId;   //!
   TBranch        *b_DiscJet_jecDown_corr_JECUp;   //!
   TBranch        *b_DiscJet_jecDown_corr_JECDown;   //!
   TBranch        *b_DiscJet_jecDown_corr;   //!
   TBranch        *b_DiscJet_jecDown_corr_JERUp;   //!
   TBranch        *b_DiscJet_jecDown_corr_JERDown;   //!
   TBranch        *b_DiscJet_jecDown_corr_JER;   //!
   TBranch        *b_DiscJet_jecDown_pt;   //!
   TBranch        *b_DiscJet_jecDown_eta;   //!
   TBranch        *b_DiscJet_jecDown_phi;   //!
   TBranch        *b_DiscJet_jecDown_mass;   //!
   TBranch        *b_DiscJet_jecDown_CorrFactor_L1;   //!
   TBranch        *b_DiscJet_jecDown_CorrFactor_L1L2;   //!
   TBranch        *b_DiscJet_jecDown_CorrFactor_L1L2L3;   //!
   TBranch        *b_DiscJet_jecDown_CorrFactor_L1L2L3Res;   //!
   TBranch        *b_nJet_jecUp;   //!
   TBranch        *b_Jet_jecUp_mcMatchFlav;   //!
   TBranch        *b_Jet_jecUp_charge;   //!
   TBranch        *b_Jet_jecUp_ctagCsvL;   //!
   TBranch        *b_Jet_jecUp_ctagCsvB;   //!
   TBranch        *b_Jet_jecUp_area;   //!
   TBranch        *b_Jet_jecUp_qgl;   //!
   TBranch        *b_Jet_jecUp_ptd;   //!
   TBranch        *b_Jet_jecUp_axis2;   //!
   TBranch        *b_Jet_jecUp_mult;   //!
   TBranch        *b_Jet_jecUp_partonId;   //!
   TBranch        *b_Jet_jecUp_partonMotherId;   //!
   TBranch        *b_Jet_jecUp_nLeptons;   //!
   TBranch        *b_Jet_jecUp_id;   //!
   TBranch        *b_Jet_jecUp_puId;   //!
   TBranch        *b_Jet_jecUp_btagCSV;   //!
   TBranch        *b_Jet_jecUp_btagCMVA;   //!
   TBranch        *b_Jet_jecUp_rawPt;   //!
   TBranch        *b_Jet_jecUp_mcPt;   //!
   TBranch        *b_Jet_jecUp_mcFlavour;   //!
   TBranch        *b_Jet_jecUp_partonFlavour;   //!
   TBranch        *b_Jet_jecUp_hadronFlavour;   //!
   TBranch        *b_Jet_jecUp_mcMatchId;   //!
   TBranch        *b_Jet_jecUp_corr_JECUp;   //!
   TBranch        *b_Jet_jecUp_corr_JECDown;   //!
   TBranch        *b_Jet_jecUp_corr;   //!
   TBranch        *b_Jet_jecUp_corr_JERUp;   //!
   TBranch        *b_Jet_jecUp_corr_JERDown;   //!
   TBranch        *b_Jet_jecUp_corr_JER;   //!
   TBranch        *b_Jet_jecUp_pt;   //!
   TBranch        *b_Jet_jecUp_eta;   //!
   TBranch        *b_Jet_jecUp_phi;   //!
   TBranch        *b_Jet_jecUp_mass;   //!
   TBranch        *b_Jet_jecUp_CorrFactor_L1;   //!
   TBranch        *b_Jet_jecUp_CorrFactor_L1L2;   //!
   TBranch        *b_Jet_jecUp_CorrFactor_L1L2L3;   //!
   TBranch        *b_Jet_jecUp_CorrFactor_L1L2L3Res;   //!
   TBranch        *b_nGenDHad;   //!
   TBranch        *b_GenDHad_charge;   //!
   TBranch        *b_GenDHad_status;   //!
   TBranch        *b_GenDHad_isPromptHard;   //!
   TBranch        *b_GenDHad_pdgId;   //!
   TBranch        *b_GenDHad_pt;   //!
   TBranch        *b_GenDHad_eta;   //!
   TBranch        *b_GenDHad_phi;   //!
   TBranch        *b_GenDHad_mass;   //!
   TBranch        *b_GenDHad_flav;   //!
   TBranch        *b_GenDHad_sourceId;   //!
   TBranch        *b_GenDHad_svMass;   //!
   TBranch        *b_GenDHad_svPt;   //!
   TBranch        *b_GenDHad_svCharge;   //!
   TBranch        *b_GenDHad_svNtracks;   //!
   TBranch        *b_GenDHad_svChi2;   //!
   TBranch        *b_GenDHad_svNdof;   //!
   TBranch        *b_GenDHad_svDxy;   //!
   TBranch        *b_GenDHad_svEdxy;   //!
   TBranch        *b_GenDHad_svIp3d;   //!
   TBranch        *b_GenDHad_svEip3d;   //!
   TBranch        *b_GenDHad_svSip3d;   //!
   TBranch        *b_GenDHad_svCosTheta;   //!
   TBranch        *b_GenDHad_svMva;   //!
   TBranch        *b_GenDHad_jetPt;   //!
   TBranch        *b_GenDHad_jetBTagCSV;   //!
   TBranch        *b_GenDHad_jetBTagCMVA;   //!
   TBranch        *b_nGenBHad;   //!
   TBranch        *b_GenBHad_charge;   //!
   TBranch        *b_GenBHad_status;   //!
   TBranch        *b_GenBHad_isPromptHard;   //!
   TBranch        *b_GenBHad_pdgId;   //!
   TBranch        *b_GenBHad_pt;   //!
   TBranch        *b_GenBHad_eta;   //!
   TBranch        *b_GenBHad_phi;   //!
   TBranch        *b_GenBHad_mass;   //!
   TBranch        *b_GenBHad_flav;   //!
   TBranch        *b_GenBHad_sourceId;   //!
   TBranch        *b_GenBHad_svMass;   //!
   TBranch        *b_GenBHad_svPt;   //!
   TBranch        *b_GenBHad_svCharge;   //!
   TBranch        *b_GenBHad_svNtracks;   //!
   TBranch        *b_GenBHad_svChi2;   //!
   TBranch        *b_GenBHad_svNdof;   //!
   TBranch        *b_GenBHad_svDxy;   //!
   TBranch        *b_GenBHad_svEdxy;   //!
   TBranch        *b_GenBHad_svIp3d;   //!
   TBranch        *b_GenBHad_svEip3d;   //!
   TBranch        *b_GenBHad_svSip3d;   //!
   TBranch        *b_GenBHad_svCosTheta;   //!
   TBranch        *b_GenBHad_svMva;   //!
   TBranch        *b_GenBHad_jetPt;   //!
   TBranch        *b_GenBHad_jetBTagCSV;   //!
   TBranch        *b_GenBHad_jetBTagCMVA;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_mcMatchFlav;   //!
   TBranch        *b_Jet_charge;   //!
   TBranch        *b_Jet_ctagCsvL;   //!
   TBranch        *b_Jet_ctagCsvB;   //!
   TBranch        *b_Jet_area;   //!
   TBranch        *b_Jet_qgl;   //!
   TBranch        *b_Jet_ptd;   //!
   TBranch        *b_Jet_axis2;   //!
   TBranch        *b_Jet_mult;   //!
   TBranch        *b_Jet_partonId;   //!
   TBranch        *b_Jet_partonMotherId;   //!
   TBranch        *b_Jet_nLeptons;   //!
   TBranch        *b_Jet_id;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_Jet_btagCSV;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_rawPt;   //!
   TBranch        *b_Jet_mcPt;   //!
   TBranch        *b_Jet_mcFlavour;   //!
   TBranch        *b_Jet_partonFlavour;   //!
   TBranch        *b_Jet_hadronFlavour;   //!
   TBranch        *b_Jet_mcMatchId;   //!
   TBranch        *b_Jet_corr_JECUp;   //!
   TBranch        *b_Jet_corr_JECDown;   //!
   TBranch        *b_Jet_corr;   //!
   TBranch        *b_Jet_corr_JERUp;   //!
   TBranch        *b_Jet_corr_JERDown;   //!
   TBranch        *b_Jet_corr_JER;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_CorrFactor_L1;   //!
   TBranch        *b_Jet_CorrFactor_L1L2;   //!
   TBranch        *b_Jet_CorrFactor_L1L2L3;   //!
   TBranch        *b_Jet_CorrFactor_L1L2L3Res;   //!
   TBranch        *b_nJetNoTauIdx;   //!
   TBranch        *b_JetNoTauIdx;   //!
   TBranch        *b_nLHEweight;   //!
   TBranch        *b_LHEweight_id;   //!
   TBranch        *b_LHEweight_wgt;   //!
   TBranch        *b_nTauGood;   //!
   TBranch        *b_TauGood_charge;   //!
   TBranch        *b_TauGood_decayMode;   //!
   TBranch        *b_TauGood_idDecayMode;   //!
   TBranch        *b_TauGood_idDecayModeNewDMs;   //!
   TBranch        *b_TauGood_dxy;   //!
   TBranch        *b_TauGood_dz;   //!
   TBranch        *b_TauGood_idMVA;   //!
   TBranch        *b_TauGood_idMVANewDM;   //!
   TBranch        *b_TauGood_idCI3hit;   //!
   TBranch        *b_TauGood_idAntiMu;   //!
   TBranch        *b_TauGood_idAntiE;   //!
   TBranch        *b_TauGood_isoCI3hit;   //!
   TBranch        *b_TauGood_mcMatchId;   //!
   TBranch        *b_TauGood_pdgId;   //!
   TBranch        *b_TauGood_pt;   //!
   TBranch        *b_TauGood_eta;   //!
   TBranch        *b_TauGood_phi;   //!
   TBranch        *b_TauGood_mass;   //!
   TBranch        *b_TauGood_idMVAOldDMRun2;   //!
   TBranch        *b_TauGood_idMVAOldDMRun2dR03;   //!
   TBranch        *b_ngenLep;   //!
   TBranch        *b_genLep_motherId;   //!
   TBranch        *b_genLep_grandmotherId;   //!
   TBranch        *b_genLep_sourceId;   //!
   TBranch        *b_genLep_charge;   //!
   TBranch        *b_genLep_status;   //!
   TBranch        *b_genLep_isPromptHard;   //!
   TBranch        *b_genLep_pdgId;   //!
   TBranch        *b_genLep_pt;   //!
   TBranch        *b_genLep_eta;   //!
   TBranch        *b_genLep_phi;   //!
   TBranch        *b_genLep_mass;   //!
   TBranch        *b_genLep_motherIndex;   //!
   TBranch        *b_ngenTau;   //!
   TBranch        *b_genTau_motherId;   //!
   TBranch        *b_genTau_grandmotherId;   //!
   TBranch        *b_genTau_sourceId;   //!
   TBranch        *b_genTau_charge;   //!
   TBranch        *b_genTau_status;   //!
   TBranch        *b_genTau_isPromptHard;   //!
   TBranch        *b_genTau_pdgId;   //!
   TBranch        *b_genTau_pt;   //!
   TBranch        *b_genTau_eta;   //!
   TBranch        *b_genTau_phi;   //!
   TBranch        *b_genTau_mass;   //!
   TBranch        *b_genTau_motherIndex;   //!
   TBranch        *b_nJet_jecDown;   //!
   TBranch        *b_Jet_jecDown_mcMatchFlav;   //!
   TBranch        *b_Jet_jecDown_charge;   //!
   TBranch        *b_Jet_jecDown_ctagCsvL;   //!
   TBranch        *b_Jet_jecDown_ctagCsvB;   //!
   TBranch        *b_Jet_jecDown_area;   //!
   TBranch        *b_Jet_jecDown_qgl;   //!
   TBranch        *b_Jet_jecDown_ptd;   //!
   TBranch        *b_Jet_jecDown_axis2;   //!
   TBranch        *b_Jet_jecDown_mult;   //!
   TBranch        *b_Jet_jecDown_partonId;   //!
   TBranch        *b_Jet_jecDown_partonMotherId;   //!
   TBranch        *b_Jet_jecDown_nLeptons;   //!
   TBranch        *b_Jet_jecDown_id;   //!
   TBranch        *b_Jet_jecDown_puId;   //!
   TBranch        *b_Jet_jecDown_btagCSV;   //!
   TBranch        *b_Jet_jecDown_btagCMVA;   //!
   TBranch        *b_Jet_jecDown_rawPt;   //!
   TBranch        *b_Jet_jecDown_mcPt;   //!
   TBranch        *b_Jet_jecDown_mcFlavour;   //!
   TBranch        *b_Jet_jecDown_partonFlavour;   //!
   TBranch        *b_Jet_jecDown_hadronFlavour;   //!
   TBranch        *b_Jet_jecDown_mcMatchId;   //!
   TBranch        *b_Jet_jecDown_corr_JECUp;   //!
   TBranch        *b_Jet_jecDown_corr_JECDown;   //!
   TBranch        *b_Jet_jecDown_corr;   //!
   TBranch        *b_Jet_jecDown_corr_JERUp;   //!
   TBranch        *b_Jet_jecDown_corr_JERDown;   //!
   TBranch        *b_Jet_jecDown_corr_JER;   //!
   TBranch        *b_Jet_jecDown_pt;   //!
   TBranch        *b_Jet_jecDown_eta;   //!
   TBranch        *b_Jet_jecDown_phi;   //!
   TBranch        *b_Jet_jecDown_mass;   //!
   TBranch        *b_Jet_jecDown_CorrFactor_L1;   //!
   TBranch        *b_Jet_jecDown_CorrFactor_L1L2;   //!
   TBranch        *b_Jet_jecDown_CorrFactor_L1L2L3;   //!
   TBranch        *b_Jet_jecDown_CorrFactor_L1L2L3Res;   //!
   TBranch        *b_nGenTop;   //!
   TBranch        *b_GenTop_pdgId;   //!
   TBranch        *b_GenTop_pt;   //!
   TBranch        *b_GenTop_eta;   //!
   TBranch        *b_GenTop_phi;   //!
   TBranch        *b_GenTop_mass;   //!
   TBranch        *b_GenTop_charge;   //!
   TBranch        *b_GenTop_status;   //!
   TBranch        *b_GenTop_isPromptHard;   //!
   TBranch        *b_nLepOther;   //!
   TBranch        *b_LepOther_charge;   //!
   TBranch        *b_LepOther_tightId;   //!
   TBranch        *b_LepOther_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_LepOther_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_LepOther_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_LepOther_dxy;   //!
   TBranch        *b_LepOther_dz;   //!
   TBranch        *b_LepOther_edxy;   //!
   TBranch        *b_LepOther_edz;   //!
   TBranch        *b_LepOther_ip3d;   //!
   TBranch        *b_LepOther_sip3d;   //!
   TBranch        *b_LepOther_convVeto;   //!
   TBranch        *b_LepOther_lostHits;   //!
   TBranch        *b_LepOther_relIso03;   //!
   TBranch        *b_LepOther_relIso04;   //!
   TBranch        *b_LepOther_miniRelIso;   //!
   TBranch        *b_LepOther_relIsoAn04;   //!
   TBranch        *b_LepOther_tightCharge;   //!
   TBranch        *b_LepOther_mcMatchId;   //!
   TBranch        *b_LepOther_mcMatchAny;   //!
   TBranch        *b_LepOther_mcMatchTau;   //!
   TBranch        *b_LepOther_mcPt;   //!
   TBranch        *b_LepOther_mediumMuonId;   //!
   TBranch        *b_LepOther_ICHEPsoftMuonId;   //!
   TBranch        *b_LepOther_ICHEPmediumMuonId;   //!
   TBranch        *b_LepOther_pdgId;   //!
   TBranch        *b_LepOther_pt;   //!
   TBranch        *b_LepOther_eta;   //!
   TBranch        *b_LepOther_phi;   //!
   TBranch        *b_LepOther_mass;   //!
   TBranch        *b_LepOther_mvaIdSpring15;   //!
   TBranch        *b_LepOther_mvaTTH;   //!
   TBranch        *b_LepOther_mvaSUSY;   //!
   TBranch        *b_LepOther_mvaSoftT2tt;   //!
   TBranch        *b_LepOther_mvaSoftEWK;   //!
   TBranch        *b_LepOther_jetPtRatiov1;   //!
   TBranch        *b_LepOther_jetPtRelv1;   //!
   TBranch        *b_LepOther_jetPtRatiov2;   //!
   TBranch        *b_LepOther_jetPtRelv2;   //!
   TBranch        *b_LepOther_jetBTagCSV;   //!
   TBranch        *b_LepOther_jetBTagCMVA;   //!
   TBranch        *b_LepOther_jetDR;   //!
   TBranch        *b_LepOther_r9;   //!
   TBranch        *b_LepOther_mvaIdSpring16;   //!
   TBranch        *b_nDiscJet_jecUp;   //!
   TBranch        *b_DiscJet_jecUp_mcMatchFlav;   //!
   TBranch        *b_DiscJet_jecUp_charge;   //!
   TBranch        *b_DiscJet_jecUp_ctagCsvL;   //!
   TBranch        *b_DiscJet_jecUp_ctagCsvB;   //!
   TBranch        *b_DiscJet_jecUp_area;   //!
   TBranch        *b_DiscJet_jecUp_qgl;   //!
   TBranch        *b_DiscJet_jecUp_ptd;   //!
   TBranch        *b_DiscJet_jecUp_axis2;   //!
   TBranch        *b_DiscJet_jecUp_mult;   //!
   TBranch        *b_DiscJet_jecUp_partonId;   //!
   TBranch        *b_DiscJet_jecUp_partonMotherId;   //!
   TBranch        *b_DiscJet_jecUp_nLeptons;   //!
   TBranch        *b_DiscJet_jecUp_id;   //!
   TBranch        *b_DiscJet_jecUp_puId;   //!
   TBranch        *b_DiscJet_jecUp_btagCSV;   //!
   TBranch        *b_DiscJet_jecUp_btagCMVA;   //!
   TBranch        *b_DiscJet_jecUp_rawPt;   //!
   TBranch        *b_DiscJet_jecUp_mcPt;   //!
   TBranch        *b_DiscJet_jecUp_mcFlavour;   //!
   TBranch        *b_DiscJet_jecUp_partonFlavour;   //!
   TBranch        *b_DiscJet_jecUp_hadronFlavour;   //!
   TBranch        *b_DiscJet_jecUp_mcMatchId;   //!
   TBranch        *b_DiscJet_jecUp_corr_JECUp;   //!
   TBranch        *b_DiscJet_jecUp_corr_JECDown;   //!
   TBranch        *b_DiscJet_jecUp_corr;   //!
   TBranch        *b_DiscJet_jecUp_corr_JERUp;   //!
   TBranch        *b_DiscJet_jecUp_corr_JERDown;   //!
   TBranch        *b_DiscJet_jecUp_corr_JER;   //!
   TBranch        *b_DiscJet_jecUp_pt;   //!
   TBranch        *b_DiscJet_jecUp_eta;   //!
   TBranch        *b_DiscJet_jecUp_phi;   //!
   TBranch        *b_DiscJet_jecUp_mass;   //!
   TBranch        *b_DiscJet_jecUp_CorrFactor_L1;   //!
   TBranch        *b_DiscJet_jecUp_CorrFactor_L1L2;   //!
   TBranch        *b_DiscJet_jecUp_CorrFactor_L1L2L3;   //!
   TBranch        *b_DiscJet_jecUp_CorrFactor_L1L2L3Res;   //!
   TBranch        *b_ngenLepFromTau;   //!
   TBranch        *b_genLepFromTau_motherId;   //!
   TBranch        *b_genLepFromTau_grandmotherId;   //!
   TBranch        *b_genLepFromTau_sourceId;   //!
   TBranch        *b_genLepFromTau_charge;   //!
   TBranch        *b_genLepFromTau_status;   //!
   TBranch        *b_genLepFromTau_isPromptHard;   //!
   TBranch        *b_genLepFromTau_pdgId;   //!
   TBranch        *b_genLepFromTau_pt;   //!
   TBranch        *b_genLepFromTau_eta;   //!
   TBranch        *b_genLepFromTau_phi;   //!
   TBranch        *b_genLepFromTau_mass;   //!
   TBranch        *b_genLepFromTau_motherIndex;   //!
   TBranch        *b_nJetFwd;   //!
   TBranch        *b_JetFwd_area;   //!
   TBranch        *b_JetFwd_qgl;   //!
   TBranch        *b_JetFwd_ptd;   //!
   TBranch        *b_JetFwd_axis2;   //!
   TBranch        *b_JetFwd_mult;   //!
   TBranch        *b_JetFwd_partonId;   //!
   TBranch        *b_JetFwd_partonMotherId;   //!
   TBranch        *b_JetFwd_nLeptons;   //!
   TBranch        *b_JetFwd_id;   //!
   TBranch        *b_JetFwd_puId;   //!
   TBranch        *b_JetFwd_btagCSV;   //!
   TBranch        *b_JetFwd_btagCMVA;   //!
   TBranch        *b_JetFwd_rawPt;   //!
   TBranch        *b_JetFwd_mcPt;   //!
   TBranch        *b_JetFwd_mcFlavour;   //!
   TBranch        *b_JetFwd_partonFlavour;   //!
   TBranch        *b_JetFwd_hadronFlavour;   //!
   TBranch        *b_JetFwd_mcMatchId;   //!
   TBranch        *b_JetFwd_corr_JECUp;   //!
   TBranch        *b_JetFwd_corr_JECDown;   //!
   TBranch        *b_JetFwd_corr;   //!
   TBranch        *b_JetFwd_corr_JERUp;   //!
   TBranch        *b_JetFwd_corr_JERDown;   //!
   TBranch        *b_JetFwd_corr_JER;   //!
   TBranch        *b_JetFwd_pt;   //!
   TBranch        *b_JetFwd_eta;   //!
   TBranch        *b_JetFwd_phi;   //!
   TBranch        *b_JetFwd_mass;   //!
   TBranch        *b_JetFwd_mcMatchFlav;   //!
   TBranch        *b_JetFwd_charge;   //!
   TBranch        *b_JetFwd_ctagCsvL;   //!
   TBranch        *b_JetFwd_ctagCsvB;   //!
   TBranch        *b_nPhoGood;   //!
   TBranch        *b_PhoGood_etaSc;   //!
   TBranch        *b_PhoGood_idCutBased;   //!
   TBranch        *b_PhoGood_hOverE;   //!
   TBranch        *b_PhoGood_r9;   //!
   TBranch        *b_PhoGood_sigmaIetaIeta;   //!
   TBranch        *b_PhoGood_chHadIso04;   //!
   TBranch        *b_PhoGood_chHadIso;   //!
   TBranch        *b_PhoGood_phIso;   //!
   TBranch        *b_PhoGood_neuHadIso;   //!
   TBranch        *b_PhoGood_relIso;   //!
   TBranch        *b_PhoGood_mcMatchId;   //!
   TBranch        *b_PhoGood_mcPt;   //!
   TBranch        *b_PhoGood_pdgId;   //!
   TBranch        *b_PhoGood_pt;   //!
   TBranch        *b_PhoGood_eta;   //!
   TBranch        *b_PhoGood_phi;   //!
   TBranch        *b_PhoGood_mass;   //!
   TBranch        *b_PhoGood_genIso04;   //!
   TBranch        *b_PhoGood_genIso03;   //!
   TBranch        *b_PhoGood_chHadIsoRC04;   //!
   TBranch        *b_PhoGood_chHadIsoRC;   //!
   TBranch        *b_PhoGood_drMinParton;   //!

   MiniTree();
   virtual ~MiniTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};


MiniTree::MiniTree() : fChain(0) { }

MiniTree::~MiniTree() { }

Int_t MiniTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MiniTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}


void MiniTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("nTrueInt", &nTrueInt, &b_nTrueInt);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("rhoCN", &rhoCN, &b_rhoCN);
   fChain->SetBranchAddress("nVert", &nVert, &b_nVert);
   fChain->SetBranchAddress("nJet25", &nJet25, &b_nJet25);
   fChain->SetBranchAddress("nJet25a", &nJet25a, &b_nJet25a);
   fChain->SetBranchAddress("nBJetLoose25", &nBJetLoose25, &b_nBJetLoose25);
   fChain->SetBranchAddress("nBJetMedium25", &nBJetMedium25, &b_nBJetMedium25);
   fChain->SetBranchAddress("nBJetTight25", &nBJetTight25, &b_nBJetTight25);
   fChain->SetBranchAddress("nJet30", &nJet30, &b_nJet30);
   fChain->SetBranchAddress("nJet30a", &nJet30a, &b_nJet30a);
   fChain->SetBranchAddress("nBJetLoose30", &nBJetLoose30, &b_nBJetLoose30);
   fChain->SetBranchAddress("nBJetMedium30", &nBJetMedium30, &b_nBJetMedium30);
   fChain->SetBranchAddress("nBJetTight30", &nBJetTight30, &b_nBJetTight30);
   fChain->SetBranchAddress("nJet40", &nJet40, &b_nJet40);
   fChain->SetBranchAddress("nJet40a", &nJet40a, &b_nJet40a);
   fChain->SetBranchAddress("nBJetLoose40", &nBJetLoose40, &b_nBJetLoose40);
   fChain->SetBranchAddress("nBJetMedium40", &nBJetMedium40, &b_nBJetMedium40);
   fChain->SetBranchAddress("nBJetTight40", &nBJetTight40, &b_nBJetTight40);
   fChain->SetBranchAddress("nLepGood20", &nLepGood20, &b_nLepGood20);
   fChain->SetBranchAddress("nLepGood15", &nLepGood15, &b_nLepGood15);
   fChain->SetBranchAddress("nLepGood10", &nLepGood10, &b_nLepGood10);
   fChain->SetBranchAddress("GenSusyMScan1", &GenSusyMScan1, &b_GenSusyMScan1);
   fChain->SetBranchAddress("GenSusyMScan2", &GenSusyMScan2, &b_GenSusyMScan2);
   fChain->SetBranchAddress("GenSusyMScan3", &GenSusyMScan3, &b_GenSusyMScan3);
   fChain->SetBranchAddress("GenSusyMScan4", &GenSusyMScan4, &b_GenSusyMScan4);
   fChain->SetBranchAddress("GenSusyMGluino", &GenSusyMGluino, &b_GenSusyMGluino);
   fChain->SetBranchAddress("GenSusyMGravitino", &GenSusyMGravitino, &b_GenSusyMGravitino);
   fChain->SetBranchAddress("GenSusyMStop", &GenSusyMStop, &b_GenSusyMStop);
   fChain->SetBranchAddress("GenSusyMSbottom", &GenSusyMSbottom, &b_GenSusyMSbottom);
   fChain->SetBranchAddress("GenSusyMStop2", &GenSusyMStop2, &b_GenSusyMStop2);
   fChain->SetBranchAddress("GenSusyMSbottom2", &GenSusyMSbottom2, &b_GenSusyMSbottom2);
   fChain->SetBranchAddress("GenSusyMSquark", &GenSusyMSquark, &b_GenSusyMSquark);
   fChain->SetBranchAddress("GenSusyMNeutralino", &GenSusyMNeutralino, &b_GenSusyMNeutralino);
   fChain->SetBranchAddress("GenSusyMNeutralino2", &GenSusyMNeutralino2, &b_GenSusyMNeutralino2);
   fChain->SetBranchAddress("GenSusyMNeutralino3", &GenSusyMNeutralino3, &b_GenSusyMNeutralino3);
   fChain->SetBranchAddress("GenSusyMNeutralino4", &GenSusyMNeutralino4, &b_GenSusyMNeutralino4);
   fChain->SetBranchAddress("GenSusyMChargino", &GenSusyMChargino, &b_GenSusyMChargino);
   fChain->SetBranchAddress("GenSusyMChargino2", &GenSusyMChargino2, &b_GenSusyMChargino2);
   fChain->SetBranchAddress("lheHT", &lheHT, &b_lheHT);
   fChain->SetBranchAddress("lheHTIncoming", &lheHTIncoming, &b_lheHTIncoming);
   fChain->SetBranchAddress("htJet25", &htJet25, &b_htJet25);
   fChain->SetBranchAddress("mhtJet25", &mhtJet25, &b_mhtJet25);
   fChain->SetBranchAddress("htJet40j", &htJet40j, &b_htJet40j);
   fChain->SetBranchAddress("htJet40ja", &htJet40ja, &b_htJet40ja);
   fChain->SetBranchAddress("htJet40", &htJet40, &b_htJet40);
   fChain->SetBranchAddress("htJet40a", &htJet40a, &b_htJet40a);
   fChain->SetBranchAddress("mhtJet40", &mhtJet40, &b_mhtJet40);
   fChain->SetBranchAddress("mhtJet40a", &mhtJet40a, &b_mhtJet40a);
   fChain->SetBranchAddress("nJet25NoTau", &nJet25NoTau, &b_nJet25NoTau);
   fChain->SetBranchAddress("nBJetLoose25NoTau", &nBJetLoose25NoTau, &b_nBJetLoose25NoTau);
   fChain->SetBranchAddress("nBJetMedium25NoTau", &nBJetMedium25NoTau, &b_nBJetMedium25NoTau);
   fChain->SetBranchAddress("nBJetCMVALoose25", &nBJetCMVALoose25, &b_nBJetCMVALoose25);
   fChain->SetBranchAddress("nBJetCMVAMedium25", &nBJetCMVAMedium25, &b_nBJetCMVAMedium25);
   fChain->SetBranchAddress("nBJetCMVATight25", &nBJetCMVATight25, &b_nBJetCMVATight25);
   fChain->SetBranchAddress("nSoftBLoose25", &nSoftBLoose25, &b_nSoftBLoose25);
   fChain->SetBranchAddress("nSoftBMedium25", &nSoftBMedium25, &b_nSoftBMedium25);
   fChain->SetBranchAddress("nSoftBTight25", &nSoftBTight25, &b_nSoftBTight25);
   fChain->SetBranchAddress("nJet30NoTau", &nJet30NoTau, &b_nJet30NoTau);
   fChain->SetBranchAddress("nBJetLoose30NoTau", &nBJetLoose30NoTau, &b_nBJetLoose30NoTau);
   fChain->SetBranchAddress("nBJetMedium30NoTau", &nBJetMedium30NoTau, &b_nBJetMedium30NoTau);
   fChain->SetBranchAddress("nJet40NoTau", &nJet40NoTau, &b_nJet40NoTau);
   fChain->SetBranchAddress("nBJetLoose40NoTau", &nBJetLoose40NoTau, &b_nBJetLoose40NoTau);
   fChain->SetBranchAddress("nBJetMedium40NoTau", &nBJetMedium40NoTau, &b_nBJetMedium40NoTau);
   fChain->SetBranchAddress("nBJetCMVALoose40", &nBJetCMVALoose40, &b_nBJetCMVALoose40);
   fChain->SetBranchAddress("nBJetCMVAMedium40", &nBJetCMVAMedium40, &b_nBJetCMVAMedium40);
   fChain->SetBranchAddress("nBJetCMVATight40", &nBJetCMVATight40, &b_nBJetCMVATight40);
   fChain->SetBranchAddress("mZ1", &mZ1, &b_mZ1);
   fChain->SetBranchAddress("mZ1SFSS", &mZ1SFSS, &b_mZ1SFSS);
   fChain->SetBranchAddress("minMllSFOS", &minMllSFOS, &b_minMllSFOS);
   fChain->SetBranchAddress("maxMllSFOS", &maxMllSFOS, &b_maxMllSFOS);
   fChain->SetBranchAddress("minMllAFOS", &minMllAFOS, &b_minMllAFOS);
   fChain->SetBranchAddress("maxMllAFOS", &maxMllAFOS, &b_maxMllAFOS);
   fChain->SetBranchAddress("minMllAFSS", &minMllAFSS, &b_minMllAFSS);
   fChain->SetBranchAddress("maxMllAFSS", &maxMllAFSS, &b_maxMllAFSS);
   fChain->SetBranchAddress("minMllAFAS", &minMllAFAS, &b_minMllAFAS);
   fChain->SetBranchAddress("maxMllAFAS", &maxMllAFAS, &b_maxMllAFAS);
   fChain->SetBranchAddress("m2l", &m2l, &b_m2l);
   fChain->SetBranchAddress("minDrllAFSS", &minDrllAFSS, &b_minDrllAFSS);
   fChain->SetBranchAddress("maxDrllAFSS", &maxDrllAFSS, &b_maxDrllAFSS);
   fChain->SetBranchAddress("minDrllAFOS", &minDrllAFOS, &b_minDrllAFOS);
   fChain->SetBranchAddress("maxDrllAFOS", &maxDrllAFOS, &b_maxDrllAFOS);
   fChain->SetBranchAddress("mZ2", &mZ2, &b_mZ2);
   fChain->SetBranchAddress("m3l", &m3l, &b_m3l);
   fChain->SetBranchAddress("m4l", &m4l, &b_m4l);
   fChain->SetBranchAddress("pt2l", &pt2l, &b_pt2l);
   fChain->SetBranchAddress("pt3l", &pt3l, &b_pt3l);
   fChain->SetBranchAddress("pt4l", &pt4l, &b_pt4l);
   fChain->SetBranchAddress("ht3l", &ht3l, &b_ht3l);
   fChain->SetBranchAddress("ht4l", &ht4l, &b_ht4l);
   fChain->SetBranchAddress("q3l", &q3l, &b_q3l);
   fChain->SetBranchAddress("q4l", &q4l, &b_q4l);
   fChain->SetBranchAddress("minMWjj", &minMWjj, &b_minMWjj);
   fChain->SetBranchAddress("minMWjjPt", &minMWjjPt, &b_minMWjjPt);
   fChain->SetBranchAddress("bestMWjj", &bestMWjj, &b_bestMWjj);
   fChain->SetBranchAddress("bestMWjjPt", &bestMWjjPt, &b_bestMWjjPt);
   fChain->SetBranchAddress("bestMTopHad", &bestMTopHad, &b_bestMTopHad);
   fChain->SetBranchAddress("bestMTopHadPt", &bestMTopHadPt, &b_bestMTopHadPt);
   fChain->SetBranchAddress("GenHiggsDecayMode", &GenHiggsDecayMode, &b_GenHiggsDecayMode);
   fChain->SetBranchAddress("absIP3DAval", &absIP3DAval, &b_absIP3DAval);
   fChain->SetBranchAddress("absIP3DAerr", &absIP3DAerr, &b_absIP3DAerr);
   fChain->SetBranchAddress("absIP3DBval", &absIP3DBval, &b_absIP3DBval);
   fChain->SetBranchAddress("absIP3DBerr", &absIP3DBerr, &b_absIP3DBerr);
   fChain->SetBranchAddress("absIP3DCval", &absIP3DCval, &b_absIP3DCval);
   fChain->SetBranchAddress("absIP3DCerr", &absIP3DCerr, &b_absIP3DCerr);
   fChain->SetBranchAddress("absIP3DDval", &absIP3DDval, &b_absIP3DDval);
   fChain->SetBranchAddress("absIP3DDerr", &absIP3DDerr, &b_absIP3DDerr);
   fChain->SetBranchAddress("absIP3DApvBCval", &absIP3DApvBCval, &b_absIP3DApvBCval);
   fChain->SetBranchAddress("absIP3DApvBCerr", &absIP3DApvBCerr, &b_absIP3DApvBCerr);
   fChain->SetBranchAddress("absIP3DBpvACval", &absIP3DBpvACval, &b_absIP3DBpvACval);
   fChain->SetBranchAddress("absIP3DBpvACerr", &absIP3DBpvACerr, &b_absIP3DBpvACerr);
   fChain->SetBranchAddress("absIP3DCpvABval", &absIP3DCpvABval, &b_absIP3DCpvABval);
   fChain->SetBranchAddress("absIP3DCpvABerr", &absIP3DCpvABerr, &b_absIP3DCpvABerr);
   fChain->SetBranchAddress("absIP3DApvBCDval", &absIP3DApvBCDval, &b_absIP3DApvBCDval);
   fChain->SetBranchAddress("absIP3DApvBCDerr", &absIP3DApvBCDerr, &b_absIP3DApvBCDerr);
   fChain->SetBranchAddress("absIP3DBpvACDval", &absIP3DBpvACDval, &b_absIP3DBpvACDval);
   fChain->SetBranchAddress("absIP3DBpvACDerr", &absIP3DBpvACDerr, &b_absIP3DBpvACDerr);
   fChain->SetBranchAddress("absIP3DCpvABDval", &absIP3DCpvABDval, &b_absIP3DCpvABDval);
   fChain->SetBranchAddress("absIP3DCpvABDerr", &absIP3DCpvABDerr, &b_absIP3DCpvABDerr);
   fChain->SetBranchAddress("absIP3DDpvABCval", &absIP3DDpvABCval, &b_absIP3DDpvABCval);
   fChain->SetBranchAddress("absIP3DDpvABCerr", &absIP3DDpvABCerr, &b_absIP3DDpvABCerr);
   fChain->SetBranchAddress("chi2pvtrksBCbutAval", &chi2pvtrksBCbutAval, &b_chi2pvtrksBCbutAval);
   fChain->SetBranchAddress("chi2pvtrksBCbutAdof", &chi2pvtrksBCbutAdof, &b_chi2pvtrksBCbutAdof);
   fChain->SetBranchAddress("chi2pvtrksACbutBval", &chi2pvtrksACbutBval, &b_chi2pvtrksACbutBval);
   fChain->SetBranchAddress("chi2pvtrksACbutBdof", &chi2pvtrksACbutBdof, &b_chi2pvtrksACbutBdof);
   fChain->SetBranchAddress("chi2pvtrksABbutCval", &chi2pvtrksABbutCval, &b_chi2pvtrksABbutCval);
   fChain->SetBranchAddress("chi2pvtrksABbutCdof", &chi2pvtrksABbutCdof, &b_chi2pvtrksABbutCdof);
   fChain->SetBranchAddress("chi2pvtrksBCDbutAval", &chi2pvtrksBCDbutAval, &b_chi2pvtrksBCDbutAval);
   fChain->SetBranchAddress("chi2pvtrksBCDbutAdof", &chi2pvtrksBCDbutAdof, &b_chi2pvtrksBCDbutAdof);
   fChain->SetBranchAddress("chi2pvtrksACDbutBval", &chi2pvtrksACDbutBval, &b_chi2pvtrksACDbutBval);
   fChain->SetBranchAddress("chi2pvtrksACDbutBdof", &chi2pvtrksACDbutBdof, &b_chi2pvtrksACDbutBdof);
   fChain->SetBranchAddress("chi2pvtrksABDbutCval", &chi2pvtrksABDbutCval, &b_chi2pvtrksABDbutCval);
   fChain->SetBranchAddress("chi2pvtrksABDbutCdof", &chi2pvtrksABDbutCdof, &b_chi2pvtrksABDbutCdof);
   fChain->SetBranchAddress("chi2pvtrksABCbutDval", &chi2pvtrksABCbutDval, &b_chi2pvtrksABCbutDval);
   fChain->SetBranchAddress("chi2pvtrksABCbutDdof", &chi2pvtrksABCbutDdof, &b_chi2pvtrksABCbutDdof);
   fChain->SetBranchAddress("nRecJet40", &nRecJet40, &b_nRecJet40);
   fChain->SetBranchAddress("nRecJet25", &nRecJet25, &b_nRecJet25);
   fChain->SetBranchAddress("nRecBJetMedium40", &nRecBJetMedium40, &b_nRecBJetMedium40);
   fChain->SetBranchAddress("nRecBJetMedium25", &nRecBJetMedium25, &b_nRecBJetMedium25);
   fChain->SetBranchAddress("nRecSplitJet40", &nRecSplitJet40, &b_nRecSplitJet40);
   fChain->SetBranchAddress("nRecSplitJet25", &nRecSplitJet25, &b_nRecSplitJet25);
   fChain->SetBranchAddress("nRecSplitBJetMedium40", &nRecSplitBJetMedium40, &b_nRecSplitBJetMedium40);
   fChain->SetBranchAddress("nRecSplitBJetMedium25", &nRecSplitBJetMedium25, &b_nRecSplitBJetMedium25);
   fChain->SetBranchAddress("hbheFilterNew50ns", &hbheFilterNew50ns, &b_hbheFilterNew50ns);
   fChain->SetBranchAddress("hbheFilterNew25ns", &hbheFilterNew25ns, &b_hbheFilterNew25ns);
   fChain->SetBranchAddress("hbheFilterIso", &hbheFilterIso, &b_hbheFilterIso);
   fChain->SetBranchAddress("Flag_badChargedHadronFilter", &Flag_badChargedHadronFilter, &b_Flag_badChargedHadronFilter);
   fChain->SetBranchAddress("Flag_badMuonFilter", &Flag_badMuonFilter, &b_Flag_badMuonFilter);
   fChain->SetBranchAddress("met_trkPt", &met_trkPt, &b_met_trkPt);
   fChain->SetBranchAddress("met_trkPhi", &met_trkPhi, &b_met_trkPhi);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v", &HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v, &b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale", &HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale, &b_HLT_BIT_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale);
   fChain->SetBranchAddress("HLT_DoubleElHT", &HLT_DoubleElHT, &b_HLT_DoubleElHT);
   fChain->SetBranchAddress("HLT_DoubleElHT_isUnprescaled", &HLT_DoubleElHT_isUnprescaled, &b_HLT_DoubleElHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_Prescale", &HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_Prescale, &b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v_Prescale);
   fChain->SetBranchAddress("HLT_TripleEl", &HLT_TripleEl, &b_HLT_TripleEl);
   fChain->SetBranchAddress("HLT_TripleEl_isUnprescaled", &HLT_TripleEl_isUnprescaled, &b_HLT_TripleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v", &HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v, &b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale", &HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale, &b_HLT_BIT_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v_Prescale);
   fChain->SetBranchAddress("HLT_MuEGHT", &HLT_MuEGHT, &b_HLT_MuEGHT);
   fChain->SetBranchAddress("HLT_MuEGHT_isUnprescaled", &HLT_MuEGHT_isUnprescaled, &b_HLT_MuEGHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v", &HLT_BIT_HLT_IsoMu20_v, &b_HLT_BIT_HLT_IsoMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v_isUnprescaled", &HLT_BIT_HLT_IsoMu20_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu20_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v_Prescale", &HLT_BIT_HLT_IsoMu20_v_Prescale, &b_HLT_BIT_HLT_IsoMu20_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v", &HLT_BIT_HLT_IsoTkMu20_v, &b_HLT_BIT_HLT_IsoTkMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled", &HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled, &b_HLT_BIT_HLT_IsoTkMu20_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v_Prescale", &HLT_BIT_HLT_IsoTkMu20_v_Prescale, &b_HLT_BIT_HLT_IsoTkMu20_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu22_v", &HLT_BIT_HLT_IsoMu22_v, &b_HLT_BIT_HLT_IsoMu22_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu22_v_isUnprescaled", &HLT_BIT_HLT_IsoMu22_v_isUnprescaled, &b_HLT_BIT_HLT_IsoMu22_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu22_v_Prescale", &HLT_BIT_HLT_IsoMu22_v_Prescale, &b_HLT_BIT_HLT_IsoMu22_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu22_v", &HLT_BIT_HLT_IsoTkMu22_v, &b_HLT_BIT_HLT_IsoTkMu22_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu22_v_isUnprescaled", &HLT_BIT_HLT_IsoTkMu22_v_isUnprescaled, &b_HLT_BIT_HLT_IsoTkMu22_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu22_v_Prescale", &HLT_BIT_HLT_IsoTkMu22_v_Prescale, &b_HLT_BIT_HLT_IsoTkMu22_v_Prescale);
   fChain->SetBranchAddress("HLT_SingleMu", &HLT_SingleMu, &b_HLT_SingleMu);
   fChain->SetBranchAddress("HLT_SingleMu_isUnprescaled", &HLT_SingleMu_isUnprescaled, &b_HLT_SingleMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_Prescale", &HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_Prescale, &b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v_Prescale);
   fChain->SetBranchAddress("HLT_DoubleMuEl", &HLT_DoubleMuEl, &b_HLT_DoubleMuEl);
   fChain->SetBranchAddress("HLT_DoubleMuEl_isUnprescaled", &HLT_DoubleMuEl_isUnprescaled, &b_HLT_DoubleMuEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_12_10_5_v", &HLT_BIT_HLT_TripleMu_12_10_5_v, &b_HLT_BIT_HLT_TripleMu_12_10_5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled", &HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled, &b_HLT_BIT_HLT_TripleMu_12_10_5_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_12_10_5_v_Prescale", &HLT_BIT_HLT_TripleMu_12_10_5_v_Prescale, &b_HLT_BIT_HLT_TripleMu_12_10_5_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_5_3_3_v", &HLT_BIT_HLT_TripleMu_5_3_3_v, &b_HLT_BIT_HLT_TripleMu_5_3_3_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_5_3_3_v_isUnprescaled", &HLT_BIT_HLT_TripleMu_5_3_3_v_isUnprescaled, &b_HLT_BIT_HLT_TripleMu_5_3_3_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_5_3_3_v_Prescale", &HLT_BIT_HLT_TripleMu_5_3_3_v_Prescale, &b_HLT_BIT_HLT_TripleMu_5_3_3_v_Prescale);
   fChain->SetBranchAddress("HLT_TripleMu", &HLT_TripleMu, &b_HLT_TripleMu);
   fChain->SetBranchAddress("HLT_TripleMu_isUnprescaled", &HLT_TripleMu_isUnprescaled, &b_HLT_TripleMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_Prescale", &HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_Prescale, &b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v_Prescale);
   fChain->SetBranchAddress("HLT_DoubleElMu", &HLT_DoubleElMu, &b_HLT_DoubleElMu);
   fChain->SetBranchAddress("HLT_DoubleElMu_isUnprescaled", &HLT_DoubleElMu_isUnprescaled, &b_HLT_DoubleElMu_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu30_TkMu11_v", &HLT_BIT_HLT_Mu30_TkMu11_v, &b_HLT_BIT_HLT_Mu30_TkMu11_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled", &HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled, &b_HLT_BIT_HLT_Mu30_TkMu11_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu30_TkMu11_v_Prescale", &HLT_BIT_HLT_Mu30_TkMu11_v_Prescale, &b_HLT_BIT_HLT_Mu30_TkMu11_v_Prescale);
   fChain->SetBranchAddress("HLT_DoubleMuNoIso", &HLT_DoubleMuNoIso, &b_HLT_DoubleMuNoIso);
   fChain->SetBranchAddress("HLT_DoubleMuNoIso_isUnprescaled", &HLT_DoubleMuNoIso_isUnprescaled, &b_HLT_DoubleMuNoIso_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_v", &HLT_BIT_HLT_Mu17_Mu8_SameSign_v, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled", &HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_v_Prescale", &HLT_BIT_HLT_Mu17_Mu8_SameSign_v_Prescale, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v", &HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_Prescale", &HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_Prescale, &b_HLT_BIT_HLT_Mu17_Mu8_SameSign_DZ_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu20_Mu10_SameSign_v", &HLT_BIT_HLT_Mu20_Mu10_SameSign_v, &b_HLT_BIT_HLT_Mu20_Mu10_SameSign_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu20_Mu10_SameSign_v_isUnprescaled", &HLT_BIT_HLT_Mu20_Mu10_SameSign_v_isUnprescaled, &b_HLT_BIT_HLT_Mu20_Mu10_SameSign_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu20_Mu10_SameSign_v_Prescale", &HLT_BIT_HLT_Mu20_Mu10_SameSign_v_Prescale, &b_HLT_BIT_HLT_Mu20_Mu10_SameSign_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v", &HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v, &b_HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_Prescale", &HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_Prescale, &b_HLT_BIT_HLT_Mu20_Mu10_SameSign_DZ_v_Prescale);
   fChain->SetBranchAddress("HLT_DoubleMuSS", &HLT_DoubleMuSS, &b_HLT_DoubleMuSS);
   fChain->SetBranchAddress("HLT_DoubleMuSS_isUnprescaled", &HLT_DoubleMuSS_isUnprescaled, &b_HLT_DoubleMuSS_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_WPTight_Gsf_v", &HLT_BIT_HLT_Ele25_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_WPTight_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele25_WPTight_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_WPTight_Gsf_v_Prescale", &HLT_BIT_HLT_Ele25_WPTight_Gsf_v_Prescale, &b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_Prescale", &HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_Prescale, &b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v", &HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_Prescale", &HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_Prescale, &b_HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPTight_Gsf_v", &HLT_BIT_HLT_Ele27_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele27_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPTight_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_WPTight_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_WPTight_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPTight_Gsf_v_Prescale", &HLT_BIT_HLT_Ele27_WPTight_Gsf_v_Prescale, &b_HLT_BIT_HLT_Ele27_WPTight_Gsf_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_Prescale", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_Prescale, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele45_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele45_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele45_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_isUnprescaled", &HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_isUnprescaled, &b_HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_Prescale", &HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_Prescale, &b_HLT_BIT_HLT_Ele45_WPLoose_Gsf_v_Prescale);
   fChain->SetBranchAddress("HLT_SingleEl", &HLT_SingleEl, &b_HLT_SingleEl);
   fChain->SetBranchAddress("HLT_SingleEl_isUnprescaled", &HLT_SingleEl_isUnprescaled, &b_HLT_SingleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v", &HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v, &b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled", &HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled, &b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_Prescale", &HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_Prescale, &b_HLT_BIT_HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v_Prescale);
   fChain->SetBranchAddress("HLT_TripleMuA", &HLT_TripleMuA, &b_HLT_TripleMuA);
   fChain->SetBranchAddress("HLT_TripleMuA_isUnprescaled", &HLT_TripleMuA_isUnprescaled, &b_HLT_TripleMuA_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v", &HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v, &b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_isUnprescaled", &HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_Prescale", &HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_Prescale, &b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v", &HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_isUnprescaled", &HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_Prescale", &HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_Prescale, &b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v", &HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v, &b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_isUnprescaled", &HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_Prescale", &HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_Prescale, &b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v", &HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_isUnprescaled", &HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_Prescale", &HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_Prescale, &b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v", &HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v, &b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_isUnprescaled", &HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_Prescale", &HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_Prescale, &b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v", &HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_isUnprescaled", &HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_Prescale", &HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_Prescale, &b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v", &HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_isUnprescaled", &HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_Prescale", &HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_Prescale, &b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v", &HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v, &b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_isUnprescaled", &HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_isUnprescaled, &b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_Prescale", &HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_Prescale, &b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v_Prescale);
   fChain->SetBranchAddress("HLT_SOSHighMET", &HLT_SOSHighMET, &b_HLT_SOSHighMET);
   fChain->SetBranchAddress("HLT_SOSHighMET_isUnprescaled", &HLT_SOSHighMET_isUnprescaled, &b_HLT_SOSHighMET_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu3_PFMET50_v", &HLT_BIT_HLT_DoubleMu3_PFMET50_v, &b_HLT_BIT_HLT_DoubleMu3_PFMET50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu3_PFMET50_v_isUnprescaled", &HLT_BIT_HLT_DoubleMu3_PFMET50_v_isUnprescaled, &b_HLT_BIT_HLT_DoubleMu3_PFMET50_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu3_PFMET50_v_Prescale", &HLT_BIT_HLT_DoubleMu3_PFMET50_v_Prescale, &b_HLT_BIT_HLT_DoubleMu3_PFMET50_v_Prescale);
   fChain->SetBranchAddress("HLT_SOSDoubleMuLowMET", &HLT_SOSDoubleMuLowMET, &b_HLT_SOSDoubleMuLowMET);
   fChain->SetBranchAddress("HLT_SOSDoubleMuLowMET_isUnprescaled", &HLT_SOSDoubleMuLowMET_isUnprescaled, &b_HLT_SOSDoubleMuLowMET_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_Prescale", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_Prescale, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_Prescale", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_Prescale, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_Prescale", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_Prescale, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v_Prescale);
   fChain->SetBranchAddress("HLT_MuEG", &HLT_MuEG, &b_HLT_MuEG);
   fChain->SetBranchAddress("HLT_MuEG_isUnprescaled", &HLT_MuEG_isUnprescaled, &b_HLT_MuEG_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v", &HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v, &b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled", &HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled, &b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_Prescale", &HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_Prescale, &b_HLT_BIT_HLT_DoubleMu8_Mass8_PFHT300_v_Prescale);
   fChain->SetBranchAddress("HLT_DoubleMuHT", &HLT_DoubleMuHT, &b_HLT_DoubleMuHT);
   fChain->SetBranchAddress("HLT_DoubleMuHT_isUnprescaled", &HLT_DoubleMuHT_isUnprescaled, &b_HLT_DoubleMuHT_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v_Prescale);
   fChain->SetBranchAddress("HLT_DoubleEl", &HLT_DoubleEl, &b_HLT_DoubleEl);
   fChain->SetBranchAddress("HLT_DoubleEl_isUnprescaled", &HLT_DoubleEl_isUnprescaled, &b_HLT_DoubleEl_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_Prescale", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_Prescale, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_Prescale", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_Prescale, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_Prescale", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_Prescale, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v_Prescale);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_isUnprescaled);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_Prescale", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_Prescale, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v_Prescale);
   fChain->SetBranchAddress("HLT_DoubleMu", &HLT_DoubleMu, &b_HLT_DoubleMu);
   fChain->SetBranchAddress("HLT_DoubleMu_isUnprescaled", &HLT_DoubleMu_isUnprescaled, &b_HLT_DoubleMu_isUnprescaled);
   fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   fChain->SetBranchAddress("Flag_trackingFailureFilter", &Flag_trackingFailureFilter, &b_Flag_trackingFailureFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("Flag_CSCTightHalo2015Filter", &Flag_CSCTightHalo2015Filter, &b_Flag_CSCTightHalo2015Filter);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_eta", &met_eta, &b_met_eta);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_mass", &met_mass, &b_met_mass);
   fChain->SetBranchAddress("met_sumEt", &met_sumEt, &b_met_sumEt);
   fChain->SetBranchAddress("met_rawPt", &met_rawPt, &b_met_rawPt);
   fChain->SetBranchAddress("met_rawPhi", &met_rawPhi, &b_met_rawPhi);
   fChain->SetBranchAddress("met_rawSumEt", &met_rawSumEt, &b_met_rawSumEt);
   fChain->SetBranchAddress("met_genPt", &met_genPt, &b_met_genPt);
   fChain->SetBranchAddress("met_genPhi", &met_genPhi, &b_met_genPhi);
   fChain->SetBranchAddress("met_genEta", &met_genEta, &b_met_genEta);
   fChain->SetBranchAddress("met_jecUp_pt", &met_jecUp_pt, &b_met_jecUp_pt);
   fChain->SetBranchAddress("met_jecUp_eta", &met_jecUp_eta, &b_met_jecUp_eta);
   fChain->SetBranchAddress("met_jecUp_phi", &met_jecUp_phi, &b_met_jecUp_phi);
   fChain->SetBranchAddress("met_jecUp_mass", &met_jecUp_mass, &b_met_jecUp_mass);
   fChain->SetBranchAddress("met_jecUp_sumEt", &met_jecUp_sumEt, &b_met_jecUp_sumEt);
   fChain->SetBranchAddress("met_jecUp_rawPt", &met_jecUp_rawPt, &b_met_jecUp_rawPt);
   fChain->SetBranchAddress("met_jecUp_rawPhi", &met_jecUp_rawPhi, &b_met_jecUp_rawPhi);
   fChain->SetBranchAddress("met_jecUp_rawSumEt", &met_jecUp_rawSumEt, &b_met_jecUp_rawSumEt);
   fChain->SetBranchAddress("met_jecUp_genPt", &met_jecUp_genPt, &b_met_jecUp_genPt);
   fChain->SetBranchAddress("met_jecUp_genPhi", &met_jecUp_genPhi, &b_met_jecUp_genPhi);
   fChain->SetBranchAddress("met_jecUp_genEta", &met_jecUp_genEta, &b_met_jecUp_genEta);
   fChain->SetBranchAddress("met_jecDown_pt", &met_jecDown_pt, &b_met_jecDown_pt);
   fChain->SetBranchAddress("met_jecDown_eta", &met_jecDown_eta, &b_met_jecDown_eta);
   fChain->SetBranchAddress("met_jecDown_phi", &met_jecDown_phi, &b_met_jecDown_phi);
   fChain->SetBranchAddress("met_jecDown_mass", &met_jecDown_mass, &b_met_jecDown_mass);
   fChain->SetBranchAddress("met_jecDown_sumEt", &met_jecDown_sumEt, &b_met_jecDown_sumEt);
   fChain->SetBranchAddress("met_jecDown_rawPt", &met_jecDown_rawPt, &b_met_jecDown_rawPt);
   fChain->SetBranchAddress("met_jecDown_rawPhi", &met_jecDown_rawPhi, &b_met_jecDown_rawPhi);
   fChain->SetBranchAddress("met_jecDown_rawSumEt", &met_jecDown_rawSumEt, &b_met_jecDown_rawSumEt);
   fChain->SetBranchAddress("met_jecDown_genPt", &met_jecDown_genPt, &b_met_jecDown_genPt);
   fChain->SetBranchAddress("met_jecDown_genPhi", &met_jecDown_genPhi, &b_met_jecDown_genPhi);
   fChain->SetBranchAddress("met_jecDown_genEta", &met_jecDown_genEta, &b_met_jecDown_genEta);
   fChain->SetBranchAddress("nFatJet", &nFatJet, &b_nFatJet);
   fChain->SetBranchAddress("FatJet_id", FatJet_id, &b_FatJet_id);
   fChain->SetBranchAddress("FatJet_puId", FatJet_puId, &b_FatJet_puId);
   fChain->SetBranchAddress("FatJet_btagCSV", FatJet_btagCSV, &b_FatJet_btagCSV);
   fChain->SetBranchAddress("FatJet_btagCMVA", FatJet_btagCMVA, &b_FatJet_btagCMVA);
   fChain->SetBranchAddress("FatJet_rawPt", FatJet_rawPt, &b_FatJet_rawPt);
   fChain->SetBranchAddress("FatJet_mcPt", FatJet_mcPt, &b_FatJet_mcPt);
   fChain->SetBranchAddress("FatJet_mcFlavour", FatJet_mcFlavour, &b_FatJet_mcFlavour);
   fChain->SetBranchAddress("FatJet_partonFlavour", FatJet_partonFlavour, &b_FatJet_partonFlavour);
   fChain->SetBranchAddress("FatJet_hadronFlavour", FatJet_hadronFlavour, &b_FatJet_hadronFlavour);
   fChain->SetBranchAddress("FatJet_mcMatchId", FatJet_mcMatchId, &b_FatJet_mcMatchId);
   fChain->SetBranchAddress("FatJet_corr_JECUp", FatJet_corr_JECUp, &b_FatJet_corr_JECUp);
   fChain->SetBranchAddress("FatJet_corr_JECDown", FatJet_corr_JECDown, &b_FatJet_corr_JECDown);
   fChain->SetBranchAddress("FatJet_corr", FatJet_corr, &b_FatJet_corr);
   fChain->SetBranchAddress("FatJet_corr_JERUp", FatJet_corr_JERUp, &b_FatJet_corr_JERUp);
   fChain->SetBranchAddress("FatJet_corr_JERDown", FatJet_corr_JERDown, &b_FatJet_corr_JERDown);
   fChain->SetBranchAddress("FatJet_corr_JER", FatJet_corr_JER, &b_FatJet_corr_JER);
   fChain->SetBranchAddress("FatJet_pt", FatJet_pt, &b_FatJet_pt);
   fChain->SetBranchAddress("FatJet_eta", FatJet_eta, &b_FatJet_eta);
   fChain->SetBranchAddress("FatJet_phi", FatJet_phi, &b_FatJet_phi);
   fChain->SetBranchAddress("FatJet_mass", FatJet_mass, &b_FatJet_mass);
   fChain->SetBranchAddress("FatJet_prunedMass", FatJet_prunedMass, &b_FatJet_prunedMass);
   fChain->SetBranchAddress("FatJet_softDropMass", FatJet_softDropMass, &b_FatJet_softDropMass);
   fChain->SetBranchAddress("FatJet_tau1", FatJet_tau1, &b_FatJet_tau1);
   fChain->SetBranchAddress("FatJet_tau2", FatJet_tau2, &b_FatJet_tau2);
   fChain->SetBranchAddress("FatJet_tau3", FatJet_tau3, &b_FatJet_tau3);
   fChain->SetBranchAddress("FatJet_topMass", FatJet_topMass, &b_FatJet_topMass);
   fChain->SetBranchAddress("FatJet_minMass", FatJet_minMass, &b_FatJet_minMass);
   fChain->SetBranchAddress("FatJet_nSubJets", FatJet_nSubJets, &b_FatJet_nSubJets);
   fChain->SetBranchAddress("nDiscLep", &nDiscLep, &b_nDiscLep);
   fChain->SetBranchAddress("DiscLep_charge", &DiscLep_charge, &b_DiscLep_charge);
   fChain->SetBranchAddress("DiscLep_tightId", &DiscLep_tightId, &b_DiscLep_tightId);
   fChain->SetBranchAddress("DiscLep_eleCutIdCSA14_25ns_v1", &DiscLep_eleCutIdCSA14_25ns_v1, &b_DiscLep_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("DiscLep_eleCutIdCSA14_50ns_v1", &DiscLep_eleCutIdCSA14_50ns_v1, &b_DiscLep_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("DiscLep_eleCutIdSpring15_25ns_v1", &DiscLep_eleCutIdSpring15_25ns_v1, &b_DiscLep_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("DiscLep_dxy", &DiscLep_dxy, &b_DiscLep_dxy);
   fChain->SetBranchAddress("DiscLep_dz", &DiscLep_dz, &b_DiscLep_dz);
   fChain->SetBranchAddress("DiscLep_edxy", &DiscLep_edxy, &b_DiscLep_edxy);
   fChain->SetBranchAddress("DiscLep_edz", &DiscLep_edz, &b_DiscLep_edz);
   fChain->SetBranchAddress("DiscLep_ip3d", &DiscLep_ip3d, &b_DiscLep_ip3d);
   fChain->SetBranchAddress("DiscLep_sip3d", &DiscLep_sip3d, &b_DiscLep_sip3d);
   fChain->SetBranchAddress("DiscLep_convVeto", &DiscLep_convVeto, &b_DiscLep_convVeto);
   fChain->SetBranchAddress("DiscLep_lostHits", &DiscLep_lostHits, &b_DiscLep_lostHits);
   fChain->SetBranchAddress("DiscLep_relIso03", &DiscLep_relIso03, &b_DiscLep_relIso03);
   fChain->SetBranchAddress("DiscLep_relIso04", &DiscLep_relIso04, &b_DiscLep_relIso04);
   fChain->SetBranchAddress("DiscLep_miniRelIso", &DiscLep_miniRelIso, &b_DiscLep_miniRelIso);
   fChain->SetBranchAddress("DiscLep_relIsoAn04", &DiscLep_relIsoAn04, &b_DiscLep_relIsoAn04);
   fChain->SetBranchAddress("DiscLep_tightCharge", &DiscLep_tightCharge, &b_DiscLep_tightCharge);
   fChain->SetBranchAddress("DiscLep_mcMatchId", &DiscLep_mcMatchId, &b_DiscLep_mcMatchId);
   fChain->SetBranchAddress("DiscLep_mcMatchAny", &DiscLep_mcMatchAny, &b_DiscLep_mcMatchAny);
   fChain->SetBranchAddress("DiscLep_mcMatchTau", &DiscLep_mcMatchTau, &b_DiscLep_mcMatchTau);
   fChain->SetBranchAddress("DiscLep_mcPt", &DiscLep_mcPt, &b_DiscLep_mcPt);
   fChain->SetBranchAddress("DiscLep_mediumMuonId", &DiscLep_mediumMuonId, &b_DiscLep_mediumMuonId);
   fChain->SetBranchAddress("DiscLep_ICHEPsoftMuonId", &DiscLep_ICHEPsoftMuonId, &b_DiscLep_ICHEPsoftMuonId);
   fChain->SetBranchAddress("DiscLep_ICHEPmediumMuonId", &DiscLep_ICHEPmediumMuonId, &b_DiscLep_ICHEPmediumMuonId);
   fChain->SetBranchAddress("DiscLep_pdgId", &DiscLep_pdgId, &b_DiscLep_pdgId);
   fChain->SetBranchAddress("DiscLep_pt", &DiscLep_pt, &b_DiscLep_pt);
   fChain->SetBranchAddress("DiscLep_eta", &DiscLep_eta, &b_DiscLep_eta);
   fChain->SetBranchAddress("DiscLep_phi", &DiscLep_phi, &b_DiscLep_phi);
   fChain->SetBranchAddress("DiscLep_mass", &DiscLep_mass, &b_DiscLep_mass);
   fChain->SetBranchAddress("DiscLep_mvaIdSpring15", &DiscLep_mvaIdSpring15, &b_DiscLep_mvaIdSpring15);
   fChain->SetBranchAddress("DiscLep_mvaTTH", &DiscLep_mvaTTH, &b_DiscLep_mvaTTH);
   fChain->SetBranchAddress("DiscLep_mvaSUSY", &DiscLep_mvaSUSY, &b_DiscLep_mvaSUSY);
   fChain->SetBranchAddress("DiscLep_mvaSoftT2tt", &DiscLep_mvaSoftT2tt, &b_DiscLep_mvaSoftT2tt);
   fChain->SetBranchAddress("DiscLep_mvaSoftEWK", &DiscLep_mvaSoftEWK, &b_DiscLep_mvaSoftEWK);
   fChain->SetBranchAddress("DiscLep_jetPtRatiov1", &DiscLep_jetPtRatiov1, &b_DiscLep_jetPtRatiov1);
   fChain->SetBranchAddress("DiscLep_jetPtRelv1", &DiscLep_jetPtRelv1, &b_DiscLep_jetPtRelv1);
   fChain->SetBranchAddress("DiscLep_jetPtRatiov2", &DiscLep_jetPtRatiov2, &b_DiscLep_jetPtRatiov2);
   fChain->SetBranchAddress("DiscLep_jetPtRelv2", &DiscLep_jetPtRelv2, &b_DiscLep_jetPtRelv2);
   fChain->SetBranchAddress("DiscLep_jetBTagCSV", &DiscLep_jetBTagCSV, &b_DiscLep_jetBTagCSV);
   fChain->SetBranchAddress("DiscLep_jetBTagCMVA", &DiscLep_jetBTagCMVA, &b_DiscLep_jetBTagCMVA);
   fChain->SetBranchAddress("DiscLep_jetDR", &DiscLep_jetDR, &b_DiscLep_jetDR);
   fChain->SetBranchAddress("DiscLep_r9", &DiscLep_r9, &b_DiscLep_r9);
   fChain->SetBranchAddress("DiscLep_mvaIdSpring16", &DiscLep_mvaIdSpring16, &b_DiscLep_mvaIdSpring16);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("GenPart_motherId", GenPart_motherId, &b_GenPart_motherId);
   fChain->SetBranchAddress("GenPart_grandmotherId", GenPart_grandmotherId, &b_GenPart_grandmotherId);
   fChain->SetBranchAddress("GenPart_sourceId", GenPart_sourceId, &b_GenPart_sourceId);
   fChain->SetBranchAddress("GenPart_charge", GenPart_charge, &b_GenPart_charge);
   fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   fChain->SetBranchAddress("GenPart_isPromptHard", GenPart_isPromptHard, &b_GenPart_isPromptHard);
   fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   fChain->SetBranchAddress("GenPart_motherIndex", GenPart_motherIndex, &b_GenPart_motherIndex);
   fChain->SetBranchAddress("nDiscJet", &nDiscJet, &b_nDiscJet);
   fChain->SetBranchAddress("DiscJet_mcMatchFlav", DiscJet_mcMatchFlav, &b_DiscJet_mcMatchFlav);
   fChain->SetBranchAddress("DiscJet_charge", DiscJet_charge, &b_DiscJet_charge);
   fChain->SetBranchAddress("DiscJet_ctagCsvL", DiscJet_ctagCsvL, &b_DiscJet_ctagCsvL);
   fChain->SetBranchAddress("DiscJet_ctagCsvB", DiscJet_ctagCsvB, &b_DiscJet_ctagCsvB);
   fChain->SetBranchAddress("DiscJet_area", DiscJet_area, &b_DiscJet_area);
   fChain->SetBranchAddress("DiscJet_qgl", DiscJet_qgl, &b_DiscJet_qgl);
   fChain->SetBranchAddress("DiscJet_ptd", DiscJet_ptd, &b_DiscJet_ptd);
   fChain->SetBranchAddress("DiscJet_axis2", DiscJet_axis2, &b_DiscJet_axis2);
   fChain->SetBranchAddress("DiscJet_mult", DiscJet_mult, &b_DiscJet_mult);
   fChain->SetBranchAddress("DiscJet_partonId", DiscJet_partonId, &b_DiscJet_partonId);
   fChain->SetBranchAddress("DiscJet_partonMotherId", DiscJet_partonMotherId, &b_DiscJet_partonMotherId);
   fChain->SetBranchAddress("DiscJet_nLeptons", DiscJet_nLeptons, &b_DiscJet_nLeptons);
   fChain->SetBranchAddress("DiscJet_id", DiscJet_id, &b_DiscJet_id);
   fChain->SetBranchAddress("DiscJet_puId", DiscJet_puId, &b_DiscJet_puId);
   fChain->SetBranchAddress("DiscJet_btagCSV", DiscJet_btagCSV, &b_DiscJet_btagCSV);
   fChain->SetBranchAddress("DiscJet_btagCMVA", DiscJet_btagCMVA, &b_DiscJet_btagCMVA);
   fChain->SetBranchAddress("DiscJet_rawPt", DiscJet_rawPt, &b_DiscJet_rawPt);
   fChain->SetBranchAddress("DiscJet_mcPt", DiscJet_mcPt, &b_DiscJet_mcPt);
   fChain->SetBranchAddress("DiscJet_mcFlavour", DiscJet_mcFlavour, &b_DiscJet_mcFlavour);
   fChain->SetBranchAddress("DiscJet_partonFlavour", DiscJet_partonFlavour, &b_DiscJet_partonFlavour);
   fChain->SetBranchAddress("DiscJet_hadronFlavour", DiscJet_hadronFlavour, &b_DiscJet_hadronFlavour);
   fChain->SetBranchAddress("DiscJet_mcMatchId", DiscJet_mcMatchId, &b_DiscJet_mcMatchId);
   fChain->SetBranchAddress("DiscJet_corr_JECUp", DiscJet_corr_JECUp, &b_DiscJet_corr_JECUp);
   fChain->SetBranchAddress("DiscJet_corr_JECDown", DiscJet_corr_JECDown, &b_DiscJet_corr_JECDown);
   fChain->SetBranchAddress("DiscJet_corr", DiscJet_corr, &b_DiscJet_corr);
   fChain->SetBranchAddress("DiscJet_corr_JERUp", DiscJet_corr_JERUp, &b_DiscJet_corr_JERUp);
   fChain->SetBranchAddress("DiscJet_corr_JERDown", DiscJet_corr_JERDown, &b_DiscJet_corr_JERDown);
   fChain->SetBranchAddress("DiscJet_corr_JER", DiscJet_corr_JER, &b_DiscJet_corr_JER);
   fChain->SetBranchAddress("DiscJet_pt", DiscJet_pt, &b_DiscJet_pt);
   fChain->SetBranchAddress("DiscJet_eta", DiscJet_eta, &b_DiscJet_eta);
   fChain->SetBranchAddress("DiscJet_phi", DiscJet_phi, &b_DiscJet_phi);
   fChain->SetBranchAddress("DiscJet_mass", DiscJet_mass, &b_DiscJet_mass);
   fChain->SetBranchAddress("DiscJet_CorrFactor_L1", DiscJet_CorrFactor_L1, &b_DiscJet_CorrFactor_L1);
   fChain->SetBranchAddress("DiscJet_CorrFactor_L1L2", DiscJet_CorrFactor_L1L2, &b_DiscJet_CorrFactor_L1L2);
   fChain->SetBranchAddress("DiscJet_CorrFactor_L1L2L3", DiscJet_CorrFactor_L1L2L3, &b_DiscJet_CorrFactor_L1L2L3);
   fChain->SetBranchAddress("DiscJet_CorrFactor_L1L2L3Res", DiscJet_CorrFactor_L1L2L3Res, &b_DiscJet_CorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_pt", SV_pt, &b_SV_pt);
   fChain->SetBranchAddress("SV_eta", SV_eta, &b_SV_eta);
   fChain->SetBranchAddress("SV_phi", SV_phi, &b_SV_phi);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_charge", SV_charge, &b_SV_charge);
   fChain->SetBranchAddress("SV_ntracks", SV_ntracks, &b_SV_ntracks);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_ndof", SV_ndof, &b_SV_ndof);
   fChain->SetBranchAddress("SV_dxy", SV_dxy, &b_SV_dxy);
   fChain->SetBranchAddress("SV_edxy", SV_edxy, &b_SV_edxy);
   fChain->SetBranchAddress("SV_ip3d", SV_ip3d, &b_SV_ip3d);
   fChain->SetBranchAddress("SV_eip3d", SV_eip3d, &b_SV_eip3d);
   fChain->SetBranchAddress("SV_sip3d", SV_sip3d, &b_SV_sip3d);
   fChain->SetBranchAddress("SV_cosTheta", SV_cosTheta, &b_SV_cosTheta);
   fChain->SetBranchAddress("SV_mva", SV_mva, &b_SV_mva);
   fChain->SetBranchAddress("SV_jetPt", SV_jetPt, &b_SV_jetPt);
   fChain->SetBranchAddress("SV_jetEta", SV_jetEta, &b_SV_jetEta);
   fChain->SetBranchAddress("SV_jetDR", SV_jetDR, &b_SV_jetDR);
   fChain->SetBranchAddress("SV_jetBTagCSV", SV_jetBTagCSV, &b_SV_jetBTagCSV);
   fChain->SetBranchAddress("SV_jetBTagCMVA", SV_jetBTagCMVA, &b_SV_jetBTagCMVA);
   fChain->SetBranchAddress("SV_mcMatchNTracks", SV_mcMatchNTracks, &b_SV_mcMatchNTracks);
   fChain->SetBranchAddress("SV_mcMatchNTracksHF", SV_mcMatchNTracksHF, &b_SV_mcMatchNTracksHF);
   fChain->SetBranchAddress("SV_mcMatchFraction", SV_mcMatchFraction, &b_SV_mcMatchFraction);
   fChain->SetBranchAddress("SV_mcFlavFirst", SV_mcFlavFirst, &b_SV_mcFlavFirst);
   fChain->SetBranchAddress("SV_mcFlavHeaviest", SV_mcFlavHeaviest, &b_SV_mcFlavHeaviest);
   fChain->SetBranchAddress("SV_maxDxyTracks", SV_maxDxyTracks, &b_SV_maxDxyTracks);
   fChain->SetBranchAddress("SV_secDxyTracks", SV_secDxyTracks, &b_SV_secDxyTracks);
   fChain->SetBranchAddress("SV_maxD3dTracks", SV_maxD3dTracks, &b_SV_maxD3dTracks);
   fChain->SetBranchAddress("SV_secD3dTracks", SV_secD3dTracks, &b_SV_secD3dTracks);
   fChain->SetBranchAddress("nTauOther", &nTauOther, &b_nTauOther);
   fChain->SetBranchAddress("TauOther_charge", TauOther_charge, &b_TauOther_charge);
   fChain->SetBranchAddress("TauOther_decayMode", TauOther_decayMode, &b_TauOther_decayMode);
   fChain->SetBranchAddress("TauOther_idDecayMode", TauOther_idDecayMode, &b_TauOther_idDecayMode);
   fChain->SetBranchAddress("TauOther_idDecayModeNewDMs", TauOther_idDecayModeNewDMs, &b_TauOther_idDecayModeNewDMs);
   fChain->SetBranchAddress("TauOther_dxy", TauOther_dxy, &b_TauOther_dxy);
   fChain->SetBranchAddress("TauOther_dz", TauOther_dz, &b_TauOther_dz);
   fChain->SetBranchAddress("TauOther_idMVA", TauOther_idMVA, &b_TauOther_idMVA);
   fChain->SetBranchAddress("TauOther_idMVANewDM", TauOther_idMVANewDM, &b_TauOther_idMVANewDM);
   fChain->SetBranchAddress("TauOther_idCI3hit", TauOther_idCI3hit, &b_TauOther_idCI3hit);
   fChain->SetBranchAddress("TauOther_idAntiMu", TauOther_idAntiMu, &b_TauOther_idAntiMu);
   fChain->SetBranchAddress("TauOther_idAntiE", TauOther_idAntiE, &b_TauOther_idAntiE);
   fChain->SetBranchAddress("TauOther_isoCI3hit", TauOther_isoCI3hit, &b_TauOther_isoCI3hit);
   fChain->SetBranchAddress("TauOther_mcMatchId", TauOther_mcMatchId, &b_TauOther_mcMatchId);
   fChain->SetBranchAddress("TauOther_pdgId", TauOther_pdgId, &b_TauOther_pdgId);
   fChain->SetBranchAddress("TauOther_pt", TauOther_pt, &b_TauOther_pt);
   fChain->SetBranchAddress("TauOther_eta", TauOther_eta, &b_TauOther_eta);
   fChain->SetBranchAddress("TauOther_phi", TauOther_phi, &b_TauOther_phi);
   fChain->SetBranchAddress("TauOther_mass", TauOther_mass, &b_TauOther_mass);
   fChain->SetBranchAddress("TauOther_idMVAOldDMRun2", TauOther_idMVAOldDMRun2, &b_TauOther_idMVAOldDMRun2);
   fChain->SetBranchAddress("TauOther_idMVAOldDMRun2dR03", TauOther_idMVAOldDMRun2dR03, &b_TauOther_idMVAOldDMRun2dR03);
   fChain->SetBranchAddress("nLepGood", &nLepGood, &b_nLepGood);
   fChain->SetBranchAddress("LepGood_mvaIdSpring15", LepGood_mvaIdSpring15, &b_LepGood_mvaIdSpring15);
   fChain->SetBranchAddress("LepGood_mvaTTH", LepGood_mvaTTH, &b_LepGood_mvaTTH);
   fChain->SetBranchAddress("LepGood_mvaSUSY", LepGood_mvaSUSY, &b_LepGood_mvaSUSY);
   fChain->SetBranchAddress("LepGood_mvaSoftT2tt", LepGood_mvaSoftT2tt, &b_LepGood_mvaSoftT2tt);
   fChain->SetBranchAddress("LepGood_mvaSoftEWK", LepGood_mvaSoftEWK, &b_LepGood_mvaSoftEWK);
   fChain->SetBranchAddress("LepGood_jetPtRatiov1", LepGood_jetPtRatiov1, &b_LepGood_jetPtRatiov1);
   fChain->SetBranchAddress("LepGood_jetPtRelv1", LepGood_jetPtRelv1, &b_LepGood_jetPtRelv1);
   fChain->SetBranchAddress("LepGood_jetPtRatiov2", LepGood_jetPtRatiov2, &b_LepGood_jetPtRatiov2);
   fChain->SetBranchAddress("LepGood_jetPtRelv2", LepGood_jetPtRelv2, &b_LepGood_jetPtRelv2);
   fChain->SetBranchAddress("LepGood_jetBTagCSV", LepGood_jetBTagCSV, &b_LepGood_jetBTagCSV);
   fChain->SetBranchAddress("LepGood_jetBTagCMVA", LepGood_jetBTagCMVA, &b_LepGood_jetBTagCMVA);
   fChain->SetBranchAddress("LepGood_jetDR", LepGood_jetDR, &b_LepGood_jetDR);
   fChain->SetBranchAddress("LepGood_r9", LepGood_r9, &b_LepGood_r9);
   fChain->SetBranchAddress("LepGood_mvaIdSpring16", LepGood_mvaIdSpring16, &b_LepGood_mvaIdSpring16);
   fChain->SetBranchAddress("LepGood_charge", LepGood_charge, &b_LepGood_charge);
   fChain->SetBranchAddress("LepGood_tightId", LepGood_tightId, &b_LepGood_tightId);
   fChain->SetBranchAddress("LepGood_eleCutIdCSA14_25ns_v1", LepGood_eleCutIdCSA14_25ns_v1, &b_LepGood_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("LepGood_eleCutIdCSA14_50ns_v1", LepGood_eleCutIdCSA14_50ns_v1, &b_LepGood_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("LepGood_eleCutIdSpring15_25ns_v1", LepGood_eleCutIdSpring15_25ns_v1, &b_LepGood_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("LepGood_dxy", LepGood_dxy, &b_LepGood_dxy);
   fChain->SetBranchAddress("LepGood_dz", LepGood_dz, &b_LepGood_dz);
   fChain->SetBranchAddress("LepGood_edxy", LepGood_edxy, &b_LepGood_edxy);
   fChain->SetBranchAddress("LepGood_edz", LepGood_edz, &b_LepGood_edz);
   fChain->SetBranchAddress("LepGood_ip3d", LepGood_ip3d, &b_LepGood_ip3d);
   fChain->SetBranchAddress("LepGood_sip3d", LepGood_sip3d, &b_LepGood_sip3d);
   fChain->SetBranchAddress("LepGood_convVeto", LepGood_convVeto, &b_LepGood_convVeto);
   fChain->SetBranchAddress("LepGood_lostHits", LepGood_lostHits, &b_LepGood_lostHits);
   fChain->SetBranchAddress("LepGood_relIso03", LepGood_relIso03, &b_LepGood_relIso03);
   fChain->SetBranchAddress("LepGood_relIso04", LepGood_relIso04, &b_LepGood_relIso04);
   fChain->SetBranchAddress("LepGood_miniRelIso", LepGood_miniRelIso, &b_LepGood_miniRelIso);
   fChain->SetBranchAddress("LepGood_relIsoAn04", LepGood_relIsoAn04, &b_LepGood_relIsoAn04);
   fChain->SetBranchAddress("LepGood_tightCharge", LepGood_tightCharge, &b_LepGood_tightCharge);
   fChain->SetBranchAddress("LepGood_mcMatchId", LepGood_mcMatchId, &b_LepGood_mcMatchId);
   fChain->SetBranchAddress("LepGood_mcMatchAny", LepGood_mcMatchAny, &b_LepGood_mcMatchAny);
   fChain->SetBranchAddress("LepGood_mcMatchTau", LepGood_mcMatchTau, &b_LepGood_mcMatchTau);
   fChain->SetBranchAddress("LepGood_mcPt", LepGood_mcPt, &b_LepGood_mcPt);
   fChain->SetBranchAddress("LepGood_mediumMuonId", LepGood_mediumMuonId, &b_LepGood_mediumMuonId);
   fChain->SetBranchAddress("LepGood_ICHEPsoftMuonId", LepGood_ICHEPsoftMuonId, &b_LepGood_ICHEPsoftMuonId);
   fChain->SetBranchAddress("LepGood_ICHEPmediumMuonId", LepGood_ICHEPmediumMuonId, &b_LepGood_ICHEPmediumMuonId);
   fChain->SetBranchAddress("LepGood_pdgId", LepGood_pdgId, &b_LepGood_pdgId);
   fChain->SetBranchAddress("LepGood_pt", LepGood_pt, &b_LepGood_pt);
   fChain->SetBranchAddress("LepGood_eta", LepGood_eta, &b_LepGood_eta);
   fChain->SetBranchAddress("LepGood_phi", LepGood_phi, &b_LepGood_phi);
   fChain->SetBranchAddress("LepGood_mass", LepGood_mass, &b_LepGood_mass);
   fChain->SetBranchAddress("LepGood_looseIdOnly", LepGood_looseIdOnly, &b_LepGood_looseIdOnly);
   fChain->SetBranchAddress("LepGood_chargedHadRelIso03", LepGood_chargedHadRelIso03, &b_LepGood_chargedHadRelIso03);
   fChain->SetBranchAddress("LepGood_chargedHadRelIso04", LepGood_chargedHadRelIso04, &b_LepGood_chargedHadRelIso04);
   fChain->SetBranchAddress("LepGood_softMuonId", LepGood_softMuonId, &b_LepGood_softMuonId);
   fChain->SetBranchAddress("LepGood_pfMuonId", LepGood_pfMuonId, &b_LepGood_pfMuonId);
   fChain->SetBranchAddress("LepGood_eleCutId2012_full5x5", LepGood_eleCutId2012_full5x5, &b_LepGood_eleCutId2012_full5x5);
   fChain->SetBranchAddress("LepGood_trackerLayers", LepGood_trackerLayers, &b_LepGood_trackerLayers);
   fChain->SetBranchAddress("LepGood_pixelLayers", LepGood_pixelLayers, &b_LepGood_pixelLayers);
   fChain->SetBranchAddress("LepGood_trackerHits", LepGood_trackerHits, &b_LepGood_trackerHits);
   fChain->SetBranchAddress("LepGood_lostOuterHits", LepGood_lostOuterHits, &b_LepGood_lostOuterHits);
   fChain->SetBranchAddress("LepGood_innerTrackValidHitFraction", LepGood_innerTrackValidHitFraction, &b_LepGood_innerTrackValidHitFraction);
   fChain->SetBranchAddress("LepGood_innerTrackChi2", LepGood_innerTrackChi2, &b_LepGood_innerTrackChi2);
   fChain->SetBranchAddress("LepGood_nStations", LepGood_nStations, &b_LepGood_nStations);
   fChain->SetBranchAddress("LepGood_caloCompatibility", LepGood_caloCompatibility, &b_LepGood_caloCompatibility);
   fChain->SetBranchAddress("LepGood_globalTrackChi2", LepGood_globalTrackChi2, &b_LepGood_globalTrackChi2);
   fChain->SetBranchAddress("LepGood_trkKink", LepGood_trkKink, &b_LepGood_trkKink);
   fChain->SetBranchAddress("LepGood_segmentCompatibility", LepGood_segmentCompatibility, &b_LepGood_segmentCompatibility);
   fChain->SetBranchAddress("LepGood_chi2LocalPosition", LepGood_chi2LocalPosition, &b_LepGood_chi2LocalPosition);
   fChain->SetBranchAddress("LepGood_chi2LocalMomentum", LepGood_chi2LocalMomentum, &b_LepGood_chi2LocalMomentum);
   fChain->SetBranchAddress("LepGood_glbTrackProbability", LepGood_glbTrackProbability, &b_LepGood_glbTrackProbability);
   fChain->SetBranchAddress("LepGood_TMOneStationTightMuonId", LepGood_TMOneStationTightMuonId, &b_LepGood_TMOneStationTightMuonId);
   fChain->SetBranchAddress("LepGood_trackHighPurityMuon", LepGood_trackHighPurityMuon, &b_LepGood_trackHighPurityMuon);
   fChain->SetBranchAddress("LepGood_isGlobalMuon", LepGood_isGlobalMuon, &b_LepGood_isGlobalMuon);
   fChain->SetBranchAddress("LepGood_isTrackerMuon", LepGood_isTrackerMuon, &b_LepGood_isTrackerMuon);
   fChain->SetBranchAddress("LepGood_sigmaIEtaIEta", LepGood_sigmaIEtaIEta, &b_LepGood_sigmaIEtaIEta);
   fChain->SetBranchAddress("LepGood_dEtaScTrkIn", LepGood_dEtaScTrkIn, &b_LepGood_dEtaScTrkIn);
   fChain->SetBranchAddress("LepGood_dPhiScTrkIn", LepGood_dPhiScTrkIn, &b_LepGood_dPhiScTrkIn);
   fChain->SetBranchAddress("LepGood_hadronicOverEm", LepGood_hadronicOverEm, &b_LepGood_hadronicOverEm);
   fChain->SetBranchAddress("LepGood_eInvMinusPInv", LepGood_eInvMinusPInv, &b_LepGood_eInvMinusPInv);
   fChain->SetBranchAddress("LepGood_eInvMinusPInv_tkMom", LepGood_eInvMinusPInv_tkMom, &b_LepGood_eInvMinusPInv_tkMom);
   fChain->SetBranchAddress("LepGood_etaSc", LepGood_etaSc, &b_LepGood_etaSc);
   fChain->SetBranchAddress("LepGood_mcMatchPdgId", LepGood_mcMatchPdgId, &b_LepGood_mcMatchPdgId);
   fChain->SetBranchAddress("LepGood_miniRelIsoCharged", LepGood_miniRelIsoCharged, &b_LepGood_miniRelIsoCharged);
   fChain->SetBranchAddress("LepGood_miniRelIsoNeutral", LepGood_miniRelIsoNeutral, &b_LepGood_miniRelIsoNeutral);
   fChain->SetBranchAddress("LepGood_jetNDauChargedMVASel", LepGood_jetNDauChargedMVASel, &b_LepGood_jetNDauChargedMVASel);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1", LepGood_jetCorrFactor_L1, &b_LepGood_jetCorrFactor_L1);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2", LepGood_jetCorrFactor_L1L2, &b_LepGood_jetCorrFactor_L1L2);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2L3", LepGood_jetCorrFactor_L1L2L3, &b_LepGood_jetCorrFactor_L1L2L3);
   fChain->SetBranchAddress("LepGood_jetCorrFactor_L1L2L3Res", LepGood_jetCorrFactor_L1L2L3Res, &b_LepGood_jetCorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("LepGood_ecalPFClusterIso", LepGood_ecalPFClusterIso, &b_LepGood_ecalPFClusterIso);
   fChain->SetBranchAddress("LepGood_hcalPFClusterIso", LepGood_hcalPFClusterIso, &b_LepGood_hcalPFClusterIso);
   fChain->SetBranchAddress("LepGood_dr03TkSumPt", LepGood_dr03TkSumPt, &b_LepGood_dr03TkSumPt);
   fChain->SetBranchAddress("LepGood_trackIso", LepGood_trackIso, &b_LepGood_trackIso);
   fChain->SetBranchAddress("LepGood_idEmuTTH", LepGood_idEmuTTH, &b_LepGood_idEmuTTH);
   fChain->SetBranchAddress("LepGood_idEmuRA5", LepGood_idEmuRA5, &b_LepGood_idEmuRA5);
   fChain->SetBranchAddress("LepGood_idIsoEmuRA5", LepGood_idIsoEmuRA5, &b_LepGood_idIsoEmuRA5);
   fChain->SetBranchAddress("LepGood_mcPrompt", LepGood_mcPrompt, &b_LepGood_mcPrompt);
   fChain->SetBranchAddress("LepGood_mcPromptTau", LepGood_mcPromptTau, &b_LepGood_mcPromptTau);
   fChain->SetBranchAddress("LepGood_mcPromptGamma", LepGood_mcPromptGamma, &b_LepGood_mcPromptGamma);
   fChain->SetBranchAddress("LepGood_mcGamma", LepGood_mcGamma, &b_LepGood_mcGamma);
   fChain->SetBranchAddress("LepGood_RelIsoMIV03", LepGood_RelIsoMIV03, &b_LepGood_RelIsoMIV03);
   fChain->SetBranchAddress("LepGood_RelIsoMIVCharged03", LepGood_RelIsoMIVCharged03, &b_LepGood_RelIsoMIVCharged03);
   fChain->SetBranchAddress("LepGood_RelIsoMIVNeutral03", LepGood_RelIsoMIVNeutral03, &b_LepGood_RelIsoMIVNeutral03);
   fChain->SetBranchAddress("LepGood_RelIsoMIV04", LepGood_RelIsoMIV04, &b_LepGood_RelIsoMIV04);
   fChain->SetBranchAddress("LepGood_RelIsoMIVCharged04", LepGood_RelIsoMIVCharged04, &b_LepGood_RelIsoMIVCharged04);
   fChain->SetBranchAddress("LepGood_RelIsoMIVNeutral04", LepGood_RelIsoMIVNeutral04, &b_LepGood_RelIsoMIVNeutral04);
   fChain->SetBranchAddress("LepGood_jetPtRelHv2", LepGood_jetPtRelHv2, &b_LepGood_jetPtRelHv2);
   fChain->SetBranchAddress("LepGood_isoRelH04", LepGood_isoRelH04, &b_LepGood_isoRelH04);
   fChain->SetBranchAddress("LepGood_jetBasedRelIsoCharged", LepGood_jetBasedRelIsoCharged, &b_LepGood_jetBasedRelIsoCharged);
   fChain->SetBranchAddress("LepGood_hasSV", LepGood_hasSV, &b_LepGood_hasSV);
   fChain->SetBranchAddress("LepGood_svSip3d", LepGood_svSip3d, &b_LepGood_svSip3d);
   fChain->SetBranchAddress("LepGood_svRedPt", LepGood_svRedPt, &b_LepGood_svRedPt);
   fChain->SetBranchAddress("LepGood_svMass", LepGood_svMass, &b_LepGood_svMass);
   fChain->SetBranchAddress("LepGood_svNTracks", LepGood_svNTracks, &b_LepGood_svNTracks);
   fChain->SetBranchAddress("LepGood_mcUCSXMatchId", LepGood_mcUCSXMatchId, &b_LepGood_mcUCSXMatchId);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_pt", LepGood_jetLepAwareJEC_pt, &b_LepGood_jetLepAwareJEC_pt);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_eta", LepGood_jetLepAwareJEC_eta, &b_LepGood_jetLepAwareJEC_eta);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_phi", LepGood_jetLepAwareJEC_phi, &b_LepGood_jetLepAwareJEC_phi);
   fChain->SetBranchAddress("LepGood_jetLepAwareJEC_energy", LepGood_jetLepAwareJEC_energy, &b_LepGood_jetLepAwareJEC_energy);
   fChain->SetBranchAddress("nDiscJet_jecDown", &nDiscJet_jecDown, &b_nDiscJet_jecDown);
   fChain->SetBranchAddress("DiscJet_jecDown_mcMatchFlav", DiscJet_jecDown_mcMatchFlav, &b_DiscJet_jecDown_mcMatchFlav);
   fChain->SetBranchAddress("DiscJet_jecDown_charge", DiscJet_jecDown_charge, &b_DiscJet_jecDown_charge);
   fChain->SetBranchAddress("DiscJet_jecDown_ctagCsvL", DiscJet_jecDown_ctagCsvL, &b_DiscJet_jecDown_ctagCsvL);
   fChain->SetBranchAddress("DiscJet_jecDown_ctagCsvB", DiscJet_jecDown_ctagCsvB, &b_DiscJet_jecDown_ctagCsvB);
   fChain->SetBranchAddress("DiscJet_jecDown_area", DiscJet_jecDown_area, &b_DiscJet_jecDown_area);
   fChain->SetBranchAddress("DiscJet_jecDown_qgl", DiscJet_jecDown_qgl, &b_DiscJet_jecDown_qgl);
   fChain->SetBranchAddress("DiscJet_jecDown_ptd", DiscJet_jecDown_ptd, &b_DiscJet_jecDown_ptd);
   fChain->SetBranchAddress("DiscJet_jecDown_axis2", DiscJet_jecDown_axis2, &b_DiscJet_jecDown_axis2);
   fChain->SetBranchAddress("DiscJet_jecDown_mult", DiscJet_jecDown_mult, &b_DiscJet_jecDown_mult);
   fChain->SetBranchAddress("DiscJet_jecDown_partonId", DiscJet_jecDown_partonId, &b_DiscJet_jecDown_partonId);
   fChain->SetBranchAddress("DiscJet_jecDown_partonMotherId", DiscJet_jecDown_partonMotherId, &b_DiscJet_jecDown_partonMotherId);
   fChain->SetBranchAddress("DiscJet_jecDown_nLeptons", DiscJet_jecDown_nLeptons, &b_DiscJet_jecDown_nLeptons);
   fChain->SetBranchAddress("DiscJet_jecDown_id", DiscJet_jecDown_id, &b_DiscJet_jecDown_id);
   fChain->SetBranchAddress("DiscJet_jecDown_puId", DiscJet_jecDown_puId, &b_DiscJet_jecDown_puId);
   fChain->SetBranchAddress("DiscJet_jecDown_btagCSV", DiscJet_jecDown_btagCSV, &b_DiscJet_jecDown_btagCSV);
   fChain->SetBranchAddress("DiscJet_jecDown_btagCMVA", DiscJet_jecDown_btagCMVA, &b_DiscJet_jecDown_btagCMVA);
   fChain->SetBranchAddress("DiscJet_jecDown_rawPt", DiscJet_jecDown_rawPt, &b_DiscJet_jecDown_rawPt);
   fChain->SetBranchAddress("DiscJet_jecDown_mcPt", DiscJet_jecDown_mcPt, &b_DiscJet_jecDown_mcPt);
   fChain->SetBranchAddress("DiscJet_jecDown_mcFlavour", DiscJet_jecDown_mcFlavour, &b_DiscJet_jecDown_mcFlavour);
   fChain->SetBranchAddress("DiscJet_jecDown_partonFlavour", DiscJet_jecDown_partonFlavour, &b_DiscJet_jecDown_partonFlavour);
   fChain->SetBranchAddress("DiscJet_jecDown_hadronFlavour", DiscJet_jecDown_hadronFlavour, &b_DiscJet_jecDown_hadronFlavour);
   fChain->SetBranchAddress("DiscJet_jecDown_mcMatchId", DiscJet_jecDown_mcMatchId, &b_DiscJet_jecDown_mcMatchId);
   fChain->SetBranchAddress("DiscJet_jecDown_corr_JECUp", DiscJet_jecDown_corr_JECUp, &b_DiscJet_jecDown_corr_JECUp);
   fChain->SetBranchAddress("DiscJet_jecDown_corr_JECDown", DiscJet_jecDown_corr_JECDown, &b_DiscJet_jecDown_corr_JECDown);
   fChain->SetBranchAddress("DiscJet_jecDown_corr", DiscJet_jecDown_corr, &b_DiscJet_jecDown_corr);
   fChain->SetBranchAddress("DiscJet_jecDown_corr_JERUp", DiscJet_jecDown_corr_JERUp, &b_DiscJet_jecDown_corr_JERUp);
   fChain->SetBranchAddress("DiscJet_jecDown_corr_JERDown", DiscJet_jecDown_corr_JERDown, &b_DiscJet_jecDown_corr_JERDown);
   fChain->SetBranchAddress("DiscJet_jecDown_corr_JER", DiscJet_jecDown_corr_JER, &b_DiscJet_jecDown_corr_JER);
   fChain->SetBranchAddress("DiscJet_jecDown_pt", DiscJet_jecDown_pt, &b_DiscJet_jecDown_pt);
   fChain->SetBranchAddress("DiscJet_jecDown_eta", DiscJet_jecDown_eta, &b_DiscJet_jecDown_eta);
   fChain->SetBranchAddress("DiscJet_jecDown_phi", DiscJet_jecDown_phi, &b_DiscJet_jecDown_phi);
   fChain->SetBranchAddress("DiscJet_jecDown_mass", DiscJet_jecDown_mass, &b_DiscJet_jecDown_mass);
   fChain->SetBranchAddress("DiscJet_jecDown_CorrFactor_L1", DiscJet_jecDown_CorrFactor_L1, &b_DiscJet_jecDown_CorrFactor_L1);
   fChain->SetBranchAddress("DiscJet_jecDown_CorrFactor_L1L2", DiscJet_jecDown_CorrFactor_L1L2, &b_DiscJet_jecDown_CorrFactor_L1L2);
   fChain->SetBranchAddress("DiscJet_jecDown_CorrFactor_L1L2L3", DiscJet_jecDown_CorrFactor_L1L2L3, &b_DiscJet_jecDown_CorrFactor_L1L2L3);
   fChain->SetBranchAddress("DiscJet_jecDown_CorrFactor_L1L2L3Res", DiscJet_jecDown_CorrFactor_L1L2L3Res, &b_DiscJet_jecDown_CorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("nJet_jecUp", &nJet_jecUp, &b_nJet_jecUp);
   fChain->SetBranchAddress("Jet_jecUp_mcMatchFlav", Jet_jecUp_mcMatchFlav, &b_Jet_jecUp_mcMatchFlav);
   fChain->SetBranchAddress("Jet_jecUp_charge", Jet_jecUp_charge, &b_Jet_jecUp_charge);
   fChain->SetBranchAddress("Jet_jecUp_ctagCsvL", Jet_jecUp_ctagCsvL, &b_Jet_jecUp_ctagCsvL);
   fChain->SetBranchAddress("Jet_jecUp_ctagCsvB", Jet_jecUp_ctagCsvB, &b_Jet_jecUp_ctagCsvB);
   fChain->SetBranchAddress("Jet_jecUp_area", Jet_jecUp_area, &b_Jet_jecUp_area);
   fChain->SetBranchAddress("Jet_jecUp_qgl", Jet_jecUp_qgl, &b_Jet_jecUp_qgl);
   fChain->SetBranchAddress("Jet_jecUp_ptd", Jet_jecUp_ptd, &b_Jet_jecUp_ptd);
   fChain->SetBranchAddress("Jet_jecUp_axis2", Jet_jecUp_axis2, &b_Jet_jecUp_axis2);
   fChain->SetBranchAddress("Jet_jecUp_mult", Jet_jecUp_mult, &b_Jet_jecUp_mult);
   fChain->SetBranchAddress("Jet_jecUp_partonId", Jet_jecUp_partonId, &b_Jet_jecUp_partonId);
   fChain->SetBranchAddress("Jet_jecUp_partonMotherId", Jet_jecUp_partonMotherId, &b_Jet_jecUp_partonMotherId);
   fChain->SetBranchAddress("Jet_jecUp_nLeptons", Jet_jecUp_nLeptons, &b_Jet_jecUp_nLeptons);
   fChain->SetBranchAddress("Jet_jecUp_id", Jet_jecUp_id, &b_Jet_jecUp_id);
   fChain->SetBranchAddress("Jet_jecUp_puId", Jet_jecUp_puId, &b_Jet_jecUp_puId);
   fChain->SetBranchAddress("Jet_jecUp_btagCSV", Jet_jecUp_btagCSV, &b_Jet_jecUp_btagCSV);
   fChain->SetBranchAddress("Jet_jecUp_btagCMVA", Jet_jecUp_btagCMVA, &b_Jet_jecUp_btagCMVA);
   fChain->SetBranchAddress("Jet_jecUp_rawPt", Jet_jecUp_rawPt, &b_Jet_jecUp_rawPt);
   fChain->SetBranchAddress("Jet_jecUp_mcPt", Jet_jecUp_mcPt, &b_Jet_jecUp_mcPt);
   fChain->SetBranchAddress("Jet_jecUp_mcFlavour", Jet_jecUp_mcFlavour, &b_Jet_jecUp_mcFlavour);
   fChain->SetBranchAddress("Jet_jecUp_partonFlavour", Jet_jecUp_partonFlavour, &b_Jet_jecUp_partonFlavour);
   fChain->SetBranchAddress("Jet_jecUp_hadronFlavour", Jet_jecUp_hadronFlavour, &b_Jet_jecUp_hadronFlavour);
   fChain->SetBranchAddress("Jet_jecUp_mcMatchId", Jet_jecUp_mcMatchId, &b_Jet_jecUp_mcMatchId);
   fChain->SetBranchAddress("Jet_jecUp_corr_JECUp", Jet_jecUp_corr_JECUp, &b_Jet_jecUp_corr_JECUp);
   fChain->SetBranchAddress("Jet_jecUp_corr_JECDown", Jet_jecUp_corr_JECDown, &b_Jet_jecUp_corr_JECDown);
   fChain->SetBranchAddress("Jet_jecUp_corr", Jet_jecUp_corr, &b_Jet_jecUp_corr);
   fChain->SetBranchAddress("Jet_jecUp_corr_JERUp", Jet_jecUp_corr_JERUp, &b_Jet_jecUp_corr_JERUp);
   fChain->SetBranchAddress("Jet_jecUp_corr_JERDown", Jet_jecUp_corr_JERDown, &b_Jet_jecUp_corr_JERDown);
   fChain->SetBranchAddress("Jet_jecUp_corr_JER", Jet_jecUp_corr_JER, &b_Jet_jecUp_corr_JER);
   fChain->SetBranchAddress("Jet_jecUp_pt", Jet_jecUp_pt, &b_Jet_jecUp_pt);
   fChain->SetBranchAddress("Jet_jecUp_eta", Jet_jecUp_eta, &b_Jet_jecUp_eta);
   fChain->SetBranchAddress("Jet_jecUp_phi", Jet_jecUp_phi, &b_Jet_jecUp_phi);
   fChain->SetBranchAddress("Jet_jecUp_mass", Jet_jecUp_mass, &b_Jet_jecUp_mass);
   fChain->SetBranchAddress("Jet_jecUp_CorrFactor_L1", Jet_jecUp_CorrFactor_L1, &b_Jet_jecUp_CorrFactor_L1);
   fChain->SetBranchAddress("Jet_jecUp_CorrFactor_L1L2", Jet_jecUp_CorrFactor_L1L2, &b_Jet_jecUp_CorrFactor_L1L2);
   fChain->SetBranchAddress("Jet_jecUp_CorrFactor_L1L2L3", Jet_jecUp_CorrFactor_L1L2L3, &b_Jet_jecUp_CorrFactor_L1L2L3);
   fChain->SetBranchAddress("Jet_jecUp_CorrFactor_L1L2L3Res", Jet_jecUp_CorrFactor_L1L2L3Res, &b_Jet_jecUp_CorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("nGenDHad", &nGenDHad, &b_nGenDHad);
   fChain->SetBranchAddress("GenDHad_charge", GenDHad_charge, &b_GenDHad_charge);
   fChain->SetBranchAddress("GenDHad_status", GenDHad_status, &b_GenDHad_status);
   fChain->SetBranchAddress("GenDHad_isPromptHard", GenDHad_isPromptHard, &b_GenDHad_isPromptHard);
   fChain->SetBranchAddress("GenDHad_pdgId", GenDHad_pdgId, &b_GenDHad_pdgId);
   fChain->SetBranchAddress("GenDHad_pt", GenDHad_pt, &b_GenDHad_pt);
   fChain->SetBranchAddress("GenDHad_eta", GenDHad_eta, &b_GenDHad_eta);
   fChain->SetBranchAddress("GenDHad_phi", GenDHad_phi, &b_GenDHad_phi);
   fChain->SetBranchAddress("GenDHad_mass", GenDHad_mass, &b_GenDHad_mass);
   fChain->SetBranchAddress("GenDHad_flav", GenDHad_flav, &b_GenDHad_flav);
   fChain->SetBranchAddress("GenDHad_sourceId", GenDHad_sourceId, &b_GenDHad_sourceId);
   fChain->SetBranchAddress("GenDHad_svMass", GenDHad_svMass, &b_GenDHad_svMass);
   fChain->SetBranchAddress("GenDHad_svPt", GenDHad_svPt, &b_GenDHad_svPt);
   fChain->SetBranchAddress("GenDHad_svCharge", GenDHad_svCharge, &b_GenDHad_svCharge);
   fChain->SetBranchAddress("GenDHad_svNtracks", GenDHad_svNtracks, &b_GenDHad_svNtracks);
   fChain->SetBranchAddress("GenDHad_svChi2", GenDHad_svChi2, &b_GenDHad_svChi2);
   fChain->SetBranchAddress("GenDHad_svNdof", GenDHad_svNdof, &b_GenDHad_svNdof);
   fChain->SetBranchAddress("GenDHad_svDxy", GenDHad_svDxy, &b_GenDHad_svDxy);
   fChain->SetBranchAddress("GenDHad_svEdxy", GenDHad_svEdxy, &b_GenDHad_svEdxy);
   fChain->SetBranchAddress("GenDHad_svIp3d", GenDHad_svIp3d, &b_GenDHad_svIp3d);
   fChain->SetBranchAddress("GenDHad_svEip3d", GenDHad_svEip3d, &b_GenDHad_svEip3d);
   fChain->SetBranchAddress("GenDHad_svSip3d", GenDHad_svSip3d, &b_GenDHad_svSip3d);
   fChain->SetBranchAddress("GenDHad_svCosTheta", GenDHad_svCosTheta, &b_GenDHad_svCosTheta);
   fChain->SetBranchAddress("GenDHad_svMva", GenDHad_svMva, &b_GenDHad_svMva);
   fChain->SetBranchAddress("GenDHad_jetPt", GenDHad_jetPt, &b_GenDHad_jetPt);
   fChain->SetBranchAddress("GenDHad_jetBTagCSV", GenDHad_jetBTagCSV, &b_GenDHad_jetBTagCSV);
   fChain->SetBranchAddress("GenDHad_jetBTagCMVA", GenDHad_jetBTagCMVA, &b_GenDHad_jetBTagCMVA);
   fChain->SetBranchAddress("nGenBHad", &nGenBHad, &b_nGenBHad);
   fChain->SetBranchAddress("GenBHad_charge", GenBHad_charge, &b_GenBHad_charge);
   fChain->SetBranchAddress("GenBHad_status", GenBHad_status, &b_GenBHad_status);
   fChain->SetBranchAddress("GenBHad_isPromptHard", GenBHad_isPromptHard, &b_GenBHad_isPromptHard);
   fChain->SetBranchAddress("GenBHad_pdgId", GenBHad_pdgId, &b_GenBHad_pdgId);
   fChain->SetBranchAddress("GenBHad_pt", GenBHad_pt, &b_GenBHad_pt);
   fChain->SetBranchAddress("GenBHad_eta", GenBHad_eta, &b_GenBHad_eta);
   fChain->SetBranchAddress("GenBHad_phi", GenBHad_phi, &b_GenBHad_phi);
   fChain->SetBranchAddress("GenBHad_mass", GenBHad_mass, &b_GenBHad_mass);
   fChain->SetBranchAddress("GenBHad_flav", GenBHad_flav, &b_GenBHad_flav);
   fChain->SetBranchAddress("GenBHad_sourceId", GenBHad_sourceId, &b_GenBHad_sourceId);
   fChain->SetBranchAddress("GenBHad_svMass", GenBHad_svMass, &b_GenBHad_svMass);
   fChain->SetBranchAddress("GenBHad_svPt", GenBHad_svPt, &b_GenBHad_svPt);
   fChain->SetBranchAddress("GenBHad_svCharge", GenBHad_svCharge, &b_GenBHad_svCharge);
   fChain->SetBranchAddress("GenBHad_svNtracks", GenBHad_svNtracks, &b_GenBHad_svNtracks);
   fChain->SetBranchAddress("GenBHad_svChi2", GenBHad_svChi2, &b_GenBHad_svChi2);
   fChain->SetBranchAddress("GenBHad_svNdof", GenBHad_svNdof, &b_GenBHad_svNdof);
   fChain->SetBranchAddress("GenBHad_svDxy", GenBHad_svDxy, &b_GenBHad_svDxy);
   fChain->SetBranchAddress("GenBHad_svEdxy", GenBHad_svEdxy, &b_GenBHad_svEdxy);
   fChain->SetBranchAddress("GenBHad_svIp3d", GenBHad_svIp3d, &b_GenBHad_svIp3d);
   fChain->SetBranchAddress("GenBHad_svEip3d", GenBHad_svEip3d, &b_GenBHad_svEip3d);
   fChain->SetBranchAddress("GenBHad_svSip3d", GenBHad_svSip3d, &b_GenBHad_svSip3d);
   fChain->SetBranchAddress("GenBHad_svCosTheta", GenBHad_svCosTheta, &b_GenBHad_svCosTheta);
   fChain->SetBranchAddress("GenBHad_svMva", GenBHad_svMva, &b_GenBHad_svMva);
   fChain->SetBranchAddress("GenBHad_jetPt", GenBHad_jetPt, &b_GenBHad_jetPt);
   fChain->SetBranchAddress("GenBHad_jetBTagCSV", GenBHad_jetBTagCSV, &b_GenBHad_jetBTagCSV);
   fChain->SetBranchAddress("GenBHad_jetBTagCMVA", GenBHad_jetBTagCMVA, &b_GenBHad_jetBTagCMVA);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_mcMatchFlav", Jet_mcMatchFlav, &b_Jet_mcMatchFlav);
   fChain->SetBranchAddress("Jet_charge", Jet_charge, &b_Jet_charge);
   fChain->SetBranchAddress("Jet_ctagCsvL", Jet_ctagCsvL, &b_Jet_ctagCsvL);
   fChain->SetBranchAddress("Jet_ctagCsvB", Jet_ctagCsvB, &b_Jet_ctagCsvB);
   fChain->SetBranchAddress("Jet_area", Jet_area, &b_Jet_area);
   fChain->SetBranchAddress("Jet_qgl", Jet_qgl, &b_Jet_qgl);
   fChain->SetBranchAddress("Jet_ptd", Jet_ptd, &b_Jet_ptd);
   fChain->SetBranchAddress("Jet_axis2", Jet_axis2, &b_Jet_axis2);
   fChain->SetBranchAddress("Jet_mult", Jet_mult, &b_Jet_mult);
   fChain->SetBranchAddress("Jet_partonId", Jet_partonId, &b_Jet_partonId);
   fChain->SetBranchAddress("Jet_partonMotherId", Jet_partonMotherId, &b_Jet_partonMotherId);
   fChain->SetBranchAddress("Jet_nLeptons", Jet_nLeptons, &b_Jet_nLeptons);
   fChain->SetBranchAddress("Jet_id", Jet_id, &b_Jet_id);
   fChain->SetBranchAddress("Jet_puId", Jet_puId, &b_Jet_puId);
   fChain->SetBranchAddress("Jet_btagCSV", Jet_btagCSV, &b_Jet_btagCSV);
   fChain->SetBranchAddress("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   fChain->SetBranchAddress("Jet_rawPt", Jet_rawPt, &b_Jet_rawPt);
   fChain->SetBranchAddress("Jet_mcPt", Jet_mcPt, &b_Jet_mcPt);
   fChain->SetBranchAddress("Jet_mcFlavour", Jet_mcFlavour, &b_Jet_mcFlavour);
   fChain->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   fChain->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   fChain->SetBranchAddress("Jet_mcMatchId", Jet_mcMatchId, &b_Jet_mcMatchId);
   fChain->SetBranchAddress("Jet_corr_JECUp", Jet_corr_JECUp, &b_Jet_corr_JECUp);
   fChain->SetBranchAddress("Jet_corr_JECDown", Jet_corr_JECDown, &b_Jet_corr_JECDown);
   fChain->SetBranchAddress("Jet_corr", Jet_corr, &b_Jet_corr);
   fChain->SetBranchAddress("Jet_corr_JERUp", Jet_corr_JERUp, &b_Jet_corr_JERUp);
   fChain->SetBranchAddress("Jet_corr_JERDown", Jet_corr_JERDown, &b_Jet_corr_JERDown);
   fChain->SetBranchAddress("Jet_corr_JER", Jet_corr_JER, &b_Jet_corr_JER);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_CorrFactor_L1", Jet_CorrFactor_L1, &b_Jet_CorrFactor_L1);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2", Jet_CorrFactor_L1L2, &b_Jet_CorrFactor_L1L2);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2L3", Jet_CorrFactor_L1L2L3, &b_Jet_CorrFactor_L1L2L3);
   fChain->SetBranchAddress("Jet_CorrFactor_L1L2L3Res", Jet_CorrFactor_L1L2L3Res, &b_Jet_CorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("nJetNoTauIdx", &nJetNoTauIdx, &b_nJetNoTauIdx);
   fChain->SetBranchAddress("JetNoTauIdx", JetNoTauIdx, &b_JetNoTauIdx);
   fChain->SetBranchAddress("nLHEweight", &nLHEweight, &b_nLHEweight);
   fChain->SetBranchAddress("LHEweight_id", LHEweight_id, &b_LHEweight_id);
   fChain->SetBranchAddress("LHEweight_wgt", LHEweight_wgt, &b_LHEweight_wgt);
   fChain->SetBranchAddress("nTauGood", &nTauGood, &b_nTauGood);
   fChain->SetBranchAddress("TauGood_charge", TauGood_charge, &b_TauGood_charge);
   fChain->SetBranchAddress("TauGood_decayMode", TauGood_decayMode, &b_TauGood_decayMode);
   fChain->SetBranchAddress("TauGood_idDecayMode", TauGood_idDecayMode, &b_TauGood_idDecayMode);
   fChain->SetBranchAddress("TauGood_idDecayModeNewDMs", TauGood_idDecayModeNewDMs, &b_TauGood_idDecayModeNewDMs);
   fChain->SetBranchAddress("TauGood_dxy", TauGood_dxy, &b_TauGood_dxy);
   fChain->SetBranchAddress("TauGood_dz", TauGood_dz, &b_TauGood_dz);
   fChain->SetBranchAddress("TauGood_idMVA", TauGood_idMVA, &b_TauGood_idMVA);
   fChain->SetBranchAddress("TauGood_idMVANewDM", TauGood_idMVANewDM, &b_TauGood_idMVANewDM);
   fChain->SetBranchAddress("TauGood_idCI3hit", TauGood_idCI3hit, &b_TauGood_idCI3hit);
   fChain->SetBranchAddress("TauGood_idAntiMu", TauGood_idAntiMu, &b_TauGood_idAntiMu);
   fChain->SetBranchAddress("TauGood_idAntiE", TauGood_idAntiE, &b_TauGood_idAntiE);
   fChain->SetBranchAddress("TauGood_isoCI3hit", TauGood_isoCI3hit, &b_TauGood_isoCI3hit);
   fChain->SetBranchAddress("TauGood_mcMatchId", TauGood_mcMatchId, &b_TauGood_mcMatchId);
   fChain->SetBranchAddress("TauGood_pdgId", TauGood_pdgId, &b_TauGood_pdgId);
   fChain->SetBranchAddress("TauGood_pt", TauGood_pt, &b_TauGood_pt);
   fChain->SetBranchAddress("TauGood_eta", TauGood_eta, &b_TauGood_eta);
   fChain->SetBranchAddress("TauGood_phi", TauGood_phi, &b_TauGood_phi);
   fChain->SetBranchAddress("TauGood_mass", TauGood_mass, &b_TauGood_mass);
   fChain->SetBranchAddress("TauGood_idMVAOldDMRun2", TauGood_idMVAOldDMRun2, &b_TauGood_idMVAOldDMRun2);
   fChain->SetBranchAddress("TauGood_idMVAOldDMRun2dR03", TauGood_idMVAOldDMRun2dR03, &b_TauGood_idMVAOldDMRun2dR03);
   fChain->SetBranchAddress("ngenLep", &ngenLep, &b_ngenLep);
   fChain->SetBranchAddress("genLep_motherId", genLep_motherId, &b_genLep_motherId);
   fChain->SetBranchAddress("genLep_grandmotherId", genLep_grandmotherId, &b_genLep_grandmotherId);
   fChain->SetBranchAddress("genLep_sourceId", genLep_sourceId, &b_genLep_sourceId);
   fChain->SetBranchAddress("genLep_charge", genLep_charge, &b_genLep_charge);
   fChain->SetBranchAddress("genLep_status", genLep_status, &b_genLep_status);
   fChain->SetBranchAddress("genLep_isPromptHard", genLep_isPromptHard, &b_genLep_isPromptHard);
   fChain->SetBranchAddress("genLep_pdgId", genLep_pdgId, &b_genLep_pdgId);
   fChain->SetBranchAddress("genLep_pt", genLep_pt, &b_genLep_pt);
   fChain->SetBranchAddress("genLep_eta", genLep_eta, &b_genLep_eta);
   fChain->SetBranchAddress("genLep_phi", genLep_phi, &b_genLep_phi);
   fChain->SetBranchAddress("genLep_mass", genLep_mass, &b_genLep_mass);
   fChain->SetBranchAddress("genLep_motherIndex", genLep_motherIndex, &b_genLep_motherIndex);
   fChain->SetBranchAddress("ngenTau", &ngenTau, &b_ngenTau);
   fChain->SetBranchAddress("genTau_motherId", genTau_motherId, &b_genTau_motherId);
   fChain->SetBranchAddress("genTau_grandmotherId", genTau_grandmotherId, &b_genTau_grandmotherId);
   fChain->SetBranchAddress("genTau_sourceId", genTau_sourceId, &b_genTau_sourceId);
   fChain->SetBranchAddress("genTau_charge", genTau_charge, &b_genTau_charge);
   fChain->SetBranchAddress("genTau_status", genTau_status, &b_genTau_status);
   fChain->SetBranchAddress("genTau_isPromptHard", genTau_isPromptHard, &b_genTau_isPromptHard);
   fChain->SetBranchAddress("genTau_pdgId", genTau_pdgId, &b_genTau_pdgId);
   fChain->SetBranchAddress("genTau_pt", genTau_pt, &b_genTau_pt);
   fChain->SetBranchAddress("genTau_eta", genTau_eta, &b_genTau_eta);
   fChain->SetBranchAddress("genTau_phi", genTau_phi, &b_genTau_phi);
   fChain->SetBranchAddress("genTau_mass", genTau_mass, &b_genTau_mass);
   fChain->SetBranchAddress("genTau_motherIndex", genTau_motherIndex, &b_genTau_motherIndex);
   fChain->SetBranchAddress("nJet_jecDown", &nJet_jecDown, &b_nJet_jecDown);
   fChain->SetBranchAddress("Jet_jecDown_mcMatchFlav", Jet_jecDown_mcMatchFlav, &b_Jet_jecDown_mcMatchFlav);
   fChain->SetBranchAddress("Jet_jecDown_charge", Jet_jecDown_charge, &b_Jet_jecDown_charge);
   fChain->SetBranchAddress("Jet_jecDown_ctagCsvL", Jet_jecDown_ctagCsvL, &b_Jet_jecDown_ctagCsvL);
   fChain->SetBranchAddress("Jet_jecDown_ctagCsvB", Jet_jecDown_ctagCsvB, &b_Jet_jecDown_ctagCsvB);
   fChain->SetBranchAddress("Jet_jecDown_area", Jet_jecDown_area, &b_Jet_jecDown_area);
   fChain->SetBranchAddress("Jet_jecDown_qgl", Jet_jecDown_qgl, &b_Jet_jecDown_qgl);
   fChain->SetBranchAddress("Jet_jecDown_ptd", Jet_jecDown_ptd, &b_Jet_jecDown_ptd);
   fChain->SetBranchAddress("Jet_jecDown_axis2", Jet_jecDown_axis2, &b_Jet_jecDown_axis2);
   fChain->SetBranchAddress("Jet_jecDown_mult", Jet_jecDown_mult, &b_Jet_jecDown_mult);
   fChain->SetBranchAddress("Jet_jecDown_partonId", Jet_jecDown_partonId, &b_Jet_jecDown_partonId);
   fChain->SetBranchAddress("Jet_jecDown_partonMotherId", Jet_jecDown_partonMotherId, &b_Jet_jecDown_partonMotherId);
   fChain->SetBranchAddress("Jet_jecDown_nLeptons", Jet_jecDown_nLeptons, &b_Jet_jecDown_nLeptons);
   fChain->SetBranchAddress("Jet_jecDown_id", Jet_jecDown_id, &b_Jet_jecDown_id);
   fChain->SetBranchAddress("Jet_jecDown_puId", Jet_jecDown_puId, &b_Jet_jecDown_puId);
   fChain->SetBranchAddress("Jet_jecDown_btagCSV", Jet_jecDown_btagCSV, &b_Jet_jecDown_btagCSV);
   fChain->SetBranchAddress("Jet_jecDown_btagCMVA", Jet_jecDown_btagCMVA, &b_Jet_jecDown_btagCMVA);
   fChain->SetBranchAddress("Jet_jecDown_rawPt", Jet_jecDown_rawPt, &b_Jet_jecDown_rawPt);
   fChain->SetBranchAddress("Jet_jecDown_mcPt", Jet_jecDown_mcPt, &b_Jet_jecDown_mcPt);
   fChain->SetBranchAddress("Jet_jecDown_mcFlavour", Jet_jecDown_mcFlavour, &b_Jet_jecDown_mcFlavour);
   fChain->SetBranchAddress("Jet_jecDown_partonFlavour", Jet_jecDown_partonFlavour, &b_Jet_jecDown_partonFlavour);
   fChain->SetBranchAddress("Jet_jecDown_hadronFlavour", Jet_jecDown_hadronFlavour, &b_Jet_jecDown_hadronFlavour);
   fChain->SetBranchAddress("Jet_jecDown_mcMatchId", Jet_jecDown_mcMatchId, &b_Jet_jecDown_mcMatchId);
   fChain->SetBranchAddress("Jet_jecDown_corr_JECUp", Jet_jecDown_corr_JECUp, &b_Jet_jecDown_corr_JECUp);
   fChain->SetBranchAddress("Jet_jecDown_corr_JECDown", Jet_jecDown_corr_JECDown, &b_Jet_jecDown_corr_JECDown);
   fChain->SetBranchAddress("Jet_jecDown_corr", Jet_jecDown_corr, &b_Jet_jecDown_corr);
   fChain->SetBranchAddress("Jet_jecDown_corr_JERUp", Jet_jecDown_corr_JERUp, &b_Jet_jecDown_corr_JERUp);
   fChain->SetBranchAddress("Jet_jecDown_corr_JERDown", Jet_jecDown_corr_JERDown, &b_Jet_jecDown_corr_JERDown);
   fChain->SetBranchAddress("Jet_jecDown_corr_JER", Jet_jecDown_corr_JER, &b_Jet_jecDown_corr_JER);
   fChain->SetBranchAddress("Jet_jecDown_pt", Jet_jecDown_pt, &b_Jet_jecDown_pt);
   fChain->SetBranchAddress("Jet_jecDown_eta", Jet_jecDown_eta, &b_Jet_jecDown_eta);
   fChain->SetBranchAddress("Jet_jecDown_phi", Jet_jecDown_phi, &b_Jet_jecDown_phi);
   fChain->SetBranchAddress("Jet_jecDown_mass", Jet_jecDown_mass, &b_Jet_jecDown_mass);
   fChain->SetBranchAddress("Jet_jecDown_CorrFactor_L1", Jet_jecDown_CorrFactor_L1, &b_Jet_jecDown_CorrFactor_L1);
   fChain->SetBranchAddress("Jet_jecDown_CorrFactor_L1L2", Jet_jecDown_CorrFactor_L1L2, &b_Jet_jecDown_CorrFactor_L1L2);
   fChain->SetBranchAddress("Jet_jecDown_CorrFactor_L1L2L3", Jet_jecDown_CorrFactor_L1L2L3, &b_Jet_jecDown_CorrFactor_L1L2L3);
   fChain->SetBranchAddress("Jet_jecDown_CorrFactor_L1L2L3Res", Jet_jecDown_CorrFactor_L1L2L3Res, &b_Jet_jecDown_CorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("nGenTop", &nGenTop, &b_nGenTop);
   fChain->SetBranchAddress("GenTop_pdgId", GenTop_pdgId, &b_GenTop_pdgId);
   fChain->SetBranchAddress("GenTop_pt", GenTop_pt, &b_GenTop_pt);
   fChain->SetBranchAddress("GenTop_eta", GenTop_eta, &b_GenTop_eta);
   fChain->SetBranchAddress("GenTop_phi", GenTop_phi, &b_GenTop_phi);
   fChain->SetBranchAddress("GenTop_mass", GenTop_mass, &b_GenTop_mass);
   fChain->SetBranchAddress("GenTop_charge", GenTop_charge, &b_GenTop_charge);
   fChain->SetBranchAddress("GenTop_status", GenTop_status, &b_GenTop_status);
   fChain->SetBranchAddress("GenTop_isPromptHard", GenTop_isPromptHard, &b_GenTop_isPromptHard);
   fChain->SetBranchAddress("nLepOther", &nLepOther, &b_nLepOther);
   fChain->SetBranchAddress("LepOther_charge", LepOther_charge, &b_LepOther_charge);
   fChain->SetBranchAddress("LepOther_tightId", LepOther_tightId, &b_LepOther_tightId);
   fChain->SetBranchAddress("LepOther_eleCutIdCSA14_25ns_v1", LepOther_eleCutIdCSA14_25ns_v1, &b_LepOther_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("LepOther_eleCutIdCSA14_50ns_v1", LepOther_eleCutIdCSA14_50ns_v1, &b_LepOther_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("LepOther_eleCutIdSpring15_25ns_v1", LepOther_eleCutIdSpring15_25ns_v1, &b_LepOther_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("LepOther_dxy", LepOther_dxy, &b_LepOther_dxy);
   fChain->SetBranchAddress("LepOther_dz", LepOther_dz, &b_LepOther_dz);
   fChain->SetBranchAddress("LepOther_edxy", LepOther_edxy, &b_LepOther_edxy);
   fChain->SetBranchAddress("LepOther_edz", LepOther_edz, &b_LepOther_edz);
   fChain->SetBranchAddress("LepOther_ip3d", LepOther_ip3d, &b_LepOther_ip3d);
   fChain->SetBranchAddress("LepOther_sip3d", LepOther_sip3d, &b_LepOther_sip3d);
   fChain->SetBranchAddress("LepOther_convVeto", LepOther_convVeto, &b_LepOther_convVeto);
   fChain->SetBranchAddress("LepOther_lostHits", LepOther_lostHits, &b_LepOther_lostHits);
   fChain->SetBranchAddress("LepOther_relIso03", LepOther_relIso03, &b_LepOther_relIso03);
   fChain->SetBranchAddress("LepOther_relIso04", LepOther_relIso04, &b_LepOther_relIso04);
   fChain->SetBranchAddress("LepOther_miniRelIso", LepOther_miniRelIso, &b_LepOther_miniRelIso);
   fChain->SetBranchAddress("LepOther_relIsoAn04", LepOther_relIsoAn04, &b_LepOther_relIsoAn04);
   fChain->SetBranchAddress("LepOther_tightCharge", LepOther_tightCharge, &b_LepOther_tightCharge);
   fChain->SetBranchAddress("LepOther_mcMatchId", LepOther_mcMatchId, &b_LepOther_mcMatchId);
   fChain->SetBranchAddress("LepOther_mcMatchAny", LepOther_mcMatchAny, &b_LepOther_mcMatchAny);
   fChain->SetBranchAddress("LepOther_mcMatchTau", LepOther_mcMatchTau, &b_LepOther_mcMatchTau);
   fChain->SetBranchAddress("LepOther_mcPt", LepOther_mcPt, &b_LepOther_mcPt);
   fChain->SetBranchAddress("LepOther_mediumMuonId", LepOther_mediumMuonId, &b_LepOther_mediumMuonId);
   fChain->SetBranchAddress("LepOther_ICHEPsoftMuonId", LepOther_ICHEPsoftMuonId, &b_LepOther_ICHEPsoftMuonId);
   fChain->SetBranchAddress("LepOther_ICHEPmediumMuonId", LepOther_ICHEPmediumMuonId, &b_LepOther_ICHEPmediumMuonId);
   fChain->SetBranchAddress("LepOther_pdgId", LepOther_pdgId, &b_LepOther_pdgId);
   fChain->SetBranchAddress("LepOther_pt", LepOther_pt, &b_LepOther_pt);
   fChain->SetBranchAddress("LepOther_eta", LepOther_eta, &b_LepOther_eta);
   fChain->SetBranchAddress("LepOther_phi", LepOther_phi, &b_LepOther_phi);
   fChain->SetBranchAddress("LepOther_mass", LepOther_mass, &b_LepOther_mass);
   fChain->SetBranchAddress("LepOther_mvaIdSpring15", LepOther_mvaIdSpring15, &b_LepOther_mvaIdSpring15);
   fChain->SetBranchAddress("LepOther_mvaTTH", LepOther_mvaTTH, &b_LepOther_mvaTTH);
   fChain->SetBranchAddress("LepOther_mvaSUSY", LepOther_mvaSUSY, &b_LepOther_mvaSUSY);
   fChain->SetBranchAddress("LepOther_mvaSoftT2tt", LepOther_mvaSoftT2tt, &b_LepOther_mvaSoftT2tt);
   fChain->SetBranchAddress("LepOther_mvaSoftEWK", LepOther_mvaSoftEWK, &b_LepOther_mvaSoftEWK);
   fChain->SetBranchAddress("LepOther_jetPtRatiov1", LepOther_jetPtRatiov1, &b_LepOther_jetPtRatiov1);
   fChain->SetBranchAddress("LepOther_jetPtRelv1", LepOther_jetPtRelv1, &b_LepOther_jetPtRelv1);
   fChain->SetBranchAddress("LepOther_jetPtRatiov2", LepOther_jetPtRatiov2, &b_LepOther_jetPtRatiov2);
   fChain->SetBranchAddress("LepOther_jetPtRelv2", LepOther_jetPtRelv2, &b_LepOther_jetPtRelv2);
   fChain->SetBranchAddress("LepOther_jetBTagCSV", LepOther_jetBTagCSV, &b_LepOther_jetBTagCSV);
   fChain->SetBranchAddress("LepOther_jetBTagCMVA", LepOther_jetBTagCMVA, &b_LepOther_jetBTagCMVA);
   fChain->SetBranchAddress("LepOther_jetDR", LepOther_jetDR, &b_LepOther_jetDR);
   fChain->SetBranchAddress("LepOther_r9", LepOther_r9, &b_LepOther_r9);
   fChain->SetBranchAddress("LepOther_mvaIdSpring16", LepOther_mvaIdSpring16, &b_LepOther_mvaIdSpring16);
   fChain->SetBranchAddress("nDiscJet_jecUp", &nDiscJet_jecUp, &b_nDiscJet_jecUp);
   fChain->SetBranchAddress("DiscJet_jecUp_mcMatchFlav", DiscJet_jecUp_mcMatchFlav, &b_DiscJet_jecUp_mcMatchFlav);
   fChain->SetBranchAddress("DiscJet_jecUp_charge", DiscJet_jecUp_charge, &b_DiscJet_jecUp_charge);
   fChain->SetBranchAddress("DiscJet_jecUp_ctagCsvL", DiscJet_jecUp_ctagCsvL, &b_DiscJet_jecUp_ctagCsvL);
   fChain->SetBranchAddress("DiscJet_jecUp_ctagCsvB", DiscJet_jecUp_ctagCsvB, &b_DiscJet_jecUp_ctagCsvB);
   fChain->SetBranchAddress("DiscJet_jecUp_area", DiscJet_jecUp_area, &b_DiscJet_jecUp_area);
   fChain->SetBranchAddress("DiscJet_jecUp_qgl", DiscJet_jecUp_qgl, &b_DiscJet_jecUp_qgl);
   fChain->SetBranchAddress("DiscJet_jecUp_ptd", DiscJet_jecUp_ptd, &b_DiscJet_jecUp_ptd);
   fChain->SetBranchAddress("DiscJet_jecUp_axis2", DiscJet_jecUp_axis2, &b_DiscJet_jecUp_axis2);
   fChain->SetBranchAddress("DiscJet_jecUp_mult", DiscJet_jecUp_mult, &b_DiscJet_jecUp_mult);
   fChain->SetBranchAddress("DiscJet_jecUp_partonId", DiscJet_jecUp_partonId, &b_DiscJet_jecUp_partonId);
   fChain->SetBranchAddress("DiscJet_jecUp_partonMotherId", DiscJet_jecUp_partonMotherId, &b_DiscJet_jecUp_partonMotherId);
   fChain->SetBranchAddress("DiscJet_jecUp_nLeptons", DiscJet_jecUp_nLeptons, &b_DiscJet_jecUp_nLeptons);
   fChain->SetBranchAddress("DiscJet_jecUp_id", DiscJet_jecUp_id, &b_DiscJet_jecUp_id);
   fChain->SetBranchAddress("DiscJet_jecUp_puId", DiscJet_jecUp_puId, &b_DiscJet_jecUp_puId);
   fChain->SetBranchAddress("DiscJet_jecUp_btagCSV", DiscJet_jecUp_btagCSV, &b_DiscJet_jecUp_btagCSV);
   fChain->SetBranchAddress("DiscJet_jecUp_btagCMVA", DiscJet_jecUp_btagCMVA, &b_DiscJet_jecUp_btagCMVA);
   fChain->SetBranchAddress("DiscJet_jecUp_rawPt", DiscJet_jecUp_rawPt, &b_DiscJet_jecUp_rawPt);
   fChain->SetBranchAddress("DiscJet_jecUp_mcPt", DiscJet_jecUp_mcPt, &b_DiscJet_jecUp_mcPt);
   fChain->SetBranchAddress("DiscJet_jecUp_mcFlavour", DiscJet_jecUp_mcFlavour, &b_DiscJet_jecUp_mcFlavour);
   fChain->SetBranchAddress("DiscJet_jecUp_partonFlavour", DiscJet_jecUp_partonFlavour, &b_DiscJet_jecUp_partonFlavour);
   fChain->SetBranchAddress("DiscJet_jecUp_hadronFlavour", DiscJet_jecUp_hadronFlavour, &b_DiscJet_jecUp_hadronFlavour);
   fChain->SetBranchAddress("DiscJet_jecUp_mcMatchId", DiscJet_jecUp_mcMatchId, &b_DiscJet_jecUp_mcMatchId);
   fChain->SetBranchAddress("DiscJet_jecUp_corr_JECUp", DiscJet_jecUp_corr_JECUp, &b_DiscJet_jecUp_corr_JECUp);
   fChain->SetBranchAddress("DiscJet_jecUp_corr_JECDown", DiscJet_jecUp_corr_JECDown, &b_DiscJet_jecUp_corr_JECDown);
   fChain->SetBranchAddress("DiscJet_jecUp_corr", DiscJet_jecUp_corr, &b_DiscJet_jecUp_corr);
   fChain->SetBranchAddress("DiscJet_jecUp_corr_JERUp", DiscJet_jecUp_corr_JERUp, &b_DiscJet_jecUp_corr_JERUp);
   fChain->SetBranchAddress("DiscJet_jecUp_corr_JERDown", DiscJet_jecUp_corr_JERDown, &b_DiscJet_jecUp_corr_JERDown);
   fChain->SetBranchAddress("DiscJet_jecUp_corr_JER", DiscJet_jecUp_corr_JER, &b_DiscJet_jecUp_corr_JER);
   fChain->SetBranchAddress("DiscJet_jecUp_pt", DiscJet_jecUp_pt, &b_DiscJet_jecUp_pt);
   fChain->SetBranchAddress("DiscJet_jecUp_eta", DiscJet_jecUp_eta, &b_DiscJet_jecUp_eta);
   fChain->SetBranchAddress("DiscJet_jecUp_phi", DiscJet_jecUp_phi, &b_DiscJet_jecUp_phi);
   fChain->SetBranchAddress("DiscJet_jecUp_mass", DiscJet_jecUp_mass, &b_DiscJet_jecUp_mass);
   fChain->SetBranchAddress("DiscJet_jecUp_CorrFactor_L1", DiscJet_jecUp_CorrFactor_L1, &b_DiscJet_jecUp_CorrFactor_L1);
   fChain->SetBranchAddress("DiscJet_jecUp_CorrFactor_L1L2", DiscJet_jecUp_CorrFactor_L1L2, &b_DiscJet_jecUp_CorrFactor_L1L2);
   fChain->SetBranchAddress("DiscJet_jecUp_CorrFactor_L1L2L3", DiscJet_jecUp_CorrFactor_L1L2L3, &b_DiscJet_jecUp_CorrFactor_L1L2L3);
   fChain->SetBranchAddress("DiscJet_jecUp_CorrFactor_L1L2L3Res", DiscJet_jecUp_CorrFactor_L1L2L3Res, &b_DiscJet_jecUp_CorrFactor_L1L2L3Res);
   fChain->SetBranchAddress("ngenLepFromTau", &ngenLepFromTau, &b_ngenLepFromTau);
   fChain->SetBranchAddress("genLepFromTau_motherId", genLepFromTau_motherId, &b_genLepFromTau_motherId);
   fChain->SetBranchAddress("genLepFromTau_grandmotherId", genLepFromTau_grandmotherId, &b_genLepFromTau_grandmotherId);
   fChain->SetBranchAddress("genLepFromTau_sourceId", genLepFromTau_sourceId, &b_genLepFromTau_sourceId);
   fChain->SetBranchAddress("genLepFromTau_charge", genLepFromTau_charge, &b_genLepFromTau_charge);
   fChain->SetBranchAddress("genLepFromTau_status", genLepFromTau_status, &b_genLepFromTau_status);
   fChain->SetBranchAddress("genLepFromTau_isPromptHard", genLepFromTau_isPromptHard, &b_genLepFromTau_isPromptHard);
   fChain->SetBranchAddress("genLepFromTau_pdgId", genLepFromTau_pdgId, &b_genLepFromTau_pdgId);
   fChain->SetBranchAddress("genLepFromTau_pt", genLepFromTau_pt, &b_genLepFromTau_pt);
   fChain->SetBranchAddress("genLepFromTau_eta", genLepFromTau_eta, &b_genLepFromTau_eta);
   fChain->SetBranchAddress("genLepFromTau_phi", genLepFromTau_phi, &b_genLepFromTau_phi);
   fChain->SetBranchAddress("genLepFromTau_mass", genLepFromTau_mass, &b_genLepFromTau_mass);
   fChain->SetBranchAddress("genLepFromTau_motherIndex", genLepFromTau_motherIndex, &b_genLepFromTau_motherIndex);
   fChain->SetBranchAddress("nJetFwd", &nJetFwd, &b_nJetFwd);
   fChain->SetBranchAddress("JetFwd_area", JetFwd_area, &b_JetFwd_area);
   fChain->SetBranchAddress("JetFwd_qgl", JetFwd_qgl, &b_JetFwd_qgl);
   fChain->SetBranchAddress("JetFwd_ptd", JetFwd_ptd, &b_JetFwd_ptd);
   fChain->SetBranchAddress("JetFwd_axis2", JetFwd_axis2, &b_JetFwd_axis2);
   fChain->SetBranchAddress("JetFwd_mult", JetFwd_mult, &b_JetFwd_mult);
   fChain->SetBranchAddress("JetFwd_partonId", JetFwd_partonId, &b_JetFwd_partonId);
   fChain->SetBranchAddress("JetFwd_partonMotherId", JetFwd_partonMotherId, &b_JetFwd_partonMotherId);
   fChain->SetBranchAddress("JetFwd_nLeptons", JetFwd_nLeptons, &b_JetFwd_nLeptons);
   fChain->SetBranchAddress("JetFwd_id", JetFwd_id, &b_JetFwd_id);
   fChain->SetBranchAddress("JetFwd_puId", JetFwd_puId, &b_JetFwd_puId);
   fChain->SetBranchAddress("JetFwd_btagCSV", JetFwd_btagCSV, &b_JetFwd_btagCSV);
   fChain->SetBranchAddress("JetFwd_btagCMVA", JetFwd_btagCMVA, &b_JetFwd_btagCMVA);
   fChain->SetBranchAddress("JetFwd_rawPt", JetFwd_rawPt, &b_JetFwd_rawPt);
   fChain->SetBranchAddress("JetFwd_mcPt", JetFwd_mcPt, &b_JetFwd_mcPt);
   fChain->SetBranchAddress("JetFwd_mcFlavour", JetFwd_mcFlavour, &b_JetFwd_mcFlavour);
   fChain->SetBranchAddress("JetFwd_partonFlavour", JetFwd_partonFlavour, &b_JetFwd_partonFlavour);
   fChain->SetBranchAddress("JetFwd_hadronFlavour", JetFwd_hadronFlavour, &b_JetFwd_hadronFlavour);
   fChain->SetBranchAddress("JetFwd_mcMatchId", JetFwd_mcMatchId, &b_JetFwd_mcMatchId);
   fChain->SetBranchAddress("JetFwd_corr_JECUp", JetFwd_corr_JECUp, &b_JetFwd_corr_JECUp);
   fChain->SetBranchAddress("JetFwd_corr_JECDown", JetFwd_corr_JECDown, &b_JetFwd_corr_JECDown);
   fChain->SetBranchAddress("JetFwd_corr", JetFwd_corr, &b_JetFwd_corr);
   fChain->SetBranchAddress("JetFwd_corr_JERUp", JetFwd_corr_JERUp, &b_JetFwd_corr_JERUp);
   fChain->SetBranchAddress("JetFwd_corr_JERDown", JetFwd_corr_JERDown, &b_JetFwd_corr_JERDown);
   fChain->SetBranchAddress("JetFwd_corr_JER", JetFwd_corr_JER, &b_JetFwd_corr_JER);
   fChain->SetBranchAddress("JetFwd_pt", JetFwd_pt, &b_JetFwd_pt);
   fChain->SetBranchAddress("JetFwd_eta", JetFwd_eta, &b_JetFwd_eta);
   fChain->SetBranchAddress("JetFwd_phi", JetFwd_phi, &b_JetFwd_phi);
   fChain->SetBranchAddress("JetFwd_mass", JetFwd_mass, &b_JetFwd_mass);
   fChain->SetBranchAddress("JetFwd_mcMatchFlav", JetFwd_mcMatchFlav, &b_JetFwd_mcMatchFlav);
   fChain->SetBranchAddress("JetFwd_charge", JetFwd_charge, &b_JetFwd_charge);
   fChain->SetBranchAddress("JetFwd_ctagCsvL", JetFwd_ctagCsvL, &b_JetFwd_ctagCsvL);
   fChain->SetBranchAddress("JetFwd_ctagCsvB", JetFwd_ctagCsvB, &b_JetFwd_ctagCsvB);
   fChain->SetBranchAddress("nPhoGood", &nPhoGood, &b_nPhoGood);
   fChain->SetBranchAddress("PhoGood_etaSc", PhoGood_etaSc, &b_PhoGood_etaSc);
   fChain->SetBranchAddress("PhoGood_idCutBased", PhoGood_idCutBased, &b_PhoGood_idCutBased);
   fChain->SetBranchAddress("PhoGood_hOverE", PhoGood_hOverE, &b_PhoGood_hOverE);
   fChain->SetBranchAddress("PhoGood_r9", PhoGood_r9, &b_PhoGood_r9);
   fChain->SetBranchAddress("PhoGood_sigmaIetaIeta", PhoGood_sigmaIetaIeta, &b_PhoGood_sigmaIetaIeta);
   fChain->SetBranchAddress("PhoGood_chHadIso04", PhoGood_chHadIso04, &b_PhoGood_chHadIso04);
   fChain->SetBranchAddress("PhoGood_chHadIso", PhoGood_chHadIso, &b_PhoGood_chHadIso);
   fChain->SetBranchAddress("PhoGood_phIso", PhoGood_phIso, &b_PhoGood_phIso);
   fChain->SetBranchAddress("PhoGood_neuHadIso", PhoGood_neuHadIso, &b_PhoGood_neuHadIso);
   fChain->SetBranchAddress("PhoGood_relIso", PhoGood_relIso, &b_PhoGood_relIso);
   fChain->SetBranchAddress("PhoGood_mcMatchId", PhoGood_mcMatchId, &b_PhoGood_mcMatchId);
   fChain->SetBranchAddress("PhoGood_mcPt", PhoGood_mcPt, &b_PhoGood_mcPt);
   fChain->SetBranchAddress("PhoGood_pdgId", PhoGood_pdgId, &b_PhoGood_pdgId);
   fChain->SetBranchAddress("PhoGood_pt", PhoGood_pt, &b_PhoGood_pt);
   fChain->SetBranchAddress("PhoGood_eta", PhoGood_eta, &b_PhoGood_eta);
   fChain->SetBranchAddress("PhoGood_phi", PhoGood_phi, &b_PhoGood_phi);
   fChain->SetBranchAddress("PhoGood_mass", PhoGood_mass, &b_PhoGood_mass);
   fChain->SetBranchAddress("PhoGood_genIso04", PhoGood_genIso04, &b_PhoGood_genIso04);
   fChain->SetBranchAddress("PhoGood_genIso03", PhoGood_genIso03, &b_PhoGood_genIso03);
   fChain->SetBranchAddress("PhoGood_chHadIsoRC04", PhoGood_chHadIsoRC04, &b_PhoGood_chHadIsoRC04);
   fChain->SetBranchAddress("PhoGood_chHadIsoRC", PhoGood_chHadIsoRC, &b_PhoGood_chHadIsoRC);
   fChain->SetBranchAddress("PhoGood_drMinParton", PhoGood_drMinParton, &b_PhoGood_drMinParton);
   Notify();
}

Bool_t MiniTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MiniTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MiniTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void MiniTree::Loop() { }
#endif
