#include "main.h"

/**
 * _islower - checks for lowercase letters
 *
 * @c: argument value
 *
 * Return: Always 1 (Success)
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}

	return (0);
}
