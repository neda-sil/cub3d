/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:50:24 by jdelmott          #+#    #+#             */
/*   Updated: 2026/07/24 13:15:50 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

/* raycasting */
void	launch_raycasting(t_data *data, t_ryct *ray);

/* calculs */
int		check_wall(t_data *data, int y, int x);
double	get_wall_height(t_data *data, t_ryct *ray);
double	launch_ray(t_data *data, t_ryct	*ray);

#endif