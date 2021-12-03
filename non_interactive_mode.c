#include "shell.h"
/**
 * @brief 
 * 
 */
void non_interactive_mode()
{
	char *line = NULL;
	size_t readline = 0;
	size_t linezise = 0;
	int non_int_mode = 0;

	non_int_mode = isatty(STDIN_FILENO);
	write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	readline = getline(&line, &linezise, stdin);
	/*Obtiene la línea y la almacena en line*/
	line[readline - 1] = 0;
	split_line(line);
	free(line);
}