/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:38:35 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/10 22:43:03 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	put_textures(char **loc, char *line, char *searched)
{
	int	i;

	if (!(line[0] == searched[0] && line[1] == searched[1]))
		return ;
	if (!check_extension(line, ".xpm", 5))
	{
		ft_printf("Error: wrong extension for an image\n");
		return ;
	}
	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	*loc = ft_strdup(line + i);
	if (!*loc)
		return ;
	// if (i <= 2)
	// 	return error
}

// ========= get_next_line -> ft_gnl_gc ============ //
void	parse_textures(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < 4)
	{
		while (!line || line[0] == '\n')
			line = get_next_line(data->fd);
		if (i == 0)
			put_textures(&data->NO, line, "NO");
		if (i == 1)
			put_textures(&data->SO, line, "SO");
		if (i == 2)
			put_textures(&data->WE, line, "WE");
		if (i == 3)
			put_textures(&data->EA, line, "EA");
		free(line);
		line = NULL;
		i++;
	}
	free(line);
}

static void	put_color(int *color, char *line, char searched)
{
	int	i;
	int	pos;
	int	num;

	if (line[0] != searched)
		return ;
	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
	}
	num = 0;
	while (line[i] && num < 3)
	{
		pos = check_color(line + i);
		if (!pos)
			return ;
		color[num++] = ft_atoi(line + i);
		i += pos + 1;
	}
}

void	parse_colors(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < 2)
	{
		while (!line || line[0] == '\n')
			line = get_next_line(data->fd);
		if (i == 0)
			put_color(data->F, line, 'F');
		if (i == 1)
			put_color(data->C, line, 'C');
		free(line);
		line = NULL;
		i++;
	}
	free(line);
}
