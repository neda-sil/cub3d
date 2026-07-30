/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:50:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/07/30 11:51:39 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILX_H
# define MINILX_H

void	destroy_imgs(t_mlx *mlx, t_txtr *txtr);
void	init_mlx(t_data *data, t_mlx *mlx);
void	load_txtr(t_data *data, bool destroy);
void	put_pixel_to_img(t_mlx *mlx, t_data *data, int x, int y, int color);

/* manage inputs */
void	handle_no_events(t_data *data);
void	key_input(int kp, t_data *data);
void	turn_left(t_ryct *ray);
void	turn_right(t_ryct *ray);
void	key_release(int kp, t_data *data);


/* movements */
void	advance(t_data *data, t_ryct *ray);
void	go_back(t_data *data, t_ryct *ray);
void	go_left(t_data *data, t_ryct *ray);
void	go_right(t_data *data, t_ryct *ray);


#endif