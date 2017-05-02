#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int status;

    switch (fork()) {
    case 0:
        printf("Soy el hijo  (%d)\n", getpid());
        return 1;

    case -1: // error
        perror("fork()");
        return -1;

    default:
        printf("Soy el padre (%d)\n", getpid());
    }

    wait(&status);
    printf("El hijo terminó con status = %d\n", status);
    printf("Soy el padre (%d) terminando ...\n", getpid());
    return 0;
}
