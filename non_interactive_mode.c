#include "main.h"
/**
 * non_interactive_mode - Non-interactive printing function
 * Return: Void
 */
void non_interactive_mode(void)
{
	char *line = NULL;
	size_t readline = 0;
	size_t linezise = 0;

	readline = getline(&line, &linezise, stdin);
	/*Obtiene la línea y la almacena en line*/
	if (readline)
	{
		exit(EXIT_SUCCESS);
	}
	split_line(line);
	free(line);
}
