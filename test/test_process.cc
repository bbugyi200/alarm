#include "test.h"

TEST(OldProcessStillAlive, test_pid)
{
    static const int PID = 123;
    int pid = -1;

    try {
        throw process::OldProcessStillAlive(PID);
    } catch(process::OldProcessStillAlive& e) {
        pid = e.pid;
    }

    EXPECT_EQ(pid, PID);
}

static const char *pid_fname = "/run/user/1000/countdown/pid";

class create_pid : public ::testing::Test {
    protected:
        virtual void SetUp () {
            std::ifstream ifile(pid_fname);
            if (ifile.good()) {
                std::remove(pid_fname);
            }
        }
};

TEST_F(create_pid, test_file_creation)
{
    process::create_pid();
    std::ifstream ifile(pid_fname);
    EXPECT_TRUE(ifile.good());
}

TEST_F(create_pid, test_pid)
{
    process::create_pid();
    int expected_pid = getpid();
    std::ifstream ifile(pid_fname);
    int actual_pid;
    ifile >> actual_pid;

    EXPECT_EQ(expected_pid, actual_pid);
}
