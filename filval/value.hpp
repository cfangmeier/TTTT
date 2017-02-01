#ifndef value_hpp
#define value_hpp
#include <iostream>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>
#include <initializer_list>
#include <functional>

namespace filval{

class GenValue{
    private:
        inline static std::vector<GenValue*> values;
        virtual void _reset() = 0;
    public:
        GenValue(){
            values.push_back(this);
        }
        static void reset(){
            for (auto val : values){
                val->_reset();
            }
        }
};
typedef std::map<std::string, GenValue*> ValueSet;


template <typename T>
class Value : public GenValue{
    public:
        Value(): GenValue(){}
        virtual T& get_value() = 0;
};


template <typename T>
class ObservedValue : public Value<T>{
    /* For "observed" values, there is nothing to calculate since this is
     * merely a wrapper around a field in the observation. A pointer to the
     * value is kept and it's value is read when requested.
     */
    private:
        T *val_ref;
        void _reset(){ }
    public:
        ObservedValue(T* val_ref)
          :Value<T>(),
           val_ref(val_ref){ }
        T& get_value(){
            return *val_ref;
        }
};


template <typename T>
class DerivedValue : public Value<T>{
    /* A "derived" value is the result of some sort of calculation. Since it is
     * desireable for the calculation to occur at most a single time for each
     * observation, the result of the calculation is stored in the object. be
     * sure that "reset" is called between processing observations to force a
     * re-calculation.
     */
    private:
        void _reset(){
            value_valid = false;
        }
    protected:
        T value;
        bool value_valid;

        virtual void update_value() = 0;
    public:
        DerivedValue() :Value<T>(), value_valid(false) { }

        T& get_value(){
            if (!value_valid){
                update_value();
                value_valid = true;
            }
            return value;
        }
};

template <typename T>
class WrapperVector : public DerivedValue<std::vector<T> >{
    private:
        Value<int>* size;
        Value<T*>* data;

        void update_value(){
            int n = size->get_value();
            T* data_ref = data->get_value();
            this->value.resize(n);
            for (int i=0; i<n; i++){
                this->value[i] = *(data_ref+i);
            }
        }

    public:
        WrapperVector(Value<int>* _size, Value<T*>* _data)
          :DerivedValue<std::vector<T> >(),
           size(_size), data(_data){ }
        WrapperVector(ValueSet *values, const std::string &label_size, const std::string &label_data)
          :WrapperVector(dynamic_cast<Value<int>*>(values->at(label_size)),
                         dynamic_cast<Value<T*>*>(values->at(label_data))) { }
};

template <typename T1, typename T2>
class Pair : public DerivedValue<std::pair<T1, T2> >{
    protected:
        std::pair<Value<T1>*, Value<T2>* > value_pair;
        void update_value(){
            this->value.first = value_pair.first->get_value();
            this->value.second = value_pair.second->get_value();
        }
    public:
        Pair(Value<T1> *value1, Value<T2> *value2)
          :DerivedValue<std::pair<T1, T2> >(),
           value_pair(value1, value2){ }
        Pair(ValueSet *values, const std::string &label1, const std::string &label2)
          :Pair((Value<T1>*) values->at(label1),
                (Value<T1>*) values->at(label2)){ }
};

template <typename R, typename T>
class ZipMapFour : public DerivedValue<std::vector<R> >{
    private:
        std::function<R(T, T, T, T)> f;
        Value<std::vector<T> >* v1;
        Value<std::vector<T> >* v2;
        Value<std::vector<T> >* v3;
        Value<std::vector<T> >* v4;

        void update_value(){
            std::vector<T> v1_val = v1->get_value();
            std::vector<T> v2_val = v2->get_value();
            std::vector<T> v3_val = v3->get_value();
            std::vector<T> v4_val = v4->get_value();

            int n;
            std::tie(n, std::ignore) = std::minmax({v1_val.size(), v2_val.size(), v3_val.size(), v4_val.size()});
            this->value.resize(n);
            for (int i=0; i<n; i++){
                this->value[i] = f(v1_val[i], v2_val[i], v3_val[i], v4_val[i]);
            }
        }

    public:
        ZipMapFour(std::function<R(T, T, T, T)> f,
                   Value<std::vector<T> >* v1, Value<std::vector<T> >* v2,
                   Value<std::vector<T> >* v3, Value<std::vector<T> >* v4)
          :DerivedValue<std::vector<R> >(),
           f(f), v1(v1), v2(v2), v3(v3), v4(v4) { }
        ZipMapFour(std::function<R(T, T, T, T)> f,
                   ValueSet *values,
                   const std::string &label1,
                   const std::string &label2,
                   const std::string &label3,
                   const std::string &label4)
          :ZipMapFour(f,
                      dynamic_cast<Value<std::vector<T> >*>(values->at(label1)),
                      dynamic_cast<Value<std::vector<T> >*>(values->at(label2)),
                      dynamic_cast<Value<std::vector<T> >*>(values->at(label3)),
                      dynamic_cast<Value<std::vector<T> >*>(values->at(label4))){ }
};

template <typename T>
class Reduce : public DerivedValue<T>{
    private:
        std::function<T(std::vector<T>)> reduce;
        Value<std::vector<T> >* v;
        void update_value(){
            this->value = reduce(v->get_value());
        }
    public:
        Reduce(std::function<T(std::vector<T>)> reduce, Value<std::vector<T> >* v)
          :DerivedValue<T>(),
           reduce(reduce), v(v) { }
};

template <typename R, typename... T>
class MultiFunc : public DerivedValue<R>{
    private:
        std::function<R(T...)> f;
        std::tuple<T...> value_tuple;

        void update_value(){
            this->value = f(value_tuple);
        }

    public:
        MultiFunc(std::function<R(std::tuple<T...>)> f, T... varargs)
          :f(f),
           value_tuple(varargs...){ }
};

template <typename T>
class BoundValue : public DerivedValue<T>{
    /* A "bound" value has it's dependencies bound into a function object. */
    protected:
        std::function<T()> f;
        void update_value(){
            this->value = f();
        }
    public:
        BoundValue(std::function<T()> f)
          :f(f) { }
};

template <typename T>
class ConstantValue : public DerivedValue<T>{
    protected:
        T const_value;
        void update_value(){
            this->value = const_value;
        }
    public:
        ConstantValue(T const_value)
            :const_value(const_value) { }
};
}
#endif // value_hpp
