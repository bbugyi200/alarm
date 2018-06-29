#ifndef INCLUDED_CLI
#define INCLUDED_CLI

namespace cli {

// The Options structure is used to hold command-line arguments and flags.
typedef struct {
    bool debug;
    std::string time;
} Arguments;

// Parses command-line arguments.
Arguments* parse_args(int, char**);

}  // namespace cli

#endif /* INCLUDED_CLI */
