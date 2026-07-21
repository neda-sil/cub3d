/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:35:04 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/21 14:42:35 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Defaults */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>

/* Useful */
# include "../lib/lib.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Project specifics */
# include "includes_h/gc.h"
# include "includes_h/structs.h"
# include "includes_h/parsing.h"
# include "includes_h/minilx.h"

/* Exit */
void	handle_exit(t_data *data, char *message);
int		*mlx_exit(t_data *data);


#endif