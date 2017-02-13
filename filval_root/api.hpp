#ifndef ROOT_API_HPP
#define ROOT_API_HPP
#include <string>
#include <vector>
#include <tuple>
#include "filval/api.hpp"
#include "filval_root/value.hpp"
namespace fv::root{

Value<std::vector<TLorentzVector>>* lorentz_vectors(Value<std::vector<float>>* pt, Value<std::vector<float>>* eta,
                                Value<std::vector<float>>* phi, Value<std::vector<float>>* mass,
                                const std::string& alias=""){
    return new root::LorentzVectors(pt, eta, phi, mass, alias);
}

Value<std::vector<TLorentzVector>>* lorentz_vectors(const std::string& pt_name, const std::string& eta_name,
                                                    const std::string& phi_name, const std::string& mass_name,
                                                    const std::string& alias=""){
    return lorentz_vectors(lookup<std::vector<float>>(pt_name), lookup<std::vector<float>>(eta_name),
                           lookup<std::vector<float>>(phi_name), lookup<std::vector<float>>(mass_name),
                           alias);
}

Value<std::vector<float>>* energies(Value<std::vector<TLorentzVector>>* vectors,
                                    const std::string& alias=""){
    return new root::Energies(vectors, alias);
}

Value<std::vector<float>>* energies(const std::string& vectors_name,
                                    const std::string& alias=""){
    return energies(lookup<std::vector<TLorentzVector>>(vectors_name), alias);
}

}
#endif // ROOT_API_HPP
