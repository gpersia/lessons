#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void *hilo (void * valor){
	printf("hola mundo, soy el hilo hilo %d \n", (int)valor);
	pthread_exit(NULL);
}

int main(){
	int retorno;
	int valor=5;
	printf("hola mundo, soy el hilo main\n");
	pthread_t tid;
	retorno = pthread_create(&tid, NULL, hilo,(void *) valor);
	if ( retorno == 0 ){
		printf ("hilo creado\n");
	}
	//sleep(1);
	pthread_exit(NULL);
	return 0;
}
