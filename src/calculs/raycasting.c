#include "../../includes/cub3d.h"

void	print_calculs(t_ryct ray)
{
	printf("x_player = %f \n", ray.x_player);
	printf("y_player = %f \n", ray.y_player);
	printf("x_map = %f \n", ray.x_player);
	printf("y_map = %f \n", ray.y_player);
}

void	init_ray(t_ryct	ray)
{
	ray.x_map = ft_abs_double(ray.x_player);
	ray.y_map = ft_abs_double(ray.y_player);
	ray.x_dir_ray = ray.x_dir + ray.x_camera * ray.camera_angle;
	ray.y_dir_ray = ray.y_dir + ray.y_camera * ray.camera_angle;
	print_calculs(ray);
}

void	init_calculs(t_data *data, t_ryct ray)
{
	int	i;

	i = 0;
	ray.x_camera = (-ray.y_dir) * 0.80;
	ray.y_camera = (ray.x_dir) * 0.80;
	while (i < data->screen_x)
	{
		ray.camera_angle = 2 * x / data->screen_x - 1;
		init_ray(ray);
		i++;
	}
}