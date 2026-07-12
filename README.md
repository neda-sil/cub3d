Je vais ecrire ce que je fais ici comme ca tu pourras suivre a ton prochain pull

- j'ai fait une regle dans le Makefile pour qu'on puisse importer la mlx sans avoir a faire un make all (make mlx)

- les premieres lignes du main sont de simples premieres verifications : nbr d'arg, extension .cub et si le fd ouvre ou non

- la fonction "parse_texture" s'occupe de chercher les textures NO, SO, WE, EA

- j'ai fait comme j'ai pu pour le parse de F et C, mais normalement ca fonctionne j'ai juste verifier que ce soit bien F et C dans l'ordre, puis j'ai verifier que ca soit bien separer par des virgules et j'ai laisser le atoi s'occuper de se debarasser des virgules

- pour le parse de la map, j'ai tout mit sur une ligne et apres j'ai fait un ft_split
  et par rapport a la map, il faut qu'on se decide sur si on gere les tabs comme des espaces ou si on met que c'est une erreur

- il reste encore quelques verifs a faire, mais jusqu'ici y a aucun leaks mdrr

- le parsing est completement fini, aucun leaks a deplorer, si tu as besoin d'explications, on verra ca ensemble quand on se voit, je te laisse faire le parsing des signaux !

quand j'y pense, je te passe cette fonction (si jamais tu l'as pas) pour avoir les codes de touches :

int    print_key(int key, void *param)
{
    (void)param;
    ft_printf("keycode : %d\n", key);
    return (0);
}

int    main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 400, 200, "test keys");
    mlx_key_hook(win, print_key, NULL);
    mlx_loop(mlx);
}

