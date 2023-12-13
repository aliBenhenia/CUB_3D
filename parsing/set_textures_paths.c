/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:50 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/02 19:59:26 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

static char	**ft_strtrim_matrix(char **matrix)
{
	char	**tmp_matrix;
	int		matrix_lines;

	matrix_lines = 0;
	while (matrix[matrix_lines] != NULL)
		matrix_lines++;
	tmp_matrix = (char **)malloc (sizeof(char *) * (matrix_lines + 1));
	if (!tmp_matrix)
		return (NULL);
	tmp_matrix[0] = ft_strtrim(matrix[0], " ");
	tmp_matrix[1] = ft_strtrim(matrix[1], " ");
	tmp_matrix[2] = ft_strtrim(matrix[2], " ");
	tmp_matrix[3] = NULL;
	return (tmp_matrix);
}

static __uint32_t	get_color(char **matrix_color)
{
	__uint32_t	color;
	int			red;
	int			green;
	int			blue;
	char		**tmp;

	color = 0x0;
	tmp = ft_strtrim_matrix(matrix_color);
	if (tmp == NULL)
		return (__UINT32_MAX__);
	red = ft_atoi(tmp[0]);
	green = ft_atoi(tmp[1]);
	blue = ft_atoi(tmp[2]);
	if (!is_int(tmp[0], red) || !is_int(tmp[1], green) || !is_int(tmp[2], blue))
		return (ft_freematrix(tmp), __UINT32_MAX__);
	if (red > 255 || green > 255 || blue > 255)
		return (ft_freematrix(tmp), __UINT32_MAX__);
	if (red < 0 || green < 0 || blue < 0)
		return (ft_freematrix(tmp), __UINT32_MAX__);
	color = red << 16 | green << 8 | blue;
	return (ft_freematrix(tmp), color);
}

static bool	set_floor_ceil(t_cub *cub, char **matrix)
{
	char	**matrix_color;
	int		i;

	matrix_color = NULL;
	i = 0;
	matrix_color = ft_split(matrix[1], ',');
	while (matrix_color[i])
		i++;
	if (i != 3 || count_verguls(matrix[1]) != 2)
		return (ft_freematrix(matrix_color), false);
	if (cub->f == __UINT32_MAX__ && ft_strcmp(matrix[0], "F") == 0)
	{
		cub->f = get_color(matrix_color);
		if (cub->f == __UINT32_MAX__)
			return (ft_freematrix(matrix_color), false);
	}
	else if (cub->c == __UINT32_MAX__ && ft_strcmp(matrix[0], "C") == 0)
	{
		cub->c = get_color(matrix_color);
		if (cub->c == __UINT32_MAX__)
			return (ft_freematrix(matrix_color), false);
	}
	else
		return (ft_freematrix(matrix_color), false);
	return (ft_freematrix(matrix_color), true);
}

static bool	set_textures(t_cub *cub, char **matrix)
{
	if (!cub->no && ft_strcmp(matrix[0], "NO") == 0)
		cub->no = ft_strdup(matrix[1]);
	else if (!cub->so && ft_strcmp(matrix[0], "SO") == 0)
		cub->so = ft_strdup(matrix[1]);
	else if (!cub->we && ft_strcmp(matrix[0], "WE") == 0)
		cub->we = ft_strdup(matrix[1]);
	else if (!cub->ea && ft_strcmp(matrix[0], "EA") == 0)
		cub->ea = ft_strdup(matrix[1]);
	else
	{
		return (false);
	}
	return (true);
}

/*set the values of the textures data, also  f anc c colors */
bool	set_textures_paths(t_cub *cub, char *line)
{
	char	**matrix;
	char	*str;

	str = ft_strtrim(line, "\n");
	if (!str)
		return (false);
	matrix = ft_split(str, ' ');
	if (!matrix)
		return (free(str), false);
	if (!matrix[0] || !matrix[1] || matrix[2] != NULL)
	{
		ft_putstr_fd("eeeeerrrror from set_textures_paths part 1 \n", 2);
		return (free(str), ft_freematrix(matrix), false);
	}
	if (!set_textures(cub, matrix) && !set_floor_ceil(cub, matrix))
	{
		ft_putstr_fd("eeeeerrrror from set_textures_paths\n", 2);
		return (free(str), ft_freematrix(matrix), false);
	}
	return (free(str), ft_freematrix(matrix), true);
}
