/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cub_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:34:32 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 21:14:46 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

int	open_map_file(char *map)
{
	int	map_fd;

	map_fd = open(map, O_RDONLY, 0666);
	if (map_fd == -1)
		print_error("Error :\ncouldn't open the file : ", map);
	return (map_fd);
}

/*here all the data of the t_cub struct is gonna be setting*/
bool	set_cub_data(t_cub *cub, char *map)
{
	char	*line;
	int		map_fd;

	map_fd = open_map_file(map);
	if (map_fd == -1)
		return (false);
	line = get_next_line(map_fd);
	while (line)
	{
		if (cub->map == NULL && !is_textures_floor_ceiles_setted(cub))
		{
			if (ft_strcmp(line, "\n") != 0 && !set_textures_paths(cub, line))
				return (print_error("Error\n", "In textures c or f"), \
				free(line), close(map_fd), false);
		}
		else if (ft_strcmp(line, "\n") != 0)
			break ;
		free(line);
		line = get_next_line(map_fd);
	}
	if (!set_map(cub, line, map_fd) || !check_map(cub->map))
		return (close(map_fd), false);
	return (close(map_fd), true);
}
