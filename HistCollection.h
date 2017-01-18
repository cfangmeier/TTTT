#ifndef histcollection_h
#define histcollection_h

#include <string>
#include <sstream>
#include <map>

#include <TH1.h>
#include <TH2.h>



class HistCollection{
  private:
    map<std::string, TH1*> histograms;
    std::string prefix;
    
    TH1D* book_histogram_1d(const std::string &id, const std::string &title,
                            int nbins, double min, double max){
        const char* full_id = (prefix+id).c_str();
        TH1D *hist = new TH1D(full_id, title.c_str(), nbins, min, max);
        histograms[id] = hist;
        return hist;
    };

    TH2D* book_histogram_2d(const std::string id, const std::string title,
                            int nbins_x, double min_x, double max_x,
                            int nbins_y, double min_y, double max_y){
        const char* full_id = (prefix+id).c_str();
        TH2D *hist = new TH2D(full_id, title.c_str(), nbins_x, min_x, max_x, nbins_y, min_y, max_y);
        histograms[id] = hist;
        return hist;
    };
  public:
    /* List of included histogram objects
    */
    TH1D *lepton_count;
    TH1D *delta_pt;
    TH2D *lepton_count_vs_delta_pt;
    
    
    HistCollection(const std::string &filename)
      : prefix(filename.substr(0, filename.size()-5))
    {
//        this->prefix = prefix.substr(0, prefix.size()-5);
        lepton_count = book_histogram_1d("lepton_count", "Good Lepton Count", 10, 0, 10);
        delta_pt = book_histogram_1d("delta_pt", "{\\\\Delta P_T}", 100, -50, 50);
        lepton_count_vs_delta_pt = book_histogram_2d("lepton_count_vs_delta_pt", "Good Lepton Count Vs {\\\\delta P_T}",
                                                     10, 0, 10,
                                                     100, -50, 50);
    };
    
    HistCollection(): HistCollection("") {};
    
    ~HistCollection(){
        for(auto& p: histograms)
            delete p.second;
    };
    
    vector<std::string> get_ids(){
        vector<std::string> vec;
        for(auto& p: histograms)
            vec.push_back(p.first);
        return vec;
    }
    TH1* get_by_id(const std::string &id){
        TH1* hist = histograms[id];
        return hist;
    }
};


#endif // histcollection_h