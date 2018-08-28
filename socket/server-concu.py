#!/usr/bin/python
import socket, os
fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM,0)
fd.bind(("0.0.0.0", 8080))
fd.listen(5)

while 1:
	(connfd , direccion) = fd.accept()
	pid = os.fork()
	if pid == 0: #hijo
		while 1:
			leido = connfd.recv(500)
			if not leido:
				break
			print direccion,leido
			connfd.send("HTTP/1.1 200 OK\n")
			connfd.send("Content-Type: text/html\n")
			#connfd.send("Content-length: 87\n")
			connfd.send("\n")
			filedes = os.open("archivo.html", 0440)
			datos = os.read(filedes, 100)
			connfd.send(datos)
			filedes.close(fd)
	else: #padre
		connfd.close()
