#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int global= 100;
pthread_barrier_t barrera;
void *hilo1 (){
	printf("hola mundo, soy el hilo hilo1\n");
	global = 200;	
	pthread_barrier_wait(&barrera);
	printf("global = %d \n",global );
	pthread_exit(NULL);
}

void *hilo2 (){
	printf("hola mundo, soy el hilo hilo2\n");
	global = 300;
	pthread_barrier_wait(&barrera);
	printf("global = %d \n",global );
	pthread_exit(NULL);
}
void *hilo3 (){
	printf("hola mundo, soy el hilo hilo3\n");
	global = 400;
	pthread_barrier_wait(&barrera);
	printf("global = %d \n",global );
	pthread_exit(NULL);
}
int main(){
//	printf("hola mundo, soy el hilo main\n");
	pthread_barrier_init (&barrera,NULL, 3);
	pthread_t tid,tid2,tid3;
	pthread_create(&tid, NULL, hilo1, NULL);
	pthread_create(&tid2, NULL, hilo2, NULL);
	pthread_create(&tid3, NULL, hilo3, NULL);
	//sleep(1);
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
		printf("valor final %d \n",global);
	pthread_exit(NULL);
	return 0;
}
