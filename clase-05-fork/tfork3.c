#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    switch (fork()) {
    case 0:
        printf("Soy el hijo: %d\n", getpid());
        return 0;

    case -1: // error
        perror("fork()");
        return -1;

    default:
        printf("Soy el padre: %d\n", getpid());
    }

    //sleep(1);
    printf("Soy el padre, terminando ...\n");
    return 0;
}
