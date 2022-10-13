/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:16:02 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/13 21:18:00 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H // Verifica se a biblioteca já existe.
# define GET_NEXT_LINE_H // Se não existir, criamos. 

#ifndef BUFFER_SIZE //comando para não precisar usar a flag do buffer_size no código
# define BUFFER_SIZE 20 //sempre melhor começar com um número mais baixo, para conseguir fazer os testes
//necesásrios. 
#endif
//abaixo, coloco as bibliotecas que usei
#include <stdlib.h> // Biblioteca para usar as funções malloc e free.

char	*get_next_line(int fd); //colocar os protótipos de funções que usei

#endif // final

