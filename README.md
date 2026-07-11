Je vais ecrire ce que je fais ici comme ca tu pourras suivre a ton prochain pull

- j'ai fait une regle dans le Makefile pour qu'on puisse importer la mlx sans avoir a faire un make all (make mlx)

- les premieres lignes du main sont de simples premieres verifications : nbr d'arg, extension .cub et si le fd ouvre ou non

- il faudra implementer le gc (je comprend finalement pas trop mdrr) et faire une fonction de sortie + free avec le gc

- la fonction "parse_texture" s'occupe de chercher les textures NO, SO, WE, EA. Pour retirer le retour a la ligne a la fin j'ai modifier "ft_strdup" dans la lib

- j'ai fait comme j'ai pu pour le parse de F et C, mais normalement ca fonctionne j'ai juste verifier que ce soit bien F et C dans l'ordre, puis j'ai verifier que ca soit bien separer par des virgules et j'ai laisser le atoi s'occuper de se debarasser des virgules

- je t'ai laisse de toute facon un test dans le main

- pour le parse de la map, j'ai tout mit sur une ligne et apres j'ai fait un ft_split, il faut juste vraiment implementer le gc parce que j'ai mit pleins de passages d'erreur vide parce que je n'ai pas de fonction de gestion d'erreur pour tout free
  et par rapport a la map, il faut qu'on se decide sur si on gere les tabs comme des espaces ou si on met que c'est une erreur
