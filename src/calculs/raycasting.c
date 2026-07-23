#include "../../includes/cub3d.h"

void	print_calculs(t_ryct *ray)
{
	// printf("x_player = %f \n", ray->x_player);
	// printf("y_player = %f \n", ray->y_player);
	// printf("x_dir_player = %f \n", ray->x_dir);
	// printf("y_dir_player = %f \n", ray->y_dir);
	// printf("x_map = %f \n", ray->x_map);
	// printf("y_map = %f \n", ray->y_map);
	// printf("x_camera = %f \n", ray->x_camera);
	// printf("y_camera = %f \n", ray->y_camera);
	// printf("camera angle = %f \n", ray->camera_angle);
	// printf("x_dir_ray = %f \n", ray->x_dir_ray);
	printf("y_dir_ray = %f \n", ray->y_dir_ray);
}

void	check_wall(t_data *data, t_ryct	*ray)
{
	if (data
}

void	init_ray(t_data *data, t_ryct	*ray)
{
	ray->x_map = ft_abs_double(ray->x_player);
	ray->y_map = ft_abs_double(ray->y_player);
	ray->x_dir_ray = ray->x_dir + ray->x_camera * ray->camera_angle;
	ray->y_dir_ray = ray->y_dir + ray->y_camera * ray->camera_angle;
	ray->x_potential_length = 1/ray->x_dir_ray;
	ray->y_potential_length = 1/ray->y_dir_ray;
	if (ray->x_dir_ray < 0)
		ray->x_next_square = (ray->x_player - ray->x_map) * ray->x_potential_length;
	else 
		ray->x_next_square = (ray->x_map + 1 - ray->x_player) * ray->x_potential_length;
	if (ray->y_dir_ray < 0)
		ray->y_next_square = (ray->y_player - ray->y_map) * ray->y_potential_length;
	else 
		ray->y_next_square = (ray->y_map + 1 - ray->y_player) * ray->y_potential_length;
	check_wall(data, ray);
	print_calculs(ray);
}

void	init_calculs(t_data *data, t_ryct *ray)
{
	double	i;

	i = 0;
	ray->x_camera = (-ray->y_dir) * 0.80;
	ray->y_camera = (ray->x_dir) * 0.80;
	while (i <= data->screen_x)
	{
		ray->camera_angle = 2 * i / data->screen_x - 1;
		init_ray(data, ray);
		i++;
	}
}