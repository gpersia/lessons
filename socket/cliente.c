#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};
struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};*/
int main(){
	int fd, leido, conectado;
	char buff[1000];
	struct sockaddr_in procrem={};
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if  (fd < 0 ){
		perror ("socket");
		return -1;
	}
	procrem.sin_family = AF_INET;
	procrem.sin_port = htons(8080);
	//procrem.sin_addr = 192.168.1.52;
	//procrem.sin_addr.s_addr = htonl(0xc0a80134);
	inet_pton(AF_INET,"192.168.1.52", &procrem.sin_addr);
	conectado = connect(fd,(struct sockaddr *)&procrem, sizeof procrem);
	if  (conectado < 0 ){
                perror ("connect");
                return -1;
        }
	write(fd, "GET /\n", 6);
	leido = read(fd, buff , sizeof buff);
	if  (leido < 0 ){
		perror ("read");
		return -1;
	}
	write(1,buff,leido);
	return 0;
}	
