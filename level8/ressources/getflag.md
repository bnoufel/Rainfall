## GET Flag

Il existe deux méthodes pour exploiter ce binaire.

La première étant de s'authetifier avec `auth ` et un nom d'utilisateur de moins de 16 caractères, par exemple `auth admin`.
Avec la commande `reset` l'espace alloué sera libéré, mais le pointeur ne sera remit à NULL, de ce fait los de l'utilisation de la commande `service` (servic), la même zone mémoire sera utilisée, de plus si l'argument a une longeur de 31 octet, le 32ème sera mit a '\0'.

```
auth 123
reset
service1234567890123456789012345678901
login
```

Service et auth partagant la même adresse vérifier le 32e caractère de auth revient a vérfier le 32e caractères de service.
Il est donc possible de faire un `login` qui lancera un shell, reste donc a récupérer le contenu de `/home/user/level9/.pass`.

La deuxième méthode provient d'une erreur de malloc, en effet l'allocation est de 4 octet alors qu'elle devrait être de 36octet (name[32] + int).
La taille de la METADATA étant de 8octet, la prochaine allocation commencera à auth + 12. La vérification se faisant sur auth + 32, il est possible de rajouter 19 octets pour que le '\0' soit bien situé.


```
auth 123
service1234567890123456789
login
```

### Flag

```
level9
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```