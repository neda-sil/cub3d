/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:00:14 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/12 14:45:36 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Caracters identifiers */
# define WALL '1'
# define FLOOR '0'
# define EMPTY ' '
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

/* Error messages */
# define ARG_ERROR "Error: need one and only one arg\n"
# define NOT_FOUND "Error: no such file or directory\n"
# define MALLOC_ERROR "Error: malloc failed\n"
# define MAP_EXTENSION "Error: wrong map extension\n"
# define TEXTURE_EXTENSION "Error: wrong texture extension\n"
# define BORDER_ERROR "Error: opened border\n"
# define UNIDENTIFIED_CHAR "Error: unidentified character in the map\n"

/* Main struct */
typedef struct s_data
{
	int		fd;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
	char	**map;
	t_gc	*gc;
}			t_data;

#endif