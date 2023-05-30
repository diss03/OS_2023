#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <sys/syscall.h>

pthread_t t1, t2;

void handler(){
        puts("Signal catched!");
        pthread_exit(0);
}

void* thread1(){
        signal(SIGUSR2, handler);
	int tid, pid;
 	tid = syscall(SYS_gettid);
 	pid = getpid();
 	printf("Thread-get with thread id = %d and pid = %d is started\n", tid, pid);

        while(1){
                puts("Thread-get");
                sleep(1);
        }
}

void main(){
        pthread_create(&t1, NULL, thread1, NULL);
        pthread_join(t1, NULL);
}
