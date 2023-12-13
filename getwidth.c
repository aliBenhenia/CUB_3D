/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getwidth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:29:57 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:29:58 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

/*return the width of the longest line of the map*/
int	getwidth(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > len)
		{
			len = ft_strlen(map[i]);
		}
		i++;
	}
	return (len);
}
