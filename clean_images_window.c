/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_images_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:29:37 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:29:38 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

void	clean_images_window(t_data *info, int failed_texture)
{
	int	i;

	i = failed_texture;
	while (--i >= 0)
	{
		mlx_destroy_image(info->mlx_ptr, info->textures[i].mlx_img);
	}
	mlx_destroy_image(info->mlx_ptr, info->wimg);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
}
