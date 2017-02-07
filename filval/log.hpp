/**
 * @file
 * @author  Caleb Fangmeier <caleb@fangmeier.tech>
 * @version 0.1
 *
 * @section LICENSE
 *
 *
 * MIT License
 *
 * Copyright (c) 2017 Caleb Fangmeier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @section DESCRIPTION
 */
#ifndef log_hpp
#define log_hpp

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

namespace fv::util{
enum LogPriority {
    kLogEmergency = 7,  // system is unusable
    kLogAlert     = 6,  // action must be taken immediately
    kLogCritical  = 5,  // critical conditions
    kLogError     = 4,  // error conditions
    kLogWarning   = 3,  // warning conditions
    kLogNotice    = 2,  // normal, but significant, condition
    kLogInfo      = 1,  // informational message
    kLogDebug     = 0   // debug-level message
};

#define CRITICAL(x,y) std::clog << fv::util::LogPriority::kLogCritical << __FILE__ << "@L" << __LINE__ << " :: " << x << std::flush; std::cout << "Errors encountered! See log file for details."<<std::endl;exit(y)
#define ERROR(x) std::clog << fv::util::LogPriority::kLogError << __FILE__ << "@L" << __LINE__ << " :: " << x << std::flush
#define WARNING(x) std::clog << fv::util::LogPriority::kLogWarning << x << std::flush
#define INFO(x) std::clog << fv::util::LogPriority::kLogInfo << x << std::flush
#define DEBUG(x) std::clog << fv::util::LogPriority::kLogDebug << __FILE__ << "@L" << __LINE__ << " :: " << x << std::flush

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
    inline static Log* singleton = nullptr;
    const std::map<LogPriority,std::string> name_map = {{kLogEmergency, "EMERGENCY"},
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
                logfile << name_map.at(priority_curr) << ": " <<  buffer_ << std::endl << std::flush;
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

    static Log& init_logger(std::string filename, LogPriority priority){
        if (singleton == nullptr){
            singleton = new Log(filename, priority);
            std::cout << "Writing log data to " << filename << std::endl;
            std::clog.rdbuf(singleton);
        }
        return *singleton;
    }
};
}
#endif // log_hpp
