/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:10:40 by astoll            #+#    #+#             */
/*   Updated: 2023/11/18 15:00:18 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_save(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
		{
			return (0);
		}
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
	{
		count++;
	}
	if (line[count] == '\0' || line[1] == '\0')
	{
		return (0);
	}
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		return (0);
	}
	line = read_and_save(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
	{
		return (NULL);
	}
	backup = extract(line);
	return (line);
}
