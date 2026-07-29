/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:03:58 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/29 14:10:00 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	verif_parse(t_data *data)
{
	printf("NO %s\n", data->no);
	printf("so %s\n", data->so);
	printf("we %s\n", data->we);
	printf("ea %s\n", data->ea);
	printf("F %d,%d,%d\n", data->f[0], data->f[1], data->f[2]);
	printf("C %d,%d,%d\n", data->c[0], data->c[1], data->c[2]);
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

// int	main(int ac, char **av)
// {
// 	t_data	*data;
// 	int		fd;

// 	if (ac != 2)
// 		return (ft_printf("%s", ARG_ERROR), EXIT_FAILURE);
// 	else if (!check_extension(av[1], ".cub", 4))
// 		return (ft_printf("%s", MAP_EXTENSION), EXIT_FAILURE);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 		return (ft_printf("%s", NOT_FOUND), EXIT_FAILURE);
// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (ft_printf("%s", MALLOC_ERROR), EXIT_FAILURE);
// 	ft_bzero(data, sizeof(t_data));
// 	data->fd = fd;
// 	parsing(data);
// 	verif_parse(data);
// 	// init_mlx(data, &data->mlx);
// 	launch_raycasting(data, &data->rycstng);
// 	handle_exit(data, NULL);
// 	return (EXIT_SUCCESS);
// }

// int	main(int ac, char **av)
// {
// 	t_data	*data;
// 	int		fd;

// 	if (ac != 2)
// 		return (ft_printf("%s", ARG_ERROR), EXIT_FAILURE);
// 	else if (!check_extension(av[1], ".cub", 4))
// 		return (ft_printf("%s", MAP_EXTENSION), EXIT_FAILURE);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 		return (ft_printf("%s", NOT_FOUND), EXIT_FAILURE);
// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (ft_printf("%s", MALLOC_ERROR), EXIT_FAILURE);
// 	ft_bzero(data, sizeof(t_data));
// 	data->fd = fd;
// 	parsing(data);
// 	verif_parse(data);
// 	// launch_raycasting(data, &data->rycstng);
// 	init_mlx(data, &data->mlx);
// 	// launch_raycasting(data, &data->rycstng);
// 	handle_exit(data, NULL);
// 	return (EXIT_SUCCESS);
// }
