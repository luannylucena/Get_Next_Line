/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:38:26 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/26 21:46:28 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//O objetivo é criar uma função que possa retornar uma única linha lida de um descritor 
//de arquivo, sem perder o rastro da próxima linha e com tamanho de buffer aleatório.

// Para que possamos ler um arquivo é necessário que ele esteja aberto. 
// Para abrir o arquivo é necessário definidir se o mesmo vai ser usado para 'leitura' (read) ou 
// 'escrita' (write). Para 'leitura' é necessário que o arquivo já exista, para 'escrita', criamos 
// um novo arquivo onde dados de saída serão escritos, ou sobrescrevemos um arquivo existente.

#include "get_next_line.h"
#include <stdio.h>

char *read_line(int fd, char *store_rest)
{
	char *buff;
	int byte_read;

	buff = (char *)malloc(sizeof(char *) * BUFFER_SIZE + 1); //JÁ RECEBENDO O TAMANHO DO BUFFER
	byte_read = 1;
	while (!ft_strchr(store_rest, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if(byte_read == -1)
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

char *print_first_line(char *store_rest)
{
	char *line;
	int i;
	
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

char *separate_line(char *store_rest)
{
	char *after_break_line;
	int i;
	int y;

	i = 0;
	while (store_rest[i] && store_rest[i] != '\n')
		i++;
	if(!store_rest[i])
	{
		free(store_rest);
		return (NULL);
	}
	after_break_line = (char *)malloc(sizeof (char *) * ft_strlen(store_rest) - i + 1);
	if(!after_break_line)
		return (NULL);
	i++;
	y = 0;
	while (store_rest[i])
		after_break_line[y++] = store_rest[i++];
	after_break_line[y] = '\0';
	free(store_rest);
	return (after_break_line);
}

char *get_next_line(int fd)
{
	static char *store_rest;
	char *line;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store_rest = read_line(fd, store_rest); //meu valor guardado é o que aconteceu no meu *read_line(int fd);
	if(!store_rest)
		return (NULL);
	line = print_first_line(store_rest);
	if (!line)
	{
		free(line);
		return(NULL);
	}
	store_rest = separate_line(store_rest);
	return (line);
}

