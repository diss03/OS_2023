#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
pthread_t t1,t2;

void my_sig(){
        printf("Accepted interrupt signal\n");
        //signal(SIGINT, SIG_DFL); //разкомментировать в b)
}

void* thread1(){
        printf("thread1 started\n");
        int i = 0;
        while(1) {
                printf("thread1, %d\n", i++);
                sleep(1);
        }
}

void* thread2(){
        printf("thread2 started\n");
        int i = 0;
        //signal(SIGINT, my_sig); //разкомментировать в b)
        while(1) {
                printf("thread2, %d\n", i++);
                sleep(5);
        }
}

void main(){
        //signal(SIGINT, my_sig); //разкомментировать в с)
        //signal(SIGINT, SIG_DFL); //разкомментировать в а)
	signal(SIGTSTP, my_sig); //разкомментировать в d)
        pthread_create(&t1, NULL, thread1, NULL);
        pthread_create(&t2, NULL, thread2, NULL);

        sleep(5);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
}
