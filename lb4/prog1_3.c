#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

pthread_t t1, t2;

void handler(){
	puts("Signal catched!");
	pthread_exit(0);
}

void* thread1(){
	signal(SIGUSR2, handler);
	while(1){
		puts("Thread 1");
		sleep(1);
	}
}

void* thread2(){
        pthread_kill(t1, SIGUSR2);
	while(1){
                puts("Thread 2");
                sleep(1);
        }
}

void main(){
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
