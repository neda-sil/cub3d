/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:15:41 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/25 21:38:35 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* Verifie le type demande par le % du ft_printf
 * et renvoi vers la bonne configuration à attribuer*/
int	find_type(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count = print_adress(va_arg(args, unsigned long *));
	else if (c == 'd')
		count = ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		count = ft_putnbr(va_arg(args, long));
	else if (c == 'u')
		count = ft_putunsigned(va_arg(args, unsigned long));
	else if (c == 'x' || c == 'X')
		count = print_hexa(va_arg(args, unsigned), c);
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}
