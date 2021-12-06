#include "main.h"
/**
 * get_func - Built in function to incorporate some commands
 * @args: Arguments passed to the function
 * Return: The function call execute
 */
int get_func(char **args)
{
	int i = 0;

	our_built_in built_in[] = {
		{"cd", built_cd},
		{"exit", built_exit},
		{"env", built_env},
		{NULL, NULL}};

	if (args[0] == NULL)
	{
		return (1);
	}
	while (built_in[i].name != NULL)
	{
		if (_strcmp(args[0], built_in[i].name) == 0)
		{
			return (built_in[i].f(args));
		}
		i++;
	}
	return (execute(args));
}

/**
 * built_cd - Function of the cd command
 * @args: Arguments passed to the function
 * Return: Past arguments, or error message in case of failure
 */
int built_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("lsh: expected argument to \"cd\"");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}

/**
 * built_exit - Exit function to exit the shell
 * @args: Arguments passed to the function
 * Return: A int
 */
int built_exit(char **args __attribute__((unused)))
{
	free(args);
	exit(EXIT_SUCCESS);
}

/**
 * built_env - Current environment function
 * @args: Arguments passed to the function
 * Return: A int
 */
int built_env(char **args __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}
