#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
        int pid, ppid;

        pid = fork();

        if (pid == -1){
                perror("fork");
                exit(1);
        }

        if(pid == 0){
		pid = getpid();
                printf("потомок: pig=%d, ppid=%d\n", pid, getppid());
        }
        else{
		pid = getpid();
                printf("родитель: pid=%d, ppid=%d\n", pid, getppid());
        }

        printf("программа завершена (%d)\n", pid);
        return 0;
}
