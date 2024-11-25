#!/usr/bin/env python3
import sys

lenx = int(sys.argv[1])
leny = int(sys.argv[2])

r = open("../map2", "w")

for y in range(leny):
    for x in range(lenx):
        if x == 0 or x == lenx - 1 or y == 0 or y == leny - 1:
            r.write("#")
        else:
            r.write(" ")
    r.write("\n")
