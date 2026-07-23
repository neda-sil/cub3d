#include "../../includes/cub3d.h"

void	init_ray(t_ryct	ray)
{
	
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
	}
	init_rays(ray);
}