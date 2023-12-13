/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:27:54 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:54:28 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

static double	get_wall_hit_x(t_ray ray, double hor_hitdis, double ver_hit_dis)
{
	if (hor_hitdis < ver_hit_dis)
		return (ray._help.wall_hit_x);
	return (ray._help.vert_wall_hit_x);
}

static double	get_wall_hit_y(t_ray ray, double hor_hitdis, double ver_hit_dis)
{
	if (hor_hitdis < ver_hit_dis)
		return (ray._help.wall_hit_y);
	return (ray._help.vert_wall_hit_y);
}

/*
* return the distance between the player and the point with coordinates (x, y)
*/
static double	distance(t_player player, double x, double y)
{
	return (sqrt(pow(x - player.x, 2) + pow(y - player.y, 2)));
}

static void	cast_ray(t_data *info, double rayAngle, int ray_index)
{
	double	horiz_hit_dis;
	double	vert_hit_dist;
	t_ray	*ray;
	t_help	*help;

	ray = &info->my_ray[ray_index];
	help = &ray->_help;
	init_info_rays(ray, rayAngle);
	handle_horizantal(info, ray_index);
	handle_vert(info, ray_index);
	if (help->found_horz_wall_hit)
		horiz_hit_dis = \
		distance(info->_player, help->wall_hit_x, help->wall_hit_y);
	else
		horiz_hit_dis = INT_MAX;
	if (help->found_vertical_wall_hit)
		vert_hit_dist = \
		distance(info->_player, help->vert_wall_hit_x, help->vert_wall_hit_y);
	else
		vert_hit_dist = INT_MAX;
	ray->wall_hit_x_ = get_wall_hit_x(*ray, horiz_hit_dis, vert_hit_dist);
	ray->wall_hit_y_ = get_wall_hit_y(*ray, horiz_hit_dis, vert_hit_dist);
	ray->was_hit_vertical = vert_hit_dist <= horiz_hit_dis;
	helper_func(info, horiz_hit_dis, vert_hit_dist, ray_index);
}

void	cast_rays(t_data *info)
{
	double	ray_angle;
	int		ray_index;

	ray_angle = info->_player.rotation_angle - (((FOV * M_PI) / 180.0) / 2);
	info->_player.rotation_angle = norm_angl(info->_player.rotation_angle);
	ray_index = 0;
	while (ray_index < NUM_RAYS)
	{
		cast_ray(info, ray_angle, ray_index);
		ray_index++;
		ray_angle += (((FOV * M_PI) / 180.0) / NUM_RAYS);
	}
}
