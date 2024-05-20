NAME = cub3D
CC = cc
LIBPARS= ./parsing/libpars.a
LIBFT= ./parsing/libft/libft.a
RM = rm -f
HEADER = render_map.h

CFLAGS_COMPILING= -Wall -Wextra -Werror -Imlx
CFLAGS_LINKING= -lmlx -framework OpenGL -framework AppKit

SRC =	cast_rays.c clean_data.c destroy.c clean_images_window.c \
		get_color_from_texture.c get_height.c  getwidth.c \
		handle_horizantal.c handle_vert.c has_wall_in_path.c helper_func.c \
		init_info_rays.c init_player_data.c is_inside_map.c is_player.c is_wall.c \
		move.c norm_angl.c release.c render_.c render_map.c \
 		main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)
 
$(NAME) : $(LIBPARS) $(LIBFT) $(OBJ)
	@$(CC) $(OBJ)  $(LIBPARS) $(LIBFT)  $(CFLAGS_LINKING) -o $(NAME)
	@echo "the executable $(NAME) has been created"

$(LIBPARS) : parsing/libpars.h parsing/libft/libft.h
	@make -C parsing all

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS_COMPILING) -c $< -o $@
	@echo "the file $@ has been created from $<"

clean :
	@$(RM) $(OBJ)
	@make -C ./parsing clean
	@echo "all the .o has been deleted successfully"

fclean : clean
	@$(RM) $(NAME)
	@make -C ./parsing fclean
	@echo "the archieve $(NAME) has been deleted"

re : fclean all

.PHONY : all clean fclean $(LIBPARS) $(LIBFT) $(NAME)