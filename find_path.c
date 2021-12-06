#include "main.h"
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
	int i = 0;

	pathname = "PATH";
	buff = _getenv(pathname); /*Obtener la variable de entorno PATH*/
	dup = _strdup(buff);
	paths = strtok(dup, ":");

	while (paths)
	{
		path[i] = paths;
		paths = strtok(NULL, ":");
		i++;
	}
	path[i] = NULL; /*Lo termina con NULL*/
	return(path);
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
 * _getenv - obtain the env variable requested
 * @name: name of the env varible requested to get
 * Return: the exact env variable requested
 */
char *_getenv(const char *name)
{
	int result, i = 0;
	char *env = NULL;
	int len = (_strlenconst(name) + 1);

	while (environ[i])
	{
		result = _strcmp(environ[i], name);
		if (result == 0)
		{
			env = environ[i] + len;
			return (env);
		}
		i++;
	}
	return (NULL);
}

/**
 * foun_PATH - 
 * 
 * @param pathname 
 * @param mode 
 * @return int 
 */
char *found_PATH(char *pathname)
{
	char *path[50];
	size_t stat_f = 0;
	char *command_path;
	int mode;

	mode = 0;
	command_path = malloc(sizeof(char) * 50);
	while (path[mode])
	{
		_strncat(path[mode], pathname, command_path);
		stat_f = access(command_path, X_OK); /*Comprueba si existe*/

		if (stat_f == 0)
		{
			return (command_path); /*Devuelve la string concatenada si se encuentra*/
		}
		mode++;
	}
	return (NULL); /*En caso contrario retorna NULL*/
}


/**
 * _strcmp - COmpares two strings
 * @s1: check s1
 * @s2: check s2
 *
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _strlen - The length of a string
 * @s: Check the string
 * Return: Always 0
 */
int _strlenconst(const char *s)
{
	int leng = 0;

	while (s[leng] != '\0')
	{
		leng++;
	}
	return (leng);
}
