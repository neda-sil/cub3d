/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:50:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/07/29 13:00:16 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILX_H
# define MINILX_H

void	destroy_imgs(t_mlx *mlx, t_txtr *txtr);
void	init_mlx(t_data *data, t_mlx *mlx);
void	load_txtr(t_data *data, bool destroy);
void	put_pixel_to_img(t_mlx *mlx, t_data *data, int x, int y, int color);

#endif