## GET Flag


Ici, le contenu du fichier `/home/user/end/.pass` va être sockée dans une variable *str*.
ensuite, la chaîne de caractères passée en premier paramètre va être converite en entier.
Un '\0' sera mis a l'index de cet entier dans la chaîne *str*.
Enfin, cette chaîne et le premier paramètre seront comparées. Si elles sont identiques, un shell sera lancé.

Il n'est pas possible de connaitre le contenu du fichier `/home/user/end/.pass`.
De ce fait il faut d'abord mettre un '\0' au premier index de `str`.
Pour que les deux chaînes soient égales, le premier caractère du paramètre doit lui aussi être un '\0'.

`
./bonus3 ""
`

### Flag

```
end
3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c
```
