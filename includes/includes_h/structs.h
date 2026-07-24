/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:00:14 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/24 11:28:36 by malaimo          ###   ########.fr       */
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
# define UNIDENTIFIED_CHAR_MAP "Error: unidentified character in the map\n"
# define UNIDENTIFIED_CHAR_TEXTURE "Error: unidentified character in the textures\n"
# define WRONG_RANGE "Error: wrong color range (must be between 0 and 255)\n"
# define WRONG_ORDER_TEXTURE "Error: wrong params order for textures\n"
# define WRONG_ORDER_COLOR "Error: wrong params order for colors\n"
# define MULTIPLE_START "Error: multiple starting points in the map\n"
# define CONSECUTIVE_NEWLINES "Error: consecutive newlines (check the last lines)\n"
# define NO_PLAYER "Error: no player in map\n"

typedef int	(*t_fn)(void);

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

typedef struct s_ryct
{
	double	x_dir;
	double	y_dir;
	double	x_player;
	double	y_player;
	double	x_camera;
	double	y_camera;
	double	camera_angle;
	int		x_map;
	int		y_map;
	double	x_dir_ray;
	double	y_dir_ray;
	double	x_length;
	double	y_length;
	double	x_next_square;
	double	y_next_square;
	int		x_guide;
	int		y_guide;
}			t_ryct;


/* Main struct */
typedef struct s_data
{
	int		fd;
	char	*no;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
	char	**map;
	int		screen_x;
	int		screen_y;
	t_gc	*gc;
	t_mlx	mlx;
	t_ryct	rycstng;
}			t_data;

#endif