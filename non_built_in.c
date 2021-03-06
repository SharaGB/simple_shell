#include "main.h"
/**
 * _which - Function that searches for the PATH and concatenates
 * @command: Check command
 * Return: PATH or NULL if doesn't exist
 */
char *_which(char *command)
{
	int len = 0;
	char *tmp = NULL;
	char *buff = NULL;
	char *pathname = "PATH";
	char *command_path = NULL;

	struct stat st;

	if (stat(command, &st) == 0)
	{
		return (command);
	}
	else
	{
		buff = _getenv(pathname); /*Obtiene la variable de entorno PATH*/
		while (buff[len - 1] != '\0')
		{
			tmp = _str_dup(buff + len);
			len += _strlen(tmp) + 1;
			command_path = str_concat(tmp, command);
			if (stat(command_path, &st) == 0)
			{
				free(tmp);
				return (command_path); /*Devuelve la string concatenada si se encuentra*/
			}
			free(tmp);
			free(command_path);
		}
	}
	return (NULL); /*En caso contrario retorna NULL*/
}
