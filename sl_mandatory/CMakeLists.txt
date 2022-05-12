cmake_minimum_required(VERSION 3.21)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long
        validation_check.c
        init_map.c
        ./GNL/get_next_line.c
        errors.c
        main.c
        )

target_link_libraries(so_long /Users/cstefany/Desktop/so_long/libft/libft.a
        /Users/cstefany/Desktop/so_long/minilibx_opengl_20191021/libmlx.a
        )

target_compile_options(so_long INTERFACE -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit)
