/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:03:58 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/21 14:51:18 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	verif_parse(t_data *data)
{
	printf("NO %s\n", data->no);
	printf("SO %s\n", data->SO);
	printf("WE %s\n", data->WE);
	printf("EA %s\n", data->EA);
	printf("F %d,%d,%d\n", data->F[0], data->F[1], data->F[2]);
	printf("C %d,%d,%d\n", data->C[0], data->C[1], data->C[2]);
	int	i = 0;
	while (data->map[i])
		printf("%s\n", data->map[i++]);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac != 2)
		return (ft_printf("%s", ARG_ERROR), EXIT_FAILURE);
	else if (!check_extension(av[1], ".cub", 4))
		return (ft_printf("%s", MAP_EXTENSION), EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("%s", NOT_FOUND), EXIT_FAILURE);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_printf("%s", MALLOC_ERROR), EXIT_FAILURE);
	ft_bzero(data, sizeof(t_data));
	data->fd = fd;
	parsing(data);
	verif_parse(data);
	init_mlx(data, &data->mlx);
	handle_exit(data, NULL);
	return (EXIT_SUCCESS);
}

// int    print_key(int key, void *param)
// {
//     (void)param;
//     ft_printf("keycode : %d\n", key);
//     return (0);
// }

// int    main(void)
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 1920, 1000, "test keys");
//     mlx_key_hook(win, print_key, NULL);
//     mlx_loop(mlx);
// }
