#ifndef argparse_hpp
#define argparse_hpp
#include <algorithm>
#include <string>
#include <vector>
namespace filval::util{
/// \see http://stackoverflow.com/questions/865668/how-to-parse-command-line-arguments-in-c#868894
class ArgParser{
    private:
        std::vector <std::string> tokens;
        std::string empty_string;
    public:
        ArgParser (int &argc, char **argv){
            for (int i=1; i < argc; ++i)
                this->tokens.push_back(std::string(argv[i]));
        }
        /// @author iain
        const std::string& getCmdOption(const std::string &option) const{
            std::vector<std::string>::const_iterator itr;
            itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
            if (itr != this->tokens.end() && ++itr != this->tokens.end()){
                return *itr;
            }
            return empty_string;
        }
        /// @author iain
        bool cmdOptionExists(const std::string &option) const{
            return std::find(this->tokens.begin(), this->tokens.end(), option)
                   != this->tokens.end();
        }
};
}
#endif // argparse_hpp
