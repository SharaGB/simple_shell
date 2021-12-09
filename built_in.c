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
		{"cd", built_cd, "help_cd"},
		{"env", built_env, "help_env"},
		{"help", built_help, "help_help"},
		{"exit", built_exit, "help_exit"},
		{NULL, NULL, NULL}
		};

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
	if (args[0] == NULL)
	{
		perror("cd");
	}
	else
	{
		if (chdir(args[0]) != 0)
		{
			perror("cd");
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

/**
 * built_help - Function describing command help
 * @args: Arguments passed to the function
 * Return: The text that can be read, or 1 if it fails
 */
int built_help(char **args)
{
	int i = 0;

	our_built_in built_in[] = {
		{"cd", built_cd, "help_cd"},
		{"env", built_env, "help_env"},
		{"help", built_help, "help_help"},
		{"exit", built_exit, "help_exit"},
		{NULL, NULL, NULL}
		};

	if (args[1] == NULL)
	{
		return (1);
	}
	while (built_in[i].name != NULL)
	{
		if (_strcmp(args[1], built_in[i].name) == 0)
		{
			read_textfile(built_in[i].help, 1024);
		}
		i++;
	}
	return (1);
}
