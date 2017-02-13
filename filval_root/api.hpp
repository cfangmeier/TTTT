#ifndef ROOT_API_HPP
#define ROOT_API_HPP
#include <string>
#include <vector>
#include <tuple>
#include "filval/api.hpp"
namespace fv{

LorentzVectors* lorentz_vectors(Value<std::vector<float>>* pt, Value<std::vector<float>>* eta,
                                Value<std::vector<float>>* phi, Value<std::vector<float>>* mass,
                                const std::string& alias=""){
    return new LorentzVectors(pt, eta, phi, mass, alias);
}

LorentzVectors* lorentz_vectors(const std::string& pt_name, const std::string& eta_name,
                                const std::string& phi_name, const std::string& mass_name,
                                const std::string& alias=""){
    return lorentz_vectors(lookup<std::vector<float>>(pt_name), lookup<std::vector<float>>(eta_name),
                           lookup<std::vector<float>>(phi_name), lookup<std::vector<float>>(mass_name),
                           alias);
}

}
#endif // ROOT_API_HPP
