/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:07:12 by cstefany          #+#    #+#             */
/*   Updated: 2022/04/27 14:07:13 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_map *map, t_list *tmp_map)
{
	map->height = ft_lstsize(tmp_map);
	map->width = (int)ft_strlen(tmp_map->content);
	map->col_amount = 0;
	map->ex_amount = 0;
	map->pos_amount = 0;
	map->current_score = 0;
	map->game_over = 0;
	map->step_counter = 0;
	map->player_pos = ft_calloc(2, sizeof(int));
}

void	check_mid_str(char *mid_str, t_map *map, t_list **tmp_tmp, int i_y)
{
	int	i_x;

	i_x = 0;
	while (i_y != 1 && i_y != map->height && mid_str[i_x])
	{
		if (mid_str[0] != '1' || mid_str[map->width - 1] != '1')
			free_and_exit(tmp_tmp, 'v');
		if (mid_str[i_x] == 'E')
			map->ex_amount++;
		else if (mid_str[i_x] == 'P')
		{
			map->pos_amount++;
			map->player_pos[0] = i_x;
			map->player_pos[1] = i_y - 1;
		}
		else if (mid_str[i_x] == 'C')
			map->col_amount++;
		else if (mid_str[i_x] != '1' && mid_str[i_x] != '0')
			free_and_exit(tmp_tmp, 'v');
		i_x++;
	}
}

void	check_strs(t_list *tmp_map, t_map *map)
{
	int	i_y;
	int	i_x;

	i_y = 1;
	i_x = 0;
	while (tmp_map)
	{
		if ((int)ft_strlen(tmp_map->content) != map->width)
			free_and_exit(&tmp_map, 'v');
		if (i_y == 1 || i_y == map->height)
		{
			while (tmp_map->content[i_x])
			{
				if (tmp_map->content[i_x] != '1')
					free_and_exit(&tmp_map, 'v');
				i_x++;
			}
		}
		check_mid_str(tmp_map->content, map, &tmp_map, i_y);
		i_y++;
		i_x = 0;
		tmp_map = tmp_map->next;
	}
}

void	validation_check(t_list *tmp_map, t_map *map)
{
	init_struct(map, tmp_map);
	if (map->height < 3 || map->width < 3 || map->width * map->height < 15)
		free_and_exit(&tmp_map, 'v');
	if (map->height > 17 || map->width > 32)
		free_and_exit(&tmp_map, 'l');
	check_strs(tmp_map, map);
	if (!map->col_amount || !map->ex_amount || map->pos_amount != 1)
		free_and_exit(&tmp_map, 'v');
}
