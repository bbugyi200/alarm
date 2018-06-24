#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <string.h>
#include "../src/cli.h"

TEST_GROUP(cli)
{
};

TEST(cli, 1)
{
    char *args[1];
    args[0] = new char[10];

    strcpy(args[0], "--help");
    cli::parse_args(1, args);

    delete args[0];
}
