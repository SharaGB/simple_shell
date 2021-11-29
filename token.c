#include "shell.h"
/**
 * split - Function that tokenizes the command line
 * @str: Check string delimiter
 * @str_list: Double pointer that divides by words
 */
void split_line(char *str, char **str_list)
{
	int size = TOK_BUFSIZE;
	int position = 0;
	const char delimitador[] = " \n\t";
	char *token_line = NULL;

	str_list = maloc(size * sizeof(char *) + 1);
	if (!str_list)
	{
		free(str_list);
		return (NULL);
	}
	token_line = strtok(str, delimitador);
	while (token_line)
	{
		str_list[position] = token_line; /*Por medio del while se recorre la acadena*/
		position++;

		if (position >= size)
		{
			size += TOK_BUFSIZE;
			str_list = realloc(str_list, size * sizeof(char *));

			if (!str_list)
			{
				perror("No such file or directory");
				exit(EXIT_FAILURE);
			}
		}
		token_line = strtok(NULL, delimitador);
		/*Se pasa NULL como primer argumento para obtener el siguiente token*/
	}
	str_list[position] = NULL;
	free(str_list);
	return (str_list);
}

/**
 * execute - Function to execute a program:
 * @pathname: Check path
 * @argv: Array of string pointers passed to new program
 * @envp: Environment variable, array of pointers to strings
 * Return:
 */
int execute(const char *pathname, char **argv, char **environ)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(pathname, argv, environ) == -1)
		{
			perror(argv[0]);
			return (0);
		}
	}
	else if (pid < 0)
	{
		perror(argv[0]);
	}
	{
		(wait(NULL));
	}
	return (1);
}

/**
 * get_path -
 * @envp: Enviroment variable
 * bin_path:
 */
void get_path(char **envp, char *bin_path)
{
	int count = 0;
	char *tmp;

	while (1)
	{
		tmp = strstr(envp[count], "PATH");

		if (tmp == NULL)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	strncpy(bin_path, tmp, _strlen_recursion(tmp));
}

/**
 * @brief 
 * 
 * @param path_str 
 */
void insert_path(char *path_str)
{
	int index = 0;
	char *tmp = path_str;
	char ret[100];

	while (*tmp != '=')
	{
		tmp++;
	}
	tmp++;
	while (*tmp != '\0')
	{
		if (*tmp == ':')
		{
			strncat(ret, "/", 1);
			search_path[index] = (char*)malloc(sizeof(char) * (_strlen_recursion(ret) + 1));
			strncat(search_path[index], ret, _strlen_recursion(ret));
			strncat(search_pat[index], "\0", 1);
			index++;
			bzero(ret, 100);
		}
		else
		{
			strncat(ret, tmp, 1);
		}
		tmp++;
	}
}
