/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:47:02 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/14 07:09:48 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copie 'src' dans 'dst'*/
size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	res;

	res = ft_strlen(src);
	if (n == 0)
		return (res);
	i = 0;
	while (i < n - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}
