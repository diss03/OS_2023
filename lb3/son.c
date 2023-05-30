#include <stdio.h>
#include <unistd.h>

int main(){
	int pid, ppid;

	pid=getpid();
	ppid=getppid();

	printf("\nSON PARAM: pid=%d, ppid=%d\n", pid, ppid);
	sleep(5);
	//system("ps -a -o uid,pid,ppid,pgid,time,cmd");
	return 0;
}
