cmake_minimum_required(VERSION 3.21)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long
        ./GNL/get_next_line.c
        check_map.c
        errors.c
        main.c)

target_link_libraries(so_long /Users/cstefany/Desktop/so_long/libft/libft.a)