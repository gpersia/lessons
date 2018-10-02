#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int global= 100;
//pthread_mutex_t sincro;
pthread_mutex_t sincro = PTHREAD_MUTEX_INITIALIZER;
void *hilo1 (){
//	printf("hola mundo, soy el hilo hilo1\n");
	int i;
	for (i= 0 ;i< 1000000;i++){
		pthread_mutex_lock(&sincro);
		global++;
		pthread_mutex_unlock(&sincro);
	}
	pthread_exit(NULL);
}

void *hilo2 (){
//	printf("hola mundo, soy el hilo hilo2\n");
	int i;
	for (i= 0 ;i< 1000000;i++){
		pthread_mutex_lock(&sincro);
		global--;
		pthread_mutex_unlock(&sincro);
	}
	pthread_exit(NULL);
}
int main(){
//	pthread_mutex_init(&sincro,NULL);	//inicializa en 1
//	printf("hola mundo, soy el hilo main\n");
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
