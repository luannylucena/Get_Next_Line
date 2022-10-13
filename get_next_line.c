/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:38:26 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/13 21:20:52 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//O objetivo é criar uma função que possa retornar uma única linha lida de um descritor 
//de arquivo, sem perder o rastro da próxima linha e com tamanho de buffer aleatório.

// Para que possamos ler um arquivo é necessário que ele esteja aberto. 
// Para abrir o arquivo é necessário definidir se o mesmo vai ser usado para 'leitura' (read) ou 
// 'escrita' (write). Para 'leitura' é necessário que o arquivo já exista, para 'escrita', criamos 
// um novo arquivo onde dados de saída serão escritos, ou sobrescrevemos um arquivo existente.

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	char *buff;
	int i;
	
	buff = (char *)malloc(sizeof(char *) * BUFFER_SIZE + 1);
	i = read(fd, buff, BUFFER_SIZE); //buff -> vai armazenar a leitura que foi feita.
// se eu der um 'int = read(fd, buff, buff_SIZE) => Vai me dar o tamanho do buff_size.	
	//char *string;
	//string = (char *) malloc (sizeof(char *) * 30);
	//string[30] = '\0';
	buff[21] = '\0';
	printf("%s!primeirachamada!\n", buff);
	if(i == 0)
		return (NULL);
	//while (buff_SIZE ) 
	return (buff); //preciso usar uma static para armazenar os valores lidos antes, pois 
	//o buffer sempre vai ser zerado, mudando de posição e não armezano o que foi lido anterormente.
}

int main()
{
	int fd;

	char *line;

	fd = open("teste.txt", O_RDONLY);

	line = "";

	while (line != NULL)
	{
		line = get_next_line(fd);
		//printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
