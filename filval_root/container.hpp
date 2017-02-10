#ifndef root_container_hpp
#define root_container_hpp
#include <iostream>
#include <utility>
#include <map>

#include "TROOT.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TH1.h"
#include "TH2.h"

#include "filval.hpp"

namespace fv::root::util{

/**
 * Save a TObject. The TObject will typically be a Histogram or Graph object,
 * but can really be any TObject. The SaveOption can be used to specify how to
 * save the file.
 */
void save_as(TObject* container, const std::string& fname, const SaveOption& option = SaveOption::PNG) {

    auto save_img = [](TObject* container, const std::string& fname){
        TCanvas* c1 = new TCanvas("c1");
        container->Draw();
        c1->Draw();
        c1->SaveAs(fname.c_str());
        delete c1;
    };

    auto save_bin = [](TObject* container){
        INFO("Saving object: " << container->GetName() << " into file " << gDirectory->GetName());
        container->Write(container->GetName(), TObject::kOverwrite);
    };

    switch(option){
        case PNG:
            save_img(container, fname+".png"); break;
        case PDF:
            save_img(container, fname+".pdf"); break;
        case ROOT:
            save_bin(container); break;
        default:
            break;
    }
}


/**
 * Saves an STL container into a ROOT file. ROOT knows how to serialize STL
 * containers, but it needs the *name* of the type of the container, eg.
 * std::map<int,int> to be able to do this. In order to generate this name at
 * run-time, the fv::util::get_type_name function uses RTTI to get type info
 * and use it to look up the proper name.
 */
void save_as_stl(void* container, const std::string& type_name,
                  const std::string& obj_name,
                  const SaveOption& option = SaveOption::PNG) {
    switch(option){
        case PNG:
            INFO("Cannot save STL container " << type_name <<" as png");
            break;
        case PDF:
            INFO("Cannot save STL container " << type_name <<" as pdf");
            break;
        case ROOT:
            gDirectory->WriteObjectAny(container, type_name.c_str(), obj_name.c_str());
            break;
        default:
            break;
    }
}
}

namespace fv::root {

template <typename V>
class _ContainerTH1 : public Container<TH1>{
    private:
        void _fill(){
            if (container == nullptr){
                if (value == nullptr){
                    CRITICAL("Container: \"" << get_name() << "\" has a null Value object. "
                             << "Probably built with imcompatible type",-1);
                }
                this->container = new TH1D(this->get_name().c_str(), this->title.c_str(),
                                           this->nbins, this->low, this->high);
            }
            _do_fill();
        }

    protected:
        std::string title;
        int nbins;
        double low;
        double high;
        Value<V> *value;

        virtual void _do_fill() = 0;

    public:
        explicit _ContainerTH1(const std::string &name, const std::string& title, GenValue *value,
                               int nbins, double low, double high)
          :Container<TH1>(name, nullptr),
           title(title), nbins(nbins), low(low), high(high),
           value(dynamic_cast<Value<V>*>(value)) { }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::save_as(get_container(), fname, option);
        }
};

template <typename V>
class ContainerTH1 : public _ContainerTH1<V>{
    using _ContainerTH1<V>::_ContainerTH1;
    void _do_fill(){
        this->container->Fill(this->value->get_value());
    }
};

template <typename V>
class ContainerTH1Many : public _ContainerTH1<std::vector<V>>{
    using _ContainerTH1<std::vector<V>>::_ContainerTH1;
    void _do_fill(){
        for(V x : this->value->get_value())
            this->container->Fill(x);
    }
};



template <typename V>
class _ContainerTH2 : public Container<TH2>{
    private:
        void _fill(){
            if (container == nullptr){
                if (value == nullptr){
                    CRITICAL("Container: \"" << get_name() << "\" has a null Value object. "
                             << "Probably built with imcompatible type",-1);
                }
                this->container = new TH2D(this->get_name().c_str(), this->title.c_str(),
                                           this->nbins_x, this->low_x, this->high_x,
                                           this->nbins_y, this->low_y, this->high_y);
            }
            _do_fill(value->get_value());
        }

    protected:
        std::string title;
        int nbins_x;
        int nbins_y;
        double low_x;
        double low_y;
        double high_x;
        double high_y;
        Value<std::pair<V,V>> *value;

        virtual void _do_fill(std::pair<V,V>& val) = 0;

    public:
        explicit _ContainerTH2(const std::string& name, const std::string& title,
                               GenValue* value,
                               int nbins_x, double low_x, double high_x,
                               int nbins_y, double low_y, double high_y)
          :Container<TH2>(name, nullptr),
           nbins_x(nbins_x), low_x(low_x), high_x(high_x),
           nbins_y(nbins_y), low_y(low_y), high_y(high_y),
           value(dynamic_cast<Value<std::pair<V, V>>*>(value)) { }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::save_as(get_container(), fname, option);
        }
};

template <typename V>
class ContainerTH2 : public _ContainerTH2<std::vector<V>>{
    using _ContainerTH2<std::vector<V>>::_ContainerTH2;
    void _do_fill(std::pair<V,V>& val){
        this->container->Fill(val.first,val.second);
    }
};

template <typename V>
class ContainerTH2Many : public _ContainerTH2<std::vector<V>>{
    using _ContainerTH2<std::vector<V>>::_ContainerTH2;
    void _do_fill(std::pair<std::vector<V>,std::vector<V>>& val){
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
        std::string title;
        bool data_modified;
        void _fill(){
            auto val = value->get_value();
            x_data.push_back(val.first);
            y_data.push_back(val.second);
            data_modified = true;
        }
    public:
        ContainerTGraph(const std::string& name, const std::string& title, GenValue* value)
          :Container<TGraph>(name, new TGraph()),
           value(dynamic_cast<Value<std::pair<int, int> >*>(value)),
           data_modified(false){ }

        TGraph* get_container(){
            if (data_modified){
                delete container;
                container = new TGraph(x_data.size(), x_data.data(), y_data.data());
                container->SetName(get_name().c_str());
                container->SetTitle(title.c_str());
                data_modified = false;
            }
            return container;
        }
        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::save_as(get_container(), fname, option);
        }
};


template <typename V, typename D>
class _Counter : public Container<std::map<D,int>>{
    protected:
        Value<V>* value;
    public:
        explicit _Counter(const std::string& name, GenValue* value)
          :Container<std::map<D,int>>(name, new std::map<D,int>()),
           value(dynamic_cast<Value<V>*>(value)) { }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            std::string type_name = "std::map<"+fv::util::get_type_name(typeid(D))+",int>";
            util::save_as_stl(this->get_container(), type_name, this->get_name(), option);
        }

};

/**
 * A Counter that keeps a mapping of the number of occurances of each input
 * value.
 */
template <typename V>
class Counter : public _Counter<V,V>{
    using _Counter<V,V>::_Counter;
        void _fill(){
            (*this->container)[this->value->get_value()]++;
        }
};

/**
 * Same as Counter but accepts multiple values per fill.
 */
template <typename V>
class CounterMany : public _Counter<std::vector<V>,V>{
    using _Counter<std::vector<V>,V>::_Counter;
        void _fill(){
            for(V& val : this->value->get_value())
                (*this->container)[val]++;
        }
};
}
#endif // root_container_hpp
