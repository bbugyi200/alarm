#ifndef INCLUDED_CONSTANTS
#define INCLUDED_CONSTANTS

#include <gutils.h>

const std::string PROJECT_NAME = "countdown";
const std::string XDG_RUNTIME_DIR = gutils::init_xdg_dir(PROJECT_NAME, "runtime");

#endif /* INCLUDED_CONSTANTS */