#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int global= 100;
pthread_mutex_t serie;
void *hilo1 (){
	printf("hola mundo, soy el hilo hilo1\n");
	global = 200;	
	pthread_mutex_unlock(&serie);
	pthread_exit(NULL);
}

void *hilo2 (){
	printf("hola mundo, soy el hilo hilo2\n");
	pthread_mutex_lock(&serie);
	printf("global = %d \n",global );
	pthread_exit(NULL);
}
int main(){
	pthread_mutex_init(&serie,NULL);
	pthread_mutex_lock(&serie); //vale 0
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
