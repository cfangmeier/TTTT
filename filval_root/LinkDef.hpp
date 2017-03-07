#ifndef linkdev_hpp
#define linkdev_hpp
#include <vector>
#include <string>
#include <map>

#ifdef __CLING__
#pragma link C++ class std::vector<std::vector<int>>+;
#pragma link C++ class std::vector<std::vector<unsigned int>>+;
#pragma link C++ class std::vector<std::vector<float>>+;
#pragma link C++ class std::map<std::string,std::string>+;
#endif

#endif // linkdev_hpp
