/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:36:22 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 14:38:40 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copie un nombre 'n' de valeures de l'adresse 'src' a l'adresse 'dst'*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*source;

	i = 0;
	dst = (char *)dest;
	source = (char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}
