/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:49:41 by astoll            #+#    #+#             */
/*   Updated: 2023/11/23 13:54:01 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *tail)
{
	char	*buf;
	ssize_t	nbytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(tail, '\n'))
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes == 0)
			break ;
		if (nbytes == -1)
		{
			free(buf);
			free(tail);
			return (NULL);
		}
		buf[nbytes] = '\0';
		tail = ft_strjoin(tail, buf);
	}
	free(buf);
	return (tail);
}

static char	*save_tail(char *line)
{
	char	*next;
	char	*newtail;

	next = ft_strchr(line, '\n');
	if (!next)
		return (NULL);
	next++;
	newtail = ft_strdup(next);
	*next = '\0';
	return (newtail);
}

char	*get_next_line(int fd)
{
	static char	*tail[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = read_line(fd, tail[fd]);
	tail[fd] = save_tail(line);
	return (line);
}
