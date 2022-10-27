/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:38:26 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/27 23:40:57 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_line(int fd, char *store_rest)
{
	char	*buff;
	int		byte_read;

	buff = (char *)malloc(sizeof(char *) * BUFFER_SIZE + 1);
	byte_read = 1;
	while (!ft_strchr(store_rest, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte_read] = '\0';
		store_rest = ft_strjoin(store_rest, buff);
	}
	free(buff);
	return (store_rest);
}

char	*print_first_line(char *store_rest)
{
	char	*line;
	int		i;

	i = 0;
	if (!store_rest[i])
		return (NULL);
	while (store_rest[i] && store_rest[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char *) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (store_rest[i] && store_rest[i] != '\n')
	{
		line[i] = store_rest[i];
		i++;
	}
	if (store_rest[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*separate_line(char *store_rest)
{
	char	*after_n;
	int		i;
	int		y;

	i = 0;
	while (store_rest[i] && store_rest[i] != '\n')
		i++;
	if (!store_rest[i])
	{
		free(store_rest);
		return (NULL);
	}
	after_n = (char *)malloc(sizeof (char *) * ft_strlen(store_rest) - i + 1);
	if (!after_n)
		return (NULL);
	i++;
	y = 0;
	while (store_rest[i])
		after_n[y++] = store_rest[i++];
	after_n[y] = '\0';
	free(store_rest);
	return (after_n);
}

char	*get_next_line(int fd)
{
	static char	*store_rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store_rest = read_line(fd, store_rest);
	if (!store_rest)
		return (NULL);
	line = print_first_line(store_rest);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	store_rest = separate_line(store_rest);
	return (line);
}
