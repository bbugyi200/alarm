#include <iostream>
#include <boost/program_options/options_description.hpp>
#include "alarm.h"
#include "cli.h"

namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    cli::parse_args(argc, argv);
    return 0;
}
