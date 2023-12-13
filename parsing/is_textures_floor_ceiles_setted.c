/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_textures_floor_ceiles_setted.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:25 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/28 23:31:03 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*return true if the info of the texutes so, no, ea, we, f, c has been setted*/
bool	is_textures_floor_ceiles_setted(t_cub *cub)
{
	if (cub->c == __UINT32_MAX__)
		return (false);
	if (cub->f == __UINT32_MAX__)
		return (false);
	if (cub->ea == NULL)
		return (false);
	if (cub->we == NULL)
		return (false);
	if (cub->so == NULL)
		return (false);
	if (cub->no == NULL)
		return (false);
	return (true);
}
