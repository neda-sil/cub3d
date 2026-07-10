/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:57:24 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/10 17:10:04 by neda-sil         ###   ########.fr       */
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

// ========= il faut tout mettre dans le gc plus tard ========= //
void	parsing(t_data *data)
{
	// if (!ft_lstadd_gc(data->gc, NULL));
		// // erreur
	parse_textures(data);
}
