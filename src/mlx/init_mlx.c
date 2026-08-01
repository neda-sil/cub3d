/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:07:42 by malaimo           #+#    #+#             */
/*   Updated: 2026/08/01 22:23:23 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx(t_data *data, t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, data->screen_x,
			data->screen_y, "test keys");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, data->screen_x, data->screen_y);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->line_len, &mlx->endian);
	load_txtr(data, false);
	launch_raycasting(data, &data->rycstng);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img_ptr, 0, 0);
	mlx_loop_hook(mlx->mlx_ptr, (t_fn)(intptr_t) & handle_no_events, data);
	mlx_hook(mlx->win_ptr, DestroyNotify, 0, (t_fn)(intptr_t)mlx_exit,
		data);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, (t_fn)(intptr_t)key_input,
		data);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask,
		(t_fn)(intptr_t)key_release, data);
	mlx_loop(mlx->mlx_ptr);
}
