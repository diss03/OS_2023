#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_accept(){
        printf("SIGUSR1 accepted\n");
}

int main(){
        int pid = getpid();
        printf("Getter pid = %i\n", pid);
        signal(SIGUSR1, sig_accept);
        sleep(60);
}
