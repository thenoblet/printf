#include "main.h"

/**
 * _itob - Converts an integer to its binary representation
 * and stores it in a character array.
 *
 * @num: The integer to be converted.
 * @binary: The character array to store the binary representation.
 */

void _itob(int num, char binary[])
{
	int i = 0;

	/* Process individual bits */
	while (num > 0)
	{
		binary[i++] = (num % 2) + '0';
		num = num / 2;
	}

	/* Null-terminate the string */
	binary[i] = '\0';

	/* Reverse the string */
	reverse(binary, i);
}

/**
 * reverse - Reverses the order of characters in a character array.
 *
 * @str: The character array to be reversed.
 * @length: The length of the character array.
 */

void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end)
	{
		/* Swap characters at start and end */
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		/* move towards center */
		start++;
		end--;
	}
}
