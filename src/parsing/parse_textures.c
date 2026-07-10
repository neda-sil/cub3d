/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:38:35 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/10 18:01:57 by neda-sil         ###   ########.fr       */
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
	printf("%s\n", *loc);
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
