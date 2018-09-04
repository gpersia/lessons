#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (){
	int pid;
	int *ptr;
	ptr = mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,-1, 0);
	pid = fork();

	if ( pid == 0) { //hijo
		*ptr = 5;
		printf("soy el hijo, ya escribi\n");
		sleep(2);
		printf ("leido por el hijo %d \n", *ptr);
		return 0;
	}
	//padre
	sleep(1);
	printf ("leido %d \n", *ptr);
	*ptr = (*ptr)*2;
	wait(NULL);
	return 0;
}
