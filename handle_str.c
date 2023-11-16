#include "main.h"


/**
 * handle_str - Handles string format specifier '%s'.
 *
 * @spec: The format specifier information
 * @args: The va_list containing the variable arguments.
 * @buffer: The string buffer to hold the formatted string.
 *
 * This simplified version of the function extracts the string from the
 * variable arguments and appends it to the given string buffer.
 * It does not consider flags, precision, width, or length specified
 * in the format specifier.
 *
 *  Return: Returns the number of characters added to the buffer.
 */

int handle_str(__attribute__((unused)) const format_spec * spec, string_buffer
		*buffer, va_list args)
{
	char *str = va_arg(args, char *);
	int char_count = 0, length = 0;

	length = buffer->length;

	if (str)
	{
		append_string(buffer, str);
	}
	else
	{
		append_string(buffer, "(null)");
	}

	char_count = buffer->length - length;

	return (char_count);
}

/*
 * handle_custom_string - Custom string formatting function
 *
 * @spec: Unused format specification (Betty style attribute)
 * @buffer: String buffer to store the formatted string
 * @args: Variable argument list
 *
 * This function handles custom string formatting by converting
 * non-printable characters to their hexadecimal representation.
 */

int handle_custom_string(__attribute__((unused)) const format_spec *spec,
		string_buffer *buffer, va_list args)
{
	char *str, *str_dup;

	char hex_buffer[10];
	int char_count;
	size_t length, i;

	str = va_arg(args, char *);
	length = buffer->length;

	if (str)
	{
		str_dup = _strdup(str); /* Duplicate the string */
		if (str_dup == NULL)
		{
			return (-1);
		}

		for (i = 0; str_dup[i] != '\0'; ++i)
		{
			if (!IS_PRINTABLE(str_dup[i]))
			{
				/* Convert non-printable character to hex */
				char_to_hex(hex_buffer, str_dup[i]);
				append_string(buffer, hex_buffer);
			}
			else
			{
				/* Append printable character to the buffer */
				append_char(buffer, str_dup[i]);
			}
		}
		safefree(str_dup);
	}
	else
	{
		append_string(buffer, "(null)");
	}

	char_count = buffer->length - length;
	return (char_count);
}


void char_to_hex(char *str, unsigned char ch) 
{
	 /* Set the first two characters to '\x' */
	str[0] = '\\';
	str[1] = 'x';

	/* Convert the higher 4 bits to hex */
	str[2] = (ch >> 4) < 10 ? (ch >> 4) + '0' : (ch >> 4) - 10 + 'A';
	
	/* Convert the lower 4 bits to hex */
	str[3] = (ch & 0x0F) < 10 ? (ch & 0x0F) + '0' : (ch & 0x0F) - 10 + 'A';
}
