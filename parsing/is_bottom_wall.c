/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bottom_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:09:04 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 20:25:59 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*check the bottom of the map*/
bool	is_bottom_wall(char **copymap)
{
	int	j;
	int	nbrlines1;

	j = 0;
	nbrlines1 = 0;
	while (copymap[nbrlines1])
		nbrlines1++;
	nbrlines1--;
	while (copymap[nbrlines1][j])
	{
		if (copymap[nbrlines1][j] != '1' && copymap[nbrlines1][j] != ' ')
		{
			print_error("the map is not sorounded by wals bottom\n", NULL);
			return (false);
		}
		j++;
	}
	return (true);
}
