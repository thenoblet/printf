#include "main.h"

/**
 * handle_char - Handles the character format specifier '%c'.
 *
 * @spec: The format specifier information.
 * @args: The va_list containing the variable arguments.
 * @buffer: The string buffer to hold the formatted strings.
 *
 * Return: The number of characters added to the buffer.
 */
int handle_char(__attribute__((unused)) const format_spec *spec,
		string_buffer *buffer, va_list args)
{
	char c = va_arg(args, int);

	append_char(buffer, c);

	return (1);
}
