#ifndef INCLUDED_CONSTANTS
#define INCLUDED_CONSTANTS

#include <gutils.h>

namespace constants
{

const std::string PROJECT_NAME = "countdown";
const std::string XDG_RUNTIME_DIR = gutils::init_xdg_dir(PROJECT_NAME, "runtime");

}  // namespace constants

#endif /* INCLUDED_CONSTANTS */
