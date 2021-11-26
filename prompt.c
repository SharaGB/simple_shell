#include "shell.h"
/**
 * main - Write our prompt
 * Return: Always 0
 */
int main(void)
{
	char *line, *prompt = "$ ";
	size_t linesize = 0;
	size_t readline;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		readline = getline(&line, &linesize, stdin);
        printf("%lu\n", readline);
	}
	return (0);
}
