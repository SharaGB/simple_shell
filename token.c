#include "main.h"
/**
 * split_line - Function that tokenizes the command line
 * @str: Is the string to be tokenized
 * Return: 0
 */
void split_line(char *str)
{
	int position = 0;
	char **tokens = NULL;
	char *token_line = NULL;

	/*Se usa un delimitador para decir que es el final de una palabra*/
	tokens = malloc(sizeof(char *) * 1024);
	/*Necesitará reservar memoria para almacenar los tokens*/
	if (!tokens)
	{
		free(tokens);
		exit(1);
	}
	token_line = strtok(str, DELIMITER); /*Lo almacena dentro de token_linen*/
	while (token_line)
	{
		tokens[position] = _strdup(token_line); /*Recorre la str en cada posición*/
		token_line = strtok(NULL, DELIMITER);
		/*Se pasa NULL como primer argumento para obtener el siguiente token*/
		position++;
	}
	tokens[position] = NULL;
	free(token_line);
	get_func(tokens);
	for (position = 0; tokens[position]; position++)
	{
		free(tokens[position]);
	}
	free(tokens);
}
