/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:10:40 by astoll            #+#    #+#             */
/*   Updated: 2023/11/16 13:34:34 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static	t_list	*stash;
	char			*line;
	
	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)//read 0 pour tester si le fichier est lisible, -1 si ya probleme ac read
	{
		return (NULL);
	}
	line = NULL;
	read_and_stash(fd, &stash);
}
