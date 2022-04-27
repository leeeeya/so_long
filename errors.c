/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:50:13 by cstefany          #+#    #+#             */
/*   Updated: 2022/04/27 13:50:15 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mem_error_handler(char *mem)
{
	if (!mem)
	{
		write(2, "ERROR: Memory allocation error\n", 31);
		exit(12);
	}
}

void	free_and_exit(t_list **tmp_map, char error)
{
	if (tmp_map)
		ft_lstclear(tmp_map, free);
	if (error == 'm')
		write(2, "ERROR: Memory allocation error\n", 31);
	else if (error == 'v')
		write(2, "Error: Invalid map\n", 19);
	else if (error == 'l')
		write(2, "Too large map\n", 14);
	exit(12);
}

void	check_fd_error(int value)
{
	if (value < 0)
	{
		write(2, "Error: fd\n", 10);
		exit(0);
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
