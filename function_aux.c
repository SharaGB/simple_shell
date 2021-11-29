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
 * 
 * @brief 
 */
char _realloc (char **old, int len1, int newlen)
{
char **ptr = malloc (newlen * sizeof(char ptr));
if (!= ptr)
{
free ptr 
return (NULL);
}
}
memcpy (ptr, old len1)
free old
return (ptr)
/**
 * @brief
 * 
 */
/**
 * _strncpy - check the code
 * @dest: char1
 * @src: char2
 * @n: int
 * Return: A function
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[i] = src[i];
for ( ; i < n; i++)
dest[i] = '\0';
return (dest);
}
