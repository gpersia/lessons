#!/usr/bin/python
import os
archivo_origen=raw_input("archivo origen: ")
archivo_destino=raw_input("archivo destino: ")

fdo = os.open( archivo_origen, os.O_RDONLY )
fdd = os.open( archivo_destino, os.O_WRONLY | os.O_CREAT ) 
EOF = False
while EOF == False:
    leido = os.read(fdo, 1024)
    os.write(fdd, leido)
    if len(leido) != 1024:
        EOF = True

os.close(fdo)
os.close(fdd)
