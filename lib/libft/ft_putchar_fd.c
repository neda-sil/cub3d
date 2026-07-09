/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:36:39 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 14:38:46 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Place le caractere 'c' dans le descripteur de fichier specifie*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
