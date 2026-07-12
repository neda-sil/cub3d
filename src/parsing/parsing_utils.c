/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 18:51:22 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/11 21:03:52 by neda-sil         ###   ########.fr       */
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

static bool	check_first_and_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != EMPTY && line[i] != WALL)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == EMPTY)
		i++;
	if (i > 0)
	{
		if (line[i - 1] == EMPTY && line[i] != WALL)
			return (false);
	}
	else
		if (line[i] != WALL)
			return (false);
	while (line[i] && line[i] != EMPTY)
		i++;
	if (line[i - 1] != WALL)
		return (false);
	if (line[i])
		return (check_line(line + i));
	return (true);
}

/* checks if the borders are closed */
bool	check_border(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i == 0 || !map[i + 1])
		{
			if (!check_first_and_last_line(map[i]))
				return (false);
		}
		else
		{
			if (!check_line(map[i]))
				return (false);
		}
		i++;
	}
	return (true);
}
