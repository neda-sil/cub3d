/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:57:24 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/23 13:55:15 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// ========= il faut tout mettre dans le gc plus tard ========= //
void	parsing(t_data *data)
{
	data->rycstng.x_dir = 0;
	data->rycstng.y_dir = 0;
	parse_textures(data);
	parse_colors(data);
	parse_map(data);
	data->screen_x = 1200;
	data->screen_y = 700;
}
