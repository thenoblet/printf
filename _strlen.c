#include "main.h"

/**
 * _strlen - returns the length of a string
 *
 * @s: parameter
 *
 * Return: length of a string
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}
