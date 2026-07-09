/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:53:37 by malaimo           #+#    #+#             */
/*   Updated: 2026/07/09 14:36:41 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_lstadd_gc(t_gc **gc, void *content)
{
	t_gc	*new;

	new = malloc(sizeof(t_gc));
	if (!new)
		return (1);
	new->content = content;
	new->previous = NULL;
	new->next = *gc;
	if (*gc)
		(*gc)->previous = new;
	*gc = new;
	return (0);
}
