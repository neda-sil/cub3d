/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:07:49 by malaimo           #+#    #+#             */
/*   Updated: 2026/07/30 11:57:09 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	handle_no_events(t_data *data)
{
	data->rycstng.moved = 0;
	if (data->mov.press_left)
		turn_left(&data->rycstng);
	if (data->mov.press_right)
		turn_right(&data->rycstng);
	if (data->mov.press_w)
		advance(data, &data->rycstng);
	if (data->mov.press_s)
		go_back(data, &data->rycstng);
	if (data->mov.press_a)
		go_left(data, &data->rycstng);
	if (data->mov.press_d)
		go_right(data, &data->rycstng);
	if (data->rycstng.moved)
	{
		launch_raycasting(data, &data->rycstng);
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
			data->mlx.img_ptr, 0, 0);
	}
}

void	turn_left(t_ryct *ray)
{
	double	x_temp;

	x_temp = ray->x_dir * cos(-0.01) - ray->y_dir * sin(-0.01);
	ray->y_dir = ray->x_dir * sin(-0.01) + ray->y_dir * cos(-0.01);
	ray->x_dir = x_temp;
	x_temp = ray->x_camera * cos(-0.01) - ray->y_camera * sin(-0.01);
	ray->y_camera = ray->x_camera * sin(-0.01) + ray->y_camera * cos(-0.01);
	ray->x_camera = x_temp;
	ray->moved = 1;
	// printf("player look at [%f][%f], camera look at [%f][%f]\n", ray->x_dir, ray->y_dir, ray->x_camera, ray->y_camera);
}

void	turn_right(t_ryct *ray)
{
	double	x_temp;

	x_temp = ray->x_dir * cos(0.01) - ray->y_dir * sin(0.01);
	ray->y_dir = ray->x_dir * sin(0.01) + ray->y_dir * cos(0.01);
	ray->x_dir = x_temp;
	x_temp = ray->x_camera * cos(0.01) - ray->y_camera * sin(0.01);
	ray->y_camera = ray->x_camera * sin(0.01) + ray->y_camera * cos(0.01);
	ray->x_camera = x_temp;
	ray->moved = 1;
	// printf("player look at [%f][%f], camera look at [%f][%f]\n", ray->x_dir, ray->y_dir, ray->x_camera, ray->y_camera);
}

void	key_input(int kp, t_data *data)
{
	if (kp == XK_Escape)
		mlx_exit(data);
	if (kp == XK_Left)
		data->mov.press_left = 1;
	if (kp == XK_Right)
		data->mov.press_right = 1;
	if (kp == XK_w)
		data->mov.press_w = 1;
	if (kp == XK_s)
		data->mov.press_s = 1;
	if (kp == XK_a)
		data->mov.press_a = 1;
	if (kp == XK_d)
		data->mov.press_d = 1;
	return;
}

void	key_release(int kp, t_data *data)
{
	if (kp == XK_Escape)
		mlx_exit(data);
	if (kp == XK_Left)
		data->mov.press_left = 0;
	if (kp == XK_Right)
		data->mov.press_right = 0;
	if (kp == XK_w)
		data->mov.press_w = 0;
	if (kp == XK_s)
		data->mov.press_s = 0;
	if (kp == XK_a)
		data->mov.press_a = 0;
	if (kp == XK_d)
		data->mov.press_d = 0;
	// launch_raycasting(data, &data->rycstng);
	return;
}
