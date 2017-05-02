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
    private:
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


namespace detail {
    template<typename Tuple, std::size_t... Is>
    decltype(auto) tuple_get_values_impl(const Tuple& t, std::index_sequence<Is...>){
        return std::make_tuple(std::get<1>(std::get<Is>(t))->get_value()...);
    }

    template<typename Tuple, std::size_t... Is>
    decltype(auto) tuple_get_labels_impl(const Tuple& t, std::index_sequence<Is...>){
        return std::make_tuple(std::get<0>(std::get<Is>(t))...);
    }
}
/**
 * Converts a tuple of pairs of label/Value objects to a tuple of the contained values
 */
template<typename... ArgTypes>
std::tuple<ArgTypes...> tuple_get_values(const std::tuple<std::pair<std::string,Value<ArgTypes>*>...>& t){
    return detail::tuple_get_values_impl<std::tuple<std::pair<std::string,Value<ArgTypes>*>...>>(t, std::index_sequence_for<ArgTypes...>{});
}

/**
 * Converts a tuple of pairs of label/Value objects to a tuple of just the
 * labels
 */
template<typename... ArgTypes>
decltype(auto) tuple_get_labels(const std::tuple<std::pair<std::string,Value<ArgTypes>*>...>& t){
    return detail::tuple_get_labels_impl<std::tuple<std::pair<std::string,Value<ArgTypes>*>...>>(t, std::index_sequence_for<ArgTypes...>{});
}


//-----------------------

template <typename T>
char type_lookup(){
    return 0;
}
template <>
char type_lookup<int>(){
    return 'I';
}
template <>
char type_lookup<float>(){
    return 'F';
}
template <>
char type_lookup<double>(){
    return 'F';
}


template<typename... DataTypes>
class MVAData : public DerivedValue<std::tuple<bool,bool,double,std::tuple<DataTypes...>>>{
    private:
        std::tuple<std::pair<std::string,Value<DataTypes>*>...> data;
        Value<bool>* is_training;
        Value<bool>* is_signal;
        Value<double>* weight;

        void update_value(){
            this->value = std::make_tuple(is_training->get_value(), is_signal->get_value(), weight->get_value(),
                                          tuple_get_values(data));
        }

        template <typename... Types>
        static std::vector<std::pair<std::string, char>> get_label_types_impl(std::pair<std::string,Value<Types>*>... pairs){
            return std::vector<std::pair<std::string, char>>({ std::make_pair(pairs.first,type_lookup<Types>())...});
        }


    public:
        typedef std::tuple<bool, bool, double, std::tuple<DataTypes...>> type;


        std::vector<std::pair<std::string, char>> get_label_types(){
            return call(get_label_types_impl<DataTypes...>, data);
        }

        static std::string fmt_name(Value<bool>* is_training, Value<bool>* is_signal, Value<double>* weight,
                                    const std::pair<std::string, Value<DataTypes>*>&&... data_vals){
            //TODO: add data names
            return "mva_data("+is_training->get_name()+","
                              +is_signal->get_name()+","
                              +weight->get_name()+")";
        }

        MVAData(Value<bool>* is_training, Value<bool>* is_signal,
                Value<double>* weight, const std::pair<std::string, Value<DataTypes>*>&&... data_vals)
          :DerivedValue<type>(fmt_name(is_training, is_signal, weight,
                                       std::forward<const std::pair<std::string,Value<DataTypes>*>>(data_vals)...),""),
           data(std::make_tuple(data_vals...)),
           is_training(is_training),
           is_signal(is_signal),
           weight(weight) { }
};
}
#endif // root_value_hpp
