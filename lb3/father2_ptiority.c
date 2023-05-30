#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[]) {
	struct sched_param shdprm;
	int pid, pid1, pid2, pid3, ppid, status;
	int n, m, l, k;
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	l = atoi(argv[3]);
	k = atoi(argv[4]);
	//n=50; m=60; l=10; k=80; //для первого экс. с политикой RR
 	// m=60; l=10; k=4; //для повторного эксперимента с политикой FIFO
 	pid = getpid();
 	ppid = getppid();

	printf("FATHER PARAMS: pid=%i ppid=%i\n", pid,ppid);
	shdprm.sched_priority = n;
	if (sched_setscheduler (0, SCHED_FIFO, &shdprm) == -1) {
		perror ("SCHED_SETSCHEDULER");
	}

	if((pid1=fork()) == 0){
			shdprm.sched_priority = m;
		if (sched_setscheduler (pid1, SCHED_FIFO, &shdprm) == -1)
			perror ("SCHED_SETSCHEDULER_1");
		execl("son1", "son1", NULL);
	}

	if((pid2=fork()) == 0){
		shdprm.sched_priority = l;
		if (sched_setscheduler (pid2, SCHED_FIFO, &shdprm) == -1)
			perror ("SCHED_SETSCHEDULER_2");
		execl("son2", "son2", NULL);
	}

	if((pid3=fork()) == 0){
		shdprm.sched_priority = k;
		if (sched_setscheduler (pid3, SCHED_FIFO, &shdprm) == -1)
			perror ("SCHED_SETSCHEDULER_3");
		execl("son3", "son3", NULL);
	}
	printf("Процесс с pid = %d завершен\n", wait(&status));
	printf("Процесс с pid = %d завершен\n", wait(&status));
	printf("Процесс с pid = %d завершен\n", wait(&status));
	return 0;
}
