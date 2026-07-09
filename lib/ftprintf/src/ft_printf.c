/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:15:35 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/28 15:29:02 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*Prend une string et un nombre invariable d'arguments*/
int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += find_type(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	n = -1;
// 	ft_printf("\ncount p : %d\n", ft_printf("%p\n", &n));
// 	ft_printf("\ncount d : %d\n", ft_printf("%d %d %d %d\n",
// 		125, -125, INT_MIN, INT_MAX));
// 	ft_printf("\ncount i : %d\n", ft_printf("%i %i %i %i %i %i\n",
// 		125, -125, 0x10, 010, INT_MIN, INT_MAX));
// 	ft_printf("\ncount s : %d\n", ft_printf("%s %s\n",
// 		"", "je ne sais pas"));
// 	ft_printf("\ncount c : %d\n", ft_printf("%c %c %c %c\n",
// 		'a', 'c', 90, 0x30));
// 	ft_printf("\ncount x : %d\n", ft_printf("%x %x %x %x \n",
// 		125, -125, INT_MAX, INT_MIN));
// 	ft_printf("\ncount X : %d\n", ft_printf("%X %X %X %X \n",
// 		125, -125, INT_MAX, INT_MIN));
// 	ft_printf("\ncount %% : %d\n", ft_printf("%% %% %% %%\n"));
// }