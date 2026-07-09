/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:35:35 by neda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 14:38:28 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Retourne 1 si le charactère est dans la table ASCII, 0 sinon*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
