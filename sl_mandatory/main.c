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

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		write (2, "Invalid number of arguments\n", 28);
		return (0);
	}
	create_map(argv[1], &map);
	map.mlx.mlx = mlx_init();
	map.mlx.mlx_win = mlx_new_window(map.mlx.mlx, IMG_SIZE * map.width,
			IMG_SIZE * map.height, "so_long");
	drawing_map(&map);
	mlx_hook(map.mlx.mlx_win, 17, 0, ft_close, NULL);
	mlx_hook(map.mlx.mlx_win, 2, 0, key_hook, &map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
