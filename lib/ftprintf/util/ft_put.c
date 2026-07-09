/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:15:46 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/25 21:39:41 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*Ce fichier entier est reserver aux impressions
 * ft_putchar  pour les caracteres uniques
 * ft_putstr pour les chaines de caracteres
 * ft_putnbr pour convertir les int en char * et les imprimer*/

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		count += ft_putchar(str[count]);
		i++;
	}
	return (count);
}

int	ft_putnbr(long nb)
{
	int		count;
	char	*str;

	str = ft_itoa(nb);
	if (!str)
		return (-1);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	ft_putunsigned(unsigned int nb)
{
	int		count;
	char	*str;

	str = ft_unsigned_itoa(nb);
	if (!str)
		return (-1);
	count = ft_putstr(str);
	free(str);
	return (count);
}
