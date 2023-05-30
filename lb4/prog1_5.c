#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t t1;

typedef struct someArgs_tag { //Т.к. функция может получать только указатель типа void
    int pid;
}someArgs_t;

void* thread1(void *args){
    	someArgs_t *arg = (someArgs_t*) args;

	int kill_pid = arg->pid;

        kill(kill_pid, SIGUSR2);

	while(1){
                puts("Thread-send");
                sleep(1);
        }
}

void main(int argc, char* argv[]){
	someArgs_t arg;
	arg.pid = atoi(argv[1]);
        pthread_create(&t1, NULL, thread1, (void*) &arg);
        pthread_join(t1, NULL);
}
