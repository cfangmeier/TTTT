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
 */
#ifndef container_hpp
#define container_hpp
#include <typeindex>
#include <vector>
#include <map>

#include "value.hpp"
#include "filter.hpp"

template class std::vector<std::vector<float> >;
template class std::vector<std::vector<int> >;

namespace fv::util{
std::string get_type_name(const std::type_index& index){
    std::map<std::type_index, std::string> _map;
    // Add to this list as needed :)
    _map[typeid(int)]="int";
    _map[typeid(unsigned int)]="unsigned int";
    _map[typeid(float)]="float";
    _map[typeid(double)]="double";
    _map[typeid(std::vector<int>)]="std::vector<int>";
    _map[typeid(std::vector<float>)]="std::vector<float>";

    if (_map[index] == ""){
        CRITICAL("Cannot lookup type name of \"" << index.name() << "\"",-1);
    }
    return _map[index];
}
}

namespace fv{

/**
 * Enumeration of different options that can be used to save Containers. Not
 * all options are allowed for all Containers.
 */
enum SaveOption{
    PNG = 0,
    PDF = 1,
    ROOT = 2
};

/**
 * Generic, untyped parent class of Container. Used to allow for placing
 * Containers of disparate types in common data structures.
 */
class GenContainer{
    private:
        std::string name;
        std::string desc;
        std::vector<ObsFilter*> filters;
    protected:
        virtual void _fill() = 0;
    public:
        GenContainer(const std::string name, const std::string& desc)
          :name(name),desc(desc) { }

        GenContainer(const std::string name)
          :GenContainer(name,"N/A"){ }

        GenContainer* add_filter(GenValue* filter){
            filters.push_back(dynamic_cast<ObsFilter*>(filter));
            return this;
        }

        void fill(){
            for (auto filter : filters){
                if (!filter->get_value()) return;
            }
            _fill();
        }

        void set_description(const std::string& description){
            desc = description;
        }
        const std::string& get_name(){
            return name;
        }
        virtual void save_as(const std::string& fname, const SaveOption& option) = 0;
        virtual void save(const SaveOption& option=SaveOption::PNG) {
            save_as(get_name(), option);
        }
};

/**
 * A class that is used to "hold" values. When an event is loaded, the
 * associated filters on this container are checked. If they all pass, the
 * \c _fill() method is called and the Container can access the stored Value
 * object to process it. For example, if the Container is a ROOT Histogram
 * object, it may call <tt>container->Fill(value->get_value())</tt>.
 */
template <typename H>
class Container : public GenContainer{
    protected:
        H* container;
    public:
        Container(const std::string& name, H* container)
          :GenContainer(name),
           container(container){ }
        virtual H* get_container(){
            return container;
        }

};

/**
 * Calculate the Mean of a Value over a series of observations. This class is
 * given a value of some type that supports addition and division(eg. a \c
 * float) and yields the mean value. Note that this implementation does \i not
 * support serialization so it is not incredibly useful. See the ROOT
 * Containers for Containers that support serialization using ROOT's
 * facilities.
 */
template <typename T>
class ContainerMean : public Container<T>{
    private:
        Value<T>* value;
        int count;
        T sum;

        void _fill(){
            count++;
            sum += value->get_value();
        }
    public:
        ContainerMean(const std::string& name, Value<T>* value)
          :Container<std::vector<T> >(name, nullptr),
           value(value){
            this->container = new T();
        }

        T* get_container(){
            *(this->container) = sum/count;
            return (this->container);
        }
        void save_as(const std::string& fname) {
            WARNING("Saving of ContainerMean objects not supported");
        }
};

}
#endif // container_hpp
