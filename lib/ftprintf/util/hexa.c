/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:15:54 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/25 21:40:59 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	hexa_len(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

static void	put_hexa(unsigned long nb, const char format)
{
	if (nb >= 16)
	{
		put_hexa(nb / 16, format);
		put_hexa(nb % 16, format);
	}
	else
	{
		if (nb < 10)
			ft_putnbr(nb);
		else
		{
			if (format == 'x')
				ft_putchar('a' + (nb - 10));
			else if (format == 'X')
				ft_putchar('A' + (nb - 10));
		}
	}
}

/*Permet d'afficher un nombre nb en hexadecimal*/
int	print_hexa(unsigned long nb, const char format)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else
		put_hexa(nb, format);
	return (hexa_len(nb));
}
