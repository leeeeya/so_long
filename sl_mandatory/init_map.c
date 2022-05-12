/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:03:03 by cstefany          #+#    #+#             */
/*   Updated: 2022/04/27 14:03:05 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player_pos[0] = j;
				map->player_pos[1] = i;
			}
			j++;
		}
		i++;
	}
}

t_list	*create_list(char *path, t_map *map)
{
	int		fd;
	char	*str;
	t_list	*tmp_map;
	char	*tmp_str;
	t_list	*new_node;

	fd = open(path, O_RDONLY);
	check_fd_error(fd);
	tmp_str = get_next_line(fd);
	while (tmp_str)
	{
		str = ft_strtrim(tmp_str, "\n");
		free(tmp_str);
		tmp_str = NULL;
		if (!str)
			free_and_exit(&tmp_map, 'm');
		new_node = ft_lstnew(str);
		if (!new_node)
			free_and_exit(&tmp_map, 'm');
		ft_lstadd_back(&tmp_map, new_node);
		tmp_str = get_next_line(fd);
	}
	validation_check(tmp_map, map);
	return (tmp_map);
}

void	create_map(char *path, t_map *map)
{
	t_list	*map_list;
	int		i;

	i = 0;
	map_list = create_list(path, map);
	map->map = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		free_and_exit(&map_list, 'm');
	while (map_list)
	{
		map->map[i] = ft_strdup(map_list->content);
		if (!map->map[i])
		{
			free_array(map->map);
			free_and_exit(&map_list, 'm');
		}
		ft_lstdelone(map_list, free);
		map_list = map_list->next;
		i++;
	}
	ft_lstclear(&map_list, free);
}
