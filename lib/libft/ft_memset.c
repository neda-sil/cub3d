/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:36:32 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 14:38:43 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Place la valeur 'c' à l'adresse 's' un nombre 'n' de fois*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (n > SIZE_MAX && !s)
		return (NULL);
	ptr = (unsigned char *)s;
	while (n--)
		*(ptr++) = (unsigned char)c;
	return (s);
}
