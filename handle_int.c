#include "main.h"

/**
 * handle_int - Handles the integer format specifier '%d' and '%i'.
 *
 * @spec: The format specifier information.
 * @args: The va_list containing the variable arguments.
 * @buffer: The string buffer to hold the formatted string.
 *
 * Return: The number of characters added to the buffer.
 */
int handle_int(__attribute__((unused)) const format_spec *spec,
		string_buffer *buffer, va_list args)
{
	int num = va_arg(args, int);
	char num_str[12];
	int length = snprintf(num_str, sizeof(num_str), "%d", num);

	if (length < 0)
	{
		return (0);
	}
	
	append_string(buffer, num_str);
	return (length);
}
