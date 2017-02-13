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
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <map>
#include <limits>
#include <vector>
#include <tuple>
#include <initializer_list>
#include <functional>

#include "log.hpp"

/**
 * The namespace containing all filval classes and functions.
 */
namespace fv{

template <typename F, typename Tuple, bool Done, int Total, int... N>
struct call_impl
{
    static auto call(F f, Tuple && t)
    {
        return call_impl<F, Tuple, Total == 1 + sizeof...(N), Total, N..., sizeof...(N)>::call(f, std::forward<Tuple>(t));
    }
};

template <typename F, typename Tuple, int Total, int... N>
struct call_impl<F, Tuple, true, Total, N...>
{
    static auto call(F f, Tuple && t)
    {
        return f(std::get<N>(std::forward<Tuple>(t))...);
    }
};

/**
 * This calls a function of type F with the contents of the tuple as arguments
 *  \see http://stackoverflow.com/questions/10766112/c11-i-can-go-from-multiple-args-to-tuple-but-can-i-go-from-tuple-to-multiple
 */
template <typename F, typename Tuple>
auto call(F f, Tuple && t)
{
    typedef typename std::decay<Tuple>::type ttype;
    return call_impl<F, Tuple, 0 == std::tuple_size<ttype>::value, std::tuple_size<ttype>::value>::call(f, std::forward<Tuple>(t));
}

template<typename> class Function; // undefined
/**
 * Parent class to all Function classes. Holds a class-level collection of all
 * created function objects.
 */
class GenFunction {
    private:
        std::string name;
        std::string impl;
    protected:
        inline static bool in_register_function=false;

    public:
        /**
         * Static mapping of functions from their name to the object wrapper of
         * the function.
         */
        inline static std::map<const std::string, GenFunction*> function_registry;

        GenFunction(const std::string& name, const std::string& impl)
          :name(name),
           impl(impl){ }

        virtual ~GenFunction() { };

        std::string& get_name(){
            return name;
        }

        /**
         * Attempt to invoke clang-format for the purpose of printing out
         * nicely formatted functions to the log file. If clang-format is not
         * present, this function just passes through the code unmodified.
         */
        static std::string format_code(const std::string& code){
            std::stringstream code_out("");
            std::string command("echo \""+code+"\" | clang-format");
            char buffer[255];
            FILE *stream = popen(command.c_str(), "r");
            while (fgets(buffer, 255, stream) != NULL)
                code_out << buffer;
            if (pclose(stream) == 0)
                return code_out.str();
            else
                return code;
        }

        static std::string summary(){
            std::stringstream ss;
            ss << "The following functions have been registered" << std::endl;
            for(auto p : function_registry){
                if (p.second == nullptr) continue;
                ss << "-->" << p.second->name << std::endl;
                ss << format_code(p.second->impl);
            }
            return ss.str();
        }

        template <typename T>
        static Function<T>& register_function(const std::string& name, std::function<T> f, const std::string& impl){
            in_register_function = true;
            Function<T>* func;
            if (GenFunction::function_registry[name] != nullptr){
                func = dynamic_cast<Function<T>*>(GenFunction::function_registry[name]);
                if (func == nullptr){
                    ERROR("Trying to register function which has already been registered with a different type");
                }
            } else {
                func = new Function<T>(name, impl, f);
                GenFunction::function_registry[name] = func;
            }
            in_register_function = false;
            return *func;
        }
};


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
template <typename R, typename... ArgTypes>
class Function<R(ArgTypes...)> : public GenFunction {
    private:
        std::function<R(ArgTypes...)> f;

    public:
        Function(const std::string& name, const std::string& impl, std::function<R(ArgTypes...)> f)
          :GenFunction(name, impl), f(f){
            if (!in_register_function) {
                WARNING("Don't instantiate Function objects directly! Use GenFunction::register_function instead.");
            }
          }
        Function(const std::string& name, std::function<R(ArgTypes...)> f)
          :Function(name, "N/A", f){ }
        ~Function() { }

        R operator()(ArgTypes ...args){
            return f(args...);
        }

};


#define FUNC(f) f, #f

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
        /**
         * Composite value names are typically nested. This makes complex
         * values have rather unwieldy names. Therefore, one can declare
         * aliases which allow for more human-usable names to be used. When a
         * value is requested by name, an alias with that value takes precidence
         * over a name with that value.
         */
        inline static std::map<const std::string, GenValue*> aliases;

    public:
        GenValue(const std::string& name, const std::string& alias)
          :name(name){
            values[name] = this;
            if (alias != "")
                GenValue::alias(alias, this);
        }

        const std::string& get_name(){
            return name;
        }

        void set_name(const std::string& new_name){
            values[name] = nullptr;
            name = new_name;
            values[name] = this;
        }

        static void reset(){
            for (auto val : values){
                if (val.second != nullptr){
                    val.second->_reset();
                }
            }
        }

        static GenValue* get_value(const std::string& name){
            if (aliases[name] != nullptr)
                return aliases[name];
            else if (values[name] != nullptr)
                return values[name];
            else{
                ERROR("Could not find alias or value \"" << name << "\". I'll tell you the ones I know about." << std::endl
                        << summary());
                CRITICAL("Aborting... :(",-1);
            }
        }

        static void alias(const std::string& name, GenValue* value){
            if (aliases[name] != nullptr){
                WARNING("WARNING: alias \"" << name << "\" overrides previous entry.");
            }
            aliases[name] = value;
        }

        static GenValue* alias(const std::string& name){
            if (values[name] != nullptr){
                WARNING("Alias \"" << name << "\" does not exist.");
            }
            return aliases[name];
        }

        static std::string summary(){
            std::stringstream ss;
            ss << "The following values have been created: " << std::endl;
            for (auto value : values){
                if (value.second == nullptr) continue;
                ss << "\t\"" << value.first << "\" at address " << value.second << std::endl;
            }
            ss << "And these aliases:" << std::endl;
            for (auto alias : aliases){
                std::string orig("VOID");
                if (alias.second == nullptr) continue;
                for (auto value : values){
                    if (alias.second == value.second){
                        orig = value.second->get_name();
                        break;
                    }
                }
                ss << "\t\"" << alias.first << "\" referring to \"" << orig << "\"" << std::endl;
            }
            return ss.str();
        }
        friend std::ostream& operator<<(std::ostream& os, const GenValue& gv);
};
std::ostream& operator<<(std::ostream& os, GenValue& gv){
    os << gv.get_name();
    return os;
}


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
        Value(const std::string& name, const std::string& alias="")
          :GenValue(name, alias){ }
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
        ObservedValue(const std::string& name, T* val_ref, const std::string& alias="")
          :Value<T>(name, alias),
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
        DerivedValue(const std::string& name, const std::string& alias="")
          :Value<T>(name, alias),
           value_valid(false) { }

        T& get_value(){
            /* std::cout << "getting value of " << this->get_name() << std::endl; */
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
 */
template <typename T>
class WrapperVector : public DerivedValue<std::vector<T> >{
    private:
        Value<int>* size;
        Value<T*>* data;

        void update_value(){
            int n = size->get_value();
            T* data_ref = data->get_value();
            this->value.assign(data_ref, data_ref+n);
        }

    public:
        WrapperVector(Value<int>* size, Value<T*>* data, const std::string& alias="")
          :DerivedValue<std::vector<T> >("vectorOf("+size->get_name()+","+data->get_name()+")", alias),
           size(size), data(data){ }
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
        Pair(Value<T1> *value1, Value<T2> *value2, const std::string alias="")
          :DerivedValue<std::pair<T1, T2> >("pair("+value1->get_name()+","+value2->get_name()+")", alias),
           value_pair(value1, value2){ }
};

template<typename... T> class _Zip;
template<>
class _Zip<> {
    protected:

        int _get_size(){
            return std::numeric_limits<int>::max();
        }

        std::tuple<> _get_at(int idx){
            return std::make_tuple();
        }

        bool _verify_integrity() {
            return true;
         }

        std::string _get_name(){
            return "";
        }

    public:
        _Zip() { }
};

template<typename Head, typename... Tail>
class _Zip<Head, Tail...> : private _Zip<Tail...> {
    protected:
        Value<std::vector<Head>>* head;

        int _get_size(){
            int this_size = head->get_value().size();
            int rest_size = _Zip<Tail...>::_get_size();
            return std::min(this_size, rest_size);
        }

        typename std::tuple<Head,Tail...> _get_at(int idx){
            auto tail_tuple = _Zip<Tail...>::_get_at(idx);
            return std::tuple_cat(std::make_tuple(head->get_value()[idx]),tail_tuple);
        }

        bool _verify_integrity() {
            return (head != nullptr) &&_Zip<Tail...>::_verify_integrity();
         }

        std::string _get_name(){
            return head->get_name()+","+_Zip<Tail...>::_get_name();
        }

    public:
        _Zip() { }

        _Zip(Value<std::vector<Head>>* head, Value<std::vector<Tail>>*... tail)
          : _Zip<Tail...>(tail...),
            head(head) { }
};

/**
 * Zips a series of observations together
 */
template <typename... ArgTypes>
class Zip : public DerivedValue<std::vector<std::tuple<ArgTypes...>>>,
             private _Zip<ArgTypes...>{
    protected:
        void update_value(){
            this->value.clear();
            int size = _Zip<ArgTypes...>::_get_size();
            for(int i=0; i<size; i++){
                this->value.push_back(_Zip<ArgTypes...>::_get_at(i));
            }
        }

        std::string _get_name(){
            return "zip("+_Zip<ArgTypes...>::_get_name()+")";
        }

    public:
        Zip(Value<std::vector<ArgTypes>>*... args, const std::string& alias)
          :DerivedValue<std::vector<std::tuple<ArgTypes...>>>("", alias),
           _Zip<ArgTypes...>(args...) {
            this->set_name(_get_name());
        }
};

template<typename> class MapOver; // undefined
template <typename Ret, typename... ArgTypes>
class MapOver<Ret(ArgTypes...)> : public DerivedValue<std::vector<Ret>>{
    private:
        Function<Ret(ArgTypes...)>& fn;
        Zip<ArgTypes...>* arg;

        void update_value(){
            this->value.clear();
            for(auto tup : arg->get_value()){
                this->value.push_back(call(fn,tup));
            }
        }

    public:
        MapOver(Function<Ret(ArgTypes...)>& fn, Zip<ArgTypes...>* arg, const std::string& alias)
          :DerivedValue<std::vector<Ret>>("map_over("+fn.get_name()+":"+arg->get_name()+")", alias),
           fn(fn), arg(arg){ }

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
        Function<R(T, T, T, T)>& f;
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
        ZipMapFour(Function<R(T, T, T, T)>& f,
                   Value<std::vector<T> >* v1, Value<std::vector<T> >* v2,
                   Value<std::vector<T> >* v3, Value<std::vector<T> >* v4, const std::string alias)
          :DerivedValue<std::vector<R> >("zipmap("+f.get_name()+":"+v1->get_name()+","+v2->get_name()+","+
                                                                    v3->get_name()+","+v4->get_name()+")", alias),
           f(f), v1(v1), v2(v2), v3(v3), v4(v4) { }

        ZipMapFour(Function<R(T, T, T, T)>& f,
                   const std::string& label1, const std::string& label2,
                   const std::string& label3, const std::string& label4, const std::string alias)
          :ZipMapFour(f,
                      dynamic_cast<Value<std::vector<T> >*>(GenValue::get_value(label1)),
                      dynamic_cast<Value<std::vector<T> >*>(GenValue::get_value(label2)),
                      dynamic_cast<Value<std::vector<T> >*>(GenValue::get_value(label3)),
                      dynamic_cast<Value<std::vector<T> >*>(GenValue::get_value(label4)),
                      alias){ }
};

/**
 * Returns the count of elements in the input vector passing a test function.
 */
template<typename T>
class Count : public DerivedValue<int>{
    private:
        Function<bool(T)>& selector;
        Value<std::vector<T> >* v;

        void update_value(){
            value = 0;
            for(auto val : v->get_value()){
                if(selector(val))
                    value++;
            }
        }

    public:
        Count(Function<bool(T)>& selector, Value<std::vector<T>>* v, const std::string alias)
          :DerivedValue<int>("count("+selector.get_name()+":"+v->get_name()+")", alias),
           selector(selector), v(v) { }
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
        Function<T(std::vector<T>)>& reduce;

        void update_value(){
            this->value = reduce(v->get_value());
        }

    protected:
        Value<std::vector<T> >* v;

    public:
        Reduce(Function<T(std::vector<T>)>& reduce, Value<std::vector<T> >* v, const std::string alias)
          :DerivedValue<T>("reduceWith("+reduce.get_name()+":"+v->get_name()+")", alias),
           reduce(reduce), v(v) { }
};

/**
 * Find and return the maximum value of a vector.
 */
template <typename T>
class Max : public Reduce<T>{
    public:
        Max(Value<std::vector<T>>* v, const std::string alias)
          :Reduce<T>(GenFunction::register_function<T(std::vector<T>)>("max",
                      FUNC(([](std::vector<T> vec){
                          return *std::max_element(vec.begin(), vec.end());}))),
                      v, alias) { }
};

/**
 * Find and return the minimum value of a vector.
 */
template <typename T>
class Min : public Reduce<T>{
    public:
        Min(Value<std::vector<T>>* v, const std::string alias)
          :Reduce<T>(GenFunction::register_function<T(std::vector<T>)>("min",
                      FUNC(([](std::vector<T> vec){
                         return *std::min_element(vec.begin(), vec.end());}))),
                     v, alias) { }
};

/**
 * Calculate the mean value of a vector.
 */
template <typename T>
class Mean : public Reduce<T>{
    public:
        Mean(Value<std::vector<T>>* v, const std::string alias)
          :Reduce<T>(GenFunction::register_function<T(std::vector<T>)>("mean",
                      FUNC(([](std::vector<T> vec){
                        int n = 0; T sum = 0;
                        for (T e : vec){ n++; sum += e; }
                        return n>0 ? sum / n : 0; }))),
                     v, alias) { }
};

/**
 * Calculate the range of the values in a vector
 */
template <typename T>
class Range : public Reduce<T>{
    public:
        Range(Value<std::vector<T>>* v, const std::string alias)
          :Reduce<T>(GenFunction::register_function<T(std::vector<T>)>("range",
                      FUNC(([](std::vector<T> vec){
                        auto minmax = std::minmax_element(vec.begin(), vec.end());
                        return (*minmax.second) - (*minmax.first); }))),
                     v, alias) { }
};

/**
 * Extract the element at a specific index from a vector.
 */
template <typename T>
class ElementOf : public Reduce<T>{
    public:
        ElementOf(Value<int>* index, Value<std::vector<T>>* v, const std::string alias)
          :Reduce<T>(GenFunction::register_function<T(std::vector<T>)>("elementOf",
                     FUNC(([index](std::vector<T> vec){return vec[index->get_value()];}))),
                     v, alias) { }
};

/**
 * Similar to Reduce, but returns a pair of a T and an int.
 * This is useful if you need to know where in the vector exists the element
 * being returned.
 */
template <typename T>
class ReduceIndex : public DerivedValue<std::pair<T, int> >{
    private:
        Function<std::pair<T,int>(std::vector<T>)>& reduce;
        Value<std::vector<T> >* v;

        void update_value(){
            this->value = reduce(v->get_value());
        }

    public:
        ReduceIndex(Function<std::pair<T,int>(std::vector<T>)>& reduce, Value<std::vector<T> >* v, const std::string alias="")
          :DerivedValue<T>("reduceIndexWith("+reduce.get_name()+":"+v->get_name()+")", alias),
           reduce(reduce), v(v) { }
};

/**
 * Find and return the maximum value of a vector and its index.
 */
template <typename T>
class MaxIndex : public ReduceIndex<T>{
    public:
        MaxIndex(Value<std::vector<T>>* v, const std::string alias="")
          :ReduceIndex<T>(GenFunction::register_function<T(std::vector<T>)>("maxIndex",
                          FUNC(([](std::vector<T> vec){
                               auto elptr = std::max_element(vec.begin(), vec.end());
                               return std::pair<T,int>(*elptr, int(elptr-vec.begin())); }))),
                          v, alias) { }
};

/**
 * Find and return the minimum value of a vector and its index.
 */
template <typename T>
class MinIndex : public ReduceIndex<T>{
    public:
        MinIndex(Value<std::vector<T>>* v, const std::string alias="")
          :ReduceIndex<T>(GenFunction::register_function<T(std::vector<T>)>("minIndex",
                          FUNC(([](std::vector<T> vec){
                               auto elptr = std::min_element(vec.begin(), vec.end());
                               return std::pair<T,int>(*elptr, int(elptr-vec.begin())); }))),
                          v, alias) { }
};

/**
 * A generic value owning only a function object.
 * All necessary values upon which this value depends must be bound to the
 * function object.
 */
template <typename T>
class BoundValue : public DerivedValue<T>{
    protected:
        Function<T()>& f;
        void update_value(){
            this->value = f();
        }
    public:
        BoundValue(Function<T()>& f, const std::string alias="")
          :DerivedValue<T>(f.get_name()+"(<bound>)", alias),
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
        PointerValue(const std::string& name, T* ptr, const std::string alias="")
          :DerivedValue<T*>(name, alias){
            this->value = ptr;
        }
};

/**
 * A Value which always returns the same value, supplied in the constructor.
 */
template <typename T>
class ConstantValue : public DerivedValue<T>{
    protected:
        void update_value(){ }

    public:
        ConstantValue(const std::string& name, T const_value, const std::string alias="")
            :DerivedValue<T>("const::"+name, alias),
             Value<T>::value(const_value) { }
};
}
#endif // value_hpp
