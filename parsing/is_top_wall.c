/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_top_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:08:17 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 20:25:36 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*check the top line of the map*/
bool	is_top_wall(char **copymap)
{
	int	j;

	j = 0;
	while (copymap[0][j])
	{
		if (copymap[0][j] != '1' && copymap[0][j] != ' ')
		{
			print_error("the map is not sorounded by walls top\n", NULL);
			return (false);
		}
		j++;
	}
	return (true);
}
