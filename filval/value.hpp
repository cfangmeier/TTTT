/**
 * @file
 * @author  Caleb Fangmeier <caleb@fangmeier.tech>
 * @version 0.1
 *
 * @section LICENSE
 *
 *
 * MIT License
 *
 * Copyright (c) 2017 Caleb Fangmeier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @section DESCRIPTION
 * This header defines a set of generic classes that wrap up "values". In
 * essence, a Value<T> object is just something that contains a value of type T
 * and can provide it when requested. The usefulness stems from composing
 * values together with calculations. This enables very clear dependency
 * mapping and a way to know clearly how every value was arrived at. This could
 * be used to, for example, automatically generate commentary for plots that
 * explain the exect calculation used to create it. Or easily making a series
 * of plots contrasting different values that have been composed slightly
 * differently.
 */
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

/**
 * The namespace containing all filval classes and functions.
 */
namespace filval{

/**
 * In order to enable proper provenance tracking, and at the same time keep
 * the ability to embed functions into values, the Function class should be
 * used. It is simply a wrapper around a std::function that also has a name.
 * This name is used when generating the name of values that use the function.
 * A function name is automatically prepended with "func::" to explicitly state
 * that the value is the result of a computation encoded within the function
 * object, and not from some other Value object. Unfortunately, it is up to the
 * user to find where that function is defined in the source code to inspect
 * what it is doing. But hopefully this isn't too onerous by just using grep.
 */
template<typename> class Function; // undefined
template <typename R, typename... ArgTypes>
class Function<R(ArgTypes...)> {
    std::string name;
    std::function<R(ArgTypes...)> f;

    public:
        Function(const std::string& name, std::function<R(ArgTypes...)> f)
          :name("func::"+name),f(f){ }

    std::string& get_name(){
        return name;
    }

    R operator()(ArgTypes ...args){
        return f(args...);
    }
};

/**
 * A type-agnostic value.
 * It is necessary to create a type-agnostic parent class to Value so that
 * it is possible to handle collections of them. GenValue also provides the
 * rest of the type-independent interface to Value.
 */
class GenValue;
typedef std::map<std::string, GenValue*> ValueSet;
class GenValue{
    private:
        /**
         * The name of the value.
         * This is used to allow for dynamic lookup of
         * values based on their name via GenValue::get_value.
         */
        std::string name;
    protected:
        /**
         * Mark the internal value as invalid. This is needed for DerivedValue
         * to force a recalculation of the internal value when a new
         * observation is loaded into memory. It is called automatically for
         * all GenValue objects when reset is called.
         */
        virtual void _reset() = 0;
        /**
         * A static mapping containing all created Value objects.
         * Every value object must have a unique name, and this name is used as
         * a key in values to that object. This is used to enable more dynamic
         * creation of objects as well as avoiding the uneccesary passing of
         * pointers.
         */
        inline static std::map<const std::string, GenValue*> values;
        inline static std::map<const std::string, GenValue*> aliases;
    public:
        GenValue(const std::string& name)
          :name(name) {
            values[name] = this;
        }

        const std::string& get_name(){
            return name;
        }

        static void reset(){
            for (auto val : values){
                val.second->_reset();
            }
        }

        static GenValue* get_value(const std::string& name){
            if (aliases[name] != NULL)
                return aliases[name];
            else if (values[name] != NULL)
                return values[name];
            else{
                std::cout << "ERROR: Could not find alias or value \"" << name << "\"" << std::endl;
                std::cout << "I'll tell you the ones I know about." << std::endl;
                summary();
                std::cout << "Aborting... :(" << std::endl;
                exit(-1);
            }
        }

        static void alias(const std::string& name, GenValue* value){
            if (aliases[name] != NULL){
                std::cout << "WARNING: alias \"" << name << "\" overrides previous entry." << std::endl;
            }
            aliases[name] = value;
        }

        static GenValue* alias(const std::string& name){
            if (values[name] != NULL){
                std::cout << "WARNING: alias \"" << name << "\" does not exist." << std::endl;
            }
            return aliases[name];
        }

        static void summary(){
            std::cout << "The following values have been created: " << std::endl;
            for (auto value : values){
                if (value.second == NULL) continue;
                std::cout << "\t\"" << value.first << "\" at address " << value.second << std::endl;
            }
            std::cout << "And these aliases:" << std::endl;
            for (auto alias : aliases){
                std::string orig("VOID");
                if (alias.second == NULL) continue;
                for (auto value : values){
                    if (alias.second == value.second){
                        orig = value.second->get_name();
                        break;
                    }
                }
                std::cout << "\t\"" << alias.first << "\" referring to \"" << orig << "\"" << std::endl;
            }
        }
};


/**
 * A generic value.
 * In order to facilitate run-time creation of analysis routines, it is
 * necessary to have some ability to get and store *values*. Values can either
 * be directly taken from some original data source (i.e. ObservedValue), or
 * they can be a function of some other set of values (i.e. DerivedValue). They
 * template class T of Value<T> is the type of thing that is returned upon
 * calling get_value().
 */
template <typename T>
class Value : public GenValue{
    public:
        Value(const std::string& name)
          :GenValue(name){ }
        /** Calculate, if necessary, and return the value held by this object.
         */
        virtual T& get_value() = 0;
};


/**
 * A generic, observed, value.
 * An ObservedValue is the interface to your dataset. Upon creation, an
 * ObservedValue is given a pointer to an object of type T. When an observation
 * is loaded into memory, the value at the location referenced by that pointer
 * must be updated with the associated data from that observation. This is the
 * responsibility of whatever DataSet implementation is being used. This object
 * then will read that data and return it when requested.
 */
template <typename T>
class ObservedValue : public Value<T>{
    private:
        T *val_ref;
        void _reset(){ }
    public:
        ObservedValue(const std::string& name, T* val_ref)
          :Value<T>(name),
           val_ref(val_ref){ }
        T& get_value(){
            return *val_ref;
        }
};


/**
 * A generic, derived, value.
 * A DerivedValue is generally defined as some function of other Value objects.
 * For example, a Pair is a function of two other Value objects that makes a
 * pair of them. Note that these other Value objects are free to be either
 * ObservedValues or other DerivedValues. 
 *
 * It is desireable from a performance standpoint that each DerivedValue be
 * calculated no more than once per observation. Therefore, when a get_value is
 * called on a DerivedValue, it first checks whether the value that it holds is
 * **valid**, meaning it has already been calculated for this observation. If
 * so, it simply returns the value. If not, the update_value function is called
 * to calculate the value. and then the newly calculated value is marked as
 * valid and returned.
 */
template <typename T>
class DerivedValue : public Value<T>{
    private:
        void _reset(){
            value_valid = false;
        }
    protected:
        T value;
        bool value_valid;

        /**
         * Updates the internal value.
         * This function should be overridden by any child class to do the
         * actual work of updating value based on whatever rules the class
         * chooses. Normally, this consists of geting the values from some
         * associated Value objects, doing some calculation on them, and
         * storing the result in value.
         */
        virtual void update_value() = 0;
    public:
        DerivedValue(const std::string& name)
          :Value<T>(name),
           value_valid(false) { }

        T& get_value(){
            if (!value_valid){
                update_value();
                value_valid = true;
            }
            return value;
        }
};


/**
 * A std::vector wrapper around a C-style array.
 * In order to make some of the higher-level Value types easier to work with,
 * it is a good idea to wrap all arrays in the original data source with
 * std::vector objects. To do this, it is necessary to supply both a Value
 * object containing the array itself as well as another Value object
 * containing the size of that array. Currently, update_value will simply copy
 * the contents of the array into the interally held vector.
 * \todo avoid an unneccessary copy and set the vectors data directly.
 */
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
        WrapperVector(Value<int>* size, Value<T*>* data)
          :DerivedValue<std::vector<T> >("vectorOf("+size->get_name()+","+data->get_name()+")"),
           size(size), data(data){ }

        WrapperVector(const std::string &label_size, const std::string &label_data)
          :WrapperVector(dynamic_cast<Value<int>*>(GenValue::values.at(label_size)),
                         dynamic_cast<Value<T*>*>(GenValue::values.at(label_data))) { }
};

/**
 * Creates a std::pair type from a two other Value objects.
 */
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
          :DerivedValue<std::pair<T1, T2> >("pair("+value1->get_name()+","+value2->get_name()+")"),
           value_pair(value1, value2){ }
        Pair(const std::string& label1, const std::string& label2)
          :Pair(dynamic_cast<Value<T1>*>(GenValue::values.at(label1)),
                dynamic_cast<Value<T1>*>(GenValue::values.at(label2))){ }
};

/**
 * Takes a set of four Value<std::vector<T> > objects and a function of four Ts
 * and returns a std::vector<R>. This is used in, for instance, calculating the
 * energy of a set of particles when one has separate arrays containing pt,
 * eta, phi, and mass. These arrays are first wrapped up in VectorWrappers and
 * then passes along with a function to calculate the energy into a ZipMapFour.
 * The result of this calculation is a new vector containing the energy for
 * each particle. Note that if the input vectors are not all the same size,
 * calculations are only performed up to the size of the shortest.
 * \see MiniTreeDataSet
 * \todo find way to implement for arbitrary number(and possibly type) of
 * vector inputs.
 */
template <typename R, typename T>
class ZipMapFour : public DerivedValue<std::vector<R> >{
    private:
        Function<R(T, T, T, T)> f;
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
        ZipMapFour(Function<R(T, T, T, T)> f,
                   Value<std::vector<T> >* v1, Value<std::vector<T> >* v2,
                   Value<std::vector<T> >* v3, Value<std::vector<T> >* v4)
          :DerivedValue<std::vector<R> >("zipmap("+f.get_name()+":"+v1->get_name()+","+v2->get_name()+","+v3->get_name()+","+v4->get_name()+")"),
           f(f), v1(v1), v2(v2), v3(v3), v4(v4) { }

        ZipMapFour(Function<R(T, T, T, T)> f,
                   const std::string &label1, const std::string &label2,
                   const std::string &label3, const std::string &label4)
          :ZipMapFour(f,
                      dynamic_cast<Value<std::vector<T> >*>(GenValue::values.at(label1)),
                      dynamic_cast<Value<std::vector<T> >*>(GenValue::values.at(label2)),
                      dynamic_cast<Value<std::vector<T> >*>(GenValue::values.at(label3)),
                      dynamic_cast<Value<std::vector<T> >*>(GenValue::values.at(label4))){ }
};

/**
 * Reduce a Value of type vector<T> to just a T.
 * This is useful functionality to model, for instance, calculating the maximum
 * element of a vector, or a the mean. See child classes for specific
 * implementations.
 */
template <typename T>
class Reduce : public DerivedValue<T>{
    private:
        Function<T(std::vector<T>)> reduce;
        Value<std::vector<T> >* v;
        void update_value(){
            this->value = reduce(v->get_value());
        }
    public:
        Reduce(Function<T(std::vector<T>)> reduce, Value<std::vector<T> >* v)
          :DerivedValue<T>("reduceWith("+reduce.get_name()+":"+v->get_name()+")"),
           reduce(reduce), v(v) { }

        Reduce(Function<T(std::vector<T>)> reduce, const std::string& v_name)
          :Reduce(reduce, dynamic_cast<Value<std::vector<T> >*>(GenValue::get_value(v_name))) { }
};

/**
 * Find and return the maximum value of a vector.
 */
template <typename T>
class Max : public Reduce<T>{
    public:
        Max(const std::string& v_name)
          :Reduce<T>(Function<T(std::vector<T>)>("max", [](std::vector<T> vec){ 
                         return *std::max_element(vec.begin(), vec.end());}),
                     v_name) { }
};

/**
 * Find and return the minimum value of a vector.
 */
template <typename T>
class Min : public Reduce<T>{
    public:
        Min(const std::string& v_name)
          :Reduce<T>(Function<T(std::vector<T>)>("min", [](std::vector<T> vec){ 
                         return *std::min_element(vec.begin(), vec.end());}),
                     v_name) { }
};

/**
 * Calculate the mean value of a vector.
 */
template <typename T>
class Mean : public Reduce<T>{
    public:
        Mean(const std::string& v_name)
          :Reduce<T>(Function<T(std::vector<T>)>("mean", [](std::vector<T> vec){
                        int n = 0; T sum = 0;
                        for (T e : vec){ n++; sum += e; }
                        return n>0 ? sum / n : 0; }),
                     v_name) { }
};

/**
 * Extract the element at a specific index from a vector. 
 */
template <typename T>
class ElementOf : public Reduce<T>{
    public:
        ElementOf(Value<int>* index, const std::string& v_name)
          :Reduce<T>(Function<T(std::vector<T>)>("elementOf", [index](std::vector<T> vec){return vec[index->get_value()];}),
                     v_name) { }
        ElementOf(const std::string& name, int index, const std::string& v_name)
          :Reduce<T>(name, [index](std::vector<T> vec){return vec[index];}, v_name) { }
};

/**
 * Similar to Reduce, but returns a pair of a T and an int.
 * This is useful if you need to know where in the vector exists the element
 * being returned.
 */
template <typename T>
class ReduceIndex : public DerivedValue<std::pair<T, int> >{
    private:
        Function<std::pair<T,int>(std::vector<T>)> reduce;
        Value<std::vector<T> >* v;
        void update_value(){
            this->value = reduce(v->get_value());
        }
    public:
        ReduceIndex(Function<std::pair<T,int>(std::vector<T>)> reduce, Value<std::vector<T> >* v)
          :DerivedValue<T>("reduceIndexWith("+reduce.get_name()+":"+v->get_name()+")"),
           reduce(reduce), v(v) { }

        ReduceIndex(Function<std::pair<T,int>(std::vector<T>)> reduce, const std::string& v_name)
          :ReduceIndex(reduce, dynamic_cast<Value<std::vector<T> >*>(GenValue::get_value(v_name))) { }
};

/**
 * Find and return the maximum value of a vector and its index.
 */
template <typename T>
class MaxIndex : public ReduceIndex<T>{
    public:
        MaxIndex(const std::string& v_name)
          :ReduceIndex<T>(Function<T(std::vector<T>)>("maxIndex", [](std::vector<T> vec){ 
                              auto elptr = std::max_element(vec.begin(), vec.end());
                              return std::pair<T,int>(*elptr, int(elptr-vec.begin()));}),
                          v_name) { }
};

/**
 * Find and return the minimum value of a vector and its index.
 */
template <typename T>
class MinIndex : public ReduceIndex<T>{
    public:
        MinIndex(const std::string& v_name)
          :ReduceIndex<T>(Function<T(std::vector<T>)>("minIndex", [](std::vector<T> vec){ 
                              auto elptr = std::min_element(vec.begin(), vec.end());
                              return std::pair<T,int>(*elptr, int(elptr-vec.begin()));}),
                          v_name) { }
};


/**
 * A variadic 
 */
/* template <typename R, typename... T> */
/* class MultiFunc : public DerivedValue<R>{ */
/*     private: */
/*         Function<R(T...)> f; */
/*         std::tuple<T...> value_tuple; */

/*         void update_value(){ */
/*             this->value = f(value_tuple); */
/*         } */

/*     public: */
/*         MultiFunc(const std::string& name, Function<R(std::tuple<T...>)> f, T... varargs) */
/*           :DerivedValue<R>(name), */
/*            f(f), */
/*            value_tuple(varargs...){ } */
/* }; */

/**
 * A generic value owning only a function object.
 * All necessary values upon which this value depends must be bound to the
 * function object.
 */
template <typename T>
class BoundValue : public DerivedValue<T>{
    protected:
        Function<T()> f;
        void update_value(){
            this->value = f();
        }
    public:
        BoundValue(Function<T()> f)
          :DerivedValue<T>(f.get_name()+"(<bound>)"),
           f(f) { }
};

/**
 * A Value of a pointer. The pointer is constant, however the data the pointer
 * points to is variable.
 */
template <typename T>
class PointerValue : public DerivedValue<T*>{
    protected:
        void update_value(){ }
    public:
        PointerValue(const std::string& name, T* ptr)
          :DerivedValue<T*>(name){ 
            this->value = ptr;
        }
};

/**
 * A Value which always returns the same value, supplied in the constructor.
 */
template <typename T>
class ConstantValue : public DerivedValue<T>{
    protected:
        T const_value;
        void update_value(){
            this->value = const_value;
        }
    public:
        ConstantValue(const std::string& name, T const_value)
            :DerivedValue<T>("const::"+name),
             const_value(const_value) { }
};
}
#endif // value_hpp
