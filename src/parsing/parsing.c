/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:57:24 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/11 13:58:15 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// ========= il faut tout mettre dans le gc plus tard ========= //
void	parsing(t_data *data)
{
	// if (!ft_lstadd_gc(data->gc, NULL));
		// // erreur
	parse_textures(data);
	parse_colors(data);
	parse_map(data);
}
