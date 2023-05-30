#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void get_signal(int signal) {
    printf("Signal %d received by process %d\n", signal, getpid());
    //exit(0);
}


int main()
{
    int pid, ppid;
    //signal(SIGINT, get_signal);
    pid = getpid();
    ppid = getppid();
    printf("\n Son parameters was: pid=%i, ppid=%i\n", pid, ppid);

    while (1) {
        sleep(1);
    }
    return 0;
}
