#ifndef value_hpp
#define value_hpp
#include <iostream>
#include <utility>
#include <map>

namespace filval{

class GenValue{
    public:
        virtual void reset() = 0;
};
typedef std::map<std::string, GenValue*> ValueSet;

/* class ValueSet: public std::map<std::string, GenValue*>{ */
/*     public: */
/*         GenValue*& operator[](const std::string& key){ */
/*             GenValue*& value = (*this)[key]; */
/*             if (value == NULL){ */
/*                 std::cerr << "ERROR: key \""<<key */
/*                     <<"\" not in valueset" << std::endl; */
/*             } */
/*             return value; */
/*         } */
/* }; */


template <typename V>
class Value : public GenValue{
    public:
        virtual V& get_value() = 0;
};


template <typename V>
class ObservedValue : public Value<V>{
    /* For "observed" values, there is nothing to calculate since this is
     * merely a wrapper around a field in the observation. A pointer to the
     * value is kept and it's value is read when requested.
     */
    private:
        V *val_ref;
    public:
        ObservedValue(V *val_ref)
            : val_ref(val_ref){}
        V& get_value(){
            return *val_ref;
        }
        void reset(){ }
};


template <typename V>
class DerivedValue : public Value<V>{
    /* A "derived" value is the result of some sort of calculation. Since it is
     * desireable for the calculation to occur at most a single time for each
     * observation, the result of the calculation is stored in the object. be
     * sure that "reset" is called between processing observations to force a
     * re-calculation.
     */
    protected:
        V value; // The value to be calculated
        bool value_valid;

        virtual void update_value() = 0;
    public:
        V& get_value(){
            if (!value_valid){
                /* std::cout << "updating value!\n"; */
                update_value();
                value_valid = true;
            }
            return value;
        }

        void reset(){
            value_valid = false;
        }
};


template <typename T1, typename T2>
class DerivedPair : public DerivedValue<std::pair<T1, T2> >{
    protected:
        std::pair<Value<T1>*, Value<T2>* > value_pair;
        void update_value(){
            this->value.first = value_pair.first->get_value();
            this->value.second = value_pair.second->get_value();
        }
    public:
        DerivedPair(ValueSet *values, const std::string &label1, const std::string &label2){
            ValueSet &valueSet = *values;
            value_pair.first  = (Value<T1>*) valueSet[label1];
            value_pair.second = (Value<T2>*) valueSet[label2];
         }
        DerivedPair(Value<T1> *value1, Value<T2> *value2){
            value_pair.first  = value1;
            value_pair.second = value2;
         }

};

template <typename V>
class ConstantValue : public DerivedValue<V>{
    protected:
        V const_value;
        void update_value(){
            this->value = const_value;
        }
    public:
        ConstantValue(V const_value)
            :const_value(const_value) { }
};
}
#endif // value_hpp
