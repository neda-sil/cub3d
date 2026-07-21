#include "../../includes/cub3d.h"

void	handle_no_events(t_data *data)
{
	(void)data;
	return;
}

void	init_mlx(t_data *data, t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1000, "test keys");
	mlx_loop_hook(mlx->win_ptr, (t_fn)(intptr_t)&handle_no_events, data);
	mlx_hook(mlx->win_ptr, DestroyNotify, 0, (t_fn)(intptr_t)mlx_exit, data);
	mlx_loop(mlx->mlx_ptr);
}