/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:36:28 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 14:38:42 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Deplace un nombre 'n' de l'adresse 'src' a l'adresse 'dst'*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*source;
	char	*dest;

	source = (char *)src;
	dest = (char *)dst;
	if (source < dest)
		while (n--)
			dest[n] = source[n];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
