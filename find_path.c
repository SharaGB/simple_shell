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
		result = strcmp_var(environ[i], name);
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
int found_PATH(char *pathname, int mode)
{
	char *path[50];
	size_t stat_f = 0;
	char *command_path;

	mode = 0;
	command_path = malloc(sizeof(char) * 50);
	while (path[mode])
	{
		_strcat(path[mode], pathname, command_path);
		stat_f = access(command_path, X_OK); /*Comprueba si existe*/

		if (stat_f == 0)
		{
			return (command_path); /*Devuelve la string concatenada si se encuentra*/
		}
		mode++;
	}
	return (NULL); /*En caso contrario retorna NULL*/
}
