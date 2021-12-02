#include "shell.h"
/**
 * execute - Function to execute a program
 * @command: The tokenized array
 * Return: On success, execve() does not return, on error -1 is returned,
	   and errno is set to indicate the error.
 */
int execute(char **command)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		return (1);
	}
	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror("./shell");
			return (0);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
