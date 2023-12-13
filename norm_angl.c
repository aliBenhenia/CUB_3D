/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_angl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <abenheni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:43 by abenheni          #+#    #+#             */
/*   Updated: 2023/12/04 13:30:44 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

double	norm_angl(double rayangle)
{
	while (rayangle > PI2 || rayangle < 0)
	{
		if (rayangle > PI2)
			rayangle = fmod(rayangle, PI2);
		if (rayangle < 0)
			rayangle = PI2 + rayangle;
	}
	return (rayangle);
}
