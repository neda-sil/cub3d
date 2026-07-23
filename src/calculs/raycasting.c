#include "../../includes/cub3d.h"

void	init_rays(t_ryct	ray)
{
	
}

void	init_calculs(t_data *data, t_ryct ray)
{
	ray.x_camera = (-ray.y_dir) * 0.80;
	ray.y_camera = (ray.x_dir) * 0.80;
	init_rays(ray);
}