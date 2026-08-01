/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:29:56 by neda-sil          #+#    #+#             */
/*   Updated: 2026/08/01 22:36:25 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_tex_x(t_data *data, t_ryct *ray)
{
	data->txtr->tex_x = (int)(ray->wall_x * data->txtr[ray->face].width);
	if (data->txtr->tex_x < 0)
		data->txtr->tex_x = 0;
	if (data->txtr->tex_x >= data->txtr[ray->face].width)
		data->txtr->tex_x = data->txtr[ray->face].width - 1;
}

static void	draw_background(t_data *data, t_ryct *ray, t_txtr *txtr, int i)
{
	int	start;
	int	end;
	int	y;
	int	tex_y;
	int	color;

	start = data->screen_y / 2 - data->height_wall / 2;
	if (start < 0)
		start = 0;
	end = data->screen_y / 2 + data->height_wall / 2;
	if (end >= data->screen_y)
		end = data->screen_y;
	calculate_tex_x(data, ray);
	y = 0;
	while (y < start)
		put_pixel_to_img(data, i, y++, data->ceiling_color);
	while (y < end)
	{
		tex_y = (int)(((y - (data->screen_y / 2 - data->height_wall / 2))
					/ data->height_wall) * txtr[ray->face].height);
		color = get_pixel_from_txtr(&txtr[ray->face], txtr->tex_x, tex_y);
		put_pixel_to_img(data, i, y++, color);
	}
	while (y < data->screen_y)
		put_pixel_to_img(data, i, y++, data->floor_color);
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
		draw_background(data, ray, data->txtr, i);
		// printf("wall height = %f\n", data->height_wall);
		i++;
	}
}
