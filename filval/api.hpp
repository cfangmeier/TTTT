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
    Value<std::vector<Ret>>*
    map(Function<Ret(ArgTypes...)>& fn,
        Value<std::vector<std::tuple<ArgTypes...>>>* arg, const std::string& alias=""){
        return new Map<Ret(ArgTypes...)>(fn, arg, alias);
    }

    template <typename... ArgTypes>
    Value<std::tuple<ArgTypes...>>*
    tuple(Value<ArgTypes>*... args, const std::string& alias=""){
        return new Tuple<ArgTypes...>(args..., alias);
    }

    template <size_t N, typename... ArgTypes>
    Value<typename std::tuple_element<N, std::tuple<ArgTypes...>>::type>*
    detup(Value<std::tuple<ArgTypes...>>* tup, const std::string& alias=""){
        return new DeTup<N, ArgTypes...>(tup, alias);
    }

    template <size_t N, typename... ArgTypes>
    Value<std::vector<typename std::tuple_element<N, std::tuple<ArgTypes...>>::type>>*
    detup_vec(Value<std::vector<std::tuple<ArgTypes...>>>* tup, const std::string& alias=""){
        return new DeTupVector<N, ArgTypes...>(tup, alias);
    }

    template <typename Ret, typename... ArgTypes>
    Value<Ret>*
    apply(Function<Ret(ArgTypes...)>& fn,
          Value<std::tuple<ArgTypes...>>* arg, const std::string& alias=""){
        return new Apply<Ret(ArgTypes...)>(fn, arg, alias);
    }

    template <typename T1, typename T2>
    Value<std::pair<T1,T2>>*
    pair(Value<T1>* val1, Value<T2>* val2, const std::string& alias=""){
        return new Pair<T1,T2>(val1, val2, alias);
    }

    template <typename T1, typename T2>
    Value<std::pair<T1,T2>>*
    pair(const std::string& name1, const std::string& name2, const std::string& alias=""){
        return pair<T1,T2>(lookup<T1>(name1), lookup<T2>(name2), alias);
    }


    template <typename T>
    Value<T>*
    max(Value<std::vector<T>>* v, const std::string& alias=""){
        return new Max<T>(v, alias);
    }

    template <typename T>
    Value<T>*
    max(const std::string& v_name, const std::string& alias=""){
        return max(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Value<T>*
    min(Value<std::vector<T>>* v, const std::string& alias=""){
        return new Min<T>(v, alias);
    }

    template <typename T>
    Value<T>*
    min(const std::string& v_name, const std::string& alias=""){
        return min(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Value<T>*
    range(Value<std::vector<T>>* v, const std::string& alias=""){
        return new Range<T>(v, alias);
    }

    template <typename T>
    Value<T>*
    range(const std::string& v_name, const std::string& alias=""){
        return range(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Value<T>*
    mean(Value<std::vector<T>>* v, const std::string& alias=""){
        return new Mean<T>(v, alias);
    }

    template <typename T>
    Value<T>*
    mean(const std::string& v_name, const std::string& alias=""){
        return mean(lookup<std::vector<T>>(v_name), alias);
    }

    template <typename T>
    Value<int>*
    count(Function<bool(T)>& selector, Value<std::vector<T>>* v, const std::string& alias=""){
        return new Count<T>(selector, v, alias);
    }

    template <typename T>
    Value<int>*
    count(Function<bool(T)>& selector, const std::string& v_name, const std::string& alias=""){
        return count<T>(selector, lookup<std::vector<T>>(v_name), alias);
    }

    template <typename FST, typename SND>
    Value<std::vector<std::tuple<FST,SND>>>*
    cart_product(Value<std::vector<FST>>* val1, Value<std::vector<SND>>* val2, const std::string& alias=""){
        return new CartProduct<FST, SND>(val1, val2, alias);
    }

    template <typename FST, typename SND>
    Value<std::vector<std::tuple<FST,SND>>>*
    cart_product(const std::string& val1_name, const std::string& val2_name, const std::string& alias=""){
        return cart_product<FST,SND>(lookup<std::vector<FST>>(val1_name), lookup<std::vector<SND>>(val2_name), alias);
    }

    template <typename T, int Size>
    Value<std::vector<typename HomoTuple<T,Size>::type>>*
    combinations(Value<std::vector<T>>* val, const std::string& alias=""){
        return new Combinations<T, Size>(val, alias);
    }

    template <typename T, int Size>
    Value<std::vector<typename HomoTuple<T,Size>::type>>*
    combinations(const std::string& val_name, const std::string alias = ""){
        return combinations<T, Size>(lookup<std::vector<T>>(val_name), alias);
    }

    template <typename T>
    Value<std::vector<T>>*
    filter(Function<bool(T)>& filter, Value<std::vector<T>>* val, const std::string alias=""){
        return new Filter<T>(filter, val, alias);
    }

    template <typename T>
    Value<std::vector<T>>*
    filter(Function<bool(T)>& filter_func, const std::string& val_name, const std::string alias=""){
        return filter<T>(filter_func, lookup<std::vector<T>>(val_name), alias);
    }

    template <typename... ArgTypes>
    Value<std::vector<std::tuple<ArgTypes...>>>*
    tup_filter(Function<bool(ArgTypes...)>& filter, Value<std::vector<std::tuple<ArgTypes...>>>* val, const std::string alias=""){
        return new TupFilter<ArgTypes...>(filter, val, alias);
    }

    template <typename... ArgTypes>
    Value<std::vector<std::tuple<ArgTypes...>>>*
    tup_filter(Function<bool(ArgTypes...)>& filter, const std::string& val_name, const std::string alias=""){
        return tup_filter<ArgTypes...>(filter, lookup<std::vector<std::tuple<ArgTypes...>>>(val_name), alias);
    }

    ObsFilter* obs_filter(const std::string& name, std::function<bool()> filter_function, const std::string& impl=""){
        return new ObsFilter(name, filter_function, impl);
    }
}
#endif // API_HPP
