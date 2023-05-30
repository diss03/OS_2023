#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        int pid, ppid, status;

        pid=getpid();
        ppid=getppid();
        printf("\nFATHER PARAM: pid=%d, ppid=%d\n", pid, ppid);

        char* file = "son";
        char* path = "son";
        char* args[] = {"son", "-l", (char*)0};
        char* env[] = {(char*)NULL };


        if(fork()==0)
                switch ((int)argv[1][0]) {

                case (int)'1':
                        execl("son", "son", "-l", (char*)NULL);break;
                case (int)'2':
                        execlp("son", "son", (char*)NULL); break;
                case (int)'3':
                        execle("son", "son", (char*)NULL, env); break;
                case (int)'4':
                        execv("son", args); break;
                case (int)'5':
                        execvp("son", args); break;
        }
        system("ps xf>file.txt");
        wait(&status);
        printf("\nChild proccess was finishd with status %d\n", status);
        return 0;
}
