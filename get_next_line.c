/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:38:26 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/12 00:14:56 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//O objetivo é criar uma função que possa retornar uma única linha lida de um descritor 
//de arquivo, sem perder o rastro da próxima linha e com tamanho de buffer aleatório.

// Para que possamos ler um arquivo é necessário que ele esteja aberto. 
// Para abrir o arquivo é necessário definidir se o mesmo vai ser usado para 'leitura' (read) ou 
// 'escrita' (write). Para 'leitura' é necessário que o arquivo já exista, para 'escrita', criamos 
// um novo arquivo onde dados de saída serão escritos, ou sobrescrevemos um arquivo existente.

char	*get_next_line(int fd)
{
	
}
