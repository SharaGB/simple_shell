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
	line[readline - 1] = 0;

	split_line(line);
	free(line);
	exit(0);
}
