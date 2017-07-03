#!/usr/bin/python3
from random import *

with open('large_input', 'w+') as f:
    f.write("200000 200000\n")
    for i in range(0, 200000):
        f.write('{} '.format(i+1))

    f.write('\n')
    for i in range(0, 200000):
        l = randint(1, 200000-1)
        r = randint(l+1, 200000)
        f.write('{} {}\n'.format(l, r))
