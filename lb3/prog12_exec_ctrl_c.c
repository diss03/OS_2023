#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signal) {
    printf("Signal %d received by process %d\n", signal, getpid());
    exit(0);
}

int main() {
    	signal(SIGINT, handler);
    	int pid = fork();

    	if (pid == -1) {
        	perror("fork");
   	}

	if (pid == 0) { // процесс-потомок
        	printf("Child process %d executing...\n", getpid());
        	execl("son", "son", NULL);
    	}
	else { // процесс-родитель
        	printf("Parent process %d executing...\n", getpid());
    	}

	system("ps xf > file.txt");

	while (1) {
        	sleep(1);
 	}
	return 0;
}
