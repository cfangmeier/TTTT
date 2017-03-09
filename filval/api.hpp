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
 */
#ifndef API_HPP
#define API_HPP
#include <string>
#include <vector>
#include "filval/value.hpp"
namespace fv{

    template<typename T>
    Value<T>* lookup(const std::string& name){
        GenValue* gv = GenValue::get_value(name);
        if (gv == nullptr){
            CRITICAL("Could not find alias or value \"" << name << "\"."
                     <<" I'll tell you the ones I know about." << std::endl
                     << GenValue::summary(), -1);
        }
        Value<T>* tv = dynamic_cast<Value<T>*>(gv);
        if(tv == nullptr){
            CRITICAL("Value: \""+gv->get_name() + "\" has improper type.",-1);
        }
        return tv;
    }

    template<typename T>
    bool check_exists(const std::string name){
        GenValue* gv = GenValue::get_value(name);
        Value<T>* tv = dynamic_cast<Value<T>*>(gv);
        return tv != nullptr;
    }

    ObsFilter* lookup_obs_filter(const std::string& name){
        ObsFilter* f =  dynamic_cast<ObsFilter*>(GenValue::get_value(name));
        if(f == nullptr){
            CRITICAL("ObsFilter: "+f->get_name() + "has improper type.",-1);
        }
        return f;
    }

    template <typename T>
    decltype(auto)
    wrapper_vector(Value<int>* size, Value<T*>* data, const std::string& alias=""){
        typedef std::vector<T> type;
        const std::string& name = WrapperVector<T>::fmt_name(size, data);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new WrapperVector<T>(size, data, alias);
    }

    template <typename... ArgTypes>
    decltype(auto)
    zip(Value<std::vector<ArgTypes>>*... args, const std::string& alias=""){
        typedef std::vector<std::tuple<ArgTypes...>> type;
        std::string& name = Zip<ArgTypes...>::fmt_name(args...);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Zip<ArgTypes...>(args..., alias);
    }

    template <typename Ret, typename... ArgTypes>
    decltype(auto)
    map(Function<Ret(ArgTypes...)>& fn, Value<std::vector<std::tuple<ArgTypes...>>>* arg, const std::string& alias=""){
        typedef std::vector<Ret> type;
        const std::string& name = Map<Ret(ArgTypes...)>::fmt_name(fn, arg);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Map<Ret(ArgTypes...)>(fn, arg, alias);
    }

    template <typename... ArgTypes>
    decltype(auto)
    tuple(Value<ArgTypes>*... args){
        typedef std::tuple<ArgTypes...> type;
        const std::string& name = Tuple<ArgTypes...>::fmt_name(args...);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Tuple<ArgTypes...>(args..., "");
    }

    template <size_t N, typename... ArgTypes>
    decltype(auto)
    detup(Value<std::tuple<ArgTypes...>>* tup, const std::string& alias=""){
        typedef typename std::tuple_element<N, std::tuple<ArgTypes...>>::type type;
        const std::string& name = DeTup<N, ArgTypes...>::fmt_name(tup);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new DeTup<N, ArgTypes...>(tup, alias);
    }

    template <size_t N, typename... ArgTypes>
    decltype(auto)
    detup_vec(Value<std::vector<std::tuple<ArgTypes...>>>* tup, const std::string& alias=""){
        typedef std::vector<typename std::tuple_element<N, std::tuple<ArgTypes...>>::type> type;
        const std::string& name = DeTupVector<N, ArgTypes...>::fmt_name(tup);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new DeTupVector<N, ArgTypes...>(tup, alias);
    }

    template <typename Ret, typename... ArgTypes>
    decltype(auto)
    apply(Function<Ret(ArgTypes...)>& fn, Value<std::tuple<ArgTypes...>>* arg, const std::string& alias=""){
        typedef Ret type;
        const std::string& name = Apply<Ret(ArgTypes...)>::fmt_name(fn, arg);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Apply<Ret(ArgTypes...)>(fn, arg, alias);
    }

    template <typename T1, typename T2>
    decltype(auto)
    pair(Value<T1>* val1, Value<T2>* val2, const std::string& alias=""){
        typedef std::pair<T1,T2> type;
        const std::string& name = Pair<T1,T2>::fmt_name(val1, val2);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Pair<T1,T2>(val1, val2, alias);
    }

    template <typename T1, typename T2>
    decltype(auto)
    pair(const std::string& name1, const std::string& name2, const std::string& alias=""){
        return pair<T1,T2>(lookup<T1>(name1), lookup<T2>(name2), alias);
    }


    template <typename T>
    decltype(auto)
    max(Value<std::vector<T>>* v, const std::string& alias=""){
        typedef T type;
        const std::string& name = Max<T>::fmt_name(v);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Max<T>(v, alias);
    }

    template <typename T>
    decltype(auto)
    max(const std::string& v_name, const std::string& alias=""){
        return max(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    decltype(auto)
    min(Value<std::vector<T>>* v, const std::string& alias=""){
        typedef T type;
        const std::string& name = Min<T>::fmt_name(v);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Min<T>(v, alias);
    }

    template <typename T>
    decltype(auto)
    min(const std::string& v_name, const std::string& alias=""){
        return min(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    decltype(auto)
    range(Value<std::vector<T>>* v, const std::string& alias=""){
        typedef T type;
        const std::string& name = Range<T>::fmt_name(v);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Range<T>(v, alias);
    }

    template <typename T>
    decltype(auto)
    range(const std::string& v_name, const std::string& alias=""){
        return range(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    decltype(auto)
    mean(Value<std::vector<T>>* v, const std::string& alias=""){
        typedef T type;
        const std::string& name = Mean<T>::fmt_name(v);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Mean<T>(v, alias);
    }

    template <typename T>
    decltype(auto)
    mean(const std::string& v_name, const std::string& alias=""){
        return mean(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    decltype(auto)
    count(Function<bool(T)>& selector, Value<std::vector<T>>* v, const std::string& alias=""){
        typedef int type;
        const std::string& name = Count<T>::fmt_name(selector, v);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Count<T>(selector, v, alias);
    }

    template <typename T>
    decltype(auto)
    count(Function<bool(T)>& selector, const std::string& v_name, const std::string& alias=""){
        return count<T>(selector, lookup<std::vector<T>>(v_name), alias);
    }

    template <typename FST, typename SND>
    decltype(auto)
    cart_product(Value<std::vector<FST>>* val1, Value<std::vector<SND>>* val2, const std::string& alias=""){
        typedef std::vector<std::tuple<FST,SND>> type;
        const std::string& name = CartProduct<FST, SND>::fmt_name(val1, val2);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new CartProduct<FST, SND>(val1, val2, alias);
    }

    template <typename FST, typename SND>
    decltype(auto)
    cart_product(const std::string& val1_name, const std::string& val2_name, const std::string& alias=""){
        return cart_product<FST,SND>(lookup<std::vector<FST>>(val1_name), lookup<std::vector<SND>>(val2_name), alias);
    }

    template <typename T, int Size>
    decltype(auto)
    combinations(Value<std::vector<T>>* val, const std::string& alias=""){
        typedef std::vector<typename HomoTuple<T,Size>::type> type;
        const std::string& name = Combinations<T, Size>::fmt_name(val);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Combinations<T, Size>(val, alias);
    }

    template <typename T, int Size>
    decltype(auto)
    combinations(const std::string& val_name, const std::string alias = ""){
        return combinations<T, Size>(lookup<std::vector<T>>(val_name), alias);
    }

    template <typename T>
    decltype(auto)
    filter(Function<bool(T)>& filter, Value<std::vector<T>>* val, const std::string alias=""){
        typedef std::vector<T> type;
        const std::string& name = Filter<T>::fmt_name(filter, val);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new Filter<T>(filter, val, alias);
    }

    template <typename T>
    decltype(auto)
    filter(Function<bool(T)>& filter_func, const std::string& val_name, const std::string alias=""){
        return filter<T>(filter_func, lookup<std::vector<T>>(val_name), alias);
    }

    template <typename... ArgTypes>
    decltype(auto)
    tup_filter(Function<bool(ArgTypes...)>& filter, Value<std::vector<std::tuple<ArgTypes...>>>* val, const std::string alias=""){
        typedef std::vector<std::tuple<ArgTypes...>> type;
        const std::string& name = TupFilter<ArgTypes...>::fmt_name(filter, val);
        if (check_exists<type>(name))
            return lookup<type>(name);
        else
            return (Value<type>*)new TupFilter<ArgTypes...>(filter, val, alias);
    }

    template <typename... ArgTypes>
    decltype(auto)
    tup_filter(Function<bool(ArgTypes...)>& filter, const std::string& val_name, const std::string alias=""){
        return tup_filter<ArgTypes...>(filter, lookup<std::vector<std::tuple<ArgTypes...>>>(val_name), alias);
    }

    ObsFilter* obs_filter(const std::string& name, std::function<bool()> filter_function, const std::string& impl=""){
        return new ObsFilter(name, filter_function, impl);
    }
}
#endif // API_HPP
