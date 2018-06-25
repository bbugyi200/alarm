#include <fstream>

#include <unistd.h>
#include <signal.h>

#include "process.h"

process::OldProcessStillAlive::OldProcessStillAlive(const int pid_) { pid = pid_; }

static const char *pid_fname = "/run/user/1000/khal-count/pid";

static bool process_is_running(int pid) { return 0 == kill(pid, 0); }

void process::create_pid() {
    int pid = getpid();
    std::ifstream ifile(pid_fname);
    if (ifile.good()) {
        int old_pid;
        ifile >> old_pid;
        ifile.close();

        if (process_is_running(old_pid)) {
            throw process::OldProcessStillAlive(old_pid);
        }
    }

    ifile.close();
    std::ofstream ofile(pid_fname);
    ofile << pid;
    ofile.close();
}
