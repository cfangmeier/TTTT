#ifndef filter_h
#define filter_h
#include <iostream>
#include <functional>
#include "value.hpp"
/* A Filter is a special type of derived value that can only return a boolean.
 * Container objects have a vector of filters that control if a "fill" call
 * actually places data into the container or not.
 */
namespace filval {

class GenFilter : public DerivedValue<bool>{};

class Filter : public GenFilter{
    private:
        std::function<bool()> filter_function;
        void update_value(){
            value = filter_function();
        }
    public:
        Filter(std::function<bool()> filter_function)
          :filter_function(filter_function){ }

        Filter* operator*(Filter *f){
            return new Filter([this, f](){return this->get_value() && f->get_value();});
        }

        Filter* operator+(Filter *f){
            return new Filter([this, f](){return this->get_value() || f->get_value();});
        }

        Filter* operator!(){
            return new Filter([this](){return !this->get_value();});
        }
};

template <typename T>
class RangeFilter : public Filter{
    private:
    public:
        RangeFilter(Value<T>* test_value, T range_low, T range_high):
          Filter([test_value, range_low, range_high]{
                  T val = test_value->get_value();
                  return (val >= range_low) && (val < range_high);
                  }){ }
};
}
#endif // filter_h
