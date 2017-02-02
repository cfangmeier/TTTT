#ifndef minitreedataset_h
#define minitreedataset_h

#include <string>
#include <tuple>

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"
#include "MiniTree.hpp"

using namespace std;
using namespace filval;
using namespace filval::root;

class MiniTreeDataSet : public DataSet,
                        public MiniTree{
    private:
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
        MiniTreeDataSet(TTree *tree)
          :MiniTree(tree){
            next_entry = 0;
            nentries = fChain->GetEntriesFast();
          }

        template <typename T>
        Value<T>* track_branch(const std::string& bname){
            T* bref = (T*) fChain->GetBranch(bname.c_str())->GetAddress();
            fChain->SetBranchStatus(bname.c_str(), true);
            cout << "Registering branch \"" << bname
                << "\" with address " << bref
                << " and type " << typeid(bref).name() << endl;
            return new ObservedValue<T>(bname, bref);
        }

        template <typename T>
        Value<T*>* track_branch_ptr(const std::string& bname){
            T* bref = (T*) fChain->GetBranch(bname.c_str())->GetAddress();
            fChain->SetBranchStatus(bname.c_str(), true);
            cout << "Registering pointer branch \"" << bname
                << "\" with address " << bref
                << " and type " << typeid(bref).name() << endl;
            return new PointerValue<T>(bname, bref);
        }

        void register_container(GenContainer* container){
            containers[container->get_name()] = container;
        }
};
#endif // minitreedataset_h
