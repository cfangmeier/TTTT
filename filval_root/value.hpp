#ifndef root_values_hpp
#define root_values_hpp
#include "value.hpp"
#include "TLorentzVector.h"

namespace filval::root{

class DerivedLorentzVector : public DerivedValue<TLorentzVector>{
    protected:
        Value<double> *pt;
        Value<double> *eta;
        Value<double> *phi;
        Value<double> *m;
        void update_value(){
            value.SetPtEtaPhiM(pt->get_value(), eta->get_value(), phi->get_value(), m->get_value());
        }
    public:
        DerivedLorentzVector(ValueSet *values,
                             const std::string &pt_label,
                             const std::string &eta_label,
                             const std::string &phi_label,
                             const std::string &m_label){
            ValueSet &valueSet = *values;
            pt = (Value<double>*) valueSet[pt_label];
            eta = (Value<double>*) valueSet[eta_label];
            phi = (Value<double>*) valueSet[phi_label];
            m = (Value<double>*) valueSet[m_label];
         }

};
}
#endif // root_values_hpp
