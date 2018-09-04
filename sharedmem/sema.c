#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	sem_t sema;
	sem_init(&sema, 1 , 3);
	printf ("decremento ...a 2 \n");
	sem_wait(&sema);
	printf ("decremento ...a 1 \n");
	sem_wait(&sema);
	printf ("decremento ...a 0 \n");
	sem_wait(&sema);
	printf ("decremento ...a -1 \n");
	sem_wait(&sema);

	return 0;
}
