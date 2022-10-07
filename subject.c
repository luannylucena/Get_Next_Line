
GNL SUBJECT
___________

Repeated calls (e.g., using loop) to your get_next_line() function should let you read the next 
file file pointed to by the file descriptor, one line at a time. 
// Chamadas repetidas (por exemplo, usando um loop) para sua função get_next_line() devem permitir
// você lê o arquivo de texto apontado pelo descritor de arquivo, uma linha de cada vez.

Your function should return the line that was read. 
If there is nothing else to read or if an error occurred, it should return NULL.
//Sua função deve retornar a linha que foi lida. Se não houver mais nada para ler 
//ou se ocorrer um erro, deve retornar NULL.

Make sure that your function works as expected both when reading a file and when reading from
the standard input.
//Certifique-se de que sua função funcione conforme o esperado ao ler um arquivo e ao ler da 
//entrada padrão

Please note that the returned line should include the terminating \n character, except if the 
and of file was reached and does not end with a \n character.
// Observe que a linha retornada deve incluir o caractere final \n, exceto se o final do arquivo 
//f oi atingido e não termina com um caractere \n.

Your header file get_next_line.h must at least contain the prototype of the get_next_line() function.
// Seu arquivo de cabeçalho get_next_line.h deve conter pelo menos o protótipo do função get_next_line().

Add all the helper functions you need in the get_next_line_utils.c file.
// Adicione todas as funções auxiliares que você precisa no arquivo get_next_line_utils.c

!!!A good start would be to know what a 'static variable' is.
// Um bom começo seria saber o que é uma variável estática.

Because you will have to read files in get_next_line(), add this option to your compiler call:
-D BUFFER_SIZE=N.
It will define the buffer size for read().
The buffer size value will be modified by your peer-evaluators and the Moulinette in order to
test your code.
// Como você terá que ler os arquivos em get_next_line(), adicione esta opção à sua chamada do 
// compilador: -D BUFFER_SIZE=n. Ele definirá o tamanho do buffer para read(). O valor do tamanho do 
// buffer será modificado por seus avaliadores de pares e pelo Moulinette para testar seu código.

You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
// Você compilará seu código da seguinte forma (um tamanho de buffer de 42 é usado como exemplo):
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <arquivos>.c

We consider that get_next_line() has an undefined behavior if the file pointed to by the file 
descriptor changed since the last call whereas read() did not reach the end of file.
// Consideramos que get_next_line() tem um comportamento indefinido se o arquivo apontado pelo descritor 
// de arquivo mudou desde a última chamada enquanto read() não chegou ao final do arquivo.

We also consider that get_next_line() has an undefined behavior when reading a binary file. 
However, you can implement a logical way to handle this behavior if you want.
// Também consideramos que get_next_line() tem um comportamento indefinido ao ler um arquivo binário. 
// No entanto, você pode implementar uma maneira lógica de lidar com esse comportamento se você quer.

!!!Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000? Do you know why?

!!!Try to read as little as possible each time get_next_line() is called. If you enconter a new line,
you have to return the current line. Do not read the whole file and then process each line.
// Tente ler o mínimo possível cada vez que get_next_line() for chamado. Se você encontrar uma nova linha, 
// deverá retornar a linha atual. Não leia o arquivo inteiro e depois processe cada linha.

Forbidden (proibido)

- You are not allowed to use your libft in this project.
- lseek() is forbidden. 
- Global variables are forbidden.



