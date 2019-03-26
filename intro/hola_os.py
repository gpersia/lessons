#!/usr/bin/python
import os
#from os import *
EOF = True
total = 0
while EOF :
    leido = os.read(0, 1000)
    total = total + len(leido)
    os.write (1,leido.upper())
    if len(leido) < 1000:
        EOF = False
os.write(2,str(total)+ "\n")
