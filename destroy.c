/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:29:40 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:54:03 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

int	destroy(t_data *info)
{
	clean_images_window(info, 4);
	clean_data(info);
	ft_putstr_fd("hope you had fun!!!!\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
