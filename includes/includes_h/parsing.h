/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 23:57:36 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/11 14:42:14 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* Utils */
int		check_color(char *color);
bool	check_extension(char *file_name, char *ext, int n);
bool	check_caracter(int c);
bool	check_border(char **map);

/* Parse steps */
void	parse_colors(t_data *data);
void	parse_textures(t_data *data);
void	parse_map(t_data *data);

/* Main Function */
void	parsing(t_data *data);

#endif