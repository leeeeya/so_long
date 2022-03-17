/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:18:10 by cstefany          #+#    #+#             */
/*   Updated: 2021/11/06 20:18:15 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	mem_error_handler(char *mem)
{
	if (!mem)
	{
		free(mem);
		write(2, "ERROR: Memory allocation error\n", 31);
		exit(12);
	}
}

char	*read_line(int fd, char **next_line)
{
	ssize_t	res;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	while (1)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
		{
			free(*next_line);
			write(2, "Error: read\n", 12);
			exit(1);
		}
		buf[res] = '\0';
		tmp = ft_strjoin(*next_line, buf);
		mem_error_handler(tmp);
		free(*next_line);
		*next_line = tmp;
		if (!res || ft_strchr(buf, '\n'))
			break ;
	}
	return (*next_line);
}

char	*cut_line(char **next_line)
{
	char	*eol;
	char	*reminder;
	char	*n;

	n = ft_strchr(*next_line, '\n');
	if (n && n[1] != '\0')
	{
		reminder = ft_strdup(n + 1);
		mem_error_handler(reminder);
		*(n + 1) = '\0';
		eol = *next_line;
		*next_line = reminder;
		reminder = NULL;
	}
	else
	{
		eol = ft_strdup(*next_line);
		mem_error_handler(eol);
		free(*next_line);
		*next_line = NULL;
	}
	return (eol);
}

char	*get_next_line(int fd)
{
	static char	*next_line = NULL;

	if (!next_line)
	{
		next_line = ft_strdup("");
		mem_error_handler(next_line);
	}
	next_line = read_line(fd, &next_line);
	if (next_line[0] == '\0')
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	return (cut_line(&next_line));
}
