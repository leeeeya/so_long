/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:04:35 by cstefany          #+#    #+#             */
/*   Updated: 2022/05/12 13:04:38 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*enemy_position(char **map)
{
	int	*position;
	int	i;
	int	j;

	position = ft_calloc(2, sizeof(int));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'V')
			{
				position[0] = j;
				position[1] = i;
			}
			j++;
		}
		i++;
	}
	return (position);
}

void	move_enemy(t_map *map, int x, int y, int dir)
{
	if (map->map[y][x + dir] == 'P')
	{
		map->game_over = 1;
		map->enemy_go = 1;
	}
	else if (map->map[y][x + dir] != '1' && map->map[y][x + dir] != 'C'
				&& map->map[y][x + dir] != 'E')
	{
		map->map[y][x] = '0';
		map->map[y][x + dir] = 'V';
	}
}

void	direction(t_map *map, int x, int y, int *right)
{
	int	xx;
	int	yy;

	if (*right)
	{
		if (map->map[y][x + 1] == '1' || map->map[y][x + 1] == 'C'
				|| map->map[y][x + 1] == 'E')
			*right = 0;
		move_enemy(map, x, y, 1);
		map->enemy = mlx_xpm_file_to_image(map->mlx.mlx,
				"./textures/wolf_r.xpm", &xx, &yy);
	}
	if (!(*right))
	{
		if (map->map[y][x - 1] == '1' || map->map[y][x - 1] == 'C'
				|| map->map[y][x - 1] == 'E')
			*right = 1;
		move_enemy(map, x, y, -1);
		map->enemy = mlx_xpm_file_to_image(map->mlx.mlx,
				"./textures/wolf_l.xpm", &xx, &yy);
	}
}

int	loop_hook(t_map *map)
{
	static int	i = 0;
	static int	right = 1;
	int			*pos;
	int			x;
	int			y;

	pos = enemy_position(map->map);
	x = pos[0];
	y = pos[1];
	if (i % 4000 == 0 && !map->game_over)
	{
		direction(map, x, y, &right);
		put_images(map);
	}
	else if (map->game_over)
		ft_gameover(map);
	i++;
	free(pos);
	return (0);
}

int	enemy(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (map->zero_amount > 10)
	{
		while (map->map[y][x] != '0')
		{
			x = rand() % map->width;
			y = rand() % map->height;
		}
		map->map[y][x] = 'V';
		return (1);
	}
	return (0);
}
