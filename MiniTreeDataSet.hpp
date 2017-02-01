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
    public:
        MiniTreeDataSet(TTree *tree)
          :MiniTree(tree){
            fChain->SetBranchStatus("*", false);

            track_branch<int>("nJet");
            track_branch<int>("nLepGood");
            track_branch_ptr<float>("LepGood_pt");
            track_branch_ptr<float>("LepGood_eta");
            track_branch_ptr<float>("LepGood_phi");
            track_branch_ptr<float>("LepGood_mass");
            auto pt_wrapper  = new WrapperVector<float>(&values, "nLepGood", "LepGood_pt");
            auto eta_wrapper = new WrapperVector<float>(&values, "nLepGood", "LepGood_eta");
            auto phi_wrapper = new WrapperVector<float>(&values, "nLepGood", "LepGood_phi");
            auto m_wrapper   = new WrapperVector<float>(&values, "nLepGood", "LepGood_mass");

            auto get_energy = [](float pt, float eta, float phi, float m){
                TLorentzVector t;
                t.SetPtEtaPhiM(pt, eta, phi, m);
                return t.E();
            };
            auto lepton_energy = new ZipMapFour<float, float>(get_energy, pt_wrapper, eta_wrapper, phi_wrapper, m_wrapper);

            auto avg_lepton_energy = new Reduce<float>([](vector<float> v){
                    int n = 0;
                    float sum = 0;
                    for (float e : v){
                        n++;
                        sum += e;
                    }
                    return n>0 ? sum / n : 0;
                    }, lepton_energy);
            add_value(avg_lepton_energy, "avg_lepton_energy");



            Filter* nLepGoodLowFilter = new Filter([nLepGood=values["nLepGood"]](){
                    return dynamic_cast<Value<int>*>(nLepGood)->get_value() >=3;});

            Filter* nLepGoodHighFilter = new Filter([nLepGood=values["nLepGood"]](){
                    return dynamic_cast<Value<int>*>(nLepGood)->get_value() <=4;});
            add_value(nLepGoodLowFilter, "nLepGoodLow");
            add_value(nLepGoodHighFilter, "nLepGoodHigh");
            auto nLepGoodRangeFilter = new RangeFilter<int>(dynamic_cast<Value<int>*>(values["nLepGood"]), 3, 5);
            add_value(nLepGoodRangeFilter, "nLepGoodRange");
            add_value(!(*nLepGoodRangeFilter), "nLepGoodRangeInv");


            add_container(new ContainerTH1I("nLepGood", "Lepton Multiplicity", 10, 0, 10, values["nLepGood"]));
            add_container(new ContainerTH1I("nLepGood2", "Lepton Multiplicity", 10, 0, 10, values["nLepGood"]));
            containers.at("nLepGood2")->add_filter(values.at("nLepGoodRange"));
            add_container(new ContainerTH1I("nLepGood3", "Lepton Multiplicity", 10, 0, 10, values["nLepGood"]));
            containers.at("nLepGood3")->add_filter(values.at("nLepGoodRangeInv"));

            add_value(new Pair<int, int>(&values, "nLepGood", "nJet"), "nLepvsnJet");
            add_container(new ContainerTGraph("nLepvsnJet", values["nLepvsnJet"]));

            add_container(new ContainerTH1F("avg_lepton_energy", "Average Lepton Energy", 50, 0, 500, values["avg_lepton_energy"]));

            next_entry = 0;
            nentries = fChain->GetEntriesFast();
          }

        template <typename T>
        void track_branch(const std::string bname){
            T* bref = (T*) fChain->GetBranch(bname.c_str())->GetAddress();
            values[bname] = new ObservedValue<T>(bref);
            fChain->SetBranchStatus(bname.c_str(), true);
            cout << "Registering branch \"" << bname
                << "\" with address " << bref
                << " and type " << typeid(bref).name() << endl;
        }

        template <typename T>
        void track_branch_ptr(const std::string bname){
            T* bref = (T*) fChain->GetBranch(bname.c_str())->GetAddress();
            values[bname] = new ConstantValue<T*>(bref);
            fChain->SetBranchStatus(bname.c_str(), true);
            cout << "Registering pointer branch \"" << bname
                << "\" with address " << bref
                << " and type " << typeid(bref).name() << endl;
        }

        void register_container(GenContainer* container){
            containers[container->get_name()] = container;
        }
        /* void process(){ */
        /*     cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; */
        /*     cout << "In process" << endl; */
        /*     cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; */
        /*     auto x = dynamic_cast<ConstantValue<float*>*>(values["LepGood_pt"]); */
        /*     cout << x->get_value() << endl; */
        /*     /1* foo(); *1/ */
        /*     while( load_next() ){ */
        /*         /1* foo(); *1/ */
        /*         cout << x->get_value() << endl; */
        /*         GenValue::reset(); */
        /*         for(auto con : containers) */
        /*             con.second->fill(); */
        /*         /1* foo(); *1/ */
        /*     } */
        /* } */

};
#endif // minitreedataset_h
