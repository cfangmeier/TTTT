#ifndef ROOT_API_HPP
#define ROOT_API_HPP
#include <string>
#include <vector>
#include <tuple>
#include "filval/api.hpp"
#include "filval_root/value.hpp"
namespace fv::root{

    decltype(auto)
    lorentz_vectors(Value<std::vector<float>>* pt, Value<std::vector<float>>* eta,
                                Value<std::vector<float>>* phi, Value<std::vector<float>>* mass,
                                const std::string& alias=""){
        typedef std::vector<TLorentzVector> type;
        const std::string& name = root::LorentzVectors::fmt_name(pt, eta, phi, mass);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new root::LorentzVectors(pt, eta, phi, mass, alias);
    }

    decltype(auto)
    lorentz_vectors(const std::string& pt_name, const std::string& eta_name,
                                                        const std::string& phi_name, const std::string& mass_name,
                                                        const std::string& alias=""){
        return lorentz_vectors(lookup<std::vector<float>>(pt_name), lookup<std::vector<float>>(eta_name),
                               lookup<std::vector<float>>(phi_name), lookup<std::vector<float>>(mass_name),
                               alias);
    }

    decltype(auto)
    energies(Value<std::vector<TLorentzVector>>* vectors, const std::string& alias=""){
        typedef std::vector<float> type;
        const std::string& name = root::Energies::fmt_name(vectors);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new root::Energies(vectors, alias);
    }

    decltype(auto)
    energies(const std::string& vectors_name, const std::string& alias=""){
        return energies(lookup<std::vector<TLorentzVector>>(vectors_name), alias);
    }

}
#endif // ROOT_API_HPP
