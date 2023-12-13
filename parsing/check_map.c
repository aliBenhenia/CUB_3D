/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:08:41 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 21:13:13 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*
*  all the functions that checks if the map is accepted
*/
bool	check_map(char **map)
{
	if (map == NULL)
		return (ft_putstr_fd("Error :\nEmpty map!!", 2), false);
	if (!has_only_one_player(map))
		return (false);
	if (!is_top_wall(map) || !is_bottom_wall(map))
		return (false);
	if (!is_right_left_wall(map))
		return (false);
	if (is_open_inside(map))
		return (false);
	if (is_open_long_line(map))
		return (false);
	return (true);
}
