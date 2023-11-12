#include "main.h"

/**
 * _printf - prints a formatted string to stdout
 * @format: the formatted string
 *
 * Return: the number of characters printed to stdout,
 * else -1 if @format is NULL
 */
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;
	string_buffer buffer;

	if (!format)
	{
		return (-1);
	}

	/* process variable arguments list */
	va_start(args, format);

	/* Declare a buffer to store the formatted string */
	init_buffer(&buffer);

	/* Process format string and store the result in the buffer */
	char_count = process_format(&buffer, format, args);

	va_end(args);
	if (char_count == -1)
	{
		safefree(buffer.string);
		return (-1);
	}

	write_string(buffer.string, char_count);

	safefree(buffer.string);

	return (char_count);
}
