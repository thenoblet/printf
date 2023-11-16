#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * @str: string
 *
 * Return: pointer to duplicated string
 */

char *_strdup(char *str)
{
	size_t size = 0;
	size_t i;
	char *s;

	/* Create a temporary pointer to keep original string unchanged */
	char *temp = str;

	if (str == NULL)
		return (NULL);

	while (*temp)
	{
		temp++;
		size++;
	}
	size += 1; /* Add 1 for the null terminator */

	s = (char *)malloc(size * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; ++i)
	{
		s[i] = str[i];
	}

	return (s); /* return pointer to duplicated string */
}
