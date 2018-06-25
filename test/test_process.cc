#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "../src/process.h"

TEST_GROUP(process)
{
};

TEST(process, OldProcessStillAlive)
{
    static const int PID = 123;

    auto throw_error = [](){ throw process::OldProcessStillAlive(PID); };

    int pid = -1;

    try {
        throw_error();
    } catch(process::OldProcessStillAlive& e) {
        pid = e.pid;
    }

    CHECK_EQUAL(pid, PID);
}
