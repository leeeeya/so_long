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

void	if_error(char error, char *tmp_str)
{
	if (error == 'e' && !tmp_str)
	{
		write(1, "Error: Empty file\n", 18);
		exit(1);
	}
	if (error == 'f')
	{
		write(1, "Error: Invalid file\n", 20);
		exit(1);
	}
}

int	check_file(char *path)
{
	int		i;
	char	*tmp;
	int		fd;
	int		len;

	i = 0;
	tmp = path;
	if (ft_strlen(tmp) < 5)
		if_error('f', NULL);
	len = (int)ft_strlen(tmp);
	while (i < len - 4)
	{
		i++;
		tmp++;
	}
	if (ft_strncmp(tmp, ".ber", (int)ft_strlen(".ber")))
		if_error('f', NULL);
	fd = open(path, O_RDONLY);
	check_fd_error(fd);
	return (fd);
}

t_list	*create_list(char *path, t_map *map)
{
	int		fd;
	char	*str;
	t_list	*tmp_map;
	char	*tmp_str;
	t_list	*new_node;

	fd = check_file(path);
	tmp_str = get_next_line(fd);
	if_error('e', tmp_str);
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
