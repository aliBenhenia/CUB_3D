/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:37 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/08 16:25:55 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

int	main(int argc, char **argv)
{
	t_data	info;
	t_cub	*data;

	data = parse_data(argc, argv);
	if (!data || !render_map(&info, data))
	{
		clean_struct(data);
		exit (EXIT_FAILURE);
	}
	return (0);
}
