/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 18:51:22 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/10 22:42:07 by neda-sil         ###   ########.fr       */
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
