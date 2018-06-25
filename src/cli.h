#ifndef CLI
#define CLI

/** Command-line argument namespace. **/
namespace cli {

    /** The Options structure is used to hold command-line arguments and flags. **/
    struct Arguments {
        bool debug;
        bool resume;
        bool stop;
        bool tomorrow;
        std::string time;
    };

    using Arguments = struct Arguments;

    Arguments* parse_args(int, char**);
}

#endif /* CLI */
