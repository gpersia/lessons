#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <netdb.h>

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
	int fd, fdcliente, leido, conectado, connfd, pid;
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
	procrem.sin_addr.s_addr = htonl(INADDR_ANY);
	//inet_pton(AF_INET,"0.0.0.0", &procrem.sin_addr);
	int a;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,&a, sizeof a);
	if (bind(fd,(struct sockaddr *)&procrem, sizeof procrem) < 0 ) {
		perror ("bind");
                return -1;
        }

	listen(fd, 5);
	signal(SIGCHLD,SIG_IGN ); //para sacar procesos terminados de la PCB ...
	while ( (connfd = accept(fd,NULL, 0)) > 0 ){
		pid = fork();
		//hijo
		if ( pid == 0 ) {
			leido = read (connfd,buff ,sizeof buff);
			write (1 ,buff ,leido);
			//write (connfd ,buff ,leido);
			// se conecta como cliente a un servidor http

	struct sockaddr_in serverhttp={};
	fdcliente = socket(AF_INET, SOCK_STREAM, 0);
	if  (fdcliente < 0 ){
		perror ("socketcliente");
		return -1;
	}
	serverhttp.sin_family = AF_INET;
	serverhttp.sin_port = htons(80); //puerto default servidor http
	//procrem.sin_addr = 192.168.1.52;
	//procrem.sin_addr.s_addr = htonl(0xc0a80134);
	//inet_pton(AF_INET,"www.um.eud.ar", &procrem.sin_addr);
	
        struct hostent *hp = gethostbyname("www.um.edu.ar");
	
	inet_pton(AF_INET,inet_ntoa( *( struct in_addr*)( hp -> h_addr_list[0])), &serverhttp.sin_addr);
	conectado = connect(fdcliente,(struct sockaddr *)&serverhttp, sizeof serverhttp);
	if  (conectado < 0 ){
                perror ("connect");
                return -1;
        }		
	write(fdcliente, "GET /es/ua/fi.html HTTP/1.1\nHost: www.um.edu.ar\nConnection: close\n\n", 67);
	while ((leido = read(fdcliente, buff , sizeof buff)) > 0){
		if  (leido < 0 ){
			perror ("read");
			return -1;
		}
	write(connfd,buff,leido);
	//parsear palabra
	}

		return 0;
		}
		close(connfd);
	}
	return 0;
}	
