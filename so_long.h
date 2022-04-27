/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:09:33 by cstefany          #+#    #+#             */
/*   Updated: 2022/04/27 14:09:34 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 80

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
# include "./minilibx_opengl_20191021/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}t_mlx;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		ex_amount;
	int		pos_amount;
	int		col_amount;
	int		*player_pos;
	void	*player;
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*gameover;
	void	*win;
	int		current_score;
	int		game_over;
	int		step_counter;
	t_mlx	mlx;
}	t_map;

void	create_map(char *path, t_map *map);
void	validation_check(t_list *tmp_map, t_map *map);
void	mem_error_handler(char *mem);
void	free_and_exit(t_list **tmp_map, char error);
void	check_fd_error(int value);
void	free_array(char **array);
int		ft_close(void);
int		key_hook(int keycode, t_map *map);
void	put_images(t_map *map);
void	field(t_map *map);
void	ft_gameover(t_map *map);
void	player_position(t_map *map);
void	drawing_map(t_map *map);
#endif //SO_LONG_H
