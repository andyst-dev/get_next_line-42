/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:50:16 by astoll            #+#    #+#             */
/*   Updated: 2023/11/21 08:36:09 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
	{
		return (0);
	}
	while ((char)c != *s)
	{
		if (!*s)
		{
			return (0);
		}
		s++;
	}
	return ((char *)s);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	if (!s || !*s)
	{
		return (0);
	}
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!dest)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		s1len;
	int		s2len;
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!dst)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	dst[s1len + s2len] = '\0';
	while (s2len--)
		dst[s1len + s2len] = s2[s2len];
	while (s1len--)
		dst[s1len] = s1[s1len];
	if (s1)
		free(s1);
	return (dst);
}
