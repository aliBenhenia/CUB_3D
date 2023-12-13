/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_vert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:03 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/08 12:20:57 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

static int	check_dir_left(t_ray ray)
{
	if (ray.is_ray_facing_left)
		return (-1);
	return (0);
}

static void	check_wall_hit_vert(t_data *info, double x_step, int ray_index)
{
	double	next_vertical_x;
	double	next_vertical_y;
	double	vertical_x;
	t_help	*help;

	help = &info->my_ray[ray_index]._help;
	next_vertical_x = help->x_intercept;
	next_vertical_y = help->y_intercept;
	while (is_inside_map(info, next_vertical_x, next_vertical_y))
	{
		vertical_x = next_vertical_x + check_dir_left(info->my_ray[ray_index]);
		if (is_wall(info, vertical_x, next_vertical_y))
		{
			help->found_vertical_wall_hit = true;
			help->vert_wall_hit_x = next_vertical_x;
			help->vert_wall_hit_y = next_vertical_y;
			break ;
		}
		else
		{
			next_vertical_x += x_step;
			next_vertical_y += help->y_step;
		}
	}
}

void	handle_vert(t_data *info, int ray_index)
{
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;
	t_ray	*ray;

	ray = &info->my_ray[ray_index];
	x_intercept = (int)(info->_player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		x_intercept += TILE_SIZE;
	y_intercept = \
	info->_player.y + (x_intercept - info->_player.x) * tan(ray->ray_angle);
	x_step = TILE_SIZE;
	if (ray->is_ray_facing_left)
		x_step *= -1;
	y_step = x_step * tan(ray->ray_angle);
	if (ray->is_ray_facing_up && y_step > 0)
		y_step *= -1;
	if (ray->is_ray_facing_down && y_step < 0)
		y_step *= -1;
	ray->_help.y_step = y_step;
	ray->_help.x_intercept = x_intercept;
	ray->_help.y_intercept = y_intercept;
	check_wall_hit_vert(info, x_step, ray_index);
}
