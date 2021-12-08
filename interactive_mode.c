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
	char *prompt = "🧿 $ ";
	int interactive_mode = 0;


	signal(SIGINT, handle_signal); /*Manejador de señales, va a ser ignorada*/
	if (isatty(STDIN_FILENO) == 0) /*Descriptor de archivo de la entrada std*/
	{
		non_interactive_mode();
		return (0);
	}
	while (!interactive_mode)
	{
		while (1)
		{
			write(STDOUT_FILENO, prompt, _strlen(prompt));
			readline = getline(&line, &linezise, stdin);
			/*Obtiene la línea y la almacena en line*/
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
	write(STDOUT_FILENO, "\n🧿 $ ", 9);
}
