#include "main.h"

/**
 * handle_pointer - Handles the pointer format specifier '%p'.
 *
 * @spec: The format specifier info.
 * @buffer: The string buffer to hold the formatted string.
 * @args: The va_list containing the variable argument.
 *
 * Return: The number characters added to the buffer.
 */
int handle_pointer(__attribute__((unused)) const format_spec * spec,
		string_buffer *buffer, va_list args)
{
	void *p = va_arg(args, void *);
	int len = snprintf(buffer->string + buffer->length,
			buffer->capacity - buffer->length, "%p", p);

	if (len < 0)
	{
		return (0);
	}
	buffer->length += len;/*update buffer length*/
	return (len);
}
