#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char global[10];
void *hilo1 (){
	printf("hola mundo, soy el hilo hilo1\n");
	//global="hola";
	strncpy(global, "hola\n", 5);
	pthread_exit(NULL);
}

void *hilo2 (){
	printf("hola mundo, soy el hilo hilo2\n");
	sleep(1);
	printf("leido: %s\n", global);
	pthread_exit(NULL);
}
int main(){
	int retorno;
	printf("hola mundo, soy el hilo main\n");
	pthread_t tid,tid2;
	retorno = pthread_create(&tid, NULL, hilo1, NULL);
	if ( retorno == 0 ){
		printf ("hilo1 creado\n");
	}
	retorno = pthread_create(&tid2, NULL, hilo2, NULL);
	if ( retorno == 0 ){
		printf ("hilo2 creado\n");
	}
	//sleep(1);
	pthread_exit(NULL);
	return 0;
}
