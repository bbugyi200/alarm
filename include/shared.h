#ifndef INCLUDED_SHARED
#define INCLUDED_SHARED

#include <gutils.h>

const std::string PROJECT_NAME = "countdown";
const std::string XDG_RUNTIME_DIR = gutils::init_xdg_dir(PROJECT_NAME, "runtime");

#endif /* INCLUDED_SHARED */
