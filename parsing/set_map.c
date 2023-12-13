/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:46 by mohtakra          #+#    #+#             */
/*   Updated: 2023/12/09 21:25:31 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpars.h"

static void	del(void *to_del)
{
	free(to_del);
}

/*return a double pointer created from the list pointer entered (lst)*/
static char	**convert_list_to_matrix(t_list *lst)
{
	char	**matrix;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (lst == NULL)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!matrix)
		return (NULL);
	while (tmp != NULL)
	{
		matrix[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

static bool	has_double_new_line(char *line, int line_nbr)
{
	if (ft_strcmp(line, "\n") == 0)
	{
		print_error("Error :", "new line in the map set_map() in line : ");
		ft_putnbr_fd(line_nbr, 2);
		ft_putstr_fd("\n", 2);
		return (true);
	}
	return (false);
}

/*set the data of the map in its place */
bool	set_map(t_cub *cub, char *line, int map_fd)
{
	char	*str;
	t_list	*lst;

	lst = NULL;
	if (!cub || line == NULL)
		return (ft_putstr_fd("Error :\nEmpty map!! set_map()", 2), false);
	while (line)
	{
		str = ft_strtrim(line, "\n");
		free(line);
		ft_lstadd_back(&lst, ft_lstnew(str));
		if (!has_accepted_chars(str, ft_lstsize(lst)))
			return (ft_lstclear(&lst, del), false);
		line = get_next_line(map_fd);
		if (has_double_new_line(line, ft_lstsize(lst)))
			return (free(line), ft_lstclear(&lst, del), false);
	}
	cub->map = convert_list_to_matrix(lst);
	ft_lstclear(&lst, del);
	if (cub->map == NULL)
		return (print_error("the map not accepted set_map()", NULL), false);
	return (true);
}
