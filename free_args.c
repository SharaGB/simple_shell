#include "main.h"
/**
 * free - Frees a 2 dimensional args
 * @args: Check array
 */
void free_args(char **args)
{
    int position = 0;

    for (position = 0; args[position]; position++)
	{
		free(args[position]);
	}
	free(args);
}
