#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int maint(){
	long number;
	number = sysconf(_SC_ARG_MAX);
	printf("Максимальное количество открываемых дескрипторов: %ld", number);
	return 0;
}



