/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:05:32 by cstefany          #+#    #+#             */
/*   Updated: 2022/04/27 14:05:33 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.mlx_win = mlx_new_window(map->mlx.mlx, IMG_SIZE * map->width,
			IMG_SIZE * map->height, "so_long");
	drawing_map(map);
	mlx_hook(map->mlx.mlx_win, 17, 0, &ft_close, NULL);
	mlx_hook(map->mlx.mlx_win, 2, 0, &key_hook, map);
	if (enemy(map))
		mlx_loop_hook(map->mlx.mlx, &loop_hook, map);
	mlx_loop(map->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		write (2, "invalid number of arguments\n", 28);
		return (0);
	}
	create_map(argv[1], &map);
	start(&map);
	return (0);
}
