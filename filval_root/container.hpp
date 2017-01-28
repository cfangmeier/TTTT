#ifndef root_container_hpp
#define root_container_hpp
#include <utility>
#include "../filval/filval.hpp"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include <iostream>

namespace filval::root {

template <typename T>
class ContainerTH1 : public Container<TH1>{
    private:
        void _fill(){
            container->Fill(value->get_value());
        }
    protected:
        Value<T> *value;
        ContainerTH1(TH1* container, const std::string &name, Value<T> *value)
          :Container<TH1>(container, name),
           value(value){ }
};

class ContainerTH1D : public ContainerTH1<double>{
    public:
        ContainerTH1D(const std::string& name, const std::string& title,
                      int nbins, double low, double high, GenValue* value)
          :ContainerTH1<double>(NULL, name, dynamic_cast<Value<double>*>(value)){
               this->container = new TH1D(name.c_str(), title.c_str(), nbins, low, high);
        }
};

class ContainerTH1I : public ContainerTH1<int>{
    public:
        ContainerTH1I(const std::string& name, const std::string& title,
                      int nbins, int low, int high, GenValue* value)
          :ContainerTH1<int>(NULL, name, dynamic_cast<Value<int>*>(value)){
               this->container = new TH1I(name.c_str(), title.c_str(), nbins, low, high);
        }
};


template <typename T>
class ContainerTH2 : public Container<TH2>{
    private:
        void _fill(){
            std::pair<T, T> val = value->get_value();
            container->Fill(val.first, val.second);
        }
    protected:
        Value<std::pair<T, T> > *value;
        ContainerTH2(TH2* container, const std::string &name, Value<std::pair<T, T> > *value)
          :Container<TH2>(container, name),
           value(value){ }
};

class ContainerTH2D : public ContainerTH2<double>{
    public:
        ContainerTH2D(const std::string& name, const std::string& title,
                      int nbins_x, double low_x, double high_x,
                      int nbins_y, double low_y, double high_y,
                      GenValue* value)
          :ContainerTH2<double>(NULL, name, dynamic_cast<Value<std::pair<double, double> >*>(value)){
               this->container = new TH2D(name.c_str(), title.c_str(), nbins_x, low_x, high_x, nbins_y, low_y, high_y);
        }
};

class ContainerTH2I : public ContainerTH2<int>{
    public:
        ContainerTH2I(const std::string& name, const std::string& title,
                      int nbins_x, int low_x, int high_x,
                      int nbins_y, int low_y, int high_y,
                      GenValue* value)
          :ContainerTH2<int>(NULL, name, dynamic_cast<Value<std::pair<int, int> >*>(value)){
               this->container = new TH2I(name.c_str(), title.c_str(), nbins_x, low_x, high_x, nbins_y, low_y, high_y);
        }
};

class ContainerTGraph : public Container<TGraph>{
    private:
        Value<std::pair<int, int> > *value;
        std::vector<int> x_data;
        std::vector<int> y_data;
        bool data_modified;
        void _fill(){
            auto val = value->get_value();
            x_data.push_back(val.first);
            y_data.push_back(val.second);
            /* std::cout << x_data.size() << std::endl; */
            data_modified = true;
        }
    public:
        ContainerTGraph(const std::string &name, GenValue* value)
          :Container<TGraph>(new TGraph(), name),
           value(dynamic_cast<Value<std::pair<int, int> >*>(value)),
           data_modified(false){ }

        TGraph* get_container(){
            if (data_modified){
                delete container;
                container = new TGraph(x_data.size(), x_data.data(), y_data.data());
                data_modified = false;
            }
            return container;
        }
};

}
#endif // root_container_hpp
