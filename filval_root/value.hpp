#ifndef root_value_hpp
#define root_value_hpp
#include "value.hpp"
#include "TLorentzVector.h"

namespace fv::root{

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
        LorentzVector(const std::string& name,
                      Value<double>* pt,
                      Value<double>* eta,
                      Value<double>* phi,
                      Value<double>* m)
          :DerivedValue<TLorentzVector>(name),
           pt(pt), eta(eta),
           phi(phi), m(m) { }

        LorentzVector(const std::string& name,
                      const std::string &pt_label,
                      const std::string &eta_label,
                      const std::string &phi_label,
                      const std::string &m_label)
          :LorentzVector(name,
                         dynamic_cast<Value<double>*>(GenValue::get_value(pt_label)),
                         dynamic_cast<Value<double>*>(GenValue::get_value(eta_label)),
                         dynamic_cast<Value<double>*>(GenValue::get_value(phi_label)),
                         dynamic_cast<Value<double>*>(GenValue::get_value(m_label))){ }
};

class LorentzVectorEnergy : public DerivedValue<double>{
    protected:
        Value<TLorentzVector>* vector;
        void update_value(){
            value = vector->get_value().E();
        }
    public:
        LorentzVectorEnergy(const std::string& name, Value<TLorentzVector>* vector)
          :DerivedValue<double>(name),
           vector(vector){ }

        LorentzVectorEnergy(const std::string& name, const std::string& vector_label)
          :LorentzVectorEnergy(name,
                               dynamic_cast<Value<TLorentzVector>*>(GenValue::get_value(vector_label))){ }
};
}
#endif // root_value_hpp
