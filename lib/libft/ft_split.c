/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:37:27 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/18 17:02:30 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free_tab(char **tab, int size)
{
	while (size--)
		free(tab[size]);
	free(tab);
	return (-1);
}

static size_t	ft_words_nbr(const char *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i + 1] == c || !str[i + 1])
			if (!(str[i] == c || !str[i]))
				words++;
		i++;
	}
	return (words);
}

static void	ft_putword(char *dst, const char *src, char c)
{
	size_t	i;

	i = 0;
	while (!(src[i] == c || !src[i]))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static int	ft_split_words(char **tab, const char *str, char c)
{
	int	i;
	int	j;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c || !str[i])
			i++;
		else
		{
			j = 0;
			while (!(str[i + j] == c || !str[i + j]))
				j++;
			tab[words] = malloc(sizeof(char) * (j + 1));
			if (!tab[words])
				return (ft_free_tab(tab, words));
			ft_putword(tab[words], str + i, c);
			i += j;
			words++;
		}
	}
	return (0);
}

/*Alloue de la mémoire pour y placer la chaîne 's' en utilisant
**le charactère 'c' pour la séparer*/
char	**ft_split(const char *s, char c)
{
	char	**tab;
	size_t	words;

	words = ft_words_nbr(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	if (ft_split_words(tab, s, c) == -1)
		return (NULL);
	return (tab);
}
