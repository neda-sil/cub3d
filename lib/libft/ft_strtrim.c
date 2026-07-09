/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:47:42 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/14 07:18:43 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_set(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*Supprime les caracteres dans 'set' du début et de la fin de la chaîne 's'*/
char	*ft_strtrim(const char *s, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new;

	if (!ft_strlen(s) || !set)
		return (ft_strdup(s));
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && verif_set(s[start], set))
		start++;
	while (end >= start && verif_set(s[end], set))
		end--;
	new = malloc(sizeof(char) * (end - start + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
