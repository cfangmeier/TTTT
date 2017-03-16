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
#ifndef dataset_hpp
#define dataset_hpp
#include <iostream>
#include "value.hpp"
#include "container.hpp"
#include "log.hpp"

namespace fv{

typedef std::map<std::string, GenContainer*> ContainerSet;

/*
 * A DataSet is a generic source of data that is used to populate
 * ObservedValues. For each ObservedValue, it is recommened that the DataSet
 * have a field whose value is updated when the load_next() method is called. A
 * pointer to this value is then passed during the creation of the
 * ObservedValue. It is important, therefore, that the location in memory of
 * the data not change from event to event.
 */
class DataSet{
    private:
        void summary(){
            INFO(GenValue::summary());
            INFO(GenFunction::summary());
        }

        Value<int>* current_event_number;

    protected:
        ContainerSet containers;
        virtual bool load_next() = 0;
        virtual int get_events() = 0;
        virtual int get_current_event() = 0;

        std::map<std::string,std::string> get_container_name_value_map(){
            std::map<std::string, std::string> value_map;
            for(auto container : containers)
                value_map[container.first] = container.second->get_value_name();
            return value_map;
        }

        std::map<std::string,std::string> get_function_name_impl_map(){
            std::map<std::string, std::string> impl_map;
            for(auto fn : GenFunction::function_registry)
                if (fn.second != nullptr){
                    impl_map[fn.first] = GenFunction::format_code(fn.second->get_impl());
                }
            return impl_map;
        }
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

        template<typename C, typename... ArgTypes>
        C* register_container(ArgTypes... args){
            C* container = new C(args...);
            if (containers[container->get_name()] != nullptr){
                CRITICAL("Container with name \""+container->get_name()+"\" already exists.", -1);
            }
            containers[container->get_name()] = container;
            return container;
        }

        GenContainer* get_container(std::string container_name){
            GenContainer* c = containers[container_name];
            if (c == nullptr){
                CRITICAL("Request for container \"" << container_name << "\" failed. Doesn't exist.", -1);
            }
            return c;
        }

        DataSet(){
            auto& event_check = GenFunction::register_function<int()>("event_number",
                FUNC(([ds=this](){
                    return ds->get_current_event();
                })));
            current_event_number = new BoundValue<int>(event_check);
        }

        Value<int>* get_current_event_number(){
            return current_event_number;
        }
};
}
#endif // dataset_hpp
