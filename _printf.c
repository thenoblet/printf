#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _write_char - writes a character to stdout
 * @c: the character to write
 *
 * Return: the number of characters written
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _write_str - writes a string to stdout
 * @str: the string to write
 *
 * Return: the number of characters written
 */
int _write_str(const char *str)
{
	if (str)
		return (write(1, str, strlen(str)));
	return (0);
}

/**
 * _write_int - writes an integer to stdout
 * @n: the integer to write
 *
 * Return: the number of character written
 */
int _write_int(int n)
{
	char buffer[12];
	int lenght = snprintf(buffer, sizeof(buffer), "%d", n);

	if (lenght < 0)
	{
		perror("snprintf");
		return (0);
	}

	return (write(1, buffer, lenght));
}

/**
 * process_format - processes the format string and writes to stdout
 * @format: the format string
 * @args: the variable arguments list
 *
 * Return: the number of characters printed to stdout
 */
int process_format(const char *format, va_list args)
{
	int count = 0;
	char c, *str;

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'c' ||
		*(format + 1) == 's' || *(format + 1) == '%' ||
		*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			switch (*(format + 1))
			{
				case 'c':
					c = va_arg(args, int);
					count += _write_char(c);
					break;
				case 's':
					str = va_arg(args, char *);
					count += _write_str(str);
					break;
				case 'd':
				case 'i':
					count += _write_int(va_arg(args, int));
					break;
				default:
					count += _write_char(*format);
			}
			format += 2;
		}
		else
		{
			count += _write_char(*format);
			format++;
		}
	}
	return (count);
}

/**
 * _printf - prints a formatted string to stdout
 * @format: the formatted string
 *
 * Return: the number of characters printed to stdout,
 * else -1 if @format is NULL
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	count = process_format(format, args);
	va_end(args);

	return (count);
}
