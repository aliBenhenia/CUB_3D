/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:06:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/16 00:47:13 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strchr(char *s, char c)
{
	char	*str;

	if (s)
	{
		str = s;
		while (*str && *str != c)
			str++;
		if (*str == c)
			return (1);
	}
	return (0);
}

static char	*get_till_new_line(int fd, char *rest)
{
	char	*buffer;
	char	*line_rest;
	ssize_t	readbuffer;

	readbuffer = 1;
	line_rest = NULL;
	line_rest = ft_strjoin2(line_rest, rest);
	if (ft_strchr(rest, '\n'))
		return (line_rest);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readbuffer)
	{
		readbuffer = read(fd, buffer, BUFFER_SIZE);
		if (readbuffer == -1)
			return (free(buffer), NULL);
		buffer[readbuffer] = '\0';
		line_rest = ft_strjoin2(line_rest, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), line_rest);
}

static char	*rest_after_line(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (ft_substr2(str, i, ft_strlen2(str) - i + 1));
}

static char	*ft_line(char *all_xbuffer)
{
	int		i;

	i = 0;
	if (!all_xbuffer)
		return (NULL);
	while (all_xbuffer[i] && all_xbuffer[i] != '\n')
		i++;
	if (all_xbuffer[i] == '\n')
		i++;
	if (all_xbuffer[0] == '\0')
		return (NULL);
	return (ft_substr2(all_xbuffer, 0, i));
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*xbuffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	xbuffer = get_till_new_line(fd, rest);
	free(rest);
	rest = rest_after_line(xbuffer);
	line = ft_line(xbuffer);
	free(xbuffer);
	return (line);
}
