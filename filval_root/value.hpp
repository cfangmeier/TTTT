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
        static std::string fmt_name(Value<std::vector<float>>* pt, Value<std::vector<float>>* eta,
                                    Value<std::vector<float>>* phi, Value<std::vector<float>>* mass){
            return "lorentz_vectors("+pt->get_name()+"," +eta->get_name()+","+
                                      phi->get_name()+"," +mass->get_name()+")";
        }

        LorentzVectors(Value<std::vector<float>>* pt,
                      Value<std::vector<float>>* eta,
                      Value<std::vector<float>>* phi,
                      Value<std::vector<float>>* mass,
                      const std::string& alias)
          :DerivedValue<std::vector<TLorentzVector>>(fmt_name(pt,eta,phi,mass), alias),
           pt_val(pt), eta_val(eta), phi_val(phi), mass_val(mass) { }
};

class Energies : public DerivedValue<std::vector<float>>{
    protected:
        Value<std::vector<TLorentzVector>> *vectors;
        void update_value(){
            std::vector<TLorentzVector>& vecs = vectors->get_value();
            this->value.clear();
            for (auto v : vecs){
                this->value.push_back(v.Energy());
            }
        }

    public:
        static std::string fmt_name(Value<std::vector<TLorentzVector>> *vectors){
            return "energies("+vectors->get_name()+")";
        }

        Energies(Value<std::vector<TLorentzVector>> *vectors,
                 const std::string& alias)
          :DerivedValue<std::vector<float>>(fmt_name(vectors), alias),
           vectors(vectors) { }
};

template<typename... DataTypes>
class MVAData : public DerivedValue<std::tuple<std::tuple<DataTypes...>, bool, bool, double>>{
    private:
        Value<std::tuple<DataTypes...>>* data;
        Value<bool>* is_training;
        Value<bool>* is_signal;
        Value<double>* weight;

    public:
        static std::string fmt_name(Value<std::tuple<DataTypes...>>* data,
                                    Value<bool>* is_training,
                                    Value<bool>* is_signal,
                                    Value<double>* weight){
            return "mva_data("+data->get_name()+","
                              +is_training->get_name()+","
                              +is_signal->get_name()+","
                              +weight->get_name()+")";
        }

        MVAData(Value<std::tuple<DataTypes...>>* data,
                Value<bool>* is_training,
                Value<bool>* is_signal,
                Value<double>* weight, const std::string& alias="")
          :DerivedValue<std::tuple<std::tuple<DataTypes...>, bool, double>>(fmt_name(data, is_training, is_signal, weight), alias),
           data(data),
           is_training(is_training),
           is_signal(is_signal),
           weight(weight) { }
};
}
#endif // root_value_hpp
