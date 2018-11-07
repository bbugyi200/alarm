#include <iostream>
#include <sstream>

#include <timer.h>

std::chrono::seconds Timer::get_duration() {
    return std::chrono::seconds(90);
}

std::string Timer::str() {
    auto secs = this->get_duration();
    int minutes = secs.count() / 60;
    int seconds = secs.count() % 60;

    std::stringstream m;
    std::stringstream s;

    m << minutes;
    s << seconds;

    std::string time = m.str();
    time += ":";
    time += s.str();

    return time;
}
