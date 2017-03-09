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
#ifndef minitreedataset_h
#define minitreedataset_h

#include <string>
#include <tuple>

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"
#include "MiniTree.hpp"

using namespace std;
using namespace fv;
using namespace fv::root;

class MiniTreeDataSet : public DataSet,
                        public MiniTree{
    private:
        std::string input_filename;
        std::string output_filename;
        TFile* input_file;
        TFile* output_file;
        long next_entry;
        long nentries;
        bool load_next(){
            if (next_entry >= nentries) return false;
            fChain->GetEntry(next_entry);
            ++next_entry;
            return true;
        }
        int get_events(){
            return nentries;
        }
        int get_current_event(){
            return next_entry-1;
        }

    public:
        MiniTreeDataSet(const std::string& input_filename, const std::string output_filename)
          :input_filename(input_filename),
           output_filename(output_filename),
           next_entry(0) {
            input_file = TFile::Open(input_filename.c_str());
            Init((TTree*) input_file->Get("tree"));
            nentries = fChain->GetEntriesFast();
            output_file = TFile::Open(output_filename.c_str(), "RECREATE");
            this->fChain->SetBranchStatus("*", false);
          }

        ~MiniTreeDataSet(){
            input_file->Close();
            output_file->Close();
        }

        template <typename T>
        Value<T>* track_branch(const std::string& bname){
            TBranch* branch = fChain->GetBranch(bname.c_str());
            if (branch == nullptr){
                CRITICAL("Branch: " << bname << " does not exist in input tree.", -1);
            }
            T* bref = (T*) branch->GetAddress();
            fChain->SetBranchStatus(bname.c_str(), true);
            INFO("Registering branch \"" << bname
                 << "\" with address " << bref
                 << " and type " << typeid(bref).name());
            return new ObservedValue<T>(bname, bref);
        }

        template <typename T>
        Value<T*>* track_branch_ptr(const std::string& bname){
            TBranch* branch = fChain->GetBranch(bname.c_str());
            if (branch == nullptr){
                CRITICAL("Branch: " << bname << " does not exist in input tree.", -1);
            }
            T* bref = (T*) branch->GetAddress();
            fChain->SetBranchStatus(bname.c_str(), true);
            INFO("Registering pointer branch \"" << bname
                 << "\" with address " << bref
                 << " and type " << typeid(bref).name());
            return new PointerValue<T>(bname, bref);
        }

        template <typename T>
        decltype(auto) track_branch_vec(const std::string& size_bname, const std::string& value_bname){
            track_branch_ptr<T>(value_bname);
            return wrapper_vector<T>(lookup<int>(size_bname), lookup<T*>(value_bname), value_bname);
        }

        void save_all(){
            output_file->cd();
            for(auto container : containers){
                container.second->save_as("outfile", SaveOption::ROOT);
            }
            // Save the value names for each container to enable looking up
            // what values are plotted
            std::map<string,string> value_lookup = this->get_container_name_value_map();
            gDirectory->WriteObjectAny(&value_lookup, "std::map<std::string,std::string>", "_value_lookup");

            std::map<string,string> fn_impl_lookup = this->get_function_name_impl_map();
            gDirectory->WriteObjectAny(&fn_impl_lookup, "std::map<std::string,std::string>", "_function_impl_lookup");
        }
};
#endif // minitreedataset_h
