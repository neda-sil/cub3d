/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:13:59 by neda-sil          #+#    #+#             */
/*   Updated: 2026/08/01 22:20:27 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_pixel_from_txtr(t_txtr *txtr, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= txtr->width || y < 0 || y >= txtr->height)
		return (0);
	pixel = txtr->addr + (y * txtr->line_len) + (x * (txtr->bpp / 8));
	return (*(int *)pixel);
}

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= data->screen_x || y < 0 || y >= data->screen_y)
		return ;
	pixel = data->mlx.addr + (y * data->mlx.line_len)
		+ (x * (data->mlx.bpp / 8));
	*(int *)pixel = color;
}
