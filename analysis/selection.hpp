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
 * Define a set of common event selections
 */
#ifndef SELECTION_HPP
#define SELECTION_HPP

#include <vector>
#include <algorithm>

#include "filval/filval.hpp"
#include "filval/root/root_filval.hpp"

#include "analysis/common/obj_types.hpp"

struct EventSelection{
    ObsFilter* trilepton;
    ObsFilter* trilepton_eemu; // OS electron pair + muon+-
    ObsFilter* trilepton_mumue; // OS muon pair + electron+-
    ObsFilter* b_jet3;
    ObsFilter* z_mass_veto;

    ObsFilter* base_sel;

    ObsFilter* J4;
    ObsFilter* J5;
    ObsFilter* J6;

    ObsFilter* SR4j;
    ObsFilter* SR5j;
    ObsFilter* SR6j;
};

EventSelection event_selection;

void init_selection(){
    auto leptons = lookup<std::vector<Particle>>("leptons");
    auto jets    = lookup<std::vector<Particle>>("jets");

    // Require *exactly* three charged leptons
    event_selection.trilepton = obs_filter("trilepton",GenFunction::register_function<bool()>("trilepton",
        FUNC(([leptons](){
            return leptons->get_value().size() == 3;
        }))));

    // Require OS electron pair and a muon
    event_selection.trilepton_eemu = obs_filter("trilepton_eemu",GenFunction::register_function<bool()>("trilepton_eemu",
        FUNC(([leptons](){
            std::vector<Particle>& leps = leptons->get_value();
            if(leps.size() != 3) return false;
            auto check_id = [](int ref_id){
                auto fn = [ref_id](const Particle& p){
                    return p.lepton.pdg_id == ref_id;
                };
                return fn;
            };
            bool has_ep = std::count_if(std::begin(leps), std::end(leps),  check_id(-11)) == 1;
            bool has_en = std::count_if(std::begin(leps), std::end(leps),  check_id( 11)) == 1;
            bool has_mup = std::count_if(std::begin(leps), std::end(leps), check_id(-13)) == 1;
            bool has_mun = std::count_if(std::begin(leps), std::end(leps), check_id( 13)) == 1;

            return has_ep && has_en && (has_mup != has_mun);
        }))));

    // Require OS muon pair and an electron
    event_selection.trilepton_mumue = obs_filter("trilepton_mumue",GenFunction::register_function<bool()>("trilepton_mumue",
        FUNC(([leptons](){
            std::vector<Particle>& leps = leptons->get_value();
            if(leps.size() != 3) return false;
            auto check_id = [](int ref_id){
                auto fn = [ref_id](const Particle& p){
                    return p.lepton.pdg_id == ref_id;
                };
                return fn;
            };
            bool has_ep = std::count_if(std::begin(leps), std::end(leps),  check_id(-11)) == 1;
            bool has_en = std::count_if(std::begin(leps), std::end(leps),  check_id( 11)) == 1;
            bool has_mup = std::count_if(std::begin(leps), std::end(leps), check_id(-13)) == 1;
            bool has_mun = std::count_if(std::begin(leps), std::end(leps), check_id( 13)) == 1;

            return (has_ep != has_en) && has_mup && has_mun;
        }))));

    // Require at least three b-jets
    event_selection.b_jet3 = obs_filter("b_jet3",GenFunction::register_function<bool()>("b_jet3",
        FUNC(([jets](){
            int n_b_jets = 0;
            for(auto jet : jets->get_value()){
                if(jet.tag == Particle::JET && jet.jet.b_cmva > 0)
                    n_b_jets++;
            }
            return n_b_jets >= 3;
        }))));

    // Require all same-flavour OS dilepton combinations are outside the Z mass
    // window (70,105)
    event_selection.z_mass_veto = obs_filter("z_mass_veto",GenFunction::register_function<bool()>("z_mass_veto",
        FUNC(([leptons](){
            auto& leps = leptons->get_value();
            int n = leps.size();
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    const Particle& p1 = leps[i];
                    const Particle& p2 = leps[j];
                    if(abs(p1.lepton.pdg_id) != abs(p2.lepton.pdg_id)) continue;
                    if(p1.lepton.charge == p2.lepton.charge) continue;
                    double m = (p1.v + p2.v).M();
                    if(70 < m && m < 105)
                        return false;
                }
            }
            return true;
        }))));


    event_selection.J4 = obs_filter("4jet_selection",GenFunction::register_function<bool()>("4jet_selection",
        FUNC(([jets](){
            return jets->get_value().size() >= 4;
        }))));

    event_selection.J5 = obs_filter("5jet_selection",GenFunction::register_function<bool()>("5jet_selection",
        FUNC(([jets](){
            return jets->get_value().size() >= 5;
        }))));

    event_selection.J6 = obs_filter("6jet_selection",GenFunction::register_function<bool()>("6jet_selection",
        FUNC(([jets](){
            return jets->get_value().size() >= 6;
        }))));

    /* event_selection.base_sel = ObsFilter::conj(event_selection.z_mass_veto, ObsFilter::conj(event_selection.trilepton, event_selection.b_jet3)); */
    event_selection.base_sel = all({event_selection.z_mass_veto, event_selection.trilepton_eemu, event_selection.b_jet3});
    event_selection.SR4j = all(event_selection.base_sel, event_selection.J4);
    event_selection.SR5j = all(event_selection.base_sel, event_selection.J5);
    event_selection.SR6j = all(event_selection.base_sel, event_selection.J6);
}
#endif // SELECTION_HPP
