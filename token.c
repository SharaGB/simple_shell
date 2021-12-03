#include "shell.h"
/**
 * split_line - Function that tokenizes the command line
 * @str: Is the string to be tokenized
 */
void split_line(char *str)
{
	int position = 0;
	char **tokens = NULL;
	int buf = counter(str);
	char *token_line = NULL;

	/*Se usa un delimitador para decir que es el final de una palabra*/
	tokens = malloc((counter(str) + 1) * sizeof(char *));
	if (!tokens)
	{
		free(tokens);
	}
	token_line = strtok(str, DELIMITER); /*Lo almacena dentro de token_linen*/
	while (token_line)
	{
		tokens[position] = token_line; /*Recorre la acadena en cada posición*/
		token_line = strtok(NULL, DELIMITER);
		/*Se pasa NULL como primer argumento para obtener el siguiente token*/
		position++;

	}
	tokens[position] = NULL; /*Establece str_list a NULL*/
	execute(tokens);
	free(tokens);
}
