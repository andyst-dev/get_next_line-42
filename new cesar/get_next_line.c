/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:49:41 by astoll            #+#    #+#             */
/*   Updated: 2023/11/21 08:38:45 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *tail, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	nbytes;

	while (!ft_strchr(tail, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == 0)
			break ;
		if (nbytes == -1)
		{
			free(tail);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		tail = ft_strjoin(tail, buffer);
	}
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
	static char	*tail;
	char		*line;

	line = read_line(tail, fd);
	tail = save_tail(line);
	return (line);
}
