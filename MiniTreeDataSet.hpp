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

        void enable_branches(){
            fChain->SetBranchStatus("*", false);
            track_branch<int>("nJet");
            track_branch<int>("nLepGood");
            track_branch_ptr<float>("LepGood_pt");
            track_branch_ptr<float>("LepGood_eta");
            track_branch_ptr<float>("LepGood_phi");
            track_branch_ptr<float>("LepGood_mass");
        }
    public:
        MiniTreeDataSet(TTree *tree)
          :MiniTree(tree){
            enable_branches();
            auto lookup = [](const string& name){ return GenValue::get_value(name);};
            auto lookup_filter = [](const string& name){ return dynamic_cast<Filter*>(GenValue::get_value(name));};
            auto mean = [](vector<float> v){
                    int n = 0;
                    float sum = 0;
                    for (float e : v){
                        n++;
                        sum += e;
                    }
                    return n>0 ? sum / n : 0;
                    };

            auto pt_wrapper  = new WrapperVector<float>("LepGood_pt_vec", "nLepGood", "LepGood_pt");
            auto eta_wrapper = new WrapperVector<float>("LepGood_eta_vec", "nLepGood", "LepGood_eta");
            auto phi_wrapper = new WrapperVector<float>("LepGood_phi_vec", "nLepGood", "LepGood_phi");
            auto m_wrapper   = new WrapperVector<float>("LepGood_mass_vec", "nLepGood", "LepGood_mass");

            auto get_energy = [](float pt, float eta, float phi, float m){
                TLorentzVector t;
                t.SetPtEtaPhiM(pt, eta, phi, m);
                return t.E();
            };
            new ZipMapFour<float, float>("lepton_energy", get_energy, pt_wrapper, eta_wrapper, phi_wrapper, m_wrapper);

            new Reduce<float>("avg_lepton_energy", mean , "lepton_energy");


            new Filter("nLepGood>=3", [nLepGood=lookup("nLepGood")](){
                    return dynamic_cast<Value<int>*>(nLepGood)->get_value() >=3;});

            new Filter("nLepGood<=4", [nLepGood=lookup("nLepGood")](){
                    return dynamic_cast<Value<int>*>(nLepGood)->get_value() <=4;});
            new RangeFilter<int>("3<=nLepGood<5", dynamic_cast<Value<int>*>(lookup("nLepGood")), 3, 5);


            add_container(new ContainerTH1I("nLepGood", "Lepton Multiplicity", 10, 0, 10, lookup("nLepGood")));

            add_container(new ContainerTH1I("nLepGood2", "Lepton Multiplicity", 10, 0, 10, lookup("nLepGood")));
            containers.at("nLepGood2")->add_filter(lookup_filter("3<=nLepGood<5"));

            add_container(new ContainerTH1I("nLepGood3", "Lepton Multiplicity", 10, 0, 10, lookup("nLepGood")));
            containers.at("nLepGood3")->add_filter(!(*lookup_filter("3<=nLepGood<5")));

            new Pair<int, int>("(nLepGood,nJet)", "nLepGood", "nJet");
            add_container(new ContainerTGraph("nLepvsnJet", lookup("(nLepGood,nJet)")));

            add_container(new ContainerTH1F("avg_lepton_energy", "Average Lepton Energy", 50, 0, 500, lookup("avg_lepton_energy")));
            add_container(new ContainerTH1F("max_lepton_energy", "Maximum Lepton Energy", 50, 0, 500, lookup("max_lepton_energy")));

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
            return new ConstantValue<T*>(bname, bref);
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
