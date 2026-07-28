/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:50:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/07/28 15:01:11 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILX_H
# define MINILX_H

void	init_mlx(t_data *data, t_mlx *mlx);

/* manage inputs */
void	key_input(int kp, t_data *data);
void	turn_left(t_ryct *ray);
void	turn_right(t_ryct *ray);

/* movements */
void	advance(t_data *data, t_ryct *ray);
void	go_back(t_data *data, t_ryct *ray);
void	go_left(t_data *data, t_ryct *ray);
void	go_right(t_data *data, t_ryct *ray);


#endif