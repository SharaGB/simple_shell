#include "main.h"
/**
 * _strcmp - Compares two strings
 * @s1: check s1
 * @s2: check s2
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
 * counter - Function that counter of words in a string
 * @str: the string
 * Return: The counter
 */
int counter(char *str)
{
	int i = 0;
	int count = 0;

	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			i = 0;
		}
		else if (i == 0)
		{
			i = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * read_textfile - Reads a text file and prints in to the POSIX stdout
 * @filename: Check name file
 * @letters: Number of letters it should read and print
 * Return: Actual numbers of letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t sz_rd, sz_wr;
	int fd = open(filename, O_RDONLY);
	char *buf = (char *)malloc(letters * sizeof(char) + 1);

	if (!buf)
	{
		free(buf);
		return (0);
	}
	sz_rd = read(fd, buf, letters);
	sz_wr = write(STDOUT_FILENO, buf, sz_rd);
	if (fd == '\0' || sz_rd == -1 || sz_wr == -1)
	{
		return (0);
	}
	free(buf);
	close(fd);

	return (sz_wr);
}

/**
 * _getenv - Function to obtain the variable env
 * @s: Name of variable
 * Return: NULL
 */
char *_getenv(const char *s)
{
	int aux, i = 0;
	char *env = NULL;
	int len = (_strlenconst(s) + 1);

	while (environ[i])
	{
		aux = str_cmp(environ[i], s);
		if (aux == 0)
		{
			env = environ[i] + len;
			return (env);
		}
		i++;
	}
	return (NULL);
}

/**
 * _strlenconst - The length of a string
 * @s: Check the string
 * Return: The leng
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
