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
 * A Filter is a special type of derived value that can only return a boolean.
 * Container objects have a vector of filters that control if a "fill" call
 * actually places data into the container or not. This file contains a variety
 * of generic filters to aide in analysis.
 */
#ifndef filter_h
#define filter_h
#include <iostream>
#include <functional>
#include "value.hpp"
namespace fv {

class ObsFilter : public DerivedValue<bool>{
    private:
        Function<bool()>& filter_function;

        void update_value(){
            value = filter_function();
        }

    public:
        ObsFilter(const std::string& name, std::function<bool()> filter_function, const std::string& impl="")
          :DerivedValue<bool>(name),
           filter_function(GenFunction::reg_func<bool()>("filter::"+name, filter_function, impl)){ }
};

/** Return a new filter that is the conjuction of a vector of source filters
 */
ObsFilter* all(const std::vector<ObsFilter*>&& fs){
    if(fs.size() == 0){
        return nullptr;
    } else{
        std::stringstream ss;
        ss << fs[0]->get_name();
        for(size_t i=1; i<fs.size(); i++) ss << "AND" << fs[i]->get_name();
        return new ObsFilter(ss.str(), [fs](){
                return std::all_of(std::begin(fs), std::end(fs), [](ObsFilter* f){return f->get_value();});
        });
    }
}

/** Return a new filter that is the disjunction of a vector of source filters
 */
ObsFilter* any(const std::vector<ObsFilter*>&& fs){
    if(fs.size() == 0){
        return nullptr;
    } else{
        std::stringstream ss;
        ss << fs[0]->get_name();
        for(size_t i=1; i<fs.size(); i++) ss << "OR" << fs[i]->get_name();
        return new ObsFilter(ss.str(), [fs](){
                return std::any_of(std::begin(fs), std::end(fs), [](ObsFilter* f){return f->get_value();});
        });
    }
}

}
#endif // filter_h
