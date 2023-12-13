/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:17:51 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/16 16:22:22 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*return number of words in a string depends on a seperateur*/
static int	count_words(char const *str, char sep)
{
	int	wrdcount;
	int	i;

	if (!str)
		return (0);
	wrdcount = 0;
	i = 0;
	while (str[i] == sep)
		i++;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			wrdcount++;
		i++;
	}
	return (wrdcount);
}

/*return the size of the next word of a string depends on a seperateur*/
static int	word_size(char const *str, char sep)
{
	int	i;
	int	word_size;

	if (!str)
		return (0);
	i = 0;
	word_size = 0;
	while (*str == sep)
		str++;
	while (str[i] && str[i] != sep)
	{
		word_size++;
		i++;
	}
	return (word_size);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		number_of_words;
	int		i;

	i = 0;
	number_of_words = count_words(s, c);
	matrix = (char **)malloc(sizeof(char *) * (number_of_words + 1));
	if (!matrix || !s)
		return (NULL);
	while (*s && i < number_of_words)
	{
		while (*s && *s == c)
			s++;
		matrix[i] = (char *)malloc(sizeof(char) * word_size(s, c) + 1);
		if (!matrix[i])
		{
			ft_freematrix(matrix);
			return (NULL);
		}
		ft_strlcpy(matrix[i++], s, word_size(s, c) + 1);
		s = s + word_size(s, c);
	}
	matrix[i] = NULL;
	return (matrix);
}
