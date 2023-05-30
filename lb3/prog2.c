#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void main(){
        int m, n, pid;
        m=1;
        n=1;
        pid = fork();

        if(pid == -1){
                perror("fork error");
                exit(1);
        }

        printf("pid=%d\n",pid);

        if(pid != 0){
                m+=1;
                printf("родитель: %d\n",m);
        }
        else{
                n-=1;
                printf("потомок: %d\n",n);
        }
        printf("Программа завершена (%d)\n", pid);
        exit(1);
}
