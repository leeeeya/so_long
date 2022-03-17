//
// Created by Claribel Stefany on 3/16/22.
//

#ifndef SO_LONG_SO_LONG_H
# define SO_LONG_SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"

typedef struct s_map
{
	int	x;
	int y;
	int ex;
	int pos;
	int col;
} t_map;

void	check_map(char *path, t_map *map);
void	mem_error_handler(char *mem);
void	mem_error_handler2(char *mem, t_list **tmp_map);
void	map_error(char *data, t_list **tmp_map);

#endif //SO_LONG_SO_LONG_H
