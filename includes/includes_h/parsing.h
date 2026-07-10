/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 23:57:36 by neda-sil          #+#    #+#             */
/*   Updated: 2026/07/10 16:02:58 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

bool	check_extension(char *file_name, char *ext, int n);
void	parse_textures(t_data *data);
void	parsing(t_data *data);

#endif