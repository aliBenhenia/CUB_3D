# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 18:37:53 by mohtakra          #+#    #+#              #
#    Updated: 2023/12/09 12:56:08 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = ft_strchr.c ft_strcmp.c ft_strncmp.c ft_strdup.c ft_strjoin.c\
	ft_strlen.c ft_strtrim.c ft_split.c ft_strlcpy.c ft_atoi.c\
	ft_freematrix.c \
	ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c \
	./get_next_line/get_next_line_utils.c \
	./get_next_line/get_next_line.c

	
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $@ $(OBJ)
		@echo "the libft has ben archived successfully in $(NAME)"

%.o: %.c libft.h ./get_next_line/get_next_line.h
		@$(CC) -I. -o $@ -c $< $(CFLAGS)
		@echo "the file $@ has been created from $<"


clean:
		@$(RM) $(OBJ)
		@echo "all the libft objects has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		@echo "the archive $(NAME) has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) all fclean re