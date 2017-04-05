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
#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <tuple>
#include <typeindex>
#include <utility>
#include <vector>

#include "log.hpp"

/**
 * The namespace containing all filval classes and functions.
 */
namespace fv{

namespace detail {
    template<typename T, int N, bool Done, typename... TYPES>
    struct _HomoTuple {
        typedef _HomoTuple<T, N, sizeof...(TYPES)+1==N, TYPES..., T> stype;
        typedef typename stype::type type;
    };

    template<typename T, int N, typename... TYPES>
    struct _HomoTuple<T, N, true, TYPES...> {
        typedef std::tuple<TYPES...> type;
    };
}

template<typename T, int N>
struct HomoTuple {
    typedef detail::_HomoTuple<T, N, N==0> stype;
    typedef typename stype::type type;
};

namespace detail {
    // Convert array into a tuple
    template<typename Array, std::size_t... I>
    decltype(auto) a2t_impl(const Array& a, std::index_sequence<I...>){
        return std::make_tuple(a[I]...);
    }
}

/**
 * Converts a std::array to a std::tuple.
 */
template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
decltype(auto) a2t(const std::array<T, N>& a){
    return detail::a2t_impl(a, Indices());
}

namespace detail {
    // Convert tuple into a vector
    template<typename R, typename Tuple, std::size_t... Is>
    decltype(auto) t2v_impl(const Tuple& t, std::index_sequence<Is...>){
        /* return std::make_tuple(a[I]...); */
        return std::vector<R>({std::get<Is>(t)...});
    }
}

/**
 * Converts a std::tuple to a std::vector.
 */
template<typename R, typename... ArgTypes>
std::vector<R> t2v(const std::tuple<ArgTypes...>& t){
    return detail::t2v_impl<R, std::tuple<ArgTypes...>>(t, std::index_sequence_for<ArgTypes...>{});
}

namespace detail {
    template <class F, class Tuple, std::size_t... I>
    constexpr decltype(auto) call_impl(F &&f, Tuple &&t, std::index_sequence<I...>){
        return std::invoke(std::forward<F>(f), std::get<I>(std::forward<Tuple>(t))...);
    }
}

/**
 * Call a function f with the elements of the tuple t as arguments
 */
template <class F, class Tuple>
constexpr decltype(auto) call(F &&f, Tuple &&t){
    return detail::call_impl(
        std::forward<F>(f), std::forward<Tuple>(t),
        std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
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

        std::string& get_impl(){
            return impl;
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
                ss << "FUNCTION::" << p.second->name  << "@" << p.second << std::endl;
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

        template <typename T>
        static Function<T>& lookup_function(const std::string& name){
            if (GenFunction::function_registry[name] == nullptr){
                CRITICAL("Function \"" << name << "\" not previously registered", -1);
            } else {
                Function<T>* func = dynamic_cast<Function<T>*>(GenFunction::function_registry[name]);
                if (func == nullptr){
                    CRITICAL("Function \"" << name << "\" request and register have mismatched types", -1);
                }
                return *GenFunction::function_registry[name];
            }
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

template <typename T>
class Value;
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
        bool value_valid;

        void _reset(){
            this->value_valid = false;
        }

        /**
         * A static mapping containing all created Value objects.
         * Every value object must have a unique name, and this name is used as
         * a key in values to that object. This is used to enable more dynamic
         * creation of objects as well as avoiding the uneccesary passing of
         * pointers.
         */
        inline static std::map<std::pair<const std::type_index, const std::string>, GenValue*> values;

        /**
         * Composite value names are typically nested. This makes complex
         * values have rather unwieldy names. Therefore, one can declare
         * aliases which allow for more human-usable names to be used. When a
         * value is requested by name, an alias with that value takes precidence
         * over a name with that value.
         */
        inline static std::map<std::pair<const std::type_index, const std::string>, GenValue*> aliases;

        bool logging_enabled;

    public:
        GenValue(const std::type_index&& ti, const std::string& name, const std::string& alias)
          :name(name), value_valid(false), logging_enabled(false){
            if (alias != "")
                INFO("Registered value: \"" << name << "\" with alias: \"" << alias << "\"");
            else
                INFO("Registered value: \"" << name);
            values[std::make_pair(ti,name)] = this;
            if (alias != "")
                GenValue::alias(ti, alias, this);
        }

        const std::string& get_name(){
            return name;
        }


        /**
         * If logging is enabled for this value, this function should be
         * implemented to format the value to a string and place it as an INFO
         * entry in the log file. Useful for debugging, but may produce alot of
         * output.
         */
        virtual void log() = 0;

        static void reset(){
            for (auto val : values){
                if (val.second != nullptr){
                    val.second->_reset();
                }
            }
        }

        template<typename T>
        static Value<T>* get_value(const std::string& name){
            const std::type_index& ti = typeid(T);
            auto lookup_id = std::make_pair(ti,name);
            if (aliases[lookup_id] != nullptr)
                return (Value<T>*)aliases[lookup_id];
            else
                return (Value<T>*)values[lookup_id];
        }


        static void alias(const std::type_index& ti, const std::string& name, GenValue* value){
            auto lookup_id = std::make_pair(ti,name);
            if (aliases[lookup_id] != nullptr){
                WARNING("WARNING: alias \"" << name << "\" overrides previous entry.");
            }
            aliases[lookup_id] = value;
        }

        template<typename T>
        static void alias(const std::string& name, Value<T>* value){
            alias(typeid(T), name, value);
        }

        static std::string summary(){
            std::stringstream ss;
            ss << "The following values have been created:" << std::endl;
            for (auto item : values){
                auto& key = item.first;
                auto& value = item.second;
                if (value == nullptr) continue;
                ss << "\tVALUE::\"" << key.second << "\" at address " << value << std::endl;
            }
            ss << "And these aliases:" << std::endl;
            for (auto item : aliases){
                auto& key = item.first;
                auto& value = item.second;
                std::string orig("VOID");
                if (value == nullptr) continue;
                for (auto v_item : values){
                    auto& v_value = v_item.second;
                    if (v_value == value){
                        orig = v_value->get_name();
                        break;
                    }
                }
                ss << "\tALIAS::\"" << key.second << "\" referring to \"" << orig << "\"" << std::endl;
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
 * A templated value.
 * In order to facilitate run-time creation of analysis routines, it is
 * necessary to have some ability to get and store *values*. Values can either
 * be directly taken from some original data source (i.e. ObservedValue), or
 * they can be a function of some other set of values (i.e. DerivedValue). They
 * template class T of Value<T> is the type of thing that is returned upon
 * calling get_value().
 */
template <typename T>
class Value : public GenValue{
    protected:
        std::function<std::string(T)> value_to_string;

    public:
        Value(const std::string& name, const std::string& alias="")
          :value_to_string([](T){return "";}),
           GenValue(typeid(T), name, alias){ }
        /** Calculate, if necessary, and return the value held by this object.
         */
        virtual T& get_value() = 0;

        void enable_logging(const std::function<std::string(T)>& value_to_string = [](T){return "";}){
            logging_enabled = true;
            this->value_to_string = value_to_string;
        }

        void disable_logging(){
            logging_enabled = false;
        }
};


/**
 * A value supplied by the dataset, not derived.
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

    public:
        ObservedValue(const std::string& name, T* val_ref, const std::string& alias="")
          :Value<T>(name, alias),
           val_ref(val_ref){ }

        void log(){
            if(this->logging_enabled){
                INFO(this->get_name() << ": " << this->value_to_string(*val_ref));
            }
        }

        static std::string fmt_name(const std::string& name){
            return name;
        }

        T& get_value(){
            if (!this->value_valid){
                this->value_valid = true;
                this->log();
            }
            return *val_ref;
        }
};


/**
 * A Value derived from some other Values, not directly from the dataset.
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
    protected:
        T value;

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
          :Value<T>(name, alias){ }

        void log(){
            if(this->logging_enabled){
                INFO(this->get_name() << ": " << this->value_to_string(value));
            }
        }

        T& get_value(){
            if (!this->value_valid){
                update_value();
                this->value_valid = true;
                this->log();
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
        static std::string fmt_name(Value<int>* size, Value<T*>* data){
            return "wrapper_vector("+size->get_name()+","+data->get_name()+")";
        }

        WrapperVector(Value<int>* size, Value<T*>* data, const std::string& alias="")
          :DerivedValue<std::vector<T> >(fmt_name(size,data), alias),
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
        static std::string fmt_name(Value<T1> *value1, Value<T2> *value2){
            return "pair("+value1->get_name()+","+value2->get_name()+")";
        }

        Pair(Value<T1> *value1, Value<T2> *value2, const std::string alias="")
          :DerivedValue<std::pair<T1, T2> >(fmt_name(value1, value2), alias),
           value_pair(value1, value2){ }
};

template<typename... T> class _Zip;
template<>
class _Zip<> {
    protected:

        int _get_size(){
            return std::numeric_limits<int>::max();
        }

        std::tuple<> _get_at(int){
            return std::make_tuple();
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

        std::string _get_name(){
            return head->get_name()+","+_Zip<Tail...>::_get_name();
        }

    public:
        _Zip() { }

        _Zip(Value<std::vector<Head>>* head, Value<std::vector<Tail>>*... tail)
          : _Zip<Tail...>(tail...),
            head(head) { }
};

namespace impl {
    std::string zip_fmt_name(){
        return "";
    }

    template<typename Head>
    std::string zip_fmt_name(Value<std::vector<Head>>* head){
        return head->get_name();
    }

    template<typename Head1, typename Head2, typename... Tail>
    std::string zip_fmt_name(Value<std::vector<Head1>>* head1, Value<std::vector<Head2>>* head2, Value<std::vector<Tail>>*... tail){
        return head1->get_name() + "," + zip_fmt_name<Head2, Tail...>(head2, tail...);
    }
}
/**
 * Zips a series of vectors together. Can be combined with Map to
 * yield a Value whose elements are individually a function of the
 * corresponding elements of the vectors that were zipped together. For those
 * familiar with python, it accompilishes the same thing as
 * @code{.py}
 * xs = [1,2,3,4]
 * ys = [10,20,30,40]
 * print(list(map(lambda t:t[0]+t[1],zip(xs,ys))))
 * @endcode
 * which outputs
 * @code
 * [11, 22, 33, 44]
 * @endcode
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

    public:
        static std::string fmt_name(Value<std::vector<ArgTypes>>*... args){
            return "zip("+zip_fmt_name(args...)+")";
        }

        Zip(Value<std::vector<ArgTypes>>*... args, const std::string& alias)
          :DerivedValue<std::vector<std::tuple<ArgTypes...>>>(fmt_name(args...), alias),
           _Zip<ArgTypes...>(args...) { }
};

template<typename> class Map; // undefined
/**
 * Maps a function over an input vector. The input vector must be a vector of
 * tuples, where the the elements of the tuple match the arguments of the
 * function. For example if the function takes two floats as arguments, the
 * tuple should contain two floats. The Value object required by Map will
 * typically be created as a Zip.
 */
template <typename Ret, typename... ArgTypes>
class Map<Ret(ArgTypes...)> : public DerivedValue<std::vector<Ret>>{
    private:
        typedef Value<std::vector<std::tuple<ArgTypes...>>> arg_type;
        Function<Ret(ArgTypes...)>& fn;
        arg_type* arg;

        void update_value(){
            this->value.clear();
            for(auto tup : arg->get_value()){
                this->value.push_back(call(fn,tup));
            }
        }

    public:
        static std::string fmt_name(Function<Ret(ArgTypes...)>& fn, arg_type* arg){
            return "map("+fn.get_name()+":"+arg->get_name()+")";
        }

        Map(Function<Ret(ArgTypes...)>& fn, arg_type* arg, const std::string& alias)
          :DerivedValue<std::vector<Ret>>(fmt_name(fn, arg), alias),
           fn(fn), arg(arg){ }

};

template<typename... T> class _Tuple;
template<>
class _Tuple<> {
    protected:

        std::tuple<> _get_value(){
            return std::make_tuple();
        }

    public:
        _Tuple() { }
};

template<typename Head, typename... Tail>
class _Tuple<Head, Tail...> : private _Tuple<Tail...> {
    protected:
        Value<Head>* head;

        typename std::tuple<Head,Tail...> _get_value(){
            auto tail_tuple = _Tuple<Tail...>::_get_value();
            return std::tuple_cat(std::make_tuple(head->get_value()),tail_tuple);
        }

    public:
        _Tuple() { }

        _Tuple(Value<Head>* head, Value<Tail>*... tail)
          : _Tuple<Tail...>(tail...),
            head(head) { }
};

namespace impl {
    std::string tuple_fmt_name(){
        return "";
    }

    template<typename Head>
    std::string tuple_fmt_name(Value<Head>* head){
        return head->get_name();
    }

    template<typename Head1, typename Head2, typename... Tail>
    std::string tuple_fmt_name(Value<Head1>* head1, Value<Head2>* head2, Value<Tail>*... tail){
        return head1->get_name() + "," + tuple_fmt_name<Head2, Tail...>(head2, tail...);
    }
}

/**
 * Takes a series of Value objects and bundles them together into a std::tuple
 * object. Typically, this is most usefull when one wants to apply a function
 * to a few values and store the result. This class can be used in conjunction
 * with Apply to achieve this.
 */
template <typename... ArgTypes>
class Tuple : public DerivedValue<std::tuple<ArgTypes...>>,
              private _Tuple<ArgTypes...>{
    protected:
        void update_value(){
            this->value = _Tuple<ArgTypes...>::_get_value();
        }

    public:
        static std::string fmt_name(Value<ArgTypes>*... args){
            return "tuple("+impl::tuple_fmt_name(args...)+")";
        }

        Tuple(Value<ArgTypes>*... args, const std::string& alias)
          :DerivedValue<std::tuple<ArgTypes...>>(fmt_name(args...), alias),
           _Tuple<ArgTypes...>(args...) { }
};

/**
 * Gets the Nth element from a tuple value
 */
template <size_t N, typename... ArgTypes>
class DeTup : public DerivedValue<typename std::tuple_element<N, std::tuple<ArgTypes...>>::type>{
    Value<std::tuple<ArgTypes...>> tup;
    protected:
        void update_value(){
            this->value = std::get<N>(tup->get_value());
        }

    public:
        static std::string fmt_name(Value<std::tuple<ArgTypes...>>* tup){
            return "detup("+tup->get_name()+")";
        }

        DeTup(Value<std::tuple<ArgTypes...>>* tup, const std::string& alias)
          :DerivedValue<typename std::tuple_element<N, std::tuple<ArgTypes...>>::type>(fmt_name(tup), alias),
           tup(tup) { }
};

/**
 * Creates a vector of extracting the Nth value from each entry in a vector of
 * tuples.
 */
template <size_t N, typename... ArgTypes>
class DeTupVector : public DerivedValue<std::vector<typename std::tuple_element<N, std::tuple<ArgTypes...>>::type>>{
    Value<std::vector<std::tuple<ArgTypes...>>>* tup;
    protected:
        void update_value(){
            this->value.clear();
            for( auto& t : tup->get_value()){
                this->value.push_back(std::get<N>(t));
            }
        }

    public:
        static std::string fmt_name(Value<std::vector<std::tuple<ArgTypes...>>>* tup){
            return "detup_vec("+tup->get_name()+")";
        }

        DeTupVector(Value<std::vector<std::tuple<ArgTypes...>>>* tup, const std::string& alias)
          :DerivedValue<std::vector<typename std::tuple_element<N, std::tuple<ArgTypes...>>::type>>(fmt_name(tup), alias),
           tup(tup) { }
};

template<typename> class Apply; // undefined
/**
 * Applies a function to a tuple of values and returns a value. This will
 * typically be called with a Tuple object as an argument.
 */
template <typename Ret, typename... ArgTypes>
class Apply<Ret(ArgTypes...)> : public DerivedValue<Ret>{
    private:
        Function<Ret(ArgTypes...)>& fn;
        Value<std::tuple<ArgTypes...>>* arg;

        void update_value(){
            auto &tup = arg->get_value();
            this->value = call(fn, tup);
        }

    public:
        static std::string fmt_name(Function<Ret(ArgTypes...)>& fn, Value<std::tuple<ArgTypes...>>* arg){
            return "apply("+fn.get_name()+":"+arg->get_name()+")";
        }

        Apply(Function<Ret(ArgTypes...)>& fn, Value<std::tuple<ArgTypes...>>* arg, const std::string& alias)
          :DerivedValue<Ret>(fmt_name(fn,arg), alias),
           fn(fn), arg(arg){ }

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
        static std::string fmt_name(Function<bool(T)>& selector, Value<std::vector<T>>* v){
            return "count("+selector.get_name()+":"+v->get_name()+")";
        }

        Count(Function<bool(T)>& selector, Value<std::vector<T>>* v, const std::string alias)
          :DerivedValue<int>(fmt_name(selector,v), alias),
           selector(selector), v(v) { }
};

/**
 * Returns the elements in a vector that pass a test function.
 */
template<typename T>
class Filter : public DerivedValue<std::vector<T>>{
    private:
        Function<bool(T)>& filter;
        Value<std::vector<T> >* v;

        void update_value(){
            this->value.clear();
            for(auto val : v->get_value()){
                if(this->filter(val))
                    this->value.push_back(val);
            }
        }

    public:
        static std::string fmt_name(Function<bool(T)>& filter, Value<std::vector<T>>* v){
            return "filter("+filter.get_name()+":"+v->get_name()+")";
        }

        Filter(Function<bool(T)>& filter, Value<std::vector<T>>* v, const std::string alias)
          :DerivedValue<std::vector<T>>(fmt_name(filter,v), alias),
           filter(filter), v(v) { }
};

/**
 * Returns the elements in a vector that pass a test function. The elements on
 * the vector must be tuples. Typically this will be used in conjunction with
 * Zip and Map.
 */
template<typename... ArgTypes>
class TupFilter : public DerivedValue<std::vector<std::tuple<ArgTypes...>>>{
    private:
        typedef std::vector<std::tuple<ArgTypes...>> value_type;
        Function<bool(ArgTypes...)>& filter;
        Value<value_type>* arg;

        void update_value(){
            this->value.clear();
            for(auto val : arg->get_value()){
                if(call(filter,val))
                    this->value.push_back(val);
            }
        }

    public:
        static std::string fmt_name(Function<bool(ArgTypes...)>& filter, Value<value_type>* arg){
            return "tup_filter("+filter.get_name()+":"+arg->get_name()+")";
        }

        TupFilter(Function<bool(ArgTypes...)>& filter, Value<value_type>* arg, const std::string alias)
          :DerivedValue<value_type>(fmt_name(filter, arg), alias),
           filter(filter), arg(arg) { }
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
        Function<T(std::vector<T>)>& reduce_fn;

        void update_value(){
            this->value = reduce_fn(v->get_value());
        }

    protected:
        Value<std::vector<T> >* v;

    public:
        static std::string fmt_name(Function<T(std::vector<T>)>& reduce_fn, Value<std::vector<T>>* v){
            return "reduce("+reduce_fn.get_name()+":"+v->get_name()+")";
        }

        Reduce(Function<T(std::vector<T>)>& reduce_fn, Value<std::vector<T> >* v, const std::string alias)
          :DerivedValue<T>(fmt_name(reduce_fn, v), alias),
           reduce_fn(reduce_fn), v(v) { }
};

/**
 * Find and return the maximum value of a vector.
 */
template <typename T>
class Max : public Reduce<T>{
    public:
        static std::string fmt_name(Value<std::vector<T>>* v){
            return "max("+v->get_name()+")";
        }

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
        static std::string fmt_name(Value<std::vector<T>>* v){
            return "min("+v->get_name()+")";
        }

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
        static std::string fmt_name(Value<std::vector<T>>* v){
            return "mean("+v->get_name()+")";
        }

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
        static std::string fmt_name(Value<std::vector<T>>* v){
            return "range("+v->get_name()+")";
        }

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
 * Find combinations of items from an input vector
 */
template <typename T, int Size>
class Combinations : public DerivedValue<std::vector<typename HomoTuple<T,Size>::type>>{
    private:
        Value<std::vector<T>>* val;
        typedef typename HomoTuple<T,Size>::type tuple_type;

        void update_value(){
            auto& v = val->get_value();
            int data_size = v.size();
            this->value.clear();

            std::vector<bool> selector(data_size);
            std::fill(selector.begin(), selector.begin()+std::min({Size,data_size}), true);
            do {
                std::array<T, Size> perm;
                int idx = 0;
                for (int i=0; i<data_size; i++){
                    if (selector[i]){
                        perm[idx] = v[i];
                        idx++;
                        if (idx == Size) break;
                    }
                }
                this->value.push_back(a2t(perm)); //!!!
            } while(std::prev_permutation(selector.begin(), selector.end()));
        }

    public:
        static std::string fmt_name(Value<std::vector<T>>* val){
            std::stringstream ss;
            ss << "combinations(" << Size << "," << val->get_name() << ")";
            return ss.str();
        }

        Combinations(Value<std::vector<T>>* val, const std::string alias="")
          :DerivedValue<std::vector<tuple_type>>(fmt_name(val), alias),
           val(val) { }

};

/**
 * Calculate the cartesian product of two input vectors
 */
template <typename FST, typename SND>
class CartProduct : public DerivedValue<std::vector<std::tuple<FST,SND>>>{
    private:
        Value<std::vector<FST>>* val1;
        Value<std::vector<SND>>* val2;

        void update_value(){
            this->value.clear();
            auto& v1 = val1->get_value();
            auto& v2 = val2->get_value();
            for(int i=0; i<v1.size(); i++){
                for(int j=0; j<v2.size(); j++){
                    this->value.push_back(std::tuple<FST,SND>(v1[i],v2[j]));
                }
            }
        }

        static std::string calc_name(Value<std::vector<FST>>* val1, Value<std::vector<SND>>* val2){
            std::stringstream ss;
            ss << "cartProduct("
               << val1->get_name() << ", " << val2->get_name()
               << ")";
            return ss.str();
        }

    public:
        static std::string fmt_name(Value<std::vector<FST>>* val1, Value<std::vector<SND>>* val2){
            return "cartProduct("+val1->get_name()+", "+val2->get_name()+")";
        }

        CartProduct(Value<std::vector<FST>>* val1, Value<std::vector<SND>>* val2, const std::string alias="")
          :DerivedValue<std::vector<std::tuple<FST,SND>>>(calc_name(val1, val2), alias),
           val1(val1), val2(val2) { }
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
        static std::string fmt_name(Function<T()> f){
            return f.get_name()+"(<bound>)";
        }

        BoundValue(Function<T()>& f, const std::string alias="")
          :DerivedValue<T>(fmt_name(f), alias),
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
        static std::string fmt_name(const std::string& name){
            return "const::"+name;
        }
        ConstantValue(const std::string& name, T const_value, const std::string alias="")
          :DerivedValue<T>(fmt_name(name), alias) {
            this->value = const_value;
        }
};
}
#endif // value_hpp
