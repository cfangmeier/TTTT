#ifndef root_value_hpp
#define root_value_hpp
#include "value.hpp"
#include "TLorentzVector.h"

namespace filval::root{

class LorentzVector : public DerivedValue<TLorentzVector>{
    protected:
        Value<double> *pt;
        Value<double> *eta;
        Value<double> *phi;
        Value<double> *m;
        void update_value(){
            value.SetPtEtaPhiM(pt->get_value(), eta->get_value(), phi->get_value(), m->get_value());
        }
    public:
        LorentzVector(Value<double>* pt,
                      Value<double>* eta,
                      Value<double>* phi,
                      Value<double>* m)
          :pt(pt), eta(eta),
           phi(phi), m(m) { }

        LorentzVector(ValueSet *values,
                      const std::string &pt_label,
                      const std::string &eta_label,
                      const std::string &phi_label,
                      const std::string &m_label)
          :LorentzVector(dynamic_cast<Value<double>*>(values->at(pt_label)),
                         dynamic_cast<Value<double>*>(values->at(eta_label)),
                         dynamic_cast<Value<double>*>(values->at(phi_label)),
                         dynamic_cast<Value<double>*>(values->at(m_label))){ }
};

class LorentzVectorEnergy : public DerivedValue<double>{
    protected:
        Value<TLorentzVector>* vector;
        void update_value(){
            value = vector->get_value().E();
        }
    public:
        LorentzVectorEnergy(Value<TLorentzVector>* vector)
          :vector(vector){ }

        LorentzVectorEnergy(ValueSet *values, const std::string& vector_label)
          :LorentzVectorEnergy(dynamic_cast<Value<TLorentzVector>*>(values->at(vector_label))){ }
};
}
#endif // root_value_hpp
