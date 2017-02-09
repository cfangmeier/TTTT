#ifndef dataset_hpp
#define dataset_hpp
#include <iostream>
#include "value.hpp"
#include "container.hpp"
#include "log.hpp"

namespace fv{
class DataSet{
    private:
        void summary(){
            INFO(GenValue::summary());
            INFO(GenFunction::summary());
        }

    protected:
        ContainerSet containers;
        virtual bool load_next() = 0;
        virtual int get_events() = 0;
        virtual int get_current_event() = 0;

    public:
        void process(bool silent=false){
            int events, current_event;
            summary();
            events = get_events();
            if (!silent) std::cout << std::endl;
            while( load_next() ){
                current_event = get_current_event();
                if (!silent) std::cout << "\rprocessing event: " << current_event+1 << "/" << events << std::flush;
                GenValue::reset();
                for(auto con : containers){
                    con.second->fill();
                }
            }
            if (!silent) std::cout << " Finished!" << std::endl;
        }

        virtual void save_all(){
            for(auto container : containers)
                container.second->save();
        }

        void register_container(GenContainer *container){
            if (containers[container->get_name()] != nullptr){
                CRITICAL("Container with name \""+container->get_name()+"\" already exists.", -1);
            }
            containers[container->get_name()] = container;
        }

        GenContainer* get_container(std::string container_name){
            GenContainer* c = containers[container_name];
            if (c == nullptr){
                CRITICAL("Request for container \"" << container_name << "\" failed. Doesn't exist.", -1);
            }
            return c;
        }
};
}
#endif // dataset_hpp
