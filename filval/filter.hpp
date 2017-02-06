#ifndef filter_h
#define filter_h
#include <iostream>
#include <functional>
#include "value.hpp"
/* A Filter is a special type of derived value that can only return a boolean.
 * Container objects have a vector of filters that control if a "fill" call
 * actually places data into the container or not.
 */
namespace fv {

class Filter : public DerivedValue<bool>{
    private:
        std::function<bool()> filter_function;
        void update_value(){
            value = filter_function();
        }
    public:
        Filter(const std::string& name, std::function<bool()> filter_function)
          :DerivedValue<bool>(name),
           filter_function(filter_function){ }

        Filter* operator*(Filter *f){
            auto new_name = this->get_name() + "&&" + f->get_name();
            return new Filter(new_name, [this, f](){return this->get_value() && f->get_value();});
        }

        Filter* operator+(Filter *f){
            auto new_name = this->get_name() + "||" + f->get_name();
            return new Filter(new_name, [this, f](){return this->get_value() || f->get_value();});
        }

        Filter* operator!(){
            auto new_name = std::string("!(") + this->get_name() + std::string(")");
            return new Filter(new_name, [this](){return !this->get_value();});
        }
};

template <typename T>
class RangeFilter : public Filter{
    private:
    public:
        RangeFilter(const std::string name, Value<T>* test_value, T range_low, T range_high):
          Filter(name, [test_value, range_low, range_high]{
                  T val = test_value->get_value();
                  return (val >= range_low) && (val < range_high);
                  }){ }
};
}
#endif // filter_h
