#include "main.h"

/**
 * handle_unsgnd - Handles unsigned interger format specifier '%u'.
 *
 * @spec: The format specifier information.
 * @args: The va_list containing the variable arguments.
 * @buffer: The sting buffer to hold the formatted string.
 *
 * Return: The number of characters added to the buffer
 */

int handle_unsigned(__attribute__((unused)) const format_spec * spec,
		string_buffer *buffer, va_list args)
{
	unsigned int un = va_arg(args, unsigned int);
	char num_str[20];/*Testing size*/
	int len = snprintf(num_str, sizeof(num_str), "%u", un);/*converting*/

	if (len < 0)
	{
		return (0);
	}
	append_string(buffer, num_str);
	return (len);
}
