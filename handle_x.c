#include "main.h"

/**
 * handle_x - Handles the lowercase hex format specifier '%x'.
 *
 * @spec: The format specifier into
 * @args: The va_list containing the variable argument.
 * @buffer: The string buffer to hold the formatted string.
 *
 * Return: The number of characters added to the buffer.
 */
int handle_x(__attribute__((unused)) const format_spec * spec,
		string_buffer * buffer, va_list args)
{
	unsigned int x = va_arg(args, unsigned int);
	char num_str[20];
	int len = snprintf(num_str, sizeof(num_str), "%x", x);

	if (len < 0)
	{
		return (0);
	}
	append_string(buffer, num_str);
	return (len);
}
