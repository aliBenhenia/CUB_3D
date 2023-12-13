/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_accepted_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:07:27 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 20:30:38 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

static bool	is_valid_char(char c)
{
	if (c == '0')
		return (true);
	if (c == '1')
		return (true);
	if (c == ' ')
		return (true);
	if (c == 'N')
		return (true);
	if (c == 'W')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'S')
		return (true);
	return (false);
}

/*check if the line has only accepted characters 0, 1, ' ', N, E, W and S*/
bool	has_accepted_chars(char *line_in_map, int line_nbr)
{
	int	i;

	i = 0;
	if (!line_in_map)
		return (true);
	while (line_in_map[i])
	{
		if (!is_valid_char(line_in_map[i]))
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("thier is non accepted character in line : ", 2);
			ft_putnbr_fd(line_nbr, 2);
			ft_putstr_fd(" column :", 2);
			ft_putnbr_fd(i + 1, 2);
			return (ft_putstr_fd("\n has_accepted_chars()", 2), false);
		}
		i++;
	}
	return (true);
}
