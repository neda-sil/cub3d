#include "../../includes/cub3d.h"

void	launch_raycasting(t_data *data, t_ryct *ray)
{
	int	i;

	i = 0;
	ray->x_camera = (-ray->y_dir) * 0.7;
	ray->y_camera = (ray->x_dir) * 0.7;
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
		printf("wall height = %f\n", data->height_wall);
		i += 3;
	}
}