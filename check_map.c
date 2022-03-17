#include "so_long.h"



void check_map(char *path, t_map *map)
{
	int		fd;
	char	*str;
	int		i = 0;
	t_list	*tmp_map = NULL;
	char	*tmp_str;
	t_list	*new_node;


	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: fd\n", 10);
		exit(0);
	}
	tmp_str = get_next_line(fd);
	map->x = (int) ft_strlen(tmp_str) - 1;
	if (map->x < 3)
		map_error(tmp_str, NULL);
	while (tmp_str)
	{
		str = ft_strtrim(tmp_str, "\n");
		if (ft_strlen(str) != map->x)
		{
			printf("ERROR\n");
			exit(0);
		}
		mem_error_handler2(str, NULL);
		free(tmp_str);
		tmp_str = NULL;
		new_node = ft_lstnew(str);
		////handler
		ft_lstadd_back(&tmp_map, new_node);
		tmp_str = get_next_line(fd);
	}
	while (tmp_map)
	{
		printf("%s\n", tmp_map->content);
		tmp_map = tmp_map->next;
	}


//	while (1)
//	{
//		tmp_str = get_next_line(fd);
//		if (!tmp_str)
//			break ;
//		str = ft_strtrim(tmp_str, "\n");
//		mem_error_handler2(str, &tmp_map);
//		free(tmp_str);
//		new_node = ft_lstnew(str);
//		mem_error_handler2(str, &tmp_map);
//		ft_lstadd_back(&tmp_map,new_node);
//		free(str);
//
//	}
//	if (ft_lstsize(tmp_map) < 3)
//		map_error(NULL, &tmp_map);
//
//	while (tmp_map)
//	{
//		printf("%s\n", (char *)tmp_map->content);
//		tmp_map = tmp_map->next;
//	}
}

