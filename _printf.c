#include <stdio.h>
#include <unistd.h>
#include <string.h>
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
	int count = 0;/*to keep track of the number of characters printed*/
	char c, *str;/*c to store characters and str to store strings*/
	va_list args;

	if (!format)/*if string is NULL, indicate error*/
		return (-1);

	va_start(args, format);

	while (*format)/*iterate over each char until null character*/
	{
		/*check if char is '%' and is next to either 'c', 's' or '%'*/
		if (*format == '%' && (*(format + 1) == 'c' ||
		*(format + 1) == 's' || *(format + 1) == '%'))
		{
			/*check for specifier following '%'*/
			switch (*(format + 1))
			{
				case 'c':/*if 'c', retrieve an int and write*/
					c = va_arg(args, int);
					count += write(1, &c, 1);
					break;
				case 's':/*if char*, write if not NULL*/
					str = va_arg(args, char *);
					if (str)
						count += write(1, str, strlen(str));
					break;
				default:
					count += write(1, format, 1);
			}
			format += 2;
		}
		else/*write to stdout and increment both count and format*/
		{
			count += write(1, format, 1);
			format++;
		}
	}
	va_end(args);/*end variable argument*/
	return (count);/*return the total count*/
}
