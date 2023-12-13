# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 21:21:25 by mohtakra          #+#    #+#              #
#    Updated: 2023/12/09 22:04:07 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpars.a
CC = cc
CFLAGS=  -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
OBJ = $(SRC:.c=.o)
RM = rm -rf
ERRPATH=./error_handler/
HEADERS = ./libpars.h $(ERRPATH)liberror.h

SRC= parse_data.c is_accepted_extension.c \
	 check_map.c \
	 set_map.c set_textures_paths.c set_cub_data.c is_textures_floor_ceiles_setted.c \
	 initializing_cub_struct.c \
	 has_accepted_chars.c has_only_one_player.c is_top_wall.c is_bottom_wall.c\
	 is_right_left_wall.c is_open_long_line.c is_up_bottom_wall.c is_open_inside.c is_int.c\
	 is_player.c \
	 count_verguls.c clean_struct.c \
	 $(ERRPATH)print_error.c
all : $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "the file $@ has been created from $<"

$(NAME) : $(LIBFT)  $(OBJ)
		@ar rc $@  $(OBJ) $(LIBFT)
		@echo "the archieve $(NAME) has been created"

$(LIBFT) : ./libft/libft.h
		@make -C ./libft all

clean:
		@$(RM) $(OBJ) $(NAME)
		@make -C ./libft clean
		@echo "all the .o has been deleted successfully"

fclean: clean
		@$(RM) $(NAME)
		@make -C ./libft fclean
		@echo "the archieve $(NAME) has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) $(LIBFT) all fclean bonus re