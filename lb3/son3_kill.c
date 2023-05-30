#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_accept() {
	printf("\nSignal SIGUSR1 have been accepted.\n\n");
}

int main() {
	int pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("\nSON3 PARAM: pid=%d ppid=%d \n\n", pid, ppid);
	signal(SIGUSR1, sig_accept);
	sleep(5);
    	return 0;
}
