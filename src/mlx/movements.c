/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:07:52 by malaimo           #+#    #+#             */
/*   Updated: 2026/08/01 22:19:28 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	advance(t_data *data, t_ryct *ray)
{
	double	x;
	double	y;

	x = ray->x_player + ray->x_dir / 45;
	y = ray->y_player + ray->y_dir / 45;
	if (data->map[(int)y][(int)x] != '1'
		&& data->map[(int)y][(int)x] != ' ')
	{
		ray->x_player = ray->x_player + ray->x_dir / 50;
		ray->y_player = ray->y_player + ray->y_dir / 50;
		ray->moved = 1;
		// printf("player is now at [%f][%f]\n", ray->y_player, ray->x_player);
	}
}

void	go_back(t_data *data, t_ryct *ray)
{
	double	x;
	double	y;

	x = ray->x_player - ray->x_dir / 50;
	y = ray->y_player - ray->y_dir / 50;
	if (data->map[(int)y][(int)x] != '1'
		&& data->map[(int)y][(int)x] != ' ')
	{
		ray->x_player = x;
		ray->y_player = y;
		ray->moved = 1;
		// printf("player is now at [%f][%f]\n", ray->y_player, ray->x_player);
	}
}

void	go_left(t_data *data, t_ryct *ray)
{
	double	x;
	double	y;

	x = ray->x_player - ray->x_camera / 50;
	y = ray->y_player - ray->y_camera / 50;
	if (data->map[(int)y][(int)x] != '1' && data->map[(int)y][(int)x] != ' ')
	{
		ray->x_player = x;
		ray->y_player = y;
		ray->moved = 1;
		// printf("player is now at [%f][%f]\n", ray->y_player, ray->x_player);
	}
}

void	go_right(t_data *data, t_ryct *ray)
{
	double	x;
	double	y;

	x = ray->x_player + ray->x_camera / 50;
	y = ray->y_player + ray->y_camera / 50;
	if (data->map[(int)y][(int)x] != '1' && data->map[(int)y][(int)x] != ' ')
	{
		ray->x_player = x;
		ray->y_player = y;
		ray->moved = 1;
		// printf("player is now at [%f][%f]\n", ray->y_player, ray->x_player);
	}
}
