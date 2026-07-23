/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 13:53:26 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/23 12:09:49 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_newlines(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '\n' && line[i + 1] == '\n'))
			handle_exit(data, CONSECUTIVE_NEWLINES);
		i++;
	}
}

static void	check_caracters_in_map(char *line, t_data *data)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0'
				&& line[i] != 'N' && line[i] != 'S'
				&& line[i] != 'W' && line[i] != 'E'
				&& line[i] != ' ' && line[i] != '\n')
				handle_exit(data, UNIDENTIFIED_CHAR_MAP);
		else if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E')
		{
			if (line[i] == 'S')
				data->rycstng.y_dir = 1;
			if (line[i] == 'N')
				data->rycstng.y_dir = -1;
			if (line[i] == 'E')
				data->rycstng.x_dir = 1;
			if (line[i] == 'W')
				data->rycstng.x_dir = -1;
			if (pos == 1)
				handle_exit(data, MULTIPLE_START);
			pos = 1;
		}
		i++;
	}
	if (!pos)
		handle_exit(data, NO_PLAYER);
}

static char	*one_line_map(t_data *data)
{
	char	*line;
	char	*gnl;
	char	*tmp;

	gnl = ft_gnl_gc(data->fd, &data->gc);
	if (!gnl)
		return (NULL);
	line = NULL;
	tmp = NULL;
	while (gnl)
	{
		if (!line)
			line = ft_strdup_gc(gnl, &data->gc);
		else
		{
			tmp = line;
			line = ft_strjoin_gc(tmp, gnl, &data->gc);
		}
		gnl = ft_gnl_gc(data->fd, &data->gc);
	}
	check_newlines(data, line);
	return (line);
}

static void	find_player_pos(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[x][y] == 'N' || map[x][y] == 'S'
				|| map[x][y] == 'W' || map[x][y] == 'E')
			{
				data->rycstng.x_player = x;
				data->rycstng.y_player = y;
			}
			x++;
		}
		y++;
	}
}

void	parse_map(t_data *data)
{
	char	*line;

	line = NULL;
	line = one_line_map(data);
	check_caracters_in_map(line, data);
	data->map = ft_split_gc(line, '\n', &data->gc);
	find_player_pos(data->map);
	if (!check_border(data, data->map))
		handle_exit(data, BORDER_ERROR);
}
