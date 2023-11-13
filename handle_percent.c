#include "main.h"

/**
 * handle_percent - Handles the '%' format specifier
 *
 * @spec: The format specifier information.
 * @buffer: The string buffer to hold the formatted string.
 * @args: The va_list containing the variable arguments.
 *
 * Description: This function handles '%' format specifier. It simply appends
 * a '%' character to a given string buffer.
 *
 * Return: The number of characters added to the buffer.
 */
int handle_percent(__attribute__((unused)) const format_spec * spec,
		string_buffer *buffer, __attribute__((unused)) va_list args)
{
	append_char(buffer, '%');

	return (1);/*The number of characters added to the buffer*/
}
