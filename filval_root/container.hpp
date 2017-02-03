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
            if (container == nullptr){
                init_TH1();
            }
            container->Fill(value->get_value());
        }
    protected:
        std::string title;
        int nbins;
        T low;
        T high;
        Value<T> *value;
        virtual void init_TH1() = 0;
    public:
        explicit ContainerTH1(const std::string &name, const std::string& title, GenValue *value,
                     int nbins, T low, T high)
          :Container<TH1>(name, nullptr),
           title(title), nbins(nbins), low(low), high(high),
           value(dynamic_cast<Value<T>*>(value)) { }
};

class ContainerTH1D : public ContainerTH1<double>{
    using ContainerTH1::ContainerTH1;
    void init_TH1(){
        this->container = new TH1D(this->get_name().c_str(), title.c_str(), nbins, low, high);
    }
};

class ContainerTH1F : public ContainerTH1<float>{
    using ContainerTH1::ContainerTH1;
    void init_TH1(){
        this->container = new TH1F(this->get_name().c_str(), title.c_str(), nbins, low, high);
    }
};

class ContainerTH1I : public ContainerTH1<int>{
    using ContainerTH1::ContainerTH1;
    void init_TH1(){
        this->container = new TH1I(this->get_name().c_str(), title.c_str(), nbins, low, high);
    }
};


template <typename T>
class ContainerTH2 : public Container<TH2>{
    private:
        void _fill(){
            if (container == nullptr){
                init_TH2();
            }
            std::pair<T, T> val = value->get_value();
            container->Fill(val.first, val.second);
        }
    protected:
        std::string title;
        int nbins_x;
        int nbins_y;
        T low_x;
        T low_y;
        T high_x;
        T high_y;
        Value<std::pair<T, T> > *value;
        virtual void init_TH2() = 0;
    public:
        explicit ContainerTH2(const std::string& name, const std::string& title,
                      int nbins_x, double low_x, double high_x,
                      int nbins_y, double low_y, double high_y,
                      GenValue* value)
          :Container<TH2>(name, nullptr),
           nbins_x(nbins_x), low_x(low_x), high_x(high_x),
           nbins_y(nbins_y), low_y(low_y), high_y(high_y),
           value(dynamic_cast<Value<T>*>(value)) { }
};

class ContainerTH2D : public ContainerTH2<double>{
    using ContainerTH2::ContainerTH2;
    void init_TH2(){
        this->container = new TH2D(this->get_name().c_str(), title.c_str(), nbins_x, low_x, high_x, nbins_y, low_y, high_y);
    }
};

class ContainerTH2F : public ContainerTH2<float>{
    using ContainerTH2::ContainerTH2;
    void init_TH2(){
        this->container = new TH2F(this->get_name().c_str(), title.c_str(), nbins_x, low_x, high_x, nbins_y, low_y, high_y);
    }
};

class ContainerTH2I : public ContainerTH2<int>{
    using ContainerTH2::ContainerTH2;
    void init_TH2(){
        this->container = new TH2I(this->get_name().c_str(), title.c_str(), nbins_x, low_x, high_x, nbins_y, low_y, high_y);
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
            data_modified = true;
        }
    public:
        ContainerTGraph(const std::string &name, GenValue* value)
          :Container<TGraph>(name, new TGraph()),
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
