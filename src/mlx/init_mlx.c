/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:07:42 by malaimo           #+#    #+#             */
/*   Updated: 2026/07/28 15:07:43 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_no_events(t_data *data)
{
	(void)data;
	return;
}

void	init_mlx(t_data *data, t_mlx *mlx)
{
	printf("player is at [%f][%f]", data->rycstng.y_player, data->rycstng.x_player);
	printf("player look at [%f][%f], camera look at [%f][%f]\n", data->rycstng.x_dir, data->rycstng.y_dir, data->rycstng.x_camera, data->rycstng.y_camera);
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, data->screen_x, data->screen_y, "test keys");
	mlx_loop_hook(mlx->win_ptr, (t_fn)(intptr_t)&handle_no_events, data);
	mlx_hook(mlx->win_ptr, DestroyNotify, 0, (t_fn)(intptr_t)mlx_exit, data);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, (t_fn)(intptr_t)key_input, data);
	mlx_loop(mlx->mlx_ptr);
}
