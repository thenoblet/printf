#include "main.h"

/**
 * handle_binary - converts an unsigned integer to its binary representation
 *
 * @spec: format specifier.
 * @buffer: The string buffer to which the binary representation is appended.
 * @args: Variable argument list containing the unsigned integer
 * to be converted
 *
 * Description: This function takes an unused format specifier, a string
 * buffer, and a variable argument list containing an unsigned integer.
 * It converts the unsigned integer to its binary representation and
 * appends it to the string buffer. The resulting character count is returned.
 *
 * Return: Number of characters added to the buffer.
 */

int handle_binary(__attribute__((unused)) const format_spec * spec,
		string_buffer *buffer, va_list args)
{
	char string_count[65];
	int char_count;

	unsigned int num = va_arg(args, unsigned int);
	size_t length = buffer->length;

	_itob(num, string_count);
	append_string(buffer, string_count);

	char_count = buffer->length - length;
	return (char_count);
}
