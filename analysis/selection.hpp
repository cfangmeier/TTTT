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

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"

#include "analysis/common/obj_types.hpp"

ObsFilter* SR4j;
ObsFilter* SR5j;
ObsFilter* SR6j;

void init_selection(){
    auto leptons = lookup<std::vector<Particle>>("leptons");
    auto jets    = lookup<std::vector<Particle>>("jets");

    // Require *exactly* three charged leptons
    auto trilepton = obs_filter("trilepton",GenFunction::register_function<bool()>("trilepton",
        FUNC(([leptons](){
            return leptons->get_value().size() == 3;
        }))));

    // Require at least three charged b-jets
    auto b_jet = obs_filter("b_jet",GenFunction::register_function<bool()>("b_jet",
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
    auto z_mass_window = obs_filter("z_mass_window",GenFunction::register_function<bool()>("z_mass_window",
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


    auto J4 = obs_filter("4jet_selection",GenFunction::register_function<bool()>("4jet_selection",
        FUNC(([jets](){
            return jets->get_value().size() >= 4;
        }))));

    auto J5 = obs_filter("5jet_selection",GenFunction::register_function<bool()>("5jet_selection",
        FUNC(([jets](){
            return jets->get_value().size() >= 5;
        }))));

    auto J6 = obs_filter("6jet_selection",GenFunction::register_function<bool()>("6jet_selection",
        FUNC(([jets](){
            return jets->get_value().size() >= 6;
        }))));

    auto base_sel = ObsFilter::conj(z_mass_window, ObsFilter::conj(trilepton, b_jet));
    SR4j = ObsFilter::conj(base_sel, J4);
    SR5j = ObsFilter::conj(base_sel, J5);
    SR6j = ObsFilter::conj(base_sel, J6);
}
#endif // SELECTION_HPP
