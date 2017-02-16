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

enum SaveOption{
    PNG = 0,
    PDF = 1,
    ROOT = 2
};

class GenContainer{
    private:
        std::string name;
        std::string desc;
        std::vector<Filter*> filters;
    protected:
        virtual void _fill() = 0;
    public:
        GenContainer(const std::string name, const std::string& desc)
          :name(name),desc(desc) { }

        GenContainer(const std::string name)
          :GenContainer(name,"N/A"){ }

        void add_filter(GenValue* filter){
            filters.push_back(dynamic_cast<Filter*>(filter));
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
typedef std::map<std::string, GenContainer*> ContainerSet;

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
