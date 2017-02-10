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
            output_file = TFile::Open(output_filename.c_str(), "UPDATE");
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
        WrapperVector<T>* track_branch_vec(const std::string& size_bname, const std::string& bname){
            track_branch_ptr<T>(bname);
            return new WrapperVector<T>(size_bname, bname, bname);
        }

        void save_all(){
            output_file->cd();
            for(auto container : containers){
                container.second->save_as("outfile", SaveOption::ROOT);
            }
        }
};
#endif // minitreedataset_h
