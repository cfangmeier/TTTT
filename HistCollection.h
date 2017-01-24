#ifndef histcollection_h
#define histcollection_h

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <cmath>

#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>

#define PI 3.14159
#define PDG_ELECTRON = 11
#define PDG_MUON = 13

struct HistWithPlottingInfo{
    TH1* hist;
    std::string draw_string;

    HistWithPlottingInfo()
      :hist(0),draw_string(""){};
    HistWithPlottingInfo(TH1* hist, std::string draw_string)
      :hist(hist),draw_string(draw_string){};
};


class HistCollection{
  private:
    map<std::string, HistWithPlottingInfo> histograms;
    std::string sample_name;

    std::string hist_id(const std::string &id){
        return sample_name+"_"+id;
    }

    TH1D* book_histogram_1d(const std::string &id, const std::string &title,
                            int nbins, double min, double max,
                            const std::string draw_string = ""){
        std::string full_id = hist_id(id);
        TH1D *hist = new TH1D(full_id.c_str(), title.c_str(), nbins, min, max);
        histograms[id] = HistWithPlottingInfo(hist, draw_string);
        return hist;
    };

    TH2D* book_histogram_2d(const std::string id, const std::string title,
                            int nbins_x, double min_x, double max_x,
                            int nbins_y, double min_y, double max_y){
        std::string full_id = hist_id(id);
        TH2D *hist = new TH2D(full_id.c_str(), title.c_str(), nbins_x, min_x, max_x, nbins_y, min_y, max_y);
        histograms[id] = HistWithPlottingInfo(hist, "COLZ");
        return hist;
    };
  public:
    // List of included histogram objects
    TH1D *lepton_count;
    TH1D *lepton_count_pass_miniiso;
    TH1D *delta_pt;
    TH2D *lepton_count_vs_delta_pt;
    TH1D *top_quark_count;

    TH1D *jet_count_trilepton;
    TH1D *jet_count_ss_dilepton;
    TH1D *jet_count_os_dilepton;
    TH1D *jet_count;

    TH1D *b_jet_discriminator;
    TH1D *b_jet_count;
    TH1D *b_jet_pt_all;
    TH1D *b_jet_pt_3_or_more;

    TH1D *trilepton_iso_1;
    TH1D *trilepton_iso_2;
    TH1D *trilepton_iso_3;

    HistCollection(const std::string &sample_name)
      : sample_name(sample_name)
    {
        // ---------------------------------------------
        lepton_count = book_histogram_1d("lepton_count", "Lepton Multiplicity",
                                         8, 0, 8);
        // ---------------------------------------------
        lepton_count_pass_miniiso = book_histogram_1d("lepton_count_pass_miniiso",
                                                      "Number of Leptons passing mini-isolation",
                                                      8, 0, 8);
        // ---------------------------------------------
        delta_pt = book_histogram_1d("delta_pt", "{\\Delta P_T}",
                                     100, -50, 50);
        // ---------------------------------------------
        lepton_count_vs_delta_pt = book_histogram_2d("lepton_count_vs_delta_pt",
                                                     "Good Lepton Count Vs {\\Delta P_T}",
                                                     10, 0, 10, 100, -50, 50);
        // ---------------------------------------------
        top_quark_count = book_histogram_1d("top_quark_count", "Top Quark Multiplicity",
                                            4, 0, 4);
        // ---------------------------------------------
        jet_count_trilepton = book_histogram_1d("jet_count_trilepton",
                                                "Jet Multiplicity - Trilepton",
                                                13, 0, 13);
        jet_count_ss_dilepton = book_histogram_1d("jet_count_ss_dilepton",
                                                  "Jet Multiplicity - Same-Sign Dilepton",
                                                  13, 0, 13);
        jet_count_os_dilepton = book_histogram_1d("jet_count_os_dilepton",
                                                  "Jet Multiplicity - Opposite-Sign Dilepton",
                                                  13, 0, 13);
        // ---------------------------------------------
        jet_count = book_histogram_1d("jet_count", "Jet Multiplicity",
                                      13, 0, 13);
        // ---------------------------------------------
        b_jet_discriminator = book_histogram_1d("b_jet_discriminator", "B-Jet Discriminator",
                                                40, -1, 1);
        // ---------------------------------------------
        b_jet_count = book_histogram_1d("b_jet_count", "B-Jet Multiplicity",
                                        10, 0, 10);
        // ---------------------------------------------
        b_jet_pt_all = book_histogram_1d("b_jet_pt_all", "B-Jet {P_T} - All",
                                         50, 0, 2000);
        // ---------------------------------------------
        b_jet_pt_3_or_more = book_histogram_1d("b_jet_pt_3_or_more", "B-Jet  {P_T} - 3 or more",
                                        50, 0, 2000);
        // ---------------------------------------------
        trilepton_iso_1 = book_histogram_1d("trilepton_iso_1", "Trilepton Isolation - First",
                                            50, 0, 2*PI);
        // ---------------------------------------------
        trilepton_iso_2 = book_histogram_1d("trilepton_iso_2", "Trilepton Isolation - Second",
                                            50, 0, 2*PI);
        // ---------------------------------------------
        trilepton_iso_3 = book_histogram_1d("trilepton_iso_3", "Trilepton Isolation - Third",
                                            50, 0, 2*PI);
        // ---------------------------------------------
    }

    HistCollection(): HistCollection("") {};

    ~HistCollection(){
        for(auto& p: histograms)
            delete p.second.hist;
    }

    void draw(TCanvas* canvas,
              std::pair<int, int> shape = {0,0}){
        std::pair<int, int> null_shape(0,0);
        if (shape == null_shape){
            int n = (int)ceil(sqrt(histograms.size()));
            shape.first = n;
            shape.second = n;
        }
        canvas->Clear();
        canvas->Divide(shape.first, shape.second);
        int i = 1;
        for(auto& p: histograms){
            canvas->cd(i++);
            p.second.hist->SetStats(false);
            p.second.hist->Draw(p.second.draw_string.c_str());
        }
    }

    std::string get_sample_name(){
        return sample_name;
    }

    vector<std::string> get_ids(){
        vector<std::string> vec;
        for(auto& p: histograms)
            vec.push_back(p.first);
        return vec;
    }

    TH1* get_by_id(const std::string &id){
        TH1* hist = histograms[id].hist;
        return hist;
    }
};


#endif // histcollection_h
