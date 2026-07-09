/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:54:40 by neda-sil          #+#    #+#             */
/*   Updated: 2026/01/29 15:45:58 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* If no BUFFER_SIZE given, sets it at 5 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE <= 0
#  error invalid BUFFER_SIZE (=0)
# endif

# include <stdlib.h>
# include <unistd.h>

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
int		found_nl(const char *s);
void	free_strs(char **str1, char **str2, char **str3);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(const char *s1, const char *s2);

#endif