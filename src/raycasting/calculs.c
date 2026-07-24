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
		if (ray->y_next_square <= ray->x_next_square)
		{
			ray->y_map += ray->y_guide;
			ray->y_next_square += ray->y_length;
			direction = 0;
		}
		else
		{
			ray->x_map += ray->x_guide;
			ray->x_next_square += ray->x_length;
			direction = 1;
		}
		if (check_wall(data, ray->y_map, ray->x_map))
			break;
	}
	return (direction);
}

double	get_wall_height(t_data *data, t_ryct *ray)
{
	double	height_wall;
	double	dist_wall;
	int		direction; 

	direction = advance_ray(data, ray);
	if (direction == 0)
		dist_wall = ray->y_next_square - ray->y_length;
	else
		dist_wall = ray->x_next_square - ray->x_length;
	printf("wall met at [%d][%d] : ", ray->y_map, ray->x_map);
	height_wall = data->screen_y / dist_wall;
	if (height_wall >= data->screen_y)
		height_wall = data->screen_y - 1;
	return (height_wall);
}

double	launch_ray(t_data *data, t_ryct	*ray)
{
	ray->x_length = fabs(1/ray->x_dir_ray);
	ray->y_length = fabs(1/ray->y_dir_ray);
	if (ray->x_dir_ray < 0)
	{
		ray->x_guide = -1;
		ray->x_next_square = (ray->x_player - (double)ray->x_map) * ray->x_length;
	}
	else
	{
		ray->x_guide = 1;
		ray->x_next_square = ((double)ray->x_map + 1.0 - ray->x_player) * ray->x_length;
	}
	if (ray->y_dir_ray < 0)
	{
		ray->y_guide = -1;
		ray->y_next_square = (ray->y_player - (double)ray->y_map) * ray->y_length;
	}
	else
	{
		ray->y_guide = 1;
		ray->y_next_square = ((double)ray->y_map + 1.0 - ray->y_player) * ray->y_length;
	}
	// print_calculs(ray);
	return (get_wall_height(data, ray));
}
