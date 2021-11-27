#include "shell.h"
/**
 * split - Function that split a string
 * @str: Check string
 * @str_list: Double pointer that divides by words
 */
void split(char *str, char **str_list)
{
	const char delimitador[] = " ";
	char *token_line = strtok(str, delimitador);
	int i = 0;

	while (token_line)
	{
		str_list[i] = token_line;
		i++;
		token_line = strtok(NULL, delimitador);

		str_list[i] = NULL;
	}
}

pid_t fork(int argc, char **argv)
{
    pid_t pid;
    int fd[2];

}