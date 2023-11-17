#include "main.h"

/**
 * rot13 - applies the ROT13 transformation to a string.
 *
 * @input: the input string to be transformed.
 *
 * This function applies the ROT13 transformation to each
 * character in the input string. Alphabetic characters are rotated by 13
 * positions, and non-alphabetic characters remain unchanged. The result
 * is a newly allocated string that should be freed by the caller when it
 * is now longer needed.
 *
 * Return: a pointer to the newly allocated RT13-transformation string.
 * Returns NULL is memory allocation fails or if input is NULL.
 */
char *rot13(const char *input)
{
	char *result;
	size_t len = 0;
	char base;
	size_t i;

	if (input == NULL)
	{
		return (NULL);
	}

	while (input[len] != '\0')
	{
		len++;
	}

	result = (char *) malloc((len + 1) * sizeof(char));

	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		if (_isalpha(input[i]))
		{
			base = (_islower(input[i])) ? 'a' : 'A';
			result[i] = (input[i] - base + 13) % 26 + base;
		}
		else
		{
			/* non-alphabetic characters remain unchanged */
			result[i] = input[i];
		}
	}
	return (result);
}
