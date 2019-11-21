## GET Flag

Cet exécutable utilise 2 malloc et un strcpy.

Il exécute en premier lieu les deux malloc.
Il initialise ensuite un pointeur sur fonction dans le second malloc (de 4 octets).
Enfin, il copie  av[1] dans le premier malloc (de 64 octets).

Cependant, le premier argument n'étant pas limité, sa taille peut être supérieure à 64 octets.

Dans ce cas, la metadata de malloc sera remplacée (8 octets) dans un premier temps.
Puis, la seconde zone mémoire où est stockée l'adresse du pointeur sur fonction sera remplacée par l'adresse que nous souhaitons appeler (l'adresse de n).

`python -c 'print "X" * 64 + "METADATA" + "\x54\x84\x04\x08"' > e`

### Flag

```
level7
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```
