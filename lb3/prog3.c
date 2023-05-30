#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
        int m, n, pid;
        m=20000;
        n=10000;
        pid = fork();

        if(pid == -1){
                perror("fork error");
                exit(1);
        }

        printf("pid=%d\n",pid);

        if(pid != 0){
                for(int i=0; i<=10000; i++){
                        n+=1;
                        if(i%100 == 0)
                                printf("родитель: %d\n",n);
                }
        }
        else{
                for(int i=0; i<=10000; i++){
                        m-=1;
                        if(i%100 == 0)
                                printf("потомок: %d\n",m);
                }
        }
        printf("Программа завершена (%d)\n", pid);
        exit(1);
}
