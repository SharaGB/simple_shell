#include "main.h"
/**
 * free_args - Frees a 2 dimensional args
 * @args: Check array
 */
void free_args(char **args)
{
	int i = 0;

	while (i < _strlen(args[i]))
	{
		free(args[i]);
		i++;
	}
	free(args);
}
