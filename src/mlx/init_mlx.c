/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:19:39 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/29 10:29:23 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_no_events(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img_ptr, 0, 0);
	return;
}

void	key_input(int kp, t_data *data)
{
	if (kp == XK_Escape)
		mlx_exit(data);
	return;
}

void	init_mlx(t_data *data, t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, data->screen_x, data->screen_y, "test keys");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, data->screen_x, data->screen_y);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->line_len, &mlx->endian);
	int y = 0;
	//temporaire
	while (y < data->screen_y)
	{
		int x = 0;
		while (x < data->screen_x)
		{
			if (y < data->screen_y / 2)
				put_pixel_to_img(mlx, data, x, y, data->ceiling_color);
			else
				put_pixel_to_img(mlx, data, x, y, data->floor_color);
			x++;
		}
		y++;
	}

	mlx_loop_hook(mlx->mlx_ptr, (t_fn)(intptr_t)&handle_no_events, data);
	mlx_hook(mlx->win_ptr, DestroyNotify, 0, (t_fn)(intptr_t)mlx_exit, data);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, (t_fn)(intptr_t)key_input, data);
	mlx_loop(mlx->mlx_ptr);
}
