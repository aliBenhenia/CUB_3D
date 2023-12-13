/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:23:55 by mohtakra          #+#    #+#             */
/*   Updated: 2022/10/28 03:24:45 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && i < n)
	{
		if (*s1 != *s2)
			return (*((unsigned char *)s1) - (*(unsigned char *)s2));
		if (i != n - 1)
		{
			s1++;
			s2++;
		}
		i++;
	}
	if (!*s1 || !*s2)
		return (ft_strlen(s1) - ft_strlen(s2));
	return (0);
}
