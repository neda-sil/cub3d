/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:35:04 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/12 14:21:45 by neda-sil         ###   ########.fr       */
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

/* Usefulls */
# include "../lib/lib.h"
# include "../minilibx-linux/mlx.h"

/* Project specifics */
# include "includes_h/gc.h"
# include "includes_h/structs.h"
# include "includes_h/parsing.h"

void	handle_exit(t_data *data, char *message);

#endif