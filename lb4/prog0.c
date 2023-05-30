#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

void handler(){
	puts("Signal catched!\n");
	pthread_exit(0);
}

void* thread0(){
	signal(SIGUSR2, handler);
	sleep(1);
	kill(getpid(), SIGUSR2);
	while(1){
		puts("Thread 0 is going");
		sleep(1);
	}
}

void main(){
	pthread_t t1;
	pthread_create(&t1, NULL, thread0, NULL);
	pthread_join(t1, NULL);
	while(1){
		puts("Main process is going");
		sleep(1);
	}
}
