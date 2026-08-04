/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:00:14 by neda-sil          #+#    #+#             */
/*   Updated: 2026/08/04 22:31:53 by neda-sil         ###   ########.fr       */
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

/* Textures */
# define NO	0
# define SO	1
# define WE	2
# define EA	3

/* Error messages */
# define ARG_ERROR "Error: need one and only one arg\n"
# define NOT_FOUND "Error: no such file or directory\n"
# define MALLOC_ERROR "Error: malloc failed\n"
# define MAP_EXTENSION "Error: wrong map extension\n"
# define TEXTURE_EXTENSION "Error: wrong texture extension\n"
# define BORDER_ERROR "Error: opened border\n"
# define UNIDENTIFIED_CHAR_MAP "Error: unidentified character in the map\n"
# define UNIDENTIFIED_CHAR_TEXTURE "Error: unknown character in textures\n"
# define WRONG_RANGE "Error: wrong color range (must be between 0 and 255)\n"
# define WRONG_ORDER_TEXTURE "Error: wrong params order for textures\n"
# define WRONG_ORDER_COLOR "Error: wrong params order for colors\n"
# define WRONG_COLOR_NOTATION "Error : color needs to be in RGB (X,Y,Z)\n"
# define MULTIPLE_START "Error: multiple starting points in the map\n"
# define CONSECUTIVE_NEWLINES "Error: consecutive newlines\n"
# define NO_PLAYER "Error: no player in map\n"
# define NO_IMG "Error: image not found\n"
# define MAP_TOO_BIG "Error: map is too big\n"
# define EMPTY_FILE "Error: file is empty\n"

typedef int	(*t_fn)(void);

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
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
	double	x_nxs;
	double	y_nxs;
	int		x_guide;
	int		y_guide;
	int		side;
	double	dist_wall;
	double	wall_x;
	int		face;
	int		moved;
}			t_ryct;

typedef struct s_txtr
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	int		tex_x;
}			t_txtr;

typedef struct s_mov
{
	int		press_left;
	int		press_right;
	int		press_w;
	int		press_s;
	int		press_a;
	int		press_d;
}			t_mov;

/* Main struct */
typedef struct s_data
{
	int		fd;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		screen_x;
	int		screen_y;
	double	height_wall;
	t_gc	*gc;
	t_mlx	mlx;
	t_ryct	rycstng;
	t_txtr	txtr[4];
	t_mov	mov;
}			t_data;

#endif