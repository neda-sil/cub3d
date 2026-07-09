/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neda-sil <neda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:19:11 by neda-sil          #+#    #+#             */
/*   Updated: 2026/01/29 15:46:42 by neda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Return a line from the beggining of the string to the first '\n' or '\0' */
static char	*before_nl(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

/* Return what remains from the first '\n' (if there's one)
 * until the end of the string */
static char	*after_nl(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	while (s && s[j])
		j++;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	res = ft_calloc((j - i) + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

/* Adds what was read from the fd and stored in "buf" to stash.
 * Ends when a newline or an end-of-file character is found */
static void	add_stash(int fd, char **stash, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free_strs(&buf, stash, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup_gnl(*stash);
		free_strs(stash, 0, 0);
		*stash = ft_strjoin_gnl(*tmp, buf);
		free_strs(tmp, 0, 0);
		if (found_nl(*stash))
			break ;
	}
	free_strs(&buf, 0, 0);
}

/* Put the line in "line" and the remaing (if there is) in stash */
static char	*parse_line(char **stash, char **tmp)
{
	char	*line;

	*tmp = ft_strdup_gnl(*stash);
	free_strs(stash, 0, 0);
	line = before_nl(*tmp);
	*stash = after_nl(*tmp);
	free_strs(tmp, 0, 0);
	return (line);
}

/* Returns one line from a file descriptor (fd) */
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	add_stash(fd, &stash, &tmp);
	if (stash && stash[0])
		line = parse_line(&stash, &tmp);
	if (!line || !line[0])
	{
		free_strs(&stash, &line, &tmp);
		return (NULL);
	}
	return (line);
}
