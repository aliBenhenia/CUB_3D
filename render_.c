/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:49 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:56:18 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

static void	handle_walk_(t_data *info)
{
	double	x_to_move;
	double	y_to_move;
	int		walk_dir;

	walk_dir = info->_player.walk_direction;
	if (info->_player.is_lr)
	{
		x_to_move = cos(info->_player.rotation_angle + (M_PI / 2)) * walk_dir;
		y_to_move = sin(info->_player.rotation_angle + (M_PI / 2)) * walk_dir;
	}
	else
	{
		x_to_move = cos(info->_player.rotation_angle) * walk_dir;
		y_to_move = sin(info->_player.rotation_angle) * walk_dir;
	}
	if (!has_wall_in_path(info, x_to_move, y_to_move))
	{
		info->_player.x = x_to_move + info->_player.x;
		info->_player.y = y_to_move + info->_player.y;
	}
}

static void	turn(t_player *player)
{
	double	turn_dir;

	turn_dir = player->turn_direction;
	if (turn_dir != 0)
		player->rotation_angle = player->rotation_angle + turn_dir;
	player->rotation_angle = norm_angl(player->rotation_angle);
}

int	render_(t_data *info)
{
	handle_walk_(info);
	turn(&info->_player);
	cast_rays(info);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->wimg, 0, 0);
	return (0);
}
