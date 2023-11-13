#include "main.h"

/**
 * process_format - Processes a format string and writes it to stdout.
 *
 * @buffer: The string buffer to hold the processed format string.
 * @format: The format string to be processed.
 * @args: The variable argument list.
 *
 * Return: The number of characters processed, or -1 on error.
 */
int process_format(string_buffer *buffer, const char *format, va_list args)
{
	int i = 0, num_chars = 0, count = 0;

	format_spec *spec = format_spec_array();

	if (spec == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				/*Handle a lone percent sign*/
				append_char(buffer, '%');
				count++;
				break;
			}
			if (lone_percent(&format[i]) == -1)
			{
				safefree(spec);
				return (-1);
			}

			num_chars = get_func(format[i], spec, buffer, args);
			count += num_chars;
		}
		else
		{
			append_char(buffer, format[i]);
			count++;
		}
		i++;
	}
	/* Write the processed string to stdout */
	write_string(buffer->string, count);
	safefree(buffer->string);
	safefree(spec);
	return (count);
}


/**
 * valid_specifier - Check if a character is a valid format specifier.
 * @ch: The character to check.
 *
 * Return: 1 if the character is a valid specifier, 0 otherwise.
 */
int valid_specifier(char ch)
{
	size_t i;

	const char valid_specs[] = "%ibducsSrRxXop";

	for (i = 0; valid_specs[i] != '\0'; ++i)
	{
		if (valid_specs[i] == ch)
			return (1); /* Found a valid specifier */
	}

	return (0);
}

/**
 * lone_percent - Handle the case of a lone '%' in the format string.
 * @format: The format string to check.
 *
 * Return: -1 if a lone '%' is detected, 0 otherwise.
 */
int lone_percent(const char *format)
{
	if (valid_specifier(format[0]) || format[0] == '%')
		return (0);
	/*Invalid use of '%'*/
	return (-1);
}
