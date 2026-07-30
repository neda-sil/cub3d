/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_destroy_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:17:56 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/30 13:39:38 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	make_img(t_data *data, char *filename, t_txtr *txtr)
{
	txtr->img = mlx_xpm_file_to_image(data->mlx.mlx_ptr, filename,
			&txtr->width, &txtr->height);
	txtr->addr = mlx_get_data_addr(txtr->img, &txtr->bpp, &txtr->line_len,
			&txtr->endian);
}

void	destroy_imgs(t_mlx *mlx, t_txtr *txtr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (txtr->img)
			mlx_destroy_image(mlx->mlx_ptr, txtr[i].img);
		i++;
	}
}

void	load_txtr(t_data *data, bool destroy)
{
	if (destroy == true)
		destroy_imgs(&data->mlx, data->txtr);
	make_img(data, data->no, &data->txtr[0]);
	make_img(data, data->so, &data->txtr[1]);
	make_img(data, data->we, &data->txtr[2]);
	make_img(data, data->ea, &data->txtr[3]);
}
