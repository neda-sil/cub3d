/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:03:58 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/11 16:01:59 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	verif_parse(t_data *data)
{
	printf("NO %s\n", data->NO);
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
		return (ft_printf("Error: wrong extension\n"), EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (ft_printf("%s\n", NOT_FOUND), EXIT_FAILURE);
	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	data->fd = fd;
	parsing(data);
	verif_parse(data);
	close(data->fd);
}
