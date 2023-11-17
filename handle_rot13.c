#include "main.h"

/**
 * handle_rot13 - handles the ROT13 custom format specifier '%R'.
 *
 * @spec: the format specifier information (unsused).
 * @buffer: the string buffer to hold the formatted string.
 * @args: the va_list containing the variable arguments.
 *
 * This function handles the ROT13 format specifier '%R'.
 * It performs the ROT13 transformation on the provided string and appends
 * the result to the given buffer. If the input string is NULL, it appends
 * "(null)" to the buffer. The resulting character count is returned.
 *
 * Return: the number of characters added to the buffer.
 */
int handle_rot13(__attribute__((unused)) const format_spec * spec,
		string_buffer *buffer, va_list args)
{
	char *str, *rot13_str;

	str = va_arg(args, char *);


	if (str != NULL)
	{
		size_t length = buffer->length;

		rot13_str = rot13(str);/* implement the rot13 function */
		append_string(buffer, rot13_str);
		safefree(rot13_str);

		return (buffer->length - length);
	}
	else
	{
		append_string(buffer, "(null)");/* case of NULL */

		return (6);
	}
}
