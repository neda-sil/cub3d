/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:19:04 by neda-sil          #+#    #+#             */
/*   Updated: 2026/08/03 11:25:47 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	verif_imgs(t_data *data)
{
	int	fd;

	fd = open(data->no, O_RDONLY);
	if (fd <= 0)
		handle_exit(data, NO_IMG);
	close(fd);
	fd = open(data->so, O_RDONLY);
	if (fd <= 0)
		handle_exit(data, NO_IMG);
	close(fd);
	fd = open(data->we, O_RDONLY);
	if (fd <= 0)
		handle_exit(data, NO_IMG);
	close(fd);
	fd = open(data->ea, O_RDONLY);
	if (fd <= 0)
		handle_exit(data, NO_IMG);
	close(fd);
}
