#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <iostream>
#include "cli.h"

namespace po = boost::program_options;

void cli::parse_args(int argc, char **argv) {
    po::options_description desc("Sets alarm");
    desc.add_options()
        ("help", "Produce help message.")
        ("debug", "Enable debug mode.")
        ("verbose", po::value<int>(), "Set verbosity level.");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
    }

    if (vm.count("verbose")) {
        std::cout << "Verbosity level set to " << vm["verbose"].as<int>() << "." << std::endl;
    }
}
