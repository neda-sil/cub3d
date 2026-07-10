/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:03:58 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/10 22:44:10 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac != 2)
		return (ft_printf("Error: need one and only one arg\n"), EXIT_FAILURE);
	else if (!check_extension(av[1], ".cub", 4))
		return (ft_printf("Error: wrong extension\n"), EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (ft_printf("Error: no such file or directory\n"), EXIT_FAILURE);
	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	data->fd = fd;
	parsing(data);
	printf("NO %s\n", data->NO);
	printf("SO %s\n", data->SO);
	printf("WE %s\n", data->WE);
	printf("EA %s\n", data->EA);
	printf("F %d,%d,%d\n", data->F[0], data->F[1], data->F[2]);
	printf("C %d,%d,%d\n", data->C[0], data->C[1], data->C[2]);
	close(data->fd);
}
