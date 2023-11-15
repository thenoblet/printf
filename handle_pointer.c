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
	char address_str[20];/*test size*/

	snprintf(address_str, sizeof(address_str), "%p", p);/*convert p address*/
	append_string(buffer, address_str);/*append address string*/

	return (_strlen(address_str));/*return length of address*/
}
