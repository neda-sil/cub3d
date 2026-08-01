/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 23:57:36 by neda-sil          #+#    #+#             */
/*   Updated: 2026/08/01 22:39:05 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* Utils */
int		check_color(char *color);
bool	check_extension(char *file_name, char *ext, int n);
bool	check_border(char **map);
void	check_dir(t_ryct **ryctng, char c);

/* Parse steps */
void	parse_colors(t_data *data);
void	parse_textures(t_data *data);
void	parse_map(t_data *data);
void	verif_imgs(t_data *data);

/* Main Function */
void	parsing(t_data *data);

#endif