NAME = so_long

SRC = main.c \
		init_map.c \
		errors.c \
		validation_check.c \
		./GNL/get_next_line.c \
		./GNL/get_next_line_utils.c \
		hooks.c \
		game_over.c \
		drawing_map.c \
		enemy.c \
		bonus.c \

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

COMPILE_FLAGS = -framework OpenGL -framework Appkit
HEADER = so_long.h
LIB_MLX = ./minilibx_opengl_20191021 -lmlx $(COMPILE_FLAGS)
LIB_FT = ./libft -lft

LINK_LIBS = -L$(LIB_MLX) -L$(LIB_FT)

.PHONY: all clean fclean re

all: $(NAME)  $(SRC)

$(NAME): $(OBJ) $(HEADER)
	make -C ./minilibx_opengl_20191021
	make -C ./libft
	gcc $(CFLAGS) $(OBJ) $(LINK_LIBS) -o $(NAME)

$(OBJ) : %.o : %.c
	gcc $(CFLAGS) -c  $< -o $@

clean:
	@rm -f ./*.o ./libft/*.o ./GNL/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

start: re
	./so_long /Users/cstefany/Desktop/so_long/map.ber