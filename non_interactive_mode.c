#include "main.h"
/**
 * non_interactive_mode - Non-interactive printing function
 * Return: 0
 */
void non_interactive_mode(void)
{
	char *line = NULL;
	char **args = NULL;
	size_t readline = 0;
	size_t linezise = 0;
	int non_int_mode = 0;

	write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	readline = getline(&line, &linezise, stdin);
	/*Obtiene la línea y la almacena en line*/
	line[readline - 1] = 0;
	if (readline == EOF) /*End of file*/
	{
		free(line);
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	split_line(line);
	if (!args)
	{
		free_args(args);
	}
	free(line);
	return (0);
}
