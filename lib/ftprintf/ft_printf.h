/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:16:03 by neda-sil          #+#    #+#             */
/*   Updated: 2026/01/13 13:22:36 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		find_type(char c, va_list args);
int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putunsigned(unsigned int nb);
int		ft_putnbr(long nb);
int		ft_putstr(char *str);
char	*ft_unsigned_itoa(unsigned int n);
int		print_adress(unsigned long *nb);
int		print_hexa(unsigned long nb, const char format);

#endif
