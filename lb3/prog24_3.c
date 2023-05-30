#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t t1, t2;

void* thread1(){
	int i, count = 0;
	int tid, pid;
	tid = syscall(SYS_gettid);
	pid = getpid();
 	printf("Thread_1 with thread id = %d and pid = %d is started\n", tid, pid);

	i = 0;
	for (i = 0; i < 10; i++){
		printf("Thread_1: %d\n", i);
		sleep(1);
	}
}

void* thread2(){
	int i, count = 0;
	int tid, pid;
	tid = syscall(SYS_gettid);
	pid = getpid();
 	printf("Thread_2 with thread id = %d and pid = %d is started\n", tid, pid);
	i = 0;
        for (i = 0; i < 10; i++){
                printf("Thread_2: %d\n", i);
                sleep(1);
        }
}

void main(){
	int policy, pid, ppid;
	struct sched_param param;
	pthread_attr_t attr_1, attr_2;

        param.sched_priority = 10;

        if (sched_setscheduler (0, SCHED_RR, &param) == -1)
                perror ("SCHED_SETSCHEDULER_1");

        pid = getpid();
        ppid = getppid();
        printf("MAIN with pid = %d and ppid = %d\n", pid, ppid);

        if (sched_getparam (0, &param) == 0)
                printf ("MAIN's priority = %d\n", param.sched_priority);
        else
                perror ("SCHED_GETPARAM");

        switch (sched_getscheduler (0)) {
                case SCHED_FIFO:
                        printf ("MAIN's policy SCHED_FIFO\n");
                        break;
                case SCHED_RR:
                        printf ("MAIN's policy SCHED_RR\n");
                        break;
                case SCHED_OTHER:
                        printf ("MAIN's policy SCHED_OTHER\n");
                        break;
                case -1:
                        perror ("MAIN's policy SCHED_GETSCHEDULER");
                        break;
                default:
                        printf ("MAIN's policy Неизвестная политика планирования\n");
        }


	if(pthread_attr_init(&attr_1)!=0){ //инициализация атрибутов потока
		perror("init_1 failed");
               	exit(1);
	}

 	if(pthread_attr_init(&attr_2)!=0){ //инициализация атрибутов потока
               	perror("init_2 failed");
               	exit(1);
	}

	//установка политики в атрибут aтрибут attr

        if(pthread_attr_setschedpolicy(&attr_1, SCHED_RR)!=0){
             	perror("setschedpolicy_1 failed");
               	exit(1);
        }

        if(pthread_attr_setschedpolicy(&attr_2, SCHED_RR)!=0){
               	perror("setschedpolicy_2 failed");
               	exit(1);
        }

	//получение приоритета планирования и его установка

	param.sched_priority = 60;

        if(pthread_attr_setschedparam(&attr_1, &param)!=0){
                perror("setschedparam_1 failed");
                exit(1);
        }

	param.sched_priority = 20;

        if(pthread_attr_setschedparam(&attr_2, &param)!=0){
                perror("setschedparam_2 failed");
                exit(1);
        }


	//PTHREAD_INHERIT_SCHED - наследование от нити-родителя
	//PTHREAD_EXPLICIT_SCHED - атрибуты из указателя attr

        /*if(pthread_attr_setinheritsched(&attr_1,PTHREAD_EXPLICIT_SCHED)!=0){
                perror("setinheritsched_1 failed");
                exit(1);
        }

        if(pthread_attr_setinheritsched(&attr_2,PTHREAD_EXPLICIT_SCHED)!=0){
                perror("setinheritsched_2 failed");
                exit(1);
        }*/

        if(pthread_attr_setinheritsched(&attr_1,PTHREAD_INHERIT_SCHED)!=0){
                perror("setinheritsched_1 failed");
                exit(1);
        }

        if(pthread_attr_setinheritsched(&attr_2,PTHREAD_INHERIT_SCHED)!=0){
                perror("setinheritsched_2 failed");
                exit(1);
        }

//????	pthread_attr_setdetachstate(&attr_2, PTHREAD_CREATE_DETACHED);

	//характеристики 1ого потока

        if(pthread_attr_getschedparam(&attr_1, &param)!=0){
                perror("getschedparam_1 failed");
                exit(1);
        }
        if(pthread_attr_getschedpolicy(&attr_1, &policy)!=0){
                perror("getschedpolicy_1 failed");
                exit(1);
        }
	printf("Thread_1's priority = %d\n", param.sched_priority);
        switch (policy) {
                case SCHED_FIFO:
                        printf ("Thread_1's policy SCHED_FIFO\n");
                        break;
                case SCHED_RR:
                        printf ("Thread_1's policy SCHED_RR\n");
                        break;
                case SCHED_OTHER:
                        printf ("Thread_1's policy SCHED_OTHER\n");
                        break;
                case -1:
                        perror ("Thread_1's policy SCHED_GETSCHEDULER");
                        break;
                default:
                        printf ("Thread_1's policy Неизвестная политика планирования\n");
        }

	//характеристики 2ого потока

	if(pthread_attr_getschedparam(&attr_2, &param)!=0){
                perror("getschedparam_2 failed");
                exit(1);
        }
        if(pthread_attr_getschedpolicy(&attr_2, &policy)!=0){
                perror("getschedpolicy_2 failed");
                exit(1);
        }
	printf("Thread_2's priority = %d\n", param.sched_priority);
	switch (policy) {
		case SCHED_FIFO:
			printf ("Thread_2's policy SCHED_FIFO\n");
			break;
		case SCHED_RR:
			printf ("Thread_2's policy SCHED_RR\n");
			break;
		case SCHED_OTHER:
			printf ("Thread_2's policy SCHED_OTHER\n");
			break;
		case -1:
			perror ("Thread_2's policy SCHED_GETSCHEDULER");
			break;
		default:
			printf ("Thread_2's policy Неизвестная политика планирования\n");
	}

	//создание потоков
        if(pthread_create(&t1, &attr_1, thread1, NULL)!=0){
                perror("pthread_create_1 failed");
                exit(1);
        }
        if(pthread_create(&t2, &attr_2, thread2, NULL)!=0){
                perror("pthread_create_2 failed");
                exit(1);
        }

	//ждет завершения нити для совершения операции очистки
        if(pthread_join(t1, NULL)!=0){
                perror("pthread_join_1 failed");
                exit(1);
        }
        if(pthread_join(t2, NULL)!=0){
                perror("pthread_join_2 failed");
                exit(1);
        }

	pthread_attr_destroy(&attr_1); //уничтожение атрибутов потока
	pthread_attr_destroy(&attr_2);
}
