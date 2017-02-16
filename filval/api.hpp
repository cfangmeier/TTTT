#ifndef API_HPP
#define API_HPP
#include <string>
#include <vector>
#include "filval/value.hpp"
namespace fv{

    template<typename T>
    Value<T>* lookup(const std::string& name){
        GenValue* gv = GenValue::get_value(name);
        Value<T>* tv = dynamic_cast<Value<T>*>(gv);
        if(tv == nullptr){
            CRITICAL("Value: "+gv->get_name() + "has improper type.",-1);
        }
        return tv;
    }

    Filter* lookup_filter(const std::string& name){
        Filter* f =  dynamic_cast<Filter*>(GenValue::get_value(name));
        if(f == nullptr){
            CRITICAL("Filter: "+f->get_name() + "has improper type.",-1);
        }
        return f;
    }

    template <typename... ArgTypes>
    Zip<ArgTypes...>* zip(Value<std::vector<ArgTypes>>*... args, const std::string& alias=""){
        return new Zip<ArgTypes...>(args..., alias);
    }

    template <typename T1, typename T2>
    Pair<T1, T2>* pair(Value<T1>* val1, Value<T2>* val2, const std::string& alias=""){
        return new Pair<T1,T2>(val1, val2, alias);
    }

    template <typename T1, typename T2>
    Pair<T1, T2>* pair(const std::string& name1, const std::string& name2, const std::string& alias=""){
        return pair<T1,T2>(lookup<T1>(name1), lookup<T2>(name2), alias);
    }

    template <typename Ret, typename... ArgTypes>
    Map<Ret(ArgTypes...)>* map(Function<Ret(ArgTypes...)>& fn,
                                        Zip<ArgTypes...>* arg, const std::string& alias=""){
        return new Map<Ret(ArgTypes...)>(fn, arg, alias);
    }

    template <typename T>
    Max<T>* max(Value<std::vector<T>>* v, const std::string alias){
        return new Max<T>(v, alias);
    }

    template <typename T>
    Max<T>* max(const std::string& v_name, const std::string alias){
        return max(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Min<T>* min(Value<std::vector<T>>* v, const std::string alias){
        return new Min<T>(v, alias);
    }

    template <typename T>
    Min<T>* min(const std::string& v_name, const std::string alias){
        return min(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Range<T>* range(Value<std::vector<T>>* v, const std::string alias){
        return new Range<T>(v, alias);
    }

    template <typename T>
    Range<T>* range(const std::string& v_name, const std::string alias){
        return range(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Mean<T>* mean(Value<std::vector<T>>* v, const std::string alias){
        return new Mean<T>(v, alias);
    }

    template <typename T>
    Mean<T>* mean(const std::string& v_name, const std::string alias){
        return mean(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Count<T>* count(Function<bool(T)>& selector, Value<std::vector<T>>* v, const std::string alias){
        return new Count<T>(selector, v, alias);
    }

    template <typename T>
    Count<T>* count(Function<bool(T)>& selector, const std::string& v_name, const std::string alias){
        return count<T>(selector, lookup<std::vector<T>>(v_name), alias);
    }

    Filter* filter(const std::string& name, std::function<bool()> filter_function, const std::string& impl=""){
        return new Filter(name, filter_function, impl);
    }
}
#endif // API_HPP
