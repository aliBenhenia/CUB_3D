/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:44:54 by takra             #+#    #+#             */
/*   Updated: 2023/11/22 16:14:49 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

/*return how many chars in a nbr */
static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*return true if the given char is a sign + or - */
static int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

/*return true if the given matrix countain only chars that is in range of int*/
bool	is_int(char *str, int converted_to_int)
{
	int	j;
	int	minus;

	j = 0;
	minus = 0;
	if (ft_is_sign(str[0]))
	{
		j++;
		if (str[0] == '-')
			minus = 1;
	}
	while (str[j] == '0' && str[j + 1] != '\0')
		j++;
	if ((int)ft_strlen(str + j) + minus != ft_nbrlen(converted_to_int))
		return (false);
	return (true);
}
