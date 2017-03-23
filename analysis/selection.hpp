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

#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <limits>

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"

#include <TSystem.h>

#define JET_REQUIREMENT   6
#define B_JET_REQUIREMENT 3
#define B_JET_WP          0.  // lower bound on CMVA value
using namespace fv;
struct Selection {
public:

    static ObsFilter* trilepton_filter;

    static ObsFilter* jet_multiplicity_filter;
    static ObsFilter* b_jet_multiplicity_filter;

    static void init(){
        auto nLep = lookup<int>("nLepGood");
        trilepton_filter = obs_filter("trilepton_filter",GenFunction::register_function<bool()>("trilepton_filter",
            FUNC(([nLep=nLep](){
                return nLep->get_value() == 3;
            }))));


        auto nJet = lookup<int>("nJet");
        jet_multiplicity_filter = obs_filter("jet_multiplicity_filter",GenFunction::register_function<bool()>("jet_multiplicity_filter",
            FUNC(([nJet=nJet](){
                return nJet->get_value() >= JET_REQUIREMENT;
            }))));

        auto bJet_MVA = lookup<std::vector<float>>("Jet_btagCMVA");
        b_jet_multiplicity_filter = obs_filter("b_jet_multiplicity_filter",GenFunction::register_function<bool()>("b_jet_multiplicity_filter",
            FUNC(([bJet_MVA=bJet_MVA](){
                int n_b_jet = 0;
                for(auto j : bJet_MVA->get_value()){
                    if(j > B_JET_WP){
                        n_b_jet++;
                    }
                }
                return n_b_jet >= B_JET_REQUIREMENT;
            }))));
    }
};
#endif // SELECTION_HPP
