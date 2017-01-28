#ifndef dataset_hpp
#define dataset_hpp
#include "value.hpp"
#include "container.hpp"

namespace filval{
class DataSet{
    protected:
        ValueSet values;
        ContainerSet containers;
        virtual bool load_next() = 0;
    public:
        void process(){
            while( load_next() ){
                for(auto val : values)
                    val.second->reset();
                for(auto con : containers)
                    con.second->fill();
            }
        }
        void add_value(GenValue *value, const std::string& value_name ){
            values[value_name] = value;
        }
        GenValue* get_value(std::string value_name){
            return values[value_name];
        }

        void add_container(GenContainer *container){
            containers[container->get_name()] = container;
        }
        GenContainer* get_container(std::string container_name){
            return containers[container_name];
        }
};
}
#endif // dataset_hpp
