#ifndef log_hpp
#define log_hpp

#include <iostream>
#include <fstream>
#include <cstring>

#define LOG_EMERG   0
#define LOG_ALERT   1
#define LOG_CRIT    2
#define LOG_ERR     3
#define LOG_WARNING 4
#define LOG_NOTICE  5
#define LOG_INFO    6
#define LOG_DEBUG   7
enum LogPriority {
    kLogEmerg   = LOG_EMERG,   // system is unusable
    kLogAlert   = LOG_ALERT,   // action must be taken immediately
    kLogCrit    = LOG_CRIT,    // critical conditions
    kLogErr     = LOG_ERR,     // error conditions
    kLogWarning = LOG_WARNING, // warning conditions
    kLogNotice  = LOG_NOTICE,  // normal, but significant, condition
    kLogInfo    = LOG_INFO,    // informational message
    kLogDebug   = LOG_DEBUG    // debug-level message
};

/**
 * /see http://stackoverflow.com/questions/2638654/redirect-c-stdclog-to-syslog-on-unix
 */
class Log : public std::basic_streambuf<char, std::char_traits<char> > {
private:
    friend std::ostream& operator<< (std::ostream& os, const LogPriority& log_priority){
        static_cast<Log *>(os.rdbuf())->priority_ = (int)log_priority;
        return os;
    }
    std::string buffer_;
    std::ofstream logfile;
    int priority_;
protected:
    int sync(){
        if (buffer_.length()) {
            /* syslog(priority_, buffer_.c_str()); */
            logfile << buffer_ << std::endl;
            buffer_.erase();
            priority_ = LOG_DEBUG; // default to debug for each message
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
    explicit Log(std::string filename)
      :logfile(filename, std::ofstream::out){
        priority_ = LOG_DEBUG;
    }
};

#endif // log_hpp
