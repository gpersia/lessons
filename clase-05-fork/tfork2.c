#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Soy el padre: %d\n", getpid());

    if (fork() == 0) {
        printf("Soy el hijo: %d\n", getpid());
        return 0;
    }

    sleep(1);
    printf("Soy el padre, terminando ...\n");
    return 0;
}
