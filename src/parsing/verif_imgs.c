/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:19:04 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/28 11:31:04 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	verif_imgs(t_data *data)
{
	int	*fd;

	fd = open(data->no, O_RDONLY);
	if (!fd)
		handle_exit(data, NO_IMG);
	close(fd);
	fd = open(data->SO, O_RDONLY);
	if (!fd)
		handle_exit(data, NO_IMG);
	close(fd);
	fd = open(data->WE, O_RDONLY);
	if (!fd)
		handle_exit(data, NO_IMG);
	close(fd);
	fd = open(data->EA, O_RDONLY);
	if (!fd)
		handle_exit(data, NO_IMG);
	close(fd);
}
