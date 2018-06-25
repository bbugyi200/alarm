#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <string.h>
#include "../src/cli.h"

TEST_GROUP(cli)
{
};

TEST(cli, parse_args)
{
    static const int ARG_COUNT = 2;
    static const char* TIME = "18:35";
    char *argv[ARG_COUNT+1];
    for (int i = 1; i < ARG_COUNT+1; ++i) {
        argv[i] = new char[10];
    }

    strcpy(argv[1], "--debug");
    strcpy(argv[2], TIME);
    auto args = cli::parse_args(ARG_COUNT+1, argv);
    CHECK_TRUE(args->debug);
    CHECK_EQUAL(args->time, TIME);

    for (int i = 1; i < ARG_COUNT+1; ++i) {
        delete argv[i];
    }
}
