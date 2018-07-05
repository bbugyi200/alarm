#include "test.h"

TEST(timer, start)
{
    Timer timer();
    auto now = std::chrono::steady_clock::now();
    std::chrono::seconds expected{600};
    auto then = now + expected;
}
