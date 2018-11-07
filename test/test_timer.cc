#include "test.h"

TEST(timer, str)
{
    Timer timer("10:30");
    EXPECT_EQ(timer.str(), "1:30");
}
