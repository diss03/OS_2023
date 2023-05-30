#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
        time_t mytime;
        struct tm * now;

        int pid, ppid, status, son_pid;
        pid = getpid();
        ppid = getppid();
        son_pid = atoi(argv[1]);

        printf("FATHER PARAM pid=%d, ppid=%d\n",pid, ppid);

        time(&mytime);
        now = localtime(&mytime);
        printf("Signal SIGUSR1 sent. Time: %d:%d:%d\n", now->tm_hour, now->tm_min, now->tm_sec);

        kill(son_pid, SIGUSR1);
        sleep(10);
}

