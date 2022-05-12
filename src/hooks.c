/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:53:46 by cstefany          #+#    #+#             */
/*   Updated: 2022/04/27 13:53:51 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_options(int x_move, int y_move, t_map *map)
{
	int	x_player;
	int	y_player;

	x_player = map->player_pos[0];
	y_player = map->player_pos[1];
	map->step_counter++;
	if (map->map[y_player + y_move][x_player + x_move] == 'E')
	{
		map->map[y_player][x_player] = '0';
		map->game_over = 1;
	}
	else if (map->map[y_player + y_move][x_player + x_move] != '1'
		&& !map->game_over)
	{
		if (map->map[y_player + y_move][x_player + x_move] == 'C')
			map->current_score++;
		map->map[y_player][x_player] = '0';
		map->map[y_player + y_move][x_player + x_move] = 'P';
	}
}

void	all_dir(int keycode, t_map *map)
{
	if (keycode == 2 || keycode == 124)
		move_options(1, 0, map);
	if (keycode == 0 || keycode == 123)
		move_options(-1, 0, map);
	if (keycode == 13 || keycode == 126)
		move_options(0, -1, map);
	if (keycode == 1 || keycode == 125)
		move_options(0, 1, map);
}

void	ft_move(int keycode, t_map *map)
{
	all_dir(keycode, map);
	if (!map->game_over)
	{
		player_position(map);
		put_images(map);
	}
	else
		ft_gameover(map);
	write(1, "Moves: ", 7);
	ft_putnbr_fd(map->step_counter, 1);
	write(1, "\r", 1);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
		ft_close();
	ft_move(keycode, map);
	return (0);
}
