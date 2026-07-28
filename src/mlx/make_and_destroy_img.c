/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_destroy_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:17:56 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/28 11:55:07 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_imgs(t_data *data, t_mlx *mlx)
{
	if (data->imgs->no_img)
		mlx_destroy_image(mlx->mlx_ptr, data->imgs->no_img);
	if (data->imgs->so_img)
		mlx_destroy_image(mlx->mlx_ptr, data->imgs->so_img);
	if (data->imgs->we_img)
		mlx_destroy_image(mlx->mlx_ptr, data->imgs->we_img);
	if (data->imgs->ea_img)
		mlx_destroy_image(mlx->mlx_ptr, data->imgs->ea_img);
}

void	make_img(t_data *data, bool destroy, int width, int height)
{
	if (destroy == true)
		destroy_imgs(data, data->mlx.mlx_ptr);
	data->imgs->no_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,data->no,
		&width, &height);
	data->imgs->so_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,data->SO,
		&width, &height);
	data->imgs->we_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,data->WE,
		&width, &height);
	data->imgs->ea_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,data->EA,
		&width, &height);
}
