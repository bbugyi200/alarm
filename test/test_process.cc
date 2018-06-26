#include "test.h"

TEST_GROUP(OldProcessStillAlive)
{
};

TEST(OldProcessStillAlive, test_pid)
{
    static const int PID = 123;
    int pid = -1;

    try {
        throw process::OldProcessStillAlive(PID);
    } catch(process::OldProcessStillAlive& e) {
        pid = e.pid;
    }

    CHECK_EQUAL(pid, PID);
}

static const char *pid_fname = "/run/user/1000/countdown/pid";

TEST_GROUP(create_pid)
{
    void setup() {
        std::ifstream ifile(pid_fname);
        if (ifile.good()) {
            std::remove(pid_fname);
        }
    }
};

TEST(create_pid, test_file_creation)
{
    process::create_pid();
    std::ifstream ifile(pid_fname);
    CHECK_TRUE(ifile.good());
}

TEST(create_pid, test_pid)
{
    process::create_pid();
    int expected_pid = getpid();
    std::ifstream ifile(pid_fname);
    int actual_pid;
    ifile >> actual_pid;

    CHECK_EQUAL(expected_pid, actual_pid);
}
