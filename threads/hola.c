#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void *hilo (){
	printf("hola mundo, soy el hilo hilo\n");
	pthread_exit(NULL);
}

int main(){
	int retorno;
	printf("hola mundo, soy el hilo main\n");
	pthread_t tid;
	retorno = pthread_create(&tid, NULL, hilo, NULL);
	if ( retorno == 0 ){
		printf ("hilo creado\n");
	}
	//sleep(1);
	pthread_exit(NULL);
	return 0;
}
