#include "shell.h"
/**
 * interactive_mode - Write our prompt, mode interactive
 * Return: Always 0
 */
int main(void)
{
	size_t readline = 0;
	size_t linesize = 32;
	char *prompt = "$ ";
	char *line = malloc(sizeof(char) * linesize);
	/*Bufer para almacenar la entrada del usuario*/

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		readline = getline(&line, &linesize, stdin);
		/*Obtiene la línea y la almacena en line*/
		while (readline == EOF)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			return (readline);
		}
	}
	return (readline);
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

/**
 * main - Function that separate two modes
 * Return: 0
 *
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("interactive_mode");
	}
	return (0);
} */
