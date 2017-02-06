#ifndef dataset_hpp
#define dataset_hpp
#include <iostream>
#include "value.hpp"
#include "container.hpp"
#include "log.hpp"

namespace filval{
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
        void process(){
            int events, current_event;
            summary();
            events = get_events();
            std::cout << std::endl;
            while( load_next() ){
                current_event = get_current_event();
                std::cout << "\rprocessing event: " << current_event+1 << "/" << events << std::flush;
                GenValue::reset();
                for(auto con : containers){
                    con.second->fill();
                }
            }
            std::cout << " Finished!" << std::endl;
        }

        void add_container(GenContainer *container){
            containers[container->get_name()] = container;
        }

        GenContainer* get_container(std::string container_name){
            GenContainer* c = containers[container_name];
            if (c == nullptr){
                std::cout << "Request for container \"" << container_name << "\" failed. Doesn't exist." << std::endl;
                exit(-1);
            }
            return c;
        }
};
}
#endif // dataset_hpp
