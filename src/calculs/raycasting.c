#include "../../includes/cub3d.h"

void	print_calculs(t_ryct *ray)
{
	printf("\nx_player = %f \n", ray->x_player);
	printf("y_player = %f \n", ray->y_player);

	printf("x_dir_player = %f \n", ray->x_dir);
	printf("y_dir_player = %f \n", ray->y_dir);

	printf("x_map = %d \n", ray->x_map);
	printf("y_map = %d \n", ray->y_map);

	printf("x_camera = %f \n", ray->x_camera);
	printf("y_camera = %f \n", ray->y_camera);
	printf("camera angle = %f \n", ray->camera_angle);

	printf("x_dir_ray = %f \n", ray->x_dir_ray);
	printf("y_dir_ray = %f \n", ray->y_dir_ray);

	printf("x_length = %f \n", ray->x_length);
	printf("y_length = %f \n", ray->y_length);

	printf("x_next_square = %f \n", ray->x_next_square);
	printf("y_next_square = %f \n", ray->y_next_square);
}

int		check_wall(t_data *data, int y, int x)
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
	if (data->map[y][x] == '1')
		return (1);
	else 
		return (0);
}

void	calculate_distance_wall(t_data *data, t_ryct *ray)
{
	(void)data;
	(void)ray;
	return ;
}

void	advance_ray(t_data *data, t_ryct *ray)
{
	int		is_wall;

	is_wall = 0;
	while (is_wall == 0)
	{
		if (ray->y_next_square <= ray->x_next_square)
		{
			ray->y_map += ray->y_guide;
			is_wall = check_wall(data, ray->y_map, ray->x_map);
			ray->y_next_square += ray->y_length;
		}
		else
		{
			ray->x_map += ray->x_guide;
			is_wall = check_wall(data, (int)ray->y_map, (int)ray->x_map);
			ray->x_next_square += ray->x_length;
		}
	}
	printf("wall found in [%d][%d]\n", ray->y_map, ray->x_map);
}

void	init_ray(t_data *data, t_ryct	*ray)
{
	ray->x_map = (int)(ray->x_player);
	ray->y_map = (int)(ray->y_player);
	ray->x_dir_ray = ray->x_dir + ray->x_camera * ray->camera_angle;
	ray->y_dir_ray = ray->y_dir + ray->y_camera * ray->camera_angle;
	ray->x_length = fabs(1/ray->x_dir_ray);
	ray->y_length = fabs(1/ray->y_dir_ray);
	if (ray->x_dir_ray < 0)
	{
		ray->x_guide = -1;
		ray->x_next_square = fabs((ray->x_player - ray->x_map) * ray->x_length);
	}
	else 
		ray->x_next_square = (ray->x_map + 1 - ray->x_player) * ray->x_length;
	if (ray->y_dir_ray < 0)
	{
		ray->y_guide = -1;
		ray->y_next_square = (ray->y_player - ray->y_map) * ray->y_length;
	}
	else 
		ray->y_next_square = (ray->y_map + 1 - ray->y_player) * ray->y_length;
	(void)data;
	// print_calculs(ray);
	advance_ray(data, ray);
}

void	init_calculs(t_data *data, t_ryct *ray)
{
	double	i;

	i = 0;
	ray->x_camera = (-ray->y_dir) * 0.7;
	ray->y_camera = (ray->x_dir) * 0.7;
	while (i <= data->screen_x)
	{
		ray->camera_angle = 2 * i / data->screen_x - 1;
		ray->x_guide = 1;
		ray->y_guide = 1;
		init_ray(data, ray);
		i += 1;
	}
}