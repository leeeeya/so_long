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

#include "so_long_bonus.h"

void	move_options(int x_move, int y_move, t_map *map)
{
	int	x_player;
	int	y_player;

	x_player = map->player_pos[0];
	y_player = map->player_pos[1];
	if (map->map[y_player + y_move][x_player + x_move] == 'E')
	{
		map->map[y_player][x_player] = '0';
		map->game_over = 1;
	}
	else if (map->map[y_player + y_move][x_player + x_move] == 'V')
	{
		map->map[y_player][x_player] = '0';
		map->game_over = 1;
		map->enemy_go = 1;
	}
	else if (map->map[y_player + y_move][x_player + x_move] != '1'
		&& !map->game_over)
	{
		if (map->map[y_player + y_move][x_player + x_move] == 'C')
			map->current_score++;
		map->map[y_player][x_player] = '0';
		map->map[y_player + y_move][x_player + x_move] = 'P';
		map->step_counter++;
	}
}

void	left_right(int keycode, t_map *map)
{
	int	x;
	int	y;

	if (keycode == 2 || keycode == 124)
	{
		move_options(1, 0, map);
		map->player = mlx_xpm_file_to_image(map->mlx.mlx,
				"./textures/right.xpm", &x, &y);
	}
	if (keycode == 0 || keycode == 123)
	{
		move_options(-1, 0, map);
		map->player = mlx_xpm_file_to_image(map->mlx.mlx,
				"./textures/left.xpm", &x, &y);
	}
}

void	up_down(int keycode, t_map *map)
{
	int	x;
	int	y;

	if (keycode == 13 || keycode == 126)
	{
		move_options(0, -1, map);
		map->player = mlx_xpm_file_to_image(map->mlx.mlx,
				"./textures/back.xpm", &x, &y);
	}
	if (keycode == 1 || keycode == 125)
	{
		move_options(0, 1, map);
		map->player = mlx_xpm_file_to_image(map->mlx.mlx,
				"./textures/player.xpm", &x, &y);
	}
}

void	ft_move(int keycode, t_map *map)
{
	left_right(keycode, map);
	up_down(keycode, map);
	if (!map->game_over)
	{
		player_position(map);
		put_images(map);
	}
	else
		ft_gameover(map);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
		ft_close();
	ft_move(keycode, map);
	return (0);
}
