#include "shell.h"
/**
 * _strlen_recursion - Length of a string
 * @s: Check of string
 * Return: The length of a string
 */
int _strlen_recursion(char *s)
{
	int len;

	len = 0;
	if (*s != '\0')
	{
		len = _strlen_recursion(s + 1);
		len++;
	}
	return (len);
}

/**
 * *_strncpy - Copies the string pointed to by src
 * @dest: check dest
 * @src: check src
 * @n: check
 * Return: The pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * *_memcpy - Copies memory area
 * @dest: Destination of the string
 * @src: Source of the string
 * @n: Number of bytes
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _realloc - Our function realloc
 * @old:
 * @len:
 * @newlen:
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
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
