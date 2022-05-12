NAME = so_long
NAME_B = so_long_bonus

SRC = 	./src/init_map.c \
		./src/errors.c \
		./GNL/get_next_line.c \
		./GNL/get_next_line_utils.c \

SRC_M = ./src/main.c \
		./src/hooks.c \
		./src/game_over.c \
		./src/drawing_map.c \
		./src/validation_check.c \

SRC_B = ./src/bonus/main_bonus.c \
		./src/bonus/hooks_bonus.c \
		./src/bonus/game_over_bonus.c \
		./src/bonus/drawing_map_bonus.c \
		./src/bonus/validation_check_bonus.c \
		./src/bonus/enemy.c \
		./src/bonus/bonus.c \

OBJ = $(SRC:%.c=%.o)
OBJ_M = $(SRC_M:%.c=%.o)
OBJ_B = $(SRC_B:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

COMPILE_FLAGS = -framework OpenGL -framework Appkit
HEADER = ./src/so_long.h
HEADER = ./src/bonus/so_long_bonus.h
LIB_MLX = ./minilibx_opengl_20191021 -lmlx $(COMPILE_FLAGS)
LIB_FT = ./libft -lft

LINK_LIBS = -L$(LIB_MLX) -L$(LIB_FT)

all: $(NAME)  $(SRC) $(SRC_M)

$(NAME): $(OBJ) $(OBJ_M) $(HEADER)
	make -C ./minilibx_opengl_20191021
	make -C ./libft
	gcc $(CFLAGS) $(OBJ) $(OBJ_M) $(LINK_LIBS) -o $(NAME)

$(OBJ) : %.o : %.c
	gcc $(CFLAGS) -c  $< -o $@

$(OBJ_M) : %.o : %.c
	gcc $(CFLAGS) -c  $< -o $@

bonus: $(NAME_B)  $(SRC) $(SRC_B)

$(NAME_B): $(OBJ_B) $(OBJ) $(HEADER_B)
	make -C ./minilibx_opengl_20191021
	make -C ./libft
	gcc $(CFLAGS) $(OBJ) $(OBJ_B) $(LINK_LIBS) -o $(NAME_B)

$(OBJ_B) : %.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)  $(OBJ_B) $(OBJ_M)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	make fclean -C $(LIB_FT)


re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re