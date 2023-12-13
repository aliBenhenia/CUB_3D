/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:26 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:30:27 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

/*return the x-coord of the player*/
static int	get_player_x(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < get_height(map))
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
				break ;
			else
				x++;
		}
		if (is_player(map[y][x]))
			break ;
		y++;
	}
	return (x * TILE_SIZE + (TILE_SIZE / 2));
}

/*return the y-coord of the player*/
static int	get_player_y(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < get_height(map))
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
				break ;
			else
				x++;
		}
		if (is_player(map[y][x]))
			break ;
		y++;
	}
	return (y * TILE_SIZE + (TILE_SIZE / 2));
}

/*return the angle depending on the charactere that represent player*/
static double	update_angle(char dir)
{
	if (dir == 'N')
		return (norm_angl(-(M_PI / 2)));
	else if (dir == 'E')
		return (0);
	else if (dir == 'S')
		return (M_PI / 2);
	else
		return (M_PI);
}

/*return the angle that a player should take as initialisation angle*/
static double	handle_player_direction(t_player player, char **map)
{
	int		x;
	int		y;
	double	angle;

	x = player.x / TILE_SIZE;
	y = player.y / TILE_SIZE;
	angle = update_angle(map[y][x]);
	return (angle);
}

void	init_player_data(t_player *player, char **map)
{
	player->x = get_player_x(map);
	player->y = get_player_y(map);
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->is_lr = 0;
	player->rotation_angle = handle_player_direction(*player, map);
}
