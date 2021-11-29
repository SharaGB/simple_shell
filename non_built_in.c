#include "shell.h"
/**
 * @brief 
 * 
 * @param pathname 
 * @param paths 
 * @return int 
 */
int found_PATH(char *pathname, char *paths)
{
	char *buff, *dup, *path[50];
	int i;

	i = 0;
	pathname = "PATH";
	buff = getenv(pathname); /*Obtener la variable de entorno PATH*/
	dup = _strdup(buff);
	paths = strtok(dup, ":");
	while (paths)
	{
		path[i] = paths;
		paths = strtok(NULL, ":");
		i++;
	}
	path[i] = NULL; /*Lo termina con NULL*/
}
