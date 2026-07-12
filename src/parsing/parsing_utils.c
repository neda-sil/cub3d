/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 18:51:22 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/12 16:50:57 by neda-sil         ###   ########.fr       */
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
	while (color[i] && i < 5)
	{
		if (!ft_isdigit(color[i]))
		{
			if (color[i] == '-')
				return (-1);
			if (color[i] == ',' || color[i] == '\n')
				return (i);
			return (-2);
		}
		i++;
	}
	return (0);
}

static char	get_char(char **map, int row, int col)
{
	if (row < 0 || !map[row])
		return (EMPTY);
	if (col < 0 || col >= (int)ft_strlen(map[row]))
		return (EMPTY);
	return (map[row][col]);
}

/* checks if the borders are closed */
bool	check_border(char **map)
{
	int	r;
	int	c;

	r = 0;
	while (map[r])
	{
		c = 0;
		while (map[r][c])
		{
			if (map[r][c] == EMPTY || map[r][c] == WALL)
				c++;
			else
			{
				if (get_char(map, r - 1, c) == EMPTY
					|| get_char(map, r + 1, c) == EMPTY
					|| get_char(map, r, c - 1) == EMPTY
					|| get_char(map, r, c + 1) == EMPTY)
					return (false);
				c++;
			}
		}
		r++;
	}
	return (true);
}
