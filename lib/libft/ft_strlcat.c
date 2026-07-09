/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:46:55 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/08 17:54:27 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Ajoute la chaine 'src' a la fin de 'dst'*/
size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	i = ft_strlen(dst);
	j = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (n < 1)
		return (len_src);
	while (src[j] && i < n - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (n < len_dst)
		return (len_src + n);
	else
		return (len_dst + len_src);
}
