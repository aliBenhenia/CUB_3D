/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:08 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/08 16:12:59 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

static void	draw_ciel(t_data info, int x)
{
	int	i;

	i = 0;
	while (i < HEIGHT / 2)
	{
		info.wframe[i * WIDTH + x] = info.pars->c;
		i++;
	}
}

static void	draw_floor(t_data info, int x)
{
	int	i;

	i = HEIGHT / 2;
	while (i < HEIGHT)
	{
		info.wframe[i * WIDTH + x] = info.pars->f;
		i++;
	}
}

static void	draw_wall_textures(t_data *info, int ray_index, int height)
{
	uint32_t	color;
	int			wall_y;
	int			wall_top;
	t_ray		*ray;

	ray = &info->my_ray[ray_index];
	wall_top = ((HEIGHT / 2)) - (ray->wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_y = 0;
	while (height-- && ray_index < WIDTH && wall_top < HEIGHT)
	{
		color = get_color_from_texture(ray, info->textures, wall_y);
		info->wframe[wall_top * WIDTH + ray_index] = color;
		wall_y++;
		wall_top++;
	}
}

static void	render_3d_effect(t_data *info, int ray_index)
{
	double	distance_to_projection_plane;
	double	wall_height;
	t_ray	*ray;

	ray = &info->my_ray[ray_index];
	distance_to_projection_plane = (WIDTH / 2) / tan(((FOV * M_PI) / 180) / 2);
	ray->distance *= cos(ray->ray_angle - info->_player.rotation_angle);
	wall_height = (TILE_SIZE / ray->distance) * distance_to_projection_plane;
	ray->wall_height = wall_height;
	draw_ciel(*info, ray_index);
	draw_floor(*info, ray_index);
	draw_wall_textures(info, ray_index, wall_height);
}

void	helper_func(t_data *info, double hor_hitdis, double ver_hitdis, int r_i)
{
	if (hor_hitdis < ver_hitdis)
		info->my_ray[r_i].distance = hor_hitdis;
	else if (hor_hitdis >= ver_hitdis)
		info->my_ray[r_i].distance = ver_hitdis;
	render_3d_effect(info, r_i);
}
