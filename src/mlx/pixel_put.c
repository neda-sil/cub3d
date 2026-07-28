/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:13:59 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/28 14:17:32 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel_to_img(t_mlx *mlx, t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= data->screen_x || y < 0 || y >= data->screen_y)
		return ;
	pixel = mlx->addr + (y * mlx->line_len) + (x * (mlx->bpp / 8));
	*(int *)pixel = color;
}
