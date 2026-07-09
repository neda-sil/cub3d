/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:35:49 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 14:38:32 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Retourne 1 si le charactère est une affichable, 0 sinon*/
int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
