/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:35 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:30:36 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

bool	is_wall(t_data *info, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	if (map_x < 0 || map_y < 0)
		return (true);
	if (map_y >= info->map_height)
		return (true);
	if (map_x >= (int)ft_strlen(info->pars->map[map_y]))
		return (true);
	return (info->pars->map[map_y][map_x] == '1');
}
