#include <iostream>

#include <signal.h>

#include <cli.h>
#include <process.h>

void sig_usr1_handler(int signum) {
    exit(signum);
}

int main(int argc, char *argv[])
{
    signal(SIGUSR1, sig_usr1_handler);
    auto args = cli::parse_args(argc, argv);

    try {
        process::create_pid();
    } catch (process::OldProcessStillAlive& e) {
        kill(e.pid, SIGUSR1);
        return 0;
    }
}
