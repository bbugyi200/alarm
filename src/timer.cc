#include <iostream>
#include <timer.h>

auto Timer::get_time_point() {
    auto now = std::chrono::steady_clock::now();
    return now;
}

std::chrono::seconds Timer::get_duration() {
    return std::chrono::seconds(90);
}

void Timer::start() {
    auto duration_seconds = this->get_duration();
    int minutes = duration_seconds.count() / 60;
    int seconds = duration_seconds.count() % 60;
    std::cout << "Minutes: " << minutes << "\nSeconds: " << seconds << std::endl;
}
