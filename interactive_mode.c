#include "shell.h"
/**
 * interactive_mode - Write our prompt, mode interactive
 * Return: Always 0
 */
int interactive_mode(void)
{
	size_t readline = 0;
	size_t linezise = 0;
	char *line = NULL;

	signal(SIGINT, handle_signal);
	while (1)
	{
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		readline = getline(&line, &linezise, stdin);
		/*Obtiene la línea y la almacena en line*/
    	line[readline - 1] = 0;
		if (readline == EOF)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		split_line(line);
	}
    free(line);
	return (0);
}

/**
 * handle_signal - Function that handles the ^C signal
 * @sign: Check our ^C signal
 */
void handle_signal(int sign __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
