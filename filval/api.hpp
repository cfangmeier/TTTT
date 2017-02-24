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
            CRITICAL("Value: \""+gv->get_name() + "\" has improper type.",-1);
        }
        return tv;
    }

    ObsFilter* lookup_obs_filter(const std::string& name){
        ObsFilter* f =  dynamic_cast<ObsFilter*>(GenValue::get_value(name));
        if(f == nullptr){
            CRITICAL("ObsFilter: "+f->get_name() + "has improper type.",-1);
        }
        return f;
    }

    template <typename... ArgTypes>
    Value<std::vector<std::tuple<ArgTypes...>>>*
    zip(Value<std::vector<ArgTypes>>*... args, const std::string& alias=""){
        return new Zip<ArgTypes...>(args..., alias);
    }

    template <typename Ret, typename... ArgTypes>
    Map<Ret(ArgTypes...)>*
    map(Function<Ret(ArgTypes...)>& fn,
        Value<std::vector<std::tuple<ArgTypes...>>>* arg, const std::string& alias=""){
        return new Map<Ret(ArgTypes...)>(fn, arg, alias);
    }


    template <typename... ArgTypes>
    Tuple<ArgTypes...>*
    tuple(Value<ArgTypes>*... args, const std::string& alias=""){
        return new Tuple<ArgTypes...>(args..., alias);
    }

    template <typename Ret, typename... ArgTypes>
    Apply<Ret(ArgTypes...)>*
    apply(Function<Ret(ArgTypes...)>& fn,
          Tuple<ArgTypes...>* arg, const std::string& alias=""){
        return new Apply<Ret(ArgTypes...)>(fn, arg, alias);
    }

    template <typename T1, typename T2>
    Pair<T1, T2>*
    pair(Value<T1>* val1, Value<T2>* val2, const std::string& alias=""){
        return new Pair<T1,T2>(val1, val2, alias);
    }

    template <typename T1, typename T2>
    Pair<T1, T2>*
    pair(const std::string& name1, const std::string& name2, const std::string& alias=""){
        return pair<T1,T2>(lookup<T1>(name1), lookup<T2>(name2), alias);
    }


    template <typename T>
    Max<T>*
    max(Value<std::vector<T>>* v, const std::string alias){
        return new Max<T>(v, alias);
    }

    template <typename T>
    Max<T>*
    max(const std::string& v_name, const std::string alias){
        return max(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Min<T>*
    min(Value<std::vector<T>>* v, const std::string alias){
        return new Min<T>(v, alias);
    }

    template <typename T>
    Min<T>*
    min(const std::string& v_name, const std::string alias){
        return min(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Range<T>*
    range(Value<std::vector<T>>* v, const std::string alias){
        return new Range<T>(v, alias);
    }

    template <typename T>
    Range<T>*
    range(const std::string& v_name, const std::string alias){
        return range(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Mean<T>*
    mean(Value<std::vector<T>>* v, const std::string alias){
        return new Mean<T>(v, alias);
    }

    template <typename T>
    Mean<T>*
    mean(const std::string& v_name, const std::string alias){
        return mean(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Count<T>*
    count(Function<bool(T)>& selector, Value<std::vector<T>>* v, const std::string alias){
        return new Count<T>(selector, v, alias);
    }

    template <typename T>
    Count<T>*
    count(Function<bool(T)>& selector, const std::string& v_name, const std::string alias){
        return count<T>(selector, lookup<std::vector<T>>(v_name), alias);
    }

    template <typename FST, typename SND>
    Value<std::vector<std::tuple<FST,SND>>>*
    cart_product(Value<std::vector<FST>>* val1, Value<std::vector<SND>>* val2, const std::string alias){
        return new CartProduct<FST, SND>(val1, val2, alias);
    }

    template <typename FST, typename SND>
    Value<std::vector<std::tuple<FST,SND>>>*
    cart_product(const std::string& val1_name, const std::string& val2_name, const std::string alias = ""){
        return cart_product<FST,SND>(lookup<std::vector<FST>>(val1_name), lookup<std::vector<SND>>(val2_name), alias);
    }

    ObsFilter* obs_filter(const std::string& name, std::function<bool()> filter_function, const std::string& impl=""){
        return new ObsFilter(name, filter_function, impl);
    }
}
#endif // API_HPP
