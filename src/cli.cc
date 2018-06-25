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
cli::Arguments* cli::parse_args(int argc, char **argv) {
    po::options_description visible("Named options");
    visible.add_options()
        ("help", "Produce help message.")
        ("debug", "Enable debug mode.")
        ("resume", "Resume alarm.")
        ("stop", "Stop alarm.")
        ("tomorrow,T", "Set alarm for tomorrow.");

    po::options_description hidden("Hidden options");
    hidden.add_options()
        ("time", "The time to set the alarm for.");

    po::options_description all("All options");
    all.add(visible).add(hidden);

    po::positional_options_description p;
    p.add("time", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(all).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << visible << std::endl;
    }

    cli::Arguments *args = new Arguments;

    auto flag_is_set = [vm](std::string flag) { return (vm.count(flag) > 0) ? true : false; };

    args->debug = flag_is_set("debug");
    args->resume = flag_is_set("resume");
    args->stop = flag_is_set("stop");
    args->tomorrow = flag_is_set("tomorrow");

    if (vm.count("time") > 0) {
        args->time = vm["time"].as<std::string>();
    } else {
        args->time = "";
    }

    return args;
}
