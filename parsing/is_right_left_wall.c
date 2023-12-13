/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_left_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:09:14 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 20:26:19 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*check the right and left border*/
bool	is_right_left_wall(char **copymap)
{
	int	i;
	int	len;

	i = -1;
	while (copymap[++i])
	{
		len = (int)ft_strlen(copymap[i]) - 1;
		if (copymap[i][0] != '1' && copymap[i][0] != ' ')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("map not sorounded by wals right and left", 2);
			return (false);
		}
		if (copymap[i][len] != '1' && copymap[i][len] != ' ')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("map not sorounded by wals right and left", 2);
			return (false);
		}
	}
	return (true);
}
