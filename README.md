Je vais ecrire ce que je fais ici comme ca tu pourras suivre a ton prochain pull

- j'ai fait une regle dans le Makefile pour qu'on puisse importer la mlx sans avoir a faire un make all (make mlx)
- les premieres lignes du main sont de simples premieres verifications : nbr d'arg, extension .cub et si le fd ouvre ou non
- il faudra implementer le gc (je comprend finalement pas trop mdrr) et faire une fonction de sortie + free avec le gc
- la fonction "parse_texture" s'occupe de chercher les textures NO, SO, WE, EA. Pour retirer le retour a la ligne a la fin j'ai modifier "ft_strdup" dans la lib
- 