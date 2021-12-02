#include "shell.h"
/**
 * main - Function that separate two modes
 * Return: 0
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else
		non_interactive_mode();

	return (0);
}
