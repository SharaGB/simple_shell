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