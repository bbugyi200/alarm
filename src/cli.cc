#include <iostream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/positional_options.hpp>

#include "cli.h"

namespace po = boost::program_options;

static const std::string program_description =
    "Sets panel countdowns for upcoming khal events.";

static const std::string usage =
    "khal-count [-h] [-d]";

/** Parses command-line arguments.
 *  
 * @param argc: The argument count.
 * @param argv: The list of arguments.
 **/
cli::Arguments* cli::parse_args(int argc, char **argv) {
    po::options_description visible("Named options");
    visible.add_options()
        ("help,h", "Produce help message.")
        ("debug,d", "Enable debug mode.");

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
        std::cout << program_description << "\n\n" 
                  << "usage: " << usage << "\n\n"
                  << visible << std::endl;
    }

    cli::Arguments *args = new Arguments;

    auto flag_is_set = [vm](std::string flag) { return (vm.count(flag) > 0) ? true : false; };

    args->debug = flag_is_set("debug");

    if (flag_is_set("time")) {
        args->time = vm["time"].as<std::string>();
    } else {
        args->time = "";
    }

    return args;
}
