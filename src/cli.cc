#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/positional_options.hpp>
#include <iostream>
#include "cli.h"

namespace po = boost::program_options;

/** Parses command-line arguments.
 *  
 * @param argc: The argument count.
 * @param argv: The list of arguments.
 **/
void cli::parse_args(int argc, char **argv) {
    po::options_description desc("Sets alarm");
    desc.add_options()
        ("help", "Produce help message.")
        ("debug", "Enable debug mode.")
        ("resume", "Resume alarm.")
        ("stop", "Stop alarm.")
        ("tomorrow,T", "Set alarm for tomorrow.")
        ("time", "The time to set the alarm for.");

    po::positional_options_description p;
    p.add("time", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
    }

    if (vm.count("time")) {
        std::cout << "Time: " << vm["time"].as<std::string>() << std::endl;
    }
}
