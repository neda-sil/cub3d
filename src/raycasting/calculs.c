/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:01:01 by malaimo           #+#    #+#             */
/*   Updated: 2026/08/03 13:02:47 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_wall(t_data *data, int y, int x)
{
	if (y < 0 || x < 0)
	{
		printf("valeur corrompu");
		exit (0);
	}
	if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'N' && data->map[y][x] != 'S'
				&& data->map[y][x] != 'W' && data->map[y][x] != 'E'
				&& data->map[y][x] != ' ' && data->map[y][x] != '\n')
	{
		printf("erreur map");
		exit (0);
	}
	if (data->map[y][x] == '1' || data->map[y][x] == ' ')
		return (1);
	else
		return (0);
}

int	advance_ray(t_data *data, t_ryct *ray)
{
	int	direction;

	while (1)
	{
		if (ray->y_nxs <= ray->x_nxs)
		{
			ray->y_map += ray->y_guide;
			ray->y_nxs += ray->y_length;
			direction = 0;
		}
		else
		{
			ray->x_map += ray->x_guide;
			ray->x_nxs += ray->x_length;
			direction = 1;
		}
		if (check_wall(data, ray->y_map, ray->x_map))
			break ;
	}
	return (direction);
}

double	get_wall_height(t_data *data, t_ryct *ray)
{
	double	height_wall;
	int		direction;

	direction = advance_ray(data, ray);
	ray->side = direction;
	if (direction == 0)
		ray->dist_wall = ray->y_nxs - ray->y_length;
	else
		ray->dist_wall = ray->x_nxs - ray->x_length;
	if (ray->side == 0)
		ray->wall_x = ray->x_player + ray->dist_wall * ray->x_dir_ray;
	else
		ray->wall_x = ray->y_player + ray->dist_wall * ray->y_dir_ray;
	ray->wall_x -= floor(ray->wall_x);
	if ((ray->side == 0 && ray->y_guide == 1)
		|| (ray->side == 1 && ray->x_guide == -1))
		ray->wall_x = 1.0 - ray->wall_x;
	height_wall = data->screen_y / ray->dist_wall;
	return (height_wall);
}

static void	know_side(t_ryct *ray)
{
	if (ray->side == 0 && ray->y_guide == -1)
		ray->face = NO;
	else if (ray->side == 0)
		ray->face = SO;
	else if (ray->x_guide == 1)
		ray->face = EA;
	else
		ray->face = WE;
}

double	launch_ray(t_data *data, t_ryct	*ray)
{
	ray->x_length = fabs(1 / ray->x_dir_ray);
	ray->y_length = fabs(1 / ray->y_dir_ray);
	if (ray->x_dir_ray < 0)
	{
		ray->x_guide = -1;
		ray->x_nxs = (ray->x_player - (double)ray->x_map) * ray->x_length;
	}
	else
	{
		ray->x_guide = 1;
		ray->x_nxs = ((double)ray->x_map + 1.0 - ray->x_player) * ray->x_length;
	}
	if (ray->y_dir_ray < 0)
	{
		ray->y_guide = -1;
		ray->y_nxs = (ray->y_player - (double)ray->y_map) * ray->y_length;
	}
	else
	{
		ray->y_guide = 1;
		ray->y_nxs = ((double)ray->y_map + 1.0 - ray->y_player) * ray->y_length;
	}
	know_side(ray);
	return (get_wall_height(data, ray));
}
