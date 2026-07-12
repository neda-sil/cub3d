/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 13:53:26 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/12 14:55:54 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_newlines(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '\n' && line[i + 1] == '\n')
			|| (line[i] == '\n' && line[i + 1] == '\0'))
			handle_exit(data, "consecutive newlines (check the last line)");
		i++;
	}
}

char	*one_line_map(t_data *data)
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

void	parse_map(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;
	line = one_line_map(data);
	data->map = ft_split_gc(line, '\n', &data->gc);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
				&& data->map[i][j] != 'W' && data->map[i][j] != 'E'
				&& data->map[i][j] != ' ')
				handle_exit(data, UNIDENTIFIED_CHAR);
			j++;
		}
		i++;
	}
	if (!check_border(data->map))
		handle_exit(data, BORDER_ERROR);
}
