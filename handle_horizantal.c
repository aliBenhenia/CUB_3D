/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_horizantal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:00 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/08 11:51:41 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

static int	check_direction_up(t_ray ray)
{
	if (ray.is_ray_facing_up)
		return (-1);
	return (0);
}

static void	check_wall_hit_horz(t_data *info, double x_step, int ray_index)
{
	double	next_horz_x;
	double	next_horz_y;
	double	y_to_check;
	t_help	*help;

	help = &info->my_ray[ray_index]._help;
	next_horz_x = help->x_intercept;
	next_horz_y = help->y_intercept;
	while (is_inside_map(info, next_horz_x, next_horz_y))
	{
		y_to_check = next_horz_y + check_direction_up(info->my_ray[ray_index]);
		if (is_wall(info, next_horz_x, y_to_check))
		{
			help->found_horz_wall_hit = true;
			help->wall_hit_x = next_horz_x;
			help->wall_hit_y = next_horz_y;
			break ;
		}
		else
		{
			next_horz_x += x_step;
			next_horz_y += help->y_step;
		}
	}
}

void	handle_horizantal(t_data *info, int ray_index)
{
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;
	t_ray	*ray;

	ray = &info->my_ray[ray_index];
	y_intercept = (int)(info->_player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_down)
		y_intercept += TILE_SIZE;
	x_intercept = \
	info->_player.x + (y_intercept - info->_player.y) / tan(ray->ray_angle);
	y_step = TILE_SIZE;
	if (ray->is_ray_facing_up)
		y_step *= -1;
	x_step = y_step / tan(ray->ray_angle);
	if (ray->is_ray_facing_left && x_step > 0)
		x_step *= -1;
	if (ray->is_ray_facing_right && x_step < 0)
		x_step *= -1;
	ray->_help.y_step = y_step;
	ray->_help.x_intercept = x_intercept;
	ray->_help.y_intercept = y_intercept;
	check_wall_hit_horz(info, x_step, ray_index);
}
