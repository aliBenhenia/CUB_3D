/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:41 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:30:42 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

static void	handle_move(t_player *player, int keycode)
{
	if (keycode == RIGHT_ARROW)
		player->turn_direction = 1 * (M_PI * ROTATION_SPEED / 180.0);
	else if (keycode == LEFT_ARROW)
		player->turn_direction = -1 * (M_PI * ROTATION_SPEED / 180.0);
	else if (keycode == KEY_W || keycode == KEY_S)
	{
		player->is_lr = false;
		if (keycode == KEY_W)
			player->walk_direction = MOVE_SPEED * 1;
		else
			player->walk_direction = MOVE_SPEED * -1;
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		player->is_lr = true;
		if (keycode == KEY_A)
			player->walk_direction = MOVE_SPEED * -1;
		else
			player->walk_direction = MOVE_SPEED * 1;
	}
}

int	move(int keycode, t_data *info)
{
	if (keycode == KEY_ESC)
	{
		destroy(info);
		exit(EXIT_SUCCESS);
	}
	handle_move(&info->_player, keycode);
	return (0);
}
