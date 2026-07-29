/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:29:56 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/29 14:03:29 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define WALL_COLOR_DEBUG 0xFFFFFF

static void	draw_background(t_data *data, int i)
{
	int	start;
	int	end;
	int	y;

	start = data->screen_y / 2 - data->height_wall / 2;
	if (start < 0)
		start = 0;
	end = data->screen_y / 2 + data->height_wall / 2;
	y = 0;
	while (y < start)
		put_pixel_to_img(&data->mlx, data, i, y++, data->ceiling_color);
	while (y < end)
		put_pixel_to_img(&data->mlx, data, i, y++, WALL_COLOR_DEBUG);
	while (y < data->screen_y)
		put_pixel_to_img(&data->mlx, data, i, y++, data->floor_color);
}

void	launch_raycasting(t_data *data, t_ryct *ray)
{
	int	i;

	i = 0;
	while (i <= data->screen_x)
	{
		ray->x_map = (int)(ray->x_player);
		ray->y_map = (int)(ray->y_player);
		ray->camera_angle = 2 * i / (double)data->screen_x - 1;
		ray->x_guide = 1;
		ray->y_guide = 1;
		ray->x_dir_ray = ray->x_dir + ray->x_camera * ray->camera_angle;
		ray->y_dir_ray = ray->y_dir + ray->y_camera * ray->camera_angle;
		data->height_wall = launch_ray(data, ray);
		draw_background(data, i);
		// printf("wall height = %f\n", data->height_wall);
		i++;
	}
}
