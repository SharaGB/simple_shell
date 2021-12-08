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

	pathname = _which(command[0]);
	pid = fork(); /*Se crea un nuevo proceso*/
	if (pid == -1)
	{
		return (1);
	}
	if (!pid)
	{
		if (execve(pathname, command, environ) == -1) /*Ejecuta el nuevo programa*/
		{
			perror("./shell");
			exit(0);
		}
	}
	else
		waitpid(pid, &status, 0); /*Espera a que el proceso hijo termine*/
	free(pathname);
	return (0);
}
