/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:51:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/03/17 04:54:02 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE    1
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
/*utile files*/
size_t	ft_strlen2(const char *s);
char	*ft_strdup2(const char *s);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_substr2(char const *s, unsigned int start, size_t len);

#endif
