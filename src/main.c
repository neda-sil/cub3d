/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:03:58 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/09 14:14:12 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

bool	check_extension(char *file_name)
{
	return (ft_strnstr(file_name + (ft_strlen(file_name) - 4), ".cub", 4));
}

int	main(int ac, char **av)
{
	if (ac != 2 || !check_extension(av[1]))
		return (1);
}
