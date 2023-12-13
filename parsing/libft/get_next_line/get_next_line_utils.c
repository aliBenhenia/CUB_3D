/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:17:46 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/16 00:46:51 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup2(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *) malloc(sizeof(char) * ft_strlen2(s) + 1);
	if (!str)
		return (NULL);
	while (*s)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup2(s2));
	i = 0;
	str = (char *)malloc(ft_strlen2(s1) + ft_strlen2(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen2(s))
		return (ft_strdup2(""));
	if (len > ft_strlen2(s) || len > ft_strlen2(s) - start)
		len = ft_strlen2(s) - (size_t)start;
	i = (size_t)start;
	substr = (char *) malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (i < len + (size_t)start)
	{
		substr[i - (size_t)start] = s[i];
		i++;
	}
	substr[i - (size_t)start] = '\0';
	return (substr);
}
