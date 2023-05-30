#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	int pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("\nSON2 PARAM: pid=%d ppid=%d \n", pid, ppid);
	signal(SIGUSR1, SIG_IGN);
	sleep(20);
    		return 0;
}
