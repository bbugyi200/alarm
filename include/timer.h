#ifndef INCLUDED_TIMER
#define INCLUDED_TIMER

#include <string>
#include <chrono>

class Timer {
    private:
        std::string time;

    public:
        Timer(std::string time_) : time{time_} { }
        auto get_time_point();
        std::chrono::seconds get_duration();
        void start();
};

#endif /* INCLUDED_TIMER */
