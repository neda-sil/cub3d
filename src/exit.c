/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:11:19 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/24 13:04:22 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_exit(t_data *data, char *message)
{
	ft_free_all_gc(&data->gc);
	close(data->fd);
	free(data);
	if (message)
	{
		ft_printf("%s", message);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
int	*mlx_exit(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	handle_exit(data, NULL);
	return (0);
}