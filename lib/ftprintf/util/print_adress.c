/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:15:59 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/25 21:41:20 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*verifie que le nb donne ne soit pas NULL (au quel cas il renvoie "(nil)"
 * puis utilise print_hexa en utilisant le format hexa*/

int	print_adress(unsigned long *nb)
{
	if (!nb)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + print_hexa((unsigned long)nb, 'x'));
}
