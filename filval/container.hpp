#ifndef container_hpp
#define container_hpp
#include "value.hpp"
#include "filter.hpp"
#include <vector>

namespace filval{
class GenContainer{
    private:
        std::string name;
        std::string desc;
        std::vector<GenFilter*> filters;
    protected:
        virtual void _fill() = 0;
    public:
        GenContainer(const std::string name)
          :name(name){ }
        void add_filter(GenValue* filter){
            filters.push_back(dynamic_cast<GenFilter*>(filter));
        }
        void fill(){
            for (auto filter : filters){
                if (!filter->get_value()){
                    return;
                }
            }
            _fill();
        }
        void set_description(const std::string& description){
            desc = description;
        }
        const std::string& get_name(){
            return name;
        }
};
typedef std::map<std::string, GenContainer*> ContainerSet;

template <typename H>
class Container : public GenContainer{
    protected:
        H* container;
    public:
        Container(H* container, const std::string name)
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
        ContainerVector(std::vector<T> *container, Value<T>* value, const std::string name)
          :Container<std::vector<T> >(container, name),
           value(value){ }
        ContainerVector(Value<T>* value, const std::string name)
          :Container<std::vector<T> >(NULL, name),
           value(value){
            this->container = new std::vector<T>();
        }
};

}
#endif // container_hpp
