#include "shell.h"
/**
 * main - Write our prompt
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL; 
	char *prompt = "#cisfun$ ";
	size_t linesize = 0;
	size_t readline = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		readline = getline(&line, &linesize, stdin);
        printf("%lu\n", readline);
	}
	return (0);
}

/**
 * _strlen_recursion - Length of a string
 * @s: Check of string
 * Return: The length of a string
 */
int _strlen_recursion(char *s)
{
	int len;

	len = 0;
	if (*s != '\0')
	{
		len = _strlen_recursion(s + 1);
		len++;
	}
	return (len);
}
