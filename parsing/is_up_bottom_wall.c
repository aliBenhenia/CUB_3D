/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_up_bottom_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:18:14 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/10 18:14:41 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/* return true if the up and down chars of the index are walls 
*  else return false
*/
bool	is_up_bottom_wall(char *up, char *bottom, int index)
{
	if (up && (int)ft_strlen(up) >= index)
	{
		if (up[index] == '0' || is_player(up[index]))
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("thier is a ' ' next to 0 or player \n", 2);
			return (false);
		}
	}
	if (bottom && (int)ft_strlen(bottom) >= index)
	{
		if (bottom[index] == '0' || is_player(bottom[index]))
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("thier is a ' ' next to 0 or player \n", 2);
			return (false);
		}
	}
	return (true);
}
