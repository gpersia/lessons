#!/usr/bin/python
import sys
import getopt
L = False
H = False
V = 0
opc ,argus = getopt.getopt(sys.argv[1:],'lhv:')

for o in opc:
    if o[0] == "-l":
        L = True
    elif o[0] == "-h":
        H = True
    elif o[0] == "-v":
        V = int (o[1])

print "L ", L
print "H ", H
print "V ", V
print "argus" , argus

