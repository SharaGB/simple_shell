#include "shell.h"
/**
 * 
 * @brief
 */
	char *path_buff, *path_dup, *paths, *path_env_name, *path[50];
	int i;

	i = 0;
	path_env_name = "PATH";
	path_buff = getenv(path_env_name); /* get the variable of PATH environment */
	path_dup = _strdup(path_buff); /* this function is found below */
	paths = strtok(path_dup, ":"); /* tokenizes it */
	while (paths)
	{
		path[i] = paths;
		paths = strtok(NULL, ":");
		i++;
	}
	path[i] = NULL; /* terminates it with NULL */
}
