/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_open_inside.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:09:28 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/10 18:16:15 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/* return true if the right chars of the index are walls
*  else return false
*/
static bool	is_right_char(char right, int line)
{
	if (right == '0' || is_player(right))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("there is a ' ' next to 0 or player in column : ", 2);
		ft_putnbr_fd(line, 2);
		ft_putstr_fd(" , line : ", 2);
		return (false);
	}
	return (true);
}

/* return true if the left chars of the index are walls
*  else return false
*/
static bool	is_left_char(char left, int line)
{
	if (left == '0' || is_player(left))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("there is a ' ' next to 0 or player in column : ", 2);
		ft_putnbr_fd(line, 2);
		ft_putstr_fd(" , line : ", 2);
		return (false);
	}
	return (true);
}

/*return false if the first wall has a space ' ' near 0*/
static bool	is_first_wall(char **copymap)
{
	int	j;

	j = 0;
	while (copymap[0][j])
	{
		if (copymap[0][j] == ' ')
		{
			if (!is_up_bottom_wall(NULL, copymap[1], j))
			{
				return (ft_putnbr_fd(1, 2), false);
			}
		}
		j++;
	}
	return (true);
}

/*return false if the last wall has a space ' ' near 0*/
static bool	is_last_wall(char **copymap)
{
	int	j;
	int	i;

	i = 0;
	while (copymap[i + 1])
		i++;
	j = 0;
	while (copymap[i][j])
	{
		if (copymap[i][j] == ' ')
		{
			if (!is_up_bottom_wall(copymap[i - 1], NULL, j))
			{
				return (ft_putnbr_fd(i + 1, 2), false);
			}
		}
		j++;
	}
	return (true);
}

/*return true if thier is a space ' ' near 0 else false*/
bool	is_open_inside(char **copymap)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	if (!is_first_wall(copymap) || !is_last_wall(copymap))
		return (true);
	while (++i && copymap[i] && copymap[i + 1])
	{
		j = -1;
		while (copymap[i][++j])
		{
			if (copymap[i][j] != ' ')
				continue ;
			if (!is_up_bottom_wall(copymap[i - 1], copymap[i + 1], j))
				return (ft_putnbr_fd(i + 1, 2), true);
			if (j != 0 && !is_left_char(copymap[i][j - 1], j))
				return (ft_putnbr_fd(i + 1, 2), true);
			len = (int)ft_strlen(copymap[i]);
			if (j != len && !is_right_char(copymap[i][j + 1], j))
				return (ft_putnbr_fd(i + 1, 2), true);
		}
	}
	return (false);
}
