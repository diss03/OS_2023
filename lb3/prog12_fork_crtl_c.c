#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>


void on_signal(int sig) {
    printf("Signal %d received\n", sig);
    exit(0);
}

int main() {
        signal(SIGINT, on_signal);
	int pid;

        if ((pid = fork()) == -1) {
                perror("Fork failed");
                exit(1);
        }

	printf("PPID: %d, PID: %d\n", getppid(), getpid());

	system("ps xf>file.txt ");

	while (true)
                sleep(1);
	return 0;
}
