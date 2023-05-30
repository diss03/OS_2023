#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("SIGUSR1 sent\n");
	kill(atoi(argv[1]), SIGUSR1);
}
