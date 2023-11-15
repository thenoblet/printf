#include "main.h"

/**
 * handle_X - Handles the uppercase hex format specifier '%X'.
 *
 * @spec: The format specifier info.
 * @args: The va_list containing the variable arguments.
 * @buffer: The string buffer to hold the formatted string.
 *
 * Return: The number of characters added to the buffer.
 */
int handle_X(__attribute__((unused)) const format_spec * spec,
		string_buffer *buffer, va_list args)
{
	unsigned int X = va_arg(args, unsigned int);
	char num_str[20];
	int len = snprintf(num_str, sizeof(num_str), "%X", X);

	if (len < 0)
	{
		return (0);
	}
	append_string(buffer, num_str);
	return (len);
}
