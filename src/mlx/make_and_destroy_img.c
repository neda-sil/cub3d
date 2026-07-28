/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_destroy_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:17:56 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/28 11:34:05 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	make_img(t_data *data, bool destroy)
{
	if (destroy == true)
		destroy_imgs(data->imgs);
}
