#include <fstream>

#include <iostream>
#include <unistd.h>
#include <signal.h>

#include <process.h>
#include <constants.h>

namespace C = constants;

static const std::string pid_fname = C::XDG_RUNTIME_DIR + "/pid";

void process::create_pid() {
    int pid = getpid();
    std::ifstream ifile(pid_fname);
    if (ifile.good()) {
        int old_pid;
        ifile >> old_pid;
        ifile.close();

        if (kill(old_pid, 0) == 0) {
            throw process::OldProcessStillAlive(old_pid);
        }
    }

    ifile.close();
    std::ofstream ofile(pid_fname);
    ofile << pid;
    ofile.close();
}
