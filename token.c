#include "shell.h"
/**
 * execute - Function to execute a program:
 * @pathname: Check path
 * @argv: Array of string pointers passed to new program
 * @envp: Environment variable, array of pointers to strings
 * Return:
 */
int execute(const char *pathname, char **argv, char **environ)
{
	pid_t pid;
    int status;

    split_line = (argv, str);
	pid = fork();
	if (pid == 0)
	{
		if (execve(pathname, argv, environ) == -1)
		{
			perror(argv[0]);
			return (0);
		}
	}
	else if (pid < 0)
	{
		perror(argv[0]);
		return (0);
	}
	else
	{
		(wait(&status));
	}
	return (1);
}

/**
 * split_line - Function that tokenizes the command line
 * @str: Is the string to be tokenized
 * @str_list: Double pointer that divides by words
 */
void *split_line(char *str, char **str_list)
{
	int position = 0;
	int size = TOK_BUFSIZE;
	char *token_line = NULL;
	const char delimitador[] = " \n\t";
	/*Se usa un delimitador para decri que es el final de una palabra*/
	str_list = malloc(size * sizeof(char *) + 1);
	if (!str_list)
	{
		free(str_list);
		return (NULL);
	}
	token_line = strtok(str, delimitador); /*Lo almacena dentro de token_linen */
	while (token_line)
	{
		str_list[position] = token_line; /*Recorre la acadena en cada posición*/
		token_line = strtok(NULL, delimitador);
		/*Se pasa NULL como primer argumento para obtener el siguiente token*/
		position++;

	}
	str_list[position] = NULL; /*Establece str_list a NULL*/
	free(str_list);
}
