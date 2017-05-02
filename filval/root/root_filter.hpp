#ifndef root_filter_hpp
#define root_filter_hpp
#include "value.hpp"
#include "TLorentzVector.h"

namespace fv::root{

class MassFilter : public Filter {
    private:
        Value<TLorentzVector> *lorentz_vector;
        Value<double> *mass_cut_low;
        Value<double> *mass_cut_high;
    void update_value(){
        double m = lorentz_vector->get_value().M();
        value = (m > mass_cut_low) && (m < mass_cut_high);
    }
    public:
        FilterAnd(Value<TLorentzVector> *lorentz_vector,
                  Value<double> *mass_cut_low,
                  Value<double> *mass_cut_high)
          :lorentz_vector(lorentz_vector),
           mass_cut_low(mass_cut_low),
           mass_cut_high(mass_cut_high){ }
};

}
#endif // root_filter_hpp
