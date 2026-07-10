/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:03:58 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/10 15:21:04 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	// t_data	*data;

	if (ac != 2)
		return (ft_printf("Error: need one and only one arg\n"), EXIT_FAILURE);
	else if (!check_extension(av[1], ".cub", 4))
		return (ft_printf("Error: wrong extension\n"), EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (ft_printf("Error: no such file or directory\n"), EXIT_FAILURE);
}
