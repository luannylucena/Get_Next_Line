## Get_Next_Line

Este projeto aborda conceitos como variáveis estáticas, alocação dinâmica de memória, descritores de arquivos e macros enquanto resolve 
uma tarefa simples: usar a função padrão do Linux read() para ler um arquivo em busca de linhas individuais 
(ou seja, sequências de caracteres terminadas por um único \n, o caractere de nova linha).

### Arquivos:

- Implementação da função: `get_next_line.c`
- Funções auxiliares (requisito do projeto): `get_next_line_utils.c`
- Arquivo de cabeçalho `get_next_line.h`

### Rodando o programa

No seu terminal, certifique-se de estar no mesmo nível dos arquivos *.c, e então execute o comando:
`gcc get_next_line_utils.c get_next_line.c main.c -D BUFFER_SIZE=42 -o get_next_line`

Aqui, BUFFER_SIZE determina o tamanho do buffer usado para ler o arquivo (em outras palavras, quantos 
caracteres serão lidos de uma vez a cada chamada read()). Para executar o programa, insira o seguinte no prompt de comando:
- `./get_next_line`
