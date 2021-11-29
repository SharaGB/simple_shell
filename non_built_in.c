#include "shell.h"
/**
 * get_path - Function that get the variable of PATH environment 
 * 
 * @param pathname 
 * @param paths 
 * @return int 
 */
int get_path(char *pathname, char *paths)
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

/**
 * *_strdup - Duplicates a string
 * @str: The string to be duplicated
 * Return: Null
 */
char *_strdup(char *str)
{
	int len = 0;
	char *ptr;
	char *dub;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	dub = ptr;
	while (*str)
	{
		*dub = *str;
		dub++;
		str++;
	}
	*dub = '\0';
	free(ptr);
	return (ptr);
}

/**
 * @brief 
 * 
 */
{
	char *command_file, *command_path, *path[50];
	int i;

	i = 0;
	command_path = malloc(sizeof(char) * 50);
	while (path[i] != NULL)
	{
		_strcat(path[i], command_file, command_path); /* this function is found below */
		stat_f = access(command_path, X_OK); /* and checks if it exists */
		if (stat_f == 0)
			return (command_path); /* returns the concatenated string if found */

		i++;
	}
	return NULL; /* otherwise returns NULL */
}


/**
 * *_strcat - Concatenates two strings
 * @dest: check the string dest
 * @src: check the sting src
 *
 * Return: dest.
 */

char *_strcat(char *dest, char *src)
{
	int l;
	int a;

	l = 0;
	while (dest[l] != '\0')
	{
		l++;
	}
	a = 0;
	while (src[a] != '\0')
	{
		dest[l + a] = src[a];
		a++;
	}
	src[a] = '\0';
	return (dest);
}
