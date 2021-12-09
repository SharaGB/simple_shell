#include "main.h"
/**
 * execute - Function to execute a program
 * @command: The tokenized array
 * Return: On success, execve() does not return, on error -1 is returned,
 * and errno is set to indicate the error.
 */
int execute(char **command)
{
	pid_t pid = 0;
	int status = 0;
	char *pathname = NULL;

	if (access(command[0], X_OK == 0))
	{
		pathname = _which(command[0]);
	}
	pid = fork(); /*Se crea un nuevo proceso*/
	if (pid == -1)
	{
		return (1);
	}
	if (!pid)
	{
		if (pathname == NULL)
		{
			if (execve(command[0], command, environ) == -1)
			{
				perror("./shell");
				exit(1);
			}
		}
		else
		{
			if (execve(pathname, command, environ) == -1)
			{
				perror("./shell");
				exit(1);
			}
		}
	}
	else
	{
		wait(&status); /*Espera a que el proceso hijo termine*/
	}
	if (pathname)
	{
		free(pathname);
	}
	return (0);
}