#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void sig_accept() {
	time_t mytime;
	struct tm * now;
	time(&mytime);
	now = localtime(&mytime);
	printf ( "Signal SIGUSR1 accepted. Time: %d:%d:%d", now->tm_hour, now->tm_min, now->tm_sec);
}

int main() {
	int pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("SON PARAM: pid=%d ppid=%d \n", pid, ppid);
	signal(SIGUSR1, sig_accept);
	sleep(120);
}
