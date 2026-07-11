/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 18:51:22 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/11 14:48:23 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* checks in 'file_name' if 'ext' are in the last 'n' chars */
bool	check_extension(char *file_name, char *ext, int n)
{
	if (ft_strlen(file_name) <= (size_t)n)
		return (false);
	return (ft_strnstr(file_name + (ft_strlen(file_name) - n), ext, n));
}

/* checks if 'color' is written in the right format and returns the lengh of the number */
int	check_color(char *color)
{
	int	i;

	i = 0;
	while (color[i] && i < 4)
	{
		if (!ft_isdigit(color[i]))
		{
			if (color[i] != ',' && color[i] != '\n')
				return (0);
			return (i);
		}
		i++;
	}
	return (0);
}

/* checks if the caracter 'c' is a valid one */
bool	check_caracter(int c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E');
}

/* checks if the borders are closed */
bool	check_border(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0)
			{
				// if (map[i][j] != WALL || map[i][j] != EMPTY)
				// 	return error
				j++;
			}
		}
	}
}
