/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:15:13 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/01 01:23:16 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*returns if a char exists in a string or not */
static int	ft_existchar(const char *wrd, char c)
{
	if (wrd)
	{
		while (*wrd)
		{
			if (*wrd == c)
				return (1);
			wrd++;
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (ft_existchar(set, *s1))
		s1++;
	if (*s1)
		while (ft_existchar(set, *(s1 + (ft_strlen(s1) - 1) - i)))
			i++;
	result = (char *)malloc (ft_strlen(s1) - i + 1);
	if (!result)
		return (NULL);
	while (*(s1 + i))
	{
		result[j] = *s1++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
