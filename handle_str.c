#include "main.h"


/**
 * handle_str - Handles string format specifier '%s'.
 *
 * @spec: The format specifier information
 * @args: The va_list containing the variable arguments.
 * @buffer: The string buffer to hold the formatted string.
 *
 * This simplified version of the function extracts the string from the
 * variable arguments and appends it to the given string buffer.
 * It does not consider flags, precision, width, or length specified
 * in the format specifier.
 *
 *  Return: Returns the number of characters added to the buffer.
 */

int handle_str(__attribute__((unused)) const format_spec * spec, string_buffer
		*buffer, va_list args)
{
	char *str = va_arg(args, char *);
	int char_count = 0, length = 0;

	length = buffer->length;

	if (str)
	{
		append_string(buffer, str);
	}
	else
	{
		append_string(buffer, "(null)");
	}

	char_count = buffer->length - length;

	return (char_count);
}
