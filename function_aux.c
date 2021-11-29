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
 * _realloc - Our function realloc
 * @old:
 * @len:
 * @newlen:
 * Return: Double ptr
 */
char _realloc(char **old, int len, int newlen)
{
	char **ptr = malloc(newlen * sizeof(char *));

	if (!ptr)
	{
		free(ptr);
		return (0);
	}
	memcpy(ptr, old, len);
	free(old);
	return (ptr);
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
