#include "main.h"
/**
 * main - Function that write our prompt, mode interactive
 * Return: Always 0
 */
int main(void)
{
	int readline = 0;
	char *line = NULL;
	size_t linezise = 0;


	signal(SIGINT, handle_signal); /*Manejador de señales, va a ser ignorada*/
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		}
		readline = getline(&line, &linezise, stdin);
		/*Obtiene la línea y la almacena en line*/
		if (readline == EOF) /*End of file*/
		{
			free(line);
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (0);
		}
		split_line(line);
	}
	free(line);
	return (0);
	exit(EXIT_SUCCESS);
}

/**
 * handle_signal - Function that handles the ^C signal
 * @sign: Check our ^C signal
 */
void handle_signal(int sign __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n🧿 $ ", 9);
}
