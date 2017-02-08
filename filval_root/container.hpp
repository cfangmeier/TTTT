#ifndef root_container_hpp
#define root_container_hpp
#include <utility>
#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TROOT.h"

#include "../filval/filval.hpp"

namespace fv::root::util{
void _save_img(TObject* container, const std::string& fname){
    TCanvas* c1 = new TCanvas("c1");
    container->Draw();
    c1->Draw();
    c1->SaveAs(fname.c_str());
    delete c1;
}

void _save_bin(TObject* container, const std::string& fname){
    INFO("Saving object: " << container->GetName() << " into file " << fname);
    TFile* f = TFile::Open(fname.c_str(), "UPDATE");
    container->Write(container->GetName(), TObject::kOverwrite);
    f->Close();
}

void _save_as(TObject* container, const std::string& fname, const SaveOption& option = SaveOption::PNG) {
    switch(option){
        case PNG:
            _save_img(container, fname+".png"); break;
        case PDF:
            _save_img(container, fname+".pdf"); break;
        case ROOT:
            _save_bin(container, fname+".root"); break;
        default:
            break;
    }
}
}

namespace fv::root {

template <typename V, typename D>
class ContainerTH1 : public Container<TH1>{
    private:
        void _fill(){
            if (container == nullptr){
                init_TH1();
            }
            _do_fill(value->get_value());
        }

    protected:
        std::string title;
        int nbins;
        D low;
        D high;
        Value<V> *value;
        virtual void init_TH1() = 0;
        virtual void _do_fill(V& val) = 0;

    public:
        explicit ContainerTH1(const std::string &name, const std::string& title, GenValue *value,
                     int nbins, D low, D high)
          :Container<TH1>(name, nullptr),
           title(title), nbins(nbins), low(low), high(high),
           value(dynamic_cast<Value<V>*>(value)) { }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::_save_as(get_container(), fname, option);
        }
};

template <typename V>
class _ContainerTH1D : public ContainerTH1<V, double>{
    using ContainerTH1<V, double>::ContainerTH1;
    void init_TH1(){
        this->container = new TH1D(this->get_name().c_str(), this->title.c_str(),
                                   this->nbins, this->low, this->high);
    }
};

class ContainerTH1D : public _ContainerTH1D<double>{
    using _ContainerTH1D<double>::_ContainerTH1D;
    void _do_fill(double& val){
        this->container->Fill(val);
    }
};

class ContainerTH1DMany : public _ContainerTH1D<std::vector<double>>{
    using _ContainerTH1D<std::vector<double>>::_ContainerTH1D;
    void _do_fill(std::vector<double>& val){
        for(double x : val)
            this->container->Fill(x);
    }
};


template <typename V>
class _ContainerTH1F : public ContainerTH1<V, float>{
    using ContainerTH1<V,float>::ContainerTH1;
    void init_TH1(){
        this->container = new TH1F(this->get_name().c_str(), this->title.c_str(),
                                   this->nbins, this->low, this->high);
    }
};

class ContainerTH1F : public _ContainerTH1F<float>{
    using _ContainerTH1F<float>::_ContainerTH1F;
    void _do_fill(float& val){
        this->container->Fill(val);
    }
};

class ContainerTH1FMany : public _ContainerTH1F<std::vector<float>>{
    using _ContainerTH1F<std::vector<float>>::_ContainerTH1F;
    void _do_fill(std::vector<float>& val){
        for(float x : val)
            this->container->Fill(x);
    }
};


template <typename V>
class _ContainerTH1I : public ContainerTH1<V, int>{
    using ContainerTH1<V,int>::ContainerTH1;
    void init_TH1(){
        this->container = new TH1I(this->get_name().c_str(), this->title.c_str(),
                                   this->nbins, this->low, this->high);
    }
};

class ContainerTH1I : public _ContainerTH1I<int>{
    using _ContainerTH1I<int>::_ContainerTH1I;
    void _do_fill(int& val){
        this->container->Fill(val);
    }
};

class ContainerTH1IMany : public _ContainerTH1I<std::vector<int>>{
    using _ContainerTH1I<std::vector<int>>::_ContainerTH1I;
    void _do_fill(std::vector<int>& val){
        for(int x : val)
            this->container->Fill(x);
    }
};


/* template <typename T> */
/* class ContainerTH2 : public Container<TH2>{ */
/*     private: */
/*         void _fill(){ */
/*             if (container == nullptr){ */
/*                 init_TH2(); */
/*             } */
/*             std::pair<T, T> val = value->get_value(); */
/*             container->Fill(val.first, val.second); */
/*         } */

/*     protected: */
/*         std::string title; */
/*         int nbins_x; */
/*         int nbins_y; */
/*         T low_x; */
/*         T low_y; */
/*         T high_x; */
/*         T high_y; */
/*         Value<std::pair<T, T> > *value; */
/*         virtual void init_TH2() = 0; */

/*     public: */
/*         explicit ContainerTH2(const std::string& name, const std::string& title, */
/*                       int nbins_x, double low_x, double high_x, */
/*                       int nbins_y, double low_y, double high_y, */
/*                       GenValue* value) */
/*           :Container<TH2>(name, nullptr), */
/*            nbins_x(nbins_x), low_x(low_x), high_x(high_x), */
/*            nbins_y(nbins_y), low_y(low_y), high_y(high_y), */
/*            value(dynamic_cast<Value<T>*>(value)) { } */

/*         void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) { */
/*             util::_save_as(get_container(), fname, option); */
/*         } */

/*         void save(const SaveOption& option = SaveOption::PNG) { */
/*             save_as(this->get_name(), option); */
/*         } */
/* }; */

/* class ContainerTH2D : public ContainerTH2<double>{ */
/*     using ContainerTH2::ContainerTH2; */
/*     void init_TH2(){ */
/*         this->container = new TH2D(this->get_name().c_str(), title.c_str(), nbins_x, low_x, high_x, nbins_y, low_y, high_y); */
/*     } */
/* }; */

/* class ContainerTH2F : public ContainerTH2<float>{ */
/*     using ContainerTH2::ContainerTH2; */
/*     void init_TH2(){ */
/*         this->container = new TH2F(this->get_name().c_str(), title.c_str(), nbins_x, low_x, high_x, nbins_y, low_y, high_y); */
/*     } */
/* }; */

/* class ContainerTH2I : public ContainerTH2<int>{ */
/*     using ContainerTH2::ContainerTH2; */
/*     void init_TH2(){ */
/*         this->container = new TH2I(this->get_name().c_str(), title.c_str(), nbins_x, low_x, high_x, nbins_y, low_y, high_y); */
/*     } */
/* }; */


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
                container->SetName(get_name().c_str());
                std::cout << "name: " << container->GetName() << std::endl;
                data_modified = false;
            }
            return container;
        }
        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::_save_as(get_container(), fname, option);
        }
};

}
#endif // root_container_hpp
