#ifndef container_hpp
#define container_hpp
#include "value.hpp"
#include "filter.hpp"
#include <vector>

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
class ContainerVector : public Container<std::vector<T> >{
    private:
        Value<T>* value;

        void _fill(){
            this->container->push_back(value->get_value());
        }
    public:
        ContainerVector(const std::string& name, std::vector<T> *container, Value<T>* value)
          :Container<std::vector<T> >(name, container),
           value(value){ }
        ContainerVector(const std::string& name, Value<T>* value)
          :Container<std::vector<T> >(name, nullptr),
           value(value){
            this->container = new std::vector<T>();
        }
        void save_as(const std::string& fname) { }
        virtual void save() { }
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
        void save_as(const std::string& fname) { }
        virtual void save() { }
};

}
#endif // container_hpp
