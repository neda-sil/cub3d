/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:11:19 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/12 14:36:11 by neda-sil         ###   ########.fr       */
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
		close(0);
		close(1);
		close(2);
		exit(EXIT_FAILURE);
	}
	close(0);
	close(1);
	close(2);
	exit(EXIT_SUCCESS);
}