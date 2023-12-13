/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:24 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:30:25 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

static bool	is_ray_facing_down(t_ray ray)
{
	if (ray.ray_angle > 0 && ray.ray_angle < M_PI)
		return (true);
	return (false);
}

static bool	is_ray_facing_up(t_ray ray)
{
	return (!is_ray_facing_down(ray));
}

static bool	is_ray_facing_right(t_ray ray)
{
	if (ray.ray_angle < 0.5 * M_PI || ray.ray_angle > 1.5 * M_PI)
		return (true);
	return (false);
}

static bool	is_ray_facing_left(t_ray ray)
{
	return (!is_ray_facing_right(ray));
}

void	init_info_rays(t_ray *ray, double rayAngle)
{
	ray->distance = 0;
	ray->ray_angle = norm_angl(rayAngle);
	ray->is_ray_facing_down = is_ray_facing_down(*ray);
	ray->is_ray_facing_up = is_ray_facing_up(*ray);
	ray->is_ray_facing_right = is_ray_facing_right(*ray);
	ray->is_ray_facing_left = is_ray_facing_left(*ray);
	ray->_help.found_vertical_wall_hit = false;
	ray->_help.vert_wall_hit_x = 0;
	ray->_help.vert_wall_hit_y = 0;
	ray->_help.found_horz_wall_hit = false;
	ray->_help.wall_hit_x = 0;
	ray->_help.wall_hit_y = 0;
}
