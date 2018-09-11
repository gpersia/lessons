#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void *hilo (void * valor){
	printf("hola mundo, soy el hilo hilo %d \n", (int)valor);
	pthread_exit(NULL);
}

int main(){
	int retorno;
	int valor;
	printf("hola mundo, soy el hilo main\n");
	pthread_t tid[6];
	for (valor=1;valor<6;valor++){
		retorno = pthread_create(&tid[valor], NULL, hilo,(void *) valor);
		if ( retorno == 0 ){
			printf ("hilo%d creado\n", valor);
		}
	}
	//sleep(1);
	for (valor=1;valor<6;valor++){
		pthread_join(tid[valor], NULL);
	}
	printf("ya terminaron los otros hilos\n");
	pthread_exit(NULL);
	return 0;
}
