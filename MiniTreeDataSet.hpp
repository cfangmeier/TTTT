#ifndef minitreedataset_h
#define minitreedataset_h

#include <string>

#include "filval/filval.hpp"
#include "filval_root/filval_root.hpp"
#include "MiniTree.hpp"

using namespace filval;
using namespace filval::root;

class MiniTreeDataSet : public filval::DataSet,
                        public MiniTree{
    private:
        template <typename T>
        void track_branch(const std::string bname, T *bval){
            values[bname] = new filval::ObservedValue<T>(bval);
            fChain->SetBranchStatus(bname.c_str(), true);
        }
        long next_entry;
        long nentries;
        bool load_next(){
            if (next_entry >= nentries) return false;
            fChain->GetEntry(next_entry);
            ++next_entry;
            return true;
        }
    public:
        MiniTreeDataSet(TTree *tree)
          :MiniTree(tree){
            fChain->SetBranchStatus("*", false);

            track_branch<int>("nLepGood", &nLepGood);
            track_branch<int>("nJet", &nJet);

            add_value(new FilterGreaterThan<int>(values["nLepGood"], 3), "nLepGoodCut");

            add_container(new ContainerTH1I("nLepGood", "Lepton Multiplicity", 10, 0, 10, values["nLepGood"]));
            add_container(new ContainerTH1I("nLepGood2", "Lepton Multiplicity", 10, 0, 10, values["nLepGood"]));
            containers["nLepGood2"]->add_filter(values["nLepGoodCut"]);

            add_value(new DerivedPair<int, int>(&values, "nLepGood", "nJet"), "nLepvsnJet");
            add_container(new ContainerTGraph("nLepvsnJet", values["nLepvsnJet"]));


            next_entry = 0;
            nentries = fChain->GetEntriesFast();
          }

        void register_container(GenContainer* container){
            containers[container->get_name()] = container;
        }

};
#endif // minitreedataset_h
