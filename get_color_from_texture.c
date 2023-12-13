/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_from_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:29:52 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:29:53 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

/*return the y_coordinate of the color to be peaked from the texture*/
static int	texture_coordinate_y(t_img txt, int strip_height, int y)
{
	double	tmp_y;
	double	newhieght;

	if (strip_height > HEIGHT)
	{
		newhieght = (strip_height - HEIGHT) / 2;
		tmp_y = ((y + newhieght) * txt.height) / strip_height;
	}
	else
		tmp_y = (y * txt.height) / strip_height;
	return (tmp_y);
}

/*return the y_coordinate of the color to be peaked from the texture*/
static int	texture_coordinate_x(t_ray *ray, t_img txt)
{
	double	x;

	if (ray->was_hit_vertical)
		x = fmod(ray->wall_hit_y_, TILE_SIZE);
	else
		x = fmod(ray->wall_hit_x_, TILE_SIZE);
	x = (x * txt.width) / TILE_SIZE;
	return (x);
}

/*return the color from a texture that feats each side*/
uint32_t	get_color_from_texture(t_ray *ray, t_img *texture, int wall_y)
{
	uint32_t	color;
	int			side;
	int			x;
	int			y;

	side = 0;
	if (ray->was_hit_vertical)
	{
		if (ray->is_ray_facing_left)
			side = WEAST;
		else if (ray->is_ray_facing_right)
			side = EAST;
	}
	else
	{
		if (ray->is_ray_facing_up)
			side = NORTH;
		else if (ray->is_ray_facing_down)
			side = SOUTH;
	}
	x = texture_coordinate_x(ray, texture[side]);
	y = texture_coordinate_y(texture[side], ray->wall_height, wall_y);
	color = texture[side].addr[y * texture[side].width + x];
	return (color);
}
