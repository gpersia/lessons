import socket
fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM,0)
fd.bind(("192.168.1.52", 8080))
fd.listen(5)
(connfd , direccion) = fd.accept()

connfd.send("url y palabra\n")
print connfd.recv(100)
