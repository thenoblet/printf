#include "main.h"

/**
 * write_char - writes a character to stdout
 *
 * @c: the character to write
 *
 * Return: the number of characters written
 */

int write_char(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
