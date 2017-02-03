#ifndef log_hpp
#define log_hpp

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

namespace filval::util{
enum LogPriority {
    kLogEmergency = 7,   // system is unusable
    kLogAlert     = 6,   // action must be taken immediately
    kLogCritical  = 5,    // critical conditions
    kLogError     = 4,     // error conditions
    kLogWarning   = 3, // warning conditions
    kLogNotice    = 2,  // normal, but significant, condition
    kLogInfo      = 1,    // informational message
    kLogDebug     = 0    // debug-level message
};

#define CRITICAL(x,y) std::clog << filval::util::LogPriority::kLogCritical << __FILE__ << "@L" << __LINE__ << " :: " << x << std::flush; exit(y)
#define ERROR(x) std::clog << filval::util::LogPriority::kLogError << __FILE__ << "@L" << __LINE__ << " :: " << x << std::flush
#define WARNING(x) std::clog << filval::util::LogPriority::kLogWarning << x << std::flush
#define INFO(x) std::clog << filval::util::LogPriority::kLogInfo << x << std::flush
#define DEBUG(x) std::clog << filval::util::LogPriority::kLogDebug << __FILE__ << "@L" << __LINE__ << " :: " << x << std::flush

/**
 * /see http://stackoverflow.com/questions/2638654/redirect-c-stdclog-to-syslog-on-unix
 */
std::ostream& operator<< (std::ostream& os, const LogPriority& log_priority);

class Log : public std::basic_streambuf<char, std::char_traits<char> > {
private:
    std::string buffer_;
    std::ofstream logfile;
    LogPriority priority_curr;
    LogPriority priority_set;
    std::map<LogPriority,std::string> name_map = {{kLogEmergency, "EMERGENCY"},
                                                  {kLogAlert,     "ALERT"},
                                                  {kLogCritical,  "CRITICAL"},
                                                  {kLogError,     "ERROR"},
                                                  {kLogWarning,   "WARNING"},
                                                  {kLogNotice,    "NOTICE"},
                                                  {kLogInfo,      "INFO"},
                                                  {kLogDebug,     "DEBUG"}};

    friend std::ostream& operator<< (std::ostream& os, const LogPriority& log_priority){
        static_cast<Log *>(os.rdbuf())->priority_curr = log_priority;
        return os;
    }
protected:
    int sync(){
        if (buffer_.length()) {
            if (priority_curr >= priority_set){
                logfile << name_map[priority_curr] << ": " <<  buffer_ << std::endl << std::flush;
            }
            buffer_.erase();
            /* priority_curr = kLogDebug; // default to debug for each message */
        }
        return 0;
    }
    int overflow(int c){
        if (c != EOF) {
            buffer_ += static_cast<char>(c);
        } else {
            sync();
        }
        return c;
    }
public:
    explicit Log(std::string filename, LogPriority priority)
      :logfile(filename, std::ofstream::out){
        priority_set = priority;
        priority_curr = kLogDebug;
    }
};
}
#endif // log_hpp
