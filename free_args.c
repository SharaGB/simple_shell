#include "main.h"
/**
 * free_args - Frees a 2 dimensional args
 * @args: Check array
 */
void free_args(char **args)
{
	int i;
	int height;

	for (i = 0; i < height; i++)
	{
		free(args[i]);
	}
	free(args);
}
