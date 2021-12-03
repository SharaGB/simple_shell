#include "shell.h"
/**
 * main - Function that write our prompt, mode interactive
 * Return: Always 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	size_t readline = 0;
	size_t linezise = 0;
	char *line = NULL;
	int interactive_mode = 0;

	signal(SIGINT, handle_signal); /*Manejador de señales, va a ser ignorada*/
	if (isatty(STDIN_FILENO) == 0) /*Descriptor de archivo de la entrada std*/
	{
		non_interactive_mode();
		return (1);
	}
	while (!interactive_mode)
	{
		interactive_mode = isatty(STDIN_FILENO);

		while (1)
		{
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
		}
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
	fflush(stdout); /*Limpia el flujo de la salida estándar*/
}
