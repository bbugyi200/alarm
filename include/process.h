#ifndef INCLUDED_PROCESS
#define INCLUDED_PROCESS

#include <stdexcept>

/** Process management. **/
namespace process {

void create_pid();

/** 
 * The OldProcessStillAlive exception is thrown if an old instance of this program is still
 * running. 
 **/
struct OldProcessStillAlive : public std::exception {
    int pid;
    OldProcessStillAlive(const int);
};

}  // namespace process

#endif /* INCLUDED_PROCESS */
