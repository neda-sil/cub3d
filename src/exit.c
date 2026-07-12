/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:11:19 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/12 16:09:34 by neda-sil         ###   ########.fr       */
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