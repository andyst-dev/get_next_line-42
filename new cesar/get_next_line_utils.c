/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:50:16 by astoll            #+#    #+#             */
/*   Updated: 2023/11/20 15:38:21 by astoll           ###   ########.fr       */
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
	char	*r;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	r = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!r)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	r[len1 + len2] = '\0';
	while (len2--)
		r[len1 + len2] = s2[len2];
	while (len1--)
		r[len1] = s1[len1];
	if (s1)
		free(s1);
	return (r);
}
