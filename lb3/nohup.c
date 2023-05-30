#include <stdio.h>
#include <unistd.h>

void main(){
        int pid=getpid();
	printf("PID: %d", pid);
        while(1)
                sleep(1);
}

