/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:38:35 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/12 16:12:55 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	put_textures(char **loc, char *line, char *searched, t_data *data)
{
	int	i;

	if (!(line[0] == searched[0] && line[1] == searched[1]))
		handle_exit(data, WRONG_ORDER_TEXTURE);
	if (!check_extension(line, ".xpm", 5))
		handle_exit(data, TEXTURE_EXTENSION);
	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	*loc = ft_strdup_gc(line + i, &data->gc);
	if (!*loc)
		handle_exit(data, MALLOC_ERROR);
}

void	parse_textures(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < 4)
	{
		while (!line || line[0] == '\n')
			line = ft_gnl_gc(data->fd, &data->gc);
		if (i == 0)
			put_textures(&data->NO, line, "NO", data);
		if (i == 1)
			put_textures(&data->SO, line, "SO", data);
		if (i == 2)
			put_textures(&data->WE, line, "WE", data);
		if (i == 3)
			put_textures(&data->EA, line, "EA", data);
		line = NULL;
		i++;
	}
}

static void	put_color(int *color, char *line, char searched, t_data *data)
{
	int	i;
	int	pos;
	int	num;

	if (line[0] != searched)
		handle_exit(data, WRONG_ORDER_COLOR);
	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	num = 0;
	while (line[i] && num < 3)
	{
		pos = check_color(line + i);
		if (pos == -1)
			handle_exit(data, WRONG_RANGE);
		if (pos == -2)
			handle_exit(data, UNIDENTIFIED_CHAR_TEXTURE);
		color[num++] = ft_atoi(line + i);
		if (color[num - 1] > 255)
			handle_exit(data, WRONG_RANGE);
		i += pos + 1;
	}
	if (line[i])
		handle_exit(data, UNIDENTIFIED_CHAR_TEXTURE);
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
			line = ft_gnl_gc(data->fd, &data->gc);
		if (i == 0)
			put_color(data->F, line, 'F', data);
		if (i == 1)
			put_color(data->C, line, 'C', data);
		line = NULL;
		i++;
	}
}
