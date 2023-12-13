/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:53 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:53:54 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

static void	init_data(t_data *info, t_cub *parse_data)
{
	info->pars = parse_data;
	info->map_height = get_height(info->pars->map);
	info->map_width = getwidth(info->pars->map);
}

static bool	init_mlx_data(t_data *info)
{
	int	a;

	info->win_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (info->win_ptr == NULL)
	{
		print_error("error : can not create new windows \n", "");
		return (false);
	}
	info->wimg = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT);
	if (info->wimg == NULL)
	{
		print_error("error : can not create new image \n", "");
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		return (false);
	}
	info->wframe = (uint32_t *)mlx_get_data_addr(info->wimg, &a, &a, &a);
	if (info->wframe == NULL)
	{
		print_error("error : can not get the data addr init_mlx_data()\n", "");
		mlx_destroy_image(info->mlx_ptr, info->wimg);
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		return (mlx_destroy_window(info->mlx_ptr, info->win_ptr), false);
	}
	return (true);
}

static bool	set_texture(t_data *info, t_img *texture, char *texture_path)
{
	int	a;
	int	*text_width;
	int	*text_height;

	text_width = &texture->width;
	text_height = &texture->height;
	texture->mlx_img = \
	mlx_xpm_file_to_image(info->mlx_ptr, texture_path, text_width, text_height);
	if (texture->mlx_img == NULL)
	{
		print_error("Error: while trying to convert xpm file to image ", "");
		print_error("texture path you entered is ", texture_path);
		return (print_error(NULL, "\n"), false);
	}
	texture->addr = (uint32_t *)mlx_get_data_addr(texture->mlx_img, &a, &a, &a);
	if (texture->addr == NULL)
	{
		print_error("Error: while trying to get adderess of a texture", "");
		print_error("texture path you entered is ", texture_path);
		return (print_error(NULL, "\n"), false);
	}
	return (true);
}

static bool	loading_images(t_data *info)
{
	if (!set_texture(info, &info->textures[NORTH], info->pars->no))
		return (clean_images_window(info, NORTH), false);
	if (!set_texture(info, &info->textures[EAST], info->pars->ea))
		return (clean_images_window(info, EAST), false);
	if (!set_texture(info, &info->textures[WEAST], info->pars->we))
		return (clean_images_window(info, WEAST), false);
	if (!set_texture(info, &info->textures[SOUTH], info->pars->so))
		return (clean_images_window(info, SOUTH), false);
	return (true);
}

bool	render_map(t_data *info, t_cub *pars_data)
{
	init_data(info, pars_data);
	init_player_data(&info->_player, info->pars->map);
	info->mlx_ptr = mlx_init();
	if (info->mlx_ptr == NULL)
	{
		print_error("Error : we could not init mlx", "\n");
		return (false);
	}
	if (!init_mlx_data(info) || !loading_images(info))
	{
		return (false);
	}
	mlx_hook(info->win_ptr, 2, 1L << 0, move, info);
	mlx_hook(info->win_ptr, 3, 1L << 1, release, info);
	mlx_hook(info->win_ptr, 17, 0, destroy, info);
	mlx_loop_hook(info->mlx_ptr, render_, info);
	mlx_loop(info->mlx_ptr);
	return (true);
}
