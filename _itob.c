#include "main.h"

/**
 * _itob - Converts an integer to its binary representation
 * and stores it in a character array.
 *
 * @num: The integer to be converted.
 * @str: The character array to store the binary representation.
 */

void _itob(size_t num, char str[])
{
	size_t i = 0;

	if (num == 0)
	{
		str[i++] = '0';
	}

	/* Process individual bits */
	while (num > 0)
	{
		if ((num % 2) > 9)
		{
			str[i++] = ('a' + ((num % 2) - 10));
		}
		else
		{
			str[i++] = ((num % 2) + '0');
		}
		num /= 2;
	}

	/* Null-terminate the string */
	str[i] = '\0';

	/* Reverse the string */
	reverse(str, i);
}

/**
 * reverse - Reverses the order of characters in a character array.
 *
 * @str: The character array to be reversed.
 * @len: The length of the character array.
 */

void reverse(char *str, size_t len)
{
	size_t i, j;
	char ch;

	if (!str)
	{
		return;
	}

	for (i = 0, j = len / 2; i < j; i++)
	{
		ch = str[i];

		/* swap values */
		str[i] = str[len - i - 1];
		str[len - i - 1] = ch;
	}
}
