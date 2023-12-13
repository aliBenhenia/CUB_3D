/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_open_long_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:09:19 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 20:27:22 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/* check if thier is a ziro in a line 
*  while one of above or under line are shorter
*/
bool	is_open_long_line(char **copymap)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (copymap[++i])
	{
		j = -1;
		while (copymap[i][++j])
		{
			if (copymap[i][j] != '0' && !is_player(copymap[i][j]))
				continue ;
			len = (int)ft_strlen(copymap[i - 1]) - 1;
			if (i > 0 && len < j)
				return (ft_putstr_fd("map not closed in the line :", 2), \
				ft_putnbr_fd(i + 1, 2), true);
			len = (int)ft_strlen(copymap[i + 1]) - 1;
			if (copymap[i + 1] != NULL && len < j)
			{
				ft_putstr_fd("map not closed in the line :", 2);
				return (ft_putnbr_fd(i + 1, 2), true);
			}
		}
	}
	return (false);
}
