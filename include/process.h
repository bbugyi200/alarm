#ifndef INCLUDED_PROCESS
#define INCLUDED_PROCESS

#include <stdexcept>

namespace process {

// Creates PID file if it does not already exist. Otherwise, checks if process with old
// PID is still running and, if not, overwrites the PID file.
//
// Throws OldProcessStillAlive exception if old process is still running.
void create_pid();

// The OldProcessStillAlive exception is thrown if an old instance of this program is still
// running. 
struct OldProcessStillAlive : public std::exception {
    int pid;
    OldProcessStillAlive(const int);
};

}  // namespace process

#endif /* INCLUDED_PROCESS */
