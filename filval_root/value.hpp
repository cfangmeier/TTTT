#ifndef root_value_hpp
#define root_value_hpp
#include "filval/value.hpp"
#include "TLorentzVector.h"

namespace fv::root{

class LorentzVectors : public DerivedValue<std::vector<TLorentzVector>>{
    protected:
        Value<std::vector<float>> *pt_val;
        Value<std::vector<float>> *eta_val;
        Value<std::vector<float>> *phi_val;
        Value<std::vector<float>> *mass_val;

        void update_value(){
            auto pt = pt_val->get_value();
            auto eta = eta_val->get_value();
            auto phi = phi_val->get_value();
            auto mass = mass_val->get_value();
            std::vector<int> sizes = {pt.size(), eta.size(), phi.size(), mass.size()};
            int size = *std::min_element(sizes.begin(), sizes.end());
            this->value.clear();
            TLorentzVector lv;
            for (int i =0; i<size; i++){
                lv.SetPtEtaPhiM(pt[i], eta[i], phi[i], mass[i]);
                this->value.push_back(lv);
            }
        }

    public:
        LorentzVectors(const std::string& name,
                      Value<std::vector<float>>* pt,
                      Value<std::vector<float>>* eta,
                      Value<std::vector<float>>* phi,
                      Value<std::vector<float>>* mass)
          :DerivedValue<std::vector<TLorentzVector>>(name),
           pt_val(pt), eta_val(eta), phi_val(phi), mass_val(mass) { }
};

}
#endif // root_value_hpp
