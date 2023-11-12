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
		return (-1);

	va_start(args, format);

	init_buffer(&buffer);

	char_count = process_format(&buffer, format, args);

	va_end(args);
	return (char_count);
}
