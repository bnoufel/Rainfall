## GET Flag

Ici, le premier argument doit être un nombre inferieur à 10.
Ce nombre multiplié par 4 sera la quantite de caractères (provenant du second argument) copiés dans un buffer de 40.
la variable verifiée par la suite doit avoir la valeur '0x574f4c46' soit '1464814662' en decimal pour lancer un shell.

Cette variable est declarée après le buffer.
Il est donc possible de l'atteindre avec un buffer overflow en surpassant la limite de 36 octets à copier.

Il est important de noter la possibilité d'utiliser un nombre négatif. Copier une quantité négative à en effet peu d'utilité.
Cependant, ce nombre est multiplié par 4.

`
0xffffffff == 4294967295
4294967295 / 4 == 1073741823
44 / 4 == 11
1073741823 - 11 = 1073741812
`

Si le premier argument correspond à -1073741823, memcpy recevra en 3e argument 0.
Si le premier argument correspond à -1073741812, memcpy recevra en 3e argument 44 .

Il est maintenant possble de passer en second parametre 40 octets suivi de la valeur à assigner à la variable (soit 0x574f4c46).

`
./bonus1 -1073741812 $(python -c 'print "A"*40 + "\x46\x4c\x4f\x57"')
`

### Flag

```
bonus02
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
```
