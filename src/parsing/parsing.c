/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:57:24 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/23 14:12:02 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// ========= il faut tout mettre dans le gc plus tard ========= //
void	parsing(t_data *data)
{
	parse_textures(data);
	parse_colors(data);
	parse_map(data);
	data->floor_color = (data->F[0] << 16) | (data->F[1] << 8) | data->F[2];
	data->ceiling_color = (data->C[0] << 16) | (data->C[1] << 8) | data->C[2];
	data->rycstng.y_dir = 0;
	data->rycstng.x_dir = 0;
	data->screen_x = 1200;
	data->screen_y = 700;
}
