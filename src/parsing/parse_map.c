/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 13:53:26 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/11 14:42:42 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static void	check_newlines(t_data *data, char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if ((line[i] == '\n' && line[i + 1] == '\n')
// 			|| (line[i] == '\n' && line[i + 1] == '\0'))
// 		{
// 			free(line);
// 			return ;
// 			// handle_error(data, "consecutive newlines (check the last line)");
// 		}
// 		i++;
// 	}
// }

char	*one_line_map(t_data *data)
{
	char	*line;
	char	*gnl;
	char	*tmp;

	gnl = get_next_line(data->fd);
	if (!gnl)
		return (NULL);
	line = NULL;
	tmp = NULL;
	while (gnl)
	{
		if (!line)
			line = ft_strdup(gnl);
		else
		{
			tmp = line;
			line = ft_strjoin(tmp, gnl);
			free(tmp);
		}
		free(gnl);
		gnl = get_next_line(data->fd);
	}
	close(data->fd);
	// check_newlines(data->map, line);
	return (line);
}

void	parse_map(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;
	line = one_line_map(data);
	data->map = ft_split(line, '\n');
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			// if (!check_caracter(data->map[i][j]))
			// 	return error
			j++;
		}
	}
	// if (!check_border(data->map))
	// 	return error;
}
