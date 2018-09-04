#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>


int main (){
	int pid;
	int *ptr;
	ptr = mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,-1, 0);
	pid = fork();

	if ( pid == 0) { //hijo
		*ptr = 5;
		printf("soy el hijo, ya escribi\n");
		return 0;
	}
	//padre
	sleep(2);
	printf ("leido %d \n", *ptr);
	return 0;
}
