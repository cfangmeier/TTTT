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

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"

#include "filval/container.hpp"

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
     *
     * For nexted containers, it is necessary to generate the CLING dictionaries
     * for each type at compile time to enable serialization. To do this, add the
     * type definition into the LinkDef.hpp header file.
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
class _ContainerTH1 : public Container<TH1,V>{
    private:
        void _fill(){
            if (this->container == nullptr){
                if (this->value == nullptr){
                    CRITICAL("Container: \"" << this->get_name() << "\" has a null Value object. "
                             << "Probably built with imcompatible type",-1);
                }
                this->container = new TH1D(this->get_name().c_str(), this->title.c_str(),
                                           this->nbins, this->low, this->high);
                this->container->SetXTitle(label_x.c_str());
                this->container->SetYTitle(label_y.c_str());
            }
            _do_fill();
        }

    protected:
        std::string title;
        std::string label_x;
        std::string label_y;
        int nbins;
        double low;
        double high;

        virtual void _do_fill() = 0;

    public:
        explicit _ContainerTH1(const std::string &name, const std::string& title, Value<V>* value,
                               int nbins, double low, double high,
                               const std::string& label_x = "",
                               const std::string& label_y = "")
          :Container<TH1,V>(name, value),
           title(title), nbins(nbins), low(low), high(high),
           label_x(label_x), label_y(label_y) { }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::save_as(this->get_container(), fname, option);
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
class _ContainerTH2 : public Container<TH2,std::pair<V,V>>{
    private:
        void _fill(){
            if (this->container == nullptr){
                if (this->value == nullptr){
                    CRITICAL("Container: \"" << this->get_name() << "\" has a null Value object. "
                             << "Probably built with imcompatible type",-1);
                }
                this->container = new TH2D(this->get_name().c_str(), this->title.c_str(),
                                           this->nbins_x, this->low_x, this->high_x,
                                           this->nbins_y, this->low_y, this->high_y);
                this->container->SetXTitle(label_x.c_str());
                this->container->SetYTitle(label_y.c_str());
            }
            _do_fill(this->value->get_value());
        }

    protected:
        std::string title;
        std::string label_x;
        std::string label_y;
        int nbins_x;
        int nbins_y;
        double low_x;
        double low_y;
        double high_x;
        double high_y;

        virtual void _do_fill(std::pair<V,V>& val) = 0;

    public:
        explicit _ContainerTH2(const std::string& name, const std::string& title,
                               Value<std::pair<V, V>>* value,
                               int nbins_x, double low_x, double high_x,
                               int nbins_y, double low_y, double high_y,
                               const std::string& label_x = "",
                               const std::string& label_y = "")
          :Container<TH2,std::pair<V,V>>(name, value),
           title(title),
           nbins_x(nbins_x), low_x(low_x), high_x(high_x),
           nbins_y(nbins_y), low_y(low_y), high_y(high_y),
           label_x(label_x), label_y(label_y) { }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::save_as(this->get_container(), fname, option);
        }
};

template <typename V>
class ContainerTH2 : public _ContainerTH2<V>{
    using _ContainerTH2<V>::_ContainerTH2;
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

template <typename V>
class ContainerTGraph : public Container<TGraph,std::pair<V,V>>{
    private:
        std::vector<V> x_data;
        std::vector<V> y_data;
        std::string title;
        bool data_modified;
        void _fill(){
            auto val = this->value->get_value();
            x_data.push_back(val.first);
            y_data.push_back(val.second);
            data_modified = true;
        }
    public:
        ContainerTGraph(const std::string& name, const std::string& title, Value<std::pair<V, V>>* value)
          :Container<TGraph,std::pair<V,V>>(name, value),
           data_modified(false){
            this->container = new TGraph();
           }

        TGraph* get_container(){
            if (data_modified){
                delete this->container;
                this->container = new TGraph(x_data.size(), x_data.data(), y_data.data());
                this->container->SetName(this->get_name().c_str());
                this->container->SetTitle(title.c_str());
                data_modified = false;
            }
            return this->container;
        }
        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            util::save_as(get_container(), fname, option);
        }
};

template <typename T>
class Vector : public Container<std::vector<T>,T>{
    private:

        void _fill(){
            this->container->push_back(this->value->get_value());
        }
    public:
        Vector(const std::string& name, Value<T>* value)
          :Container<std::vector<T>,T>(name, value){
            this->container = new std::vector<T>;
        }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            std::string type_name = "std::vector<"+fv::util::get_type_name(typeid(T))+">";
            util::save_as_stl(this->get_container(), type_name, this->get_name(), option);
        }
};

template <typename V, typename D>
class _Counter : public Container<std::map<D,int>,V>{
    public:
        explicit _Counter(const std::string& name, Value<V>* value)
          :Container<std::map<D,int>,V>(name, value) {
            this->container = new std::map<D,int>;
        }

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

// TMVA::DataLoader *dataloader=new TMVA::DataLoader("dataset");

template <typename... ArgTypes>
class MVA : public Container<TMVA::DataLoader,std::tuple<ArgTypes...>>{
    private:

        void _fill(){
            this->container->push_back(this->value->get_value());
            std::vector<double>& v = t2v<double>(this->value->get_value());
            this->container->AddSignalTrainingEvent(v, 1);
            //TODO: Make custom Value type that includes explicit truth info as
            //well as weights and ablity to specify testing/training dataset.
        }
    public:
        MVA(const std::string& name, Value<std::tuple<ArgTypes...>>* value, const std::vector<std::string>& labels=std::vector<std::string>())
          :Container<TMVA::DataLoader,std::tuple<ArgTypes...>(name, value){
            this->container = new DataLoader(name);
            if (labels.size() != sizeof...(ArgTypes)){
                CRITICAL("Length of labels vector ("<<labels.size()<<") not equal to number of MVA arguments ("<<sizeof...(ArgTypes)<<")",-1)
            }
            for(std::string& label : labels){
                this->container->AddVariable(label, 'F');
            }
        }

        void save_as(const std::string& fname, const SaveOption& option = SaveOption::PNG) {
            std::string type_name = "std::vector<"+fv::util::get_type_name(typeid(T))+">";
            util::save_as_stl(this->get_container(), type_name, this->get_name(), option);
        }
};
}
#endif // root_container_hpp
