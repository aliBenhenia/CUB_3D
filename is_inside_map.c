/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:29 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:30:30 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

bool	is_inside_map(t_data *info, double next_x, double next_y)
{
	if (next_x >= 0 && next_x <= info->map_width * TILE_SIZE)
	{
		if (next_y >= 0 && next_y <= info->map_height * TILE_SIZE)
		{
			return (true);
		}
	}
	return (false);
}
