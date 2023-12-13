/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:21:30 by mohtakra          #+#    #+#             */
/*   Updated: 2023/11/29 11:12:15 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*here is the main function of the parsing*/
t_cub	*parse_data(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 1 || argc > 2)
	{
		ft_putstr_fd("Error :\n", 2);
		ft_putstr_fd("exemple : \"./cub3D map.cub\"", 2);
		exit(EXIT_FAILURE);
	}
	if (!is_accepted_extension(argv[1]))
	{
		print_error("Error\n", "map entered not accepted : \"");
		print_error(argv[1], "\"\n");
		return (NULL);
	}
	cub = initializing_cub_struct();
	if (!set_cub_data(cub, argv[1]))
	{
		return (clean_struct(cub), NULL);
	}
	return (cub);
}
