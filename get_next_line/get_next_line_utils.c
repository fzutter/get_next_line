/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:38:03 by fzutter           #+#    #+#             */
/*   Updated: 2024/04/09 15:23:28 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char) c)
		return (&str[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + 1;
	j = 0;
	s2 = malloc(sizeof(char) * i);
	if (s2 == 0)
		return (NULL);
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = ft_strlen(s);
	j = 0;
	if (!s)
		return (NULL);
	if (i < start && i < start + len)
		return (ft_strdup(""));
	if (len > i - start)
		len = i - start;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == 0)
		return (NULL);
	while (j < len)
	{
		dest[j] = s[start + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		len;
	char		*dest;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * len);
	if (dest == 0)
		return (NULL);
	ft_strlcpy(dest, s1, len + 1);
	ft_strlcat(dest, s2, len + 1);
	return (dest);
}
