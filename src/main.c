/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:03:58 by neda-sil          #+#    #+#             */
/*   Updated: 2026/08/03 12:59:51 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	init_mlx(data, &data->mlx);
	handle_exit(data, NULL);
	return (EXIT_SUCCESS);
}
