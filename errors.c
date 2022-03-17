#include "so_long.h"

void	mem_error_handler2(char *mem, t_list **tmp_map)
{
	if (!mem)
	{
		free(mem);
		ft_lstclear(tmp_map, free);
		write(2, "ERROR: Memory allocation error\n", 31);
		exit(12);
	}
}

void map_error(char *data, t_list **tmp_map)
{
	free(data);
	ft_lstclear(tmp_map, free);
	write(2, "Error: Invalid map\n", 19);
	exit(12);
}
