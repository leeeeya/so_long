/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:03:33 by cstefany          #+#    #+#             */
/*   Updated: 2022/05/12 13:03:37 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	write_moves(t_map *map)
{
	char	*concat;
	char	*ia;

	ia = ft_itoa(map->step_counter);
	concat = ft_strjoin("Moves: ", ia);
	mlx_string_put(map->mlx.mlx, map->mlx.mlx_win, 15, 50, 0xFFFFFFFF, concat);
	if (ia)
		free(ia);
	if (concat)
		free(concat);
}

void	if_bonus(int h, int *w, int *j)
{
	if (h == 0)
	{
		*w = IMG_SIZE;
		(*j)++;
	}
}
