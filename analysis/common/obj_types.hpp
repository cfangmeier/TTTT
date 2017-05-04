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
 * Define some common data structures used throughout the analysis and methods
 * to make them available.
 */
#ifndef OBJ_TYPES_HPP
#define OBJ_TYPES_HPP

#include "TLorentzVector.h"
#include "filval/filval.hpp"
#include "analysis/MiniTreeDataSet.hpp"

struct Jet{
    float b_cmva;
    int   mcMatchFlav;
};

struct Lepton {
    int pdg_id;
    int mcMatchPdgId;
    int charge;
    float relIso;
};

struct GenPart{
    int pdgId;
    int motherIndex;
    int motherId;
    int status;
};


struct Particle{
    enum{JET,
         LEPTON,
         GENPART,
         VOID,
        }          tag;
    int            idx;
    TLorentzVector v;

    union
    {
        Jet     jet;
        Lepton  lepton;
        GenPart genpart;
    };

    static Particle
    Jet(int idx, TLorentzVector v, Jet&& jet){
        Particle p = {Particle::JET, idx, v, {}};
        p.jet = jet;
        return p;
    }

    static Particle
    Lepton(int idx, TLorentzVector v, Lepton&& lepton){
        Particle p = {Particle::LEPTON, idx, v, {}};
        p.lepton = lepton;
        return p;
    }

    static Particle
    GenPart(int idx, TLorentzVector v, GenPart&& genpart){
        Particle p = {Particle::GENPART, idx, v, {}};
        p.genpart = genpart;
        return p;
    }

    static Particle
    Void(){
        Particle p;
        p.tag = Particle::VOID;
        return p;
    }

};

Function<Particle(std::vector<Particle>)>& leading_particle = GenFunction::reg_func<Particle(std::vector<Particle>)>("leading_particle",
    FUNC(([](const std::vector<Particle>& particles){
        if(particles.size() == 0) return Particle::Void();

        Particle leading_particle = particles[0];
        for (auto particle : particles){
            if(particle.tag != Particle::VOID && particle.v.Pt() > leading_particle.v.Pt()){
                leading_particle = particle;
            }
        }
        return leading_particle;
    })));

Function<float(Particle)>& particle_pt = GenFunction::reg_func<float(Particle)>("particle_pt",
        FUNC(([](const Particle& p){
            return p.v.Pt();
        })));
Function<float(Particle)>& particle_eta = GenFunction::reg_func<float(Particle)>("particle_eta",
        FUNC(([](const Particle& p){
            return p.v.Eta();
        })));


Function<float(Particle)>& lepton_relIso = GenFunction::reg_func<float(Particle)>("lepton_relIso",
        FUNC(([](const Particle& p){
            return p.lepton.relIso;
        })));

decltype(auto)
construct_jets_value(MiniTreeDataSet& mt){

    mt.track_branch<int>("nJet");
    mt.track_branch_vec<float>("nJet", "Jet_pt");
    mt.track_branch_vec<float>("nJet", "Jet_eta");
    mt.track_branch_vec<float>("nJet", "Jet_phi");
    mt.track_branch_vec<float>("nJet", "Jet_mass");
    auto Jet_4v = lorentz_vectors("Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass", "Jet_4v");


    auto jets = apply(GenFunction::reg_func<std::vector<Particle>(std::vector<TLorentzVector>,
                                                                           std::vector<float>,
                                                                           std::vector< int >
                                                                           )>("build_reco_jets",
        FUNC(([](const std::vector<TLorentzVector>& vs,
                 const std::vector<float>&          b_cmvas,
                 const std::vector< int >&          mcMatchFlavs
                 ){
            std::vector<Particle> jets;
            for(int i=0; i<vs.size(); i++){
                Particle p = Particle::Jet(i, vs[i], {b_cmvas[i],
                                                      mcMatchFlavs[i]
                                                      });
                jets.push_back(p);
            }
            return jets;
        }))), fv::tuple(Jet_4v,
                        mt.track_branch_vec<float>("nJet", "Jet_btagCMVA"),
                        mt.track_branch_vec< int >("nJet", "Jet_mcMatchFlav")
                       ), "jets");
    return jets;
}

decltype(auto)
construct_b_jets_value(MiniTreeDataSet& mt){
    auto b_jets = fv::filter(GenFunction::reg_func<bool(Particle)>("is_b_jet",
        FUNC(([](const Particle& p){
            if(p.tag != Particle::JET) return false;
            return p.jet.b_cmva > 0;
        }))), lookup<std::vector<Particle>>("jets"), "b_jets");
    return b_jets;
}


decltype(auto)
construct_leptons_value(MiniTreeDataSet& mt){
    mt.track_branch<int>("nLepGood");
    mt.track_branch_vec<float>("nLepGood", "LepGood_pt");
    mt.track_branch_vec<float>("nLepGood", "LepGood_eta");
    mt.track_branch_vec<float>("nLepGood", "LepGood_phi");
    mt.track_branch_vec<float>("nLepGood", "LepGood_mass");
    auto LepGood_4v = lorentz_vectors("LepGood_pt", "LepGood_eta", "LepGood_phi", "LepGood_mass", "LepGood_4v");


    auto leptons = apply(GenFunction::reg_func<std::vector<Particle>(std::vector<TLorentzVector>,
                                                                              std::vector<int>,
                                                                              std::vector<int>,
                                                                              std::vector<int>,
                                                                              std::vector<float>)>("build_reco_leptons",
        FUNC(([](const std::vector<TLorentzVector>& vs,
                 const std::vector<int>& pdgIds,
                 const std::vector<int>& mcMatchPdgIds,
                 const std::vector<int>& charges,
                 const std::vector<float>& relIso
                 ){
            std::vector<Particle> leptons;
            for(int i=0; i<vs.size(); i++){
                Particle p = Particle::Lepton(i, vs[i], {pdgIds[i],
                                                         mcMatchPdgIds[i],
                                                         charges[i],
                                                         relIso[i]});
                leptons.push_back(p);
            }
            return leptons;
        }))), fv::tuple(LepGood_4v,
                        mt.track_branch_vec< int >("nLepGood", "LepGood_pdgId"),
                        mt.track_branch_vec< int >("nLepGood", "LepGood_mcMatchPdgId"),
                        mt.track_branch_vec< int >("nLepGood", "LepGood_charge"),
                        mt.track_branch_vec<float>("nLepGood", "LepGood_miniRelIso")
                        ), "leptons");
    return leptons;
}

decltype(auto)
construct_mc_jets_value(MiniTreeDataSet& mt){
    mt.track_branch<int>("nGenPart");
    mt.track_branch_vec<float>("nGenPart", "GenPart_pt");
    mt.track_branch_vec<float>("nGenPart", "GenPart_eta");
    mt.track_branch_vec<float>("nGenPart", "GenPart_phi");
    mt.track_branch_vec<float>("nGenPart", "GenPart_mass");
    auto Jet_4v = lorentz_vectors("GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "GenPart_4v");
    energies(Jet_4v, "GenPart_energy");

    auto mc_jets = apply(GenFunction::reg_func<std::vector<Particle>(std::vector<TLorentzVector>,
                                                                              std::vector<int>,
                                                                              std::vector<int>,
                                                                              std::vector<int>,
                                                                              std::vector<int>)>("build_mc_jets",
        FUNC(([](const std::vector<TLorentzVector>& vs,
                 const std::vector<int>& pdgIds,
                 const std::vector<int>& motherIndices,
                 const std::vector<int>& motherIds,
                 const std::vector<int>& statuses){
            std::vector<Particle> mc_jets;
            for(int i=0; i<vs.size(); i++){
                Particle p = Particle::GenPart(i, vs[i], {pdgIds[i],
                                                          motherIndices[i],
                                                          motherIds[i],
                                                          statuses[i]});
                mc_jets.push_back(p);
            }
            return mc_jets;
        }))), fv::tuple(Jet_4v,
                        mt.track_branch_vec<int>("nGenPart", "GenPart_pdgId"),
                        mt.track_branch_vec<int>("nGenPart", "GenPart_motherIndex"),
                        mt.track_branch_vec<int>("nGenPart", "GenPart_motherId"),
                        mt.track_branch_vec<int>("nGenPart", "GenPart_status")
                        ),"mc_jets");
    return mc_jets;
}

void create_all_common_values(MiniTreeDataSet& mt){
    construct_jets_value(mt);
    construct_b_jets_value(mt);
    construct_mc_jets_value(mt);
    construct_leptons_value(mt);
}

#endif
