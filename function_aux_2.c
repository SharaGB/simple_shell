#include "main.h"
/**
 * str_concat - Concatenate two string.
 * @s1: Check string 1
 * @s2: Check string 2
 * Return: str
 */
char *str_concat(char *s1, char *s2)
{
	char *str = NULL;
	int len1, len2, i, j;

	if (s1 == NULL)
	{
		s1 = "";
	}
	len1 = _strlen(s1);
	if (s2 == NULL)
	{
		s2 = "";
	}
	len2 = _strlen(s2);

	str = (char *)malloc((len1 + len2) * sizeof(char) + 2);
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '/';
	i++;
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = s2[j];
	return (str);
}

/**
 * _strlen - The length of a string
 * @s: Check the string
 * Return: The leng
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strdup - Contains a copy of the string
 * @str: Check string
 * Return: A pointer
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
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
	{
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
	return (ptr);
}

/**
 *_str_dup - Contains a copy of the string
 *@str: Check string
 *Return: A pointer
 */
char *_str_dup(char *str)
{
	int len = 0, i = 0;
	char *dup;
	char *duppass;

	if (str == NULL)
	{
		return (NULL);
	}
	len = _strlen(str);
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	duppass = dup;
	while (str[i] != ':' && str[i] != '\0')
	{
		*duppass = str[i];
		duppass++;
		i++;
	}
	*duppass = '\0';
	return (dup);
}

/**
 * str_cmp - Compares str pointed to by str1 with the str pointed to by str2
 *@s1: First string to be compared.
 *@s2: Second string to be compared.
 *Return: 0
 */
int str_cmp(char *s1, const char *s2)
{
	int i = 0, j = 0;

	while (s1[j] != '=')
	{
		if (s1[j] != s2[j])
		{
			i = 1;
			break;
		}
		j++;
	}
	if (i == 0)
		return (0);
	else
		return (1);
}
