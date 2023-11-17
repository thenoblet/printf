#include "main.h"

/**
 * handle_reverse - handles reverse string format specifier '%r'.
 *
 * @spec: the format specifier information.
 * @buffer: the string buffer to hold the formatted string.
 * @args: the va_list containing the variable arguments.
 *
 * Description: this function handles the reversed string format specifier '%r'
 * It extracts a string from a variable argument, reverses the string and
 * appends the reversed string to the given string buffer. If the input string
 * is NULL, appends "(null)" to the buffer.
 *
 * Return: the number of characters added to the buffer.
 */
int handle_reverse(__attribute__((unused)) const format_spec * spec,
		string_buffer *buffer, va_list args)
{
	char *str = va_arg(args, char *);
	size_t len = _strlen(str);
	int i;

	if (str)
	{
		/* reverse the string and append each character to buffer */
		for (i = len - 1; i >= 0; --i)
		{
			append_char(buffer, str[i]);
		}
	}
	else
		/* case NULL, then append "(null)" to buffer */
	{
		append_string(buffer, "(null)");
	}

	return (len);
}
