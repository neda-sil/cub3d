/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:50:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/07/28 11:54:15 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILX_H
# define MINILX_H

void	destroy_imgs(t_data *data, t_mlx *mlx);
void	init_mlx(t_data *data, t_mlx *mlx);
void	make_img(t_data *data, bool destroy, int width, int height);

#endif