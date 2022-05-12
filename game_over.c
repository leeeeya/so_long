/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:51:32 by cstefany          #+#    #+#             */
/*   Updated: 2022/04/27 13:51:33 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_frame(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (h != IMG_SIZE * map->height)
	{
		w = 0;
		while (w != IMG_SIZE * map->width)
		{
			if (h == 0 || h == IMG_SIZE * map->height - IMG_SIZE
				|| w == 0 || w == IMG_SIZE * map->width - IMG_SIZE)
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win,
					map->wall, w, h);
			w += IMG_SIZE;
		}
		h += IMG_SIZE;
	}
}

void	ft_gameover(t_map *map)
{
	int	x_words;
	int	y_words;
	int	average_x;
	int	average_y;

	average_x = map->width;
	average_y = map->height;
	if (average_x % 2 == 1)
		average_x++;
	if (average_y % 2 == 1)
		average_y++;
	x_words = (average_x / 2) * IMG_SIZE - IMG_SIZE * 2;
	y_words = (average_y / 2) * IMG_SIZE - IMG_SIZE;
	field(map);
	draw_frame(map);
	if (map->current_score != map->col_amount || map->enemy_go)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->gameover,
			x_words, y_words);
	else
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->win,
			x_words, y_words);
}
