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
        std::map<std::string,std::string> input_filenames_with_labels;
        /* std::vector<TFile*> input_files; */
        std::string output_filename;
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
        MiniTreeDataSet(const std::string& output_filename, const std::string input_filename)
          :DataSet(),
           input_filenames_with_labels({ {input_filename, "signal"} }),
           output_filename(output_filename),
           next_entry(0) {
            TChain* chain = new TChain("tree");
            chain->Add(input_filename.c_str());
            Init(chain);
            nentries = fChain->GetEntries();
            output_file = TFile::Open(output_filename.c_str(), "RECREATE");
            this->fChain->SetBranchStatus("*", false);
          }

        MiniTreeDataSet(const std::string& output_filename, const std::map<std::string,std::string>& filenames_with_labels)
          :DataSet(),
           input_filenames_with_labels(filenames_with_labels),
           output_filename(output_filename),
           next_entry(0) {
            TChain* chain = new TChain("tree");
            for(auto& p : filenames_with_labels){
                std::string filename;
                std::tie(filename, std::ignore) = p;
                chain->Add(filename.c_str());
            }
            Init(chain);
            nentries = fChain->GetEntries();
            output_file = TFile::Open(output_filename.c_str(), "RECREATE");
            this->fChain->SetBranchStatus("*", false);
          }

        ~MiniTreeDataSet(){
            output_file->Close();
        }

        const std::string& get_current_event_label() const{
            TFile* file = fChain->GetFile();
            std::string filename = file->GetName();
            return input_filenames_with_labels.at(filename);
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

            // Save the value names for each container to enable looking up
            // what values are plotted
            std::map<string,string> value_lookup = this->get_container_name_value_map();
            gDirectory->WriteObjectAny(&value_lookup, "std::map<std::string,std::string>", "_value_lookup");

            std::map<string,string> fn_impl_lookup = this->get_function_name_impl_map();
            gDirectory->WriteObjectAny(&fn_impl_lookup, "std::map<std::string,std::string>", "_function_impl_lookup");

            for(auto container : containers){
                container.second->save_as("outfile", SaveOption::ROOT);
            }
        }
};
#endif // minitreedataset_h
