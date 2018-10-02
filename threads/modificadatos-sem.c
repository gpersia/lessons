#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

int global= 100;
sem_t sincro;
void *hilo1 (){
//	printf("hola mundo, soy el hilo hilo1\n");
	int i;
	for (i= 0 ;i< 1000000;i++){
		sem_wait(&sincro);
		global++;
		sem_post(&sincro);
	}
	pthread_exit(NULL);
}

void *hilo2 (){
//	printf("hola mundo, soy el hilo hilo2\n");
	int i;
	for (i= 0 ;i< 1000000;i++){
		sem_wait(&sincro);
		global--;
		sem_post(&sincro);
	}
	pthread_exit(NULL);
}
int main(){
//	pthread_mutex_init(&sincro,NULL);	//inicializa en 1
//	printf("hola mundo, soy el hilo main\n");
	sem_init(&sincro,0,1);
	pthread_t tid,tid2;
	pthread_create(&tid, NULL, hilo1, NULL);
	pthread_create(&tid2, NULL, hilo2, NULL);
	//sleep(1);
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
		printf("valor final %d \n",global);
	pthread_exit(NULL);
	return 0;
}
