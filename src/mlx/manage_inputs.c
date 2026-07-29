/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:07:49 by malaimo           #+#    #+#             */
/*   Updated: 2026/07/29 14:47:23 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(t_ryct *ray)
{
	double	x_temp;

	x_temp = ray->x_dir * cos(-0.1) - ray->y_dir * sin(-0.1);
	ray->y_dir = ray->x_dir * sin(-0.1) + ray->y_dir * cos(-0.1);
	ray->x_dir = x_temp;
	x_temp = ray->x_camera * cos(-0.1) - ray->y_camera * sin(-0.1);
	ray->y_camera = ray->x_camera * sin(-0.1) + ray->y_camera * cos(-0.1);
	ray->x_camera = x_temp;
	// printf("player look at [%f][%f], camera look at [%f][%f]\n", ray->x_dir, ray->y_dir, ray->x_camera, ray->y_camera);
}

void	turn_right(t_ryct *ray)
{
	double	x_temp;

	x_temp = ray->x_dir * cos(0.1) - ray->y_dir * sin(0.1);
	ray->y_dir = ray->x_dir * sin(0.1) + ray->y_dir * cos(0.1);
	ray->x_dir = x_temp;
	x_temp = ray->x_camera * cos(0.1) - ray->y_camera * sin(0.1);
	ray->y_camera = ray->x_camera * sin(0.1) + ray->y_camera * cos(0.1);
	ray->x_camera = x_temp;
	// printf("player look at [%f][%f], camera look at [%f][%f]\n", ray->x_dir, ray->y_dir, ray->x_camera, ray->y_camera);
}

void	key_input(int kp, t_data *data)
{
	if (kp == XK_Escape)
		mlx_exit(data);
	if (kp == XK_Left)
		turn_left(&data->rycstng);
	if (kp == XK_Right)
		turn_right(&data->rycstng);
	if (kp == XK_w)
		advance(data, &data->rycstng);
	if (kp == XK_s)
		go_back(data, &data->rycstng);
	if (kp == XK_a)
		go_left(data, &data->rycstng);
	if (kp == XK_d)
		go_right(data, &data->rycstng);
	launch_raycasting(data, &data->rycstng);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img_ptr, 0, 0);
	return;
}

void	key_release(int kp, t_data *data)
{
	if (kp == XK_Escape)
		mlx_exit(data);
	if (kp == XK_Left)
		turn_left(&data->rycstng);
	if (kp == XK_Right)
		turn_right(&data->rycstng);
	if (kp == XK_w)
		advance(data, &data->rycstng);
	if (kp == XK_s)
		go_back(data, &data->rycstng);
	if (kp == XK_a)
		go_left(data, &data->rycstng);
	if (kp == XK_d)
		go_right(data, &data->rycstng);
	// launch_raycasting(data, &data->rycstng);
	return;
}
