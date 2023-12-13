/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_verguls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:08:24 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/02 20:09:11 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

int	count_verguls(char *str)
{
	int	count;

	count = 0;
	while (str && *str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}
