#ifndef linkdev_hpp
#define linkdev_hpp
#include <vector>

#ifdef __CLING__
#pragma link C++ class std::vector<std::vector<int>>+;
#pragma link C++ class std::vector<std::vector<unsigned int>>+;
#pragma link C++ class std::vector<std::vector<float>>+;
#endif

#endif // linkdev_hpp
