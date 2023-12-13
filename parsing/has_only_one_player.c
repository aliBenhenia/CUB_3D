/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_only_one_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:08:03 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 21:18:35 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

static bool	is_valid_nbr_player(int player_num, int lineSecond_player)
{
	if (player_num == 1)
		return (true);
	else
	{
		ft_putstr_fd("Error\n", 2);
		if (player_num == 0)
			ft_putstr_fd("Thier is no player in the map ", 2);
		else
		{
			ft_putstr_fd("Thier is a second player in the map at line : ", 2);
			ft_putnbr_fd(lineSecond_player, 2);
		}
		ft_putstr_fd("\n", 2);
		return (false);
	}
}

/*check if the map has only one player*/
bool	has_only_one_player(char **map)
{
	int	i;
	int	j;
	int	players_num;

	players_num = 0;
	i = 0;
	while (players_num < 2 && map[i])
	{
		j = 0;
		while (players_num < 2 && map[i][j])
		{
			if (is_player(map[i][j]))
				players_num++;
			j++;
		}
		i++;
	}
	return (is_valid_nbr_player(players_num, i));
}
