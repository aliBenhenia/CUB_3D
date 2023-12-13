/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:21:12 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 17:20:41 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

void	clean_struct(t_cub *cub)
{
	if (cub)
	{
		free(cub->ea);
		free(cub->we);
		free(cub->so);
		free(cub->no);
		ft_freematrix(cub->map);
		free(cub);
	}
}
