/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:42:04 by cstefany          #+#    #+#             */
/*   Updated: 2022/04/27 13:42:11 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_map *map)
{
	int	x;
	int	y;

	map->floor = mlx_xpm_file_to_image(map->mlx.mlx,
			"./textures/grass.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image(map->mlx.mlx,
			"./textures/tree.xpm", &x, &y);
	map->exit = mlx_xpm_file_to_image(map->mlx.mlx,
			"./textures/exit.xpm", &x, &y);
	map->collect = mlx_xpm_file_to_image(map->mlx.mlx,
			"./textures/carrot.xpm", &x, &y);
	map->player = mlx_xpm_file_to_image(map->mlx.mlx,
			"./textures/player.xpm", &x, &y);
	map->gameover = mlx_xpm_file_to_image(map->mlx.mlx,
			"./textures/gameover.xpm", &x, &y);
	map->win = mlx_xpm_file_to_image(map->mlx.mlx,
			"./textures/win.xpm", &x, &y);
}

void	field(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (h != IMG_SIZE * map->height)
	{
		w = 0;
		while (w != IMG_SIZE * map->width)
		{
			mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win,
				map->floor, w, h);
			w += IMG_SIZE;
		}
		h += IMG_SIZE;
	}
}

void	switch_items(t_map *map, char item, int h, int w)
{
	if (item == '1')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->wall, w, h);
	if (item == 'E')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->exit, w, h);
	if (item == 'P')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->player, w, h);
	if (item == 'C')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->collect, w, h);
	if (item == 'V')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->enemy, w, h);
}

void	put_images(t_map *map)
{
	int	h;
	int	w;
	int	i;
	int	j;

	h = 0;
	i = 0;
	field(map);
	while (h != IMG_SIZE * map->height && map->map[i])
	{
		j = 0;
		w = 0;
		if_bonus(h, &w, &j);
		while (w != IMG_SIZE * map->width && map->map[i][j])
		{
			switch_items(map, map->map[i][j], h, w);
			j++;
			w += IMG_SIZE;
		}
		h += IMG_SIZE;
		i++;
	}
	write_moves(map);
}

void	drawing_map(t_map *map)
{
	images(map);
	put_images(map);
}
