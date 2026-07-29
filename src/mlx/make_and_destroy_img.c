/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_destroy_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:17:56 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/29 12:43:49 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_imgs(t_data *data, t_mlx *mlx)
{
}

void	make_img(t_data *data, bool destroy, t_txtr *txtr,
	int width, int height)
{
	if (destroy == true)
		destroy_imgs(data, &data->mlx);
	txtr->img = mlx_xpm_file_to_image(&data->mlx.mlx_ptr, data->no,
		&width, &height);
	txtr->addr = mlx_get_data_addr(txtr->img, &txtr->bpp, &txtr->line_len,
		&txtr->endian);
}
