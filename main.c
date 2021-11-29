#include "shell.h"
/**
 * main - Write our prompt
 * Return: Always 0
 */
int interactive_mode(void)
{
	char *line = NULL;
	char *prompt = "$ ";
	size_t linesize = 0;
	size_t readline = 0;

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen_recursion(prompt));
		readline = getline(&line, &linesize, stdin);

		while (readline == EOF)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			return (readline);
		}
	}
	printf("%s\n", line);
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
 * 
 * @brief 
 */
int main(void)
int fd;
if (isatty (fileno (stdin)))
fd = interactive_mode; 
else 
return (0);
