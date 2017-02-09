#ifndef root_container_hpp
#define root_container_hpp
#include <utility>
#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TROOT.h"

#include "filval.hpp"

namespace fv::root::util{
void _save_img(TObject* container, const std::string& fname){
    TCanvas* c1 = new TCanvas("c1");
    container->Draw();
    c1->Draw();
    c1->SaveAs(fname.c_str());
    delete c1;
}

void _save_bin(TObject* container){
    INFO("Saving object: " << container->GetName() << " into file " << gDirectory->GetName());
    /* TFile* f = TFile::Open(fname.c_str(), "UPDATE"); */
    container->Write(container->GetName(), TObject::kOverwrite);
    /* f->Close(); */
}

void _save_as(TObject* container, const std::string& fname, const SaveOption& option = SaveOption::PNG) {
    switch(option){
        case PNG:
            _save_img(container, fname+".png"); break;
        case PDF:
            _save_img(container, fname+".pdf"); break;
        case ROOT:
            _save_bin(container); break;
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
                if (value == nullptr){
                    CRITICAL("Container: \"" << get_name() << "\" has a null Value object. "
                             << "Probably built with imcompatible type",-1);
                }
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


template <typename V, typename D>
class ContainerTH2 : public Container<TH2>{
    private:
        void _fill(){
            if (container == nullptr){
                if (value == nullptr){
                    CRITICAL("Container: \"" << get_name() << "\" has a null Value object. "
                             << "Probably built with imcompatible type",-1);
                }
                init_TH2();
            }
            _do_fill(value->get_value());
        }

    protected:
        std::string title;
        int nbins_x;
        int nbins_y;
        D low_x;
        D low_y;
        D high_x;
        D high_y;
        Value<std::pair<V,V>> *value;
        virtual void init_TH2() = 0;
        virtual void _do_fill(std::pair<V,V>& val) = 0;

    public:
        explicit ContainerTH2(const std::string& name, const std::string& title,
                              GenValue* value,
                              int nbins_x, D low_x, D high_x,
                              int nbins_y, D low_y, D high_y)
          :Container<TH2>(name, nullptr),
           nbins_x(nbins_x), low_x(low_x), high_x(high_x),
           nbins_y(nbins_y), low_y(low_y), high_y(high_y),
           value(dynamic_cast<Value<std::pair<V, V>>*>(value)) { }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::_save_as(get_container(), fname, option);
        }
};

template <typename V>
class _ContainerTH2D : public ContainerTH2<V, double>{
    using ContainerTH2<V, double>::ContainerTH2;
    void init_TH2(){
        this->container = new TH2D(this->get_name().c_str(), this->title.c_str(),
                                   this->nbins_x, this->low_x, this->high_x,
                                   this->nbins_y, this->low_y, this->high_y);
    }
};

class ContainerTH2D : public _ContainerTH2D<double>{
    using _ContainerTH2D<double>::_ContainerTH2D;
    void _do_fill(std::pair<double,double>& val){
        this->container->Fill(val.first, val.second);
    }
};

class ContainerTH2DMany : public _ContainerTH2D<std::vector<double>>{
    using _ContainerTH2D<std::vector<double>>::_ContainerTH2D;
    void _do_fill(std::pair<std::vector<double>,std::vector<double>>& val){
        int min_size = std::min(val.first.size(), val.second.size());
        for(int i=0; i<min_size; i++)
            this->container->Fill(val.first[i],val.second[i]);
    }
};

template <typename V>
class _ContainerTH2F : public ContainerTH2<V, float>{
    using ContainerTH2<V, float>::ContainerTH2;
    void init_TH2(){
        this->container = new TH2F(this->get_name().c_str(), this->title.c_str(),
                                   this->nbins_x, this->low_x, this->high_x,
                                   this->nbins_y, this->low_y, this->high_y);
    }
};

class ContainerTH2F : public _ContainerTH2F<float>{
    using _ContainerTH2F<float>::_ContainerTH2F;
    void _do_fill(std::pair<float,float>& val){
        this->container->Fill(val.first, val.second);
    }
};

class ContainerTH2FMany : public _ContainerTH2F<std::vector<float>>{
    using _ContainerTH2F<std::vector<float>>::_ContainerTH2F;
    void _do_fill(std::pair<std::vector<float>,std::vector<float>>& val){
        int min_size = std::min(val.first.size(), val.second.size());
        for(int i=0; i<min_size; i++)
            this->container->Fill(val.first[i],val.second[i]);
    }
};

template <typename V>
class _ContainerTH2I : public ContainerTH2<V, int>{
    using ContainerTH2<V, int>::ContainerTH2;
    void init_TH2(){
        this->container = new TH2I(this->get_name().c_str(), this->title.c_str(),
                                   this->nbins_x, this->low_x, this->high_x,
                                   this->nbins_y, this->low_y, this->high_y);
    }
};

class ContainerTH2I : public _ContainerTH2I<int>{
    using _ContainerTH2I<int>::_ContainerTH2I;
    void _do_fill(std::pair<int,int>& val){
        this->container->Fill(val.first, val.second);
    }
};

class ContainerTH2IMany : public _ContainerTH2I<std::vector<int>>{
    using _ContainerTH2I<std::vector<int>>::_ContainerTH2I;
    void _do_fill(std::pair<std::vector<int>,std::vector<int>>& val){
        int min_size = std::min(val.first.size(), val.second.size());
        for(int i=0; i<min_size; i++)
            this->container->Fill(val.first[i],val.second[i]);
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
                container->SetName(get_name().c_str());
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
