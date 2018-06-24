#include <iostream>
#include "alarm.h"
#include "cli.h"

int main(int argc, char *argv[])
{
    cli::parse_args(argc, argv);
    return 0;
}
