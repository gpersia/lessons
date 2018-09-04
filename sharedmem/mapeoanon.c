#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

int main (){
	sem_t *sema, *sem2;
	int pid;
	int *ptr;
	ptr = mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,-1, 0);
	sema = (sem_t *) ptr + sizeof sema;
	sem2 = sema + sizeof sem2;
	sem_init(sema,1,0);
	sem_init(sem2,1,0);
	pid = fork();

	if ( pid == 0) { //hijo
		*ptr = 5;
		printf("soy el hijo, ya escribi\n");
		sem_post(sema);
		sem_wait(sem2);
		printf ("leido por el hijo %d \n", *ptr);
		return 0;
	}
	//padre
	sem_wait(sema);
	printf ("leido %d \n", *ptr);
	*ptr = (*ptr)*2;
	sem_post(sem2);
	wait(NULL);
	return 0;
}
