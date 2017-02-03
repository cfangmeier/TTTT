#ifndef dataset_hpp
#define dataset_hpp
#include <iostream>
#include "value.hpp"
#include "container.hpp"

namespace filval{
class DataSet{
    private:
        void summary(){
            GenValue::summary();
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
                    /* std::cout << std::endl << "Filling container: " << con.first; */
                    con.second->fill();
                }
                /* std::cout << std::endl; */
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
