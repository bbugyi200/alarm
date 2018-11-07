#ifndef INCLUDED_TIMER
#define INCLUDED_TIMER

#include <string>
#include <chrono>

class Timer {
    private:
        std::string time;

        std::chrono::seconds get_duration();

    public:
        Timer(std::string time_) : time{time_} { }
        std::string str();
};

#endif /* INCLUDED_TIMER */
