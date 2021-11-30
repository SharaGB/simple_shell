#include "shell.h"
/**
 * _strlen - The length of a string
 * @s: Check the string
 *
 * Return: Always 0
 */
int _strlen(char *s)
{
	int leng = 0;

	while (s[leng] != '\0')
	{
		leng++;
	}
	return (leng);
}

/**
 * _realloc - Our function realloc
 * @old:
 * @len:
 * @newlen:
 */
char *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;

	if (old_size == new_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		return (malloc(new_size));
	}
	new_ptr = (void *)malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	if (new_ptr)
	{
		_memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
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
