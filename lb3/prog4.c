#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>


void main(){
	struct sched_param shdprm;

        int m, n, pid;
        m=2000;
        n=1000;

        int pid1, pid2, ppid;
        pid1 = getpid();
        ppid = getppid();
	printf("FATHER PARAMS: pid=%i ppid=%i\n", pid1,ppid);

	shdprm.sched_priority = 50;

        if (sched_setscheduler (0, SCHED_RR, &shdprm) == -1) {
                perror ("SCHED_SETSCHEDULER");
        }

        if((pid = fork()) == -1){
                perror("fork error");
                exit(1);
        }

        printf("pid=%d\n",pid);

        if(pid != 0){
                for(int i=0; i<=1000; i++){
                        n+=1;
                        if(i%100 == 0)
                                printf("родитель: %d\n",n);
                }
        }
        else{
		shdprm.sched_priority = 70;
                for(int i=0; i<=1000; i++){
                        m-=1;
                        if(i%100 == 0)
                                printf("потомок: %d\n",m);
                }
        }
        printf("Программа завершена (%d)\n", pid);
        exit(1);
}
