#include "main.h"
/**
 * @brief 
 * 
 */
int get_op_func(char **args)
{
	our_built_in built_in[] = {
		{"exit", built_exit},
		{"env", built_env},
		{NULL, NULL}};

	int i = 0;
	int aux = 0;
	int (*func)(char **args);

	if (args[0] == NULL)
	{
		return (1);
	}
	while (built_in[i].name != NULL)
	{
		if (_strcmp(args[0], built_in[i].name) == 0)
		{
			func = built_in[i].f;
			aux = func(args);
			return (aux);
		}
		i++;
	}
	return (execute(args));
}

/**
 * @brief 
 * 
 */
int built_exit(char **args __attribute__((unused)))
{
	free(args);
	exit(EXIT_FAILURE);
}

/**
 * @brief 
 * 
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
