/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:23:04 by mohtakra          #+#    #+#             */
/*   Updated: 2023/10/16 16:23:43 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*free located memory for a matrix*/
void	ft_freematrix(char **matrix)
{
	char	**temp;

	if (!matrix)
		return ;
	temp = matrix;
	while (*matrix)
	{
		free(*matrix);
		matrix++;
	}
	matrix = temp;
	free(matrix);
}
