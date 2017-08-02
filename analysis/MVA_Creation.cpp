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
 * MVA Creation script. This file demonstrates how to use filval_root's TMVA integration.
 */
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <limits>

#include <TSystem.h>

#include "filval/filval.hpp"
#include "filval/root/filval.hpp"

#include "analysis/common/obj_types.hpp"


#define PI 3.14159
#define W_MASS 80.385 // GeV/c^2
#define Z_MASS 91.188 // GeV/c^2
#define T_MASS 172.44 // GeV/c^2

using namespace std;
using namespace fv;
using namespace fv::root;

void enable_branches(MiniTreeDataSet& mt){
    mt.track_branch<int>("nLepGood");
    mt.track_branch<int>("nJet");
    mt.track_branch<int>("nGenPart");

    mt.track_branch<int>("nBJetLoose40");
    mt.track_branch<int>("nBJetMedium40");
    mt.track_branch<int>("nBJetTight40");
}
#define MVA_DTYPES int, int, int, int, int
void declare_values(MiniTreeDataSet& mt){

    auto event_number = mt.get_current_event_number();
    auto is_training = fv::apply(fv::GenFunction::reg_func<bool(int)>("is_odd",
        FUNC(([](int n){
            return (n%2) == 1;
        }))), fv::tuple(event_number));

    auto is_signal = fv::bound(fv::GenFunction::reg_func<bool()>("is_signal",
        FUNC(([mt=&mt](){
            const std::string& label = mt->get_current_event_label();
            return label == "signal";
        }))), "is_signal");

    auto weight = fv::constant<double>("1", 1);

    auto mva_data = fv::root::mva_data<MVA_DTYPES>(is_training, is_signal, weight,
            {"nJet",          lookup<int>("nJet")},
            {"nBJetLoose40",  lookup<int>("nBJetLoose40")},
            {"nBJetMedium40", lookup<int>("nBJetMedium40")},
            {"nBJetTight40",  lookup<int>("nBJetTight40")},
            {"nLepGood",      lookup<int>("nLepGood")}
            );
    GenValue::alias("mva_data", mva_data);

}

void declare_containers(MiniTreeDataSet& mt){

    auto mva_data = (MVAData<MVA_DTYPES>*)lookup<MVAData<MVA_DTYPES>::type>("mva_data");
    auto mva =  mt.register_container<MVA<MVA_DTYPES>>("my_mva", mva_data);
    mva->add_method("KNN", "H:nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim");
}


void create_mva(const vector<fv::util::DataFileDescriptor>& dfds, const std::string& output_filename, bool silent){
    gSystem->Load("libfilval.so");
    auto replace_suffix = [](const std::string& input, const std::string& new_suffix){
        return input.substr(0, input.find_last_of(".")) + new_suffix;
    };
    string log_filename = replace_suffix(output_filename, ".log");
    fv::util::Log::init_logger(log_filename, fv::util::LogPriority::kLogDebug);

    MiniTreeDataSet mt(output_filename, dfds, "tree");

    enable_branches(mt);
    declare_values(mt);
    declare_containers(mt);

    mt.process(silent);
    mt.save_all();
}

int main(int argc, char * argv[])
{
    fv::util::ArgParser args(argc, argv);
    if(args.cmdOptionExists("-h")) {
        cout << "Usage: ./mva (-s) -o outfile.root -F datafiles.txt" << endl;
        return 0;
    }
    bool silent = args.cmdOptionExists("-s");
    string output_filename = args.getCmdOption("-out");
    auto file_list = fv::util::read_input_list(args.getCmdOption("-F"));

    create_mva(file_list, output_filename, silent);
}
