#include "main.h"
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
 * realloc - reallocates a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to number of elements in the old array
 *
 * Return: pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new);
}

/**
 * *_strcat - Concatenates two strings
 * @dest: check the string dest
 * @src: check the sting src
 * Return: dest.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	src[j] = '\0';
	return (dest);
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
	char *buf = (char *)malloc(letters * sizeof(char));

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
