/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_in_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:06 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/08 13:55:15 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

bool	has_wall_in_path(t_data *info, double x_to_move, double y_to_move)
{
	double	t;
	double	x;
	double	y;
	double	distance;

	t = 0;
	distance = sqrt(pow(x_to_move, 2) + pow(y_to_move, 2));
	while (t <= distance)
	{
		x = info->_player.x + t * x_to_move / 2;
		y = info->_player.y + t * y_to_move / 2;
		if (is_wall(info, x, y))
			return (true);
		t += 0.01;
	}
	return (false);
}
