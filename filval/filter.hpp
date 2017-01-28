#ifndef filter_h
#define filter_h
#include <iostream>
#include "value.hpp"
/* A Filter is a special type of derived value that can only return a boolean.
 * Container objects have a vector of filters that control if a "fill" call
 * actually places data into the container or not.
 */
namespace filval {

class Filter : public DerivedValue<bool>{ };


class FilterAnd : public Filter {
    protected:
        Filter *filterA;
        Filter *filterB;
    void update_value(){
        value = filterA->get_value() && filterB->get_value();
    }
    public:
        FilterAnd(Filter *filterA, Filter *filterB)
            :filterA(filterA), filterB(filterB){ }
};

class FilterOr : public Filter {
    private:
        Filter *filterA;
        Filter *filterB;
    void update_value(){
        value = filterA->get_value() || filterB->get_value();
    }
    public:
        FilterOr(Filter *filterA, Filter *filterB)
            :filterA(filterA), filterB(filterB){ }
};

class FilterInv : public Filter {
    private:
        Filter *filter;
    void update_value(){
        value = !filter->get_value();
    }
    public:
        FilterInv(Filter *filter)
            :filter(filter){ }
};

template <typename T>
class FilterGreaterThan : public Filter {
    private:
        Value<T> *filter_value;
        Value<T> *range_low;
        void update_value(){
            value = filter_value->get_value() > range_low->get_value();
        }
    public:
        FilterGreaterThan(GenValue* filter_value, GenValue* range_low)
            :filter_value(dynamic_cast<Value<T>*>(filter_value)),
             range_low(dynamic_cast<Value<T>*>(range_low)) { }

        FilterGreaterThan(GenValue* filter_value, T range_low)
            :filter_value(dynamic_cast<Value<T>*>(filter_value)){
            this->range_low = new ConstantValue<T>(range_low);
        }
};

template <typename T>
class FilterLessThan : public Filter {
    private:
        Value<T> *filter_value;
        Value<T> *range_high;
        void update_value(){
            value = filter_value->get_value() < range_high->get_value();
        }
    public:
        FilterLessThan(GenValue* filter_value, GenValue* range_high)
            :filter_value(dynamic_cast<Value<T>*>(filter_value)),
             range_high(dynamic_cast<Value<T>*>(range_high)) { }

        FilterLessThan(GenValue* filter_value, T range_high)
            :filter_value(dynamic_cast<Value<T>*>(filter_value)){
            this->range_high = new ConstantValue<T>(range_high);
        }
};


template <typename T>
class RangeFilter : public FilterAnd {
    public:
        RangeFilter(Value<T> *filter_value, Value<T> *range_low, Value<T> *range_high){
            this->filterA = new FilterLessThan<T>(filter_value, range_high);
            this->filterB = new FilterGreaterThan<T>(filter_value, range_low);
         }
        RangeFilter(Value<T> *filter_value, T range_low, T range_high){
            this->filterA = new FilterLessThan<T>(filter_value, range_high);
            this->filterB = new FilterGreaterThan<T>(filter_value, range_low);
        }
};
}
#endif // filter_h
