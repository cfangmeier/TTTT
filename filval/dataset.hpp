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
                GenValue::reset();
                for(auto con : containers)
                    con.second->fill();
            }
        }

        /* template <typename T> */
        /* virtual T* get_field(const std::string& field_name) = 0; */

        void add_value(GenValue *value, const std::string& value_name ){
            /* Adds a value to the dataset's list of known value objects. Note
             * that all new values are automatically kept track of by
             * GenValue::values so this is only needed if one wants to recall
             * the value by name.
             */
            values[value_name] = value;
        }
        GenValue* get_value(std::string value_name){
            return values.at(value_name);
        }

        void add_container(GenContainer *container){
            containers[container->get_name()] = container;
        }
        GenContainer* get_container(std::string container_name){
            return containers.at(container_name);
        }
};
}
#endif // dataset_hpp
