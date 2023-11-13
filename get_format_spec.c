#include "main.h"

/*
 * get_format_spec - Function to retrieve a format specifier
 * function based on the given specifier
 *
 * @specifier: The format specifier to search for
 *
 * This function searches through an array of format_spec structures
 * to find a match for the provided specifier. If a match is found,
 * it returns a pointer to the corresponding function.
 * If no match is found, it returns NULL.
 */

int get_func(const char specifier, format_spec *spec,
		string_buffer *buffer, va_list args)
{
	unsigned int i;
	size_t length = buffer->length;
	int char_count;

	for (i = 0; spec[i].specifier != '\0'; ++i)
	{
		if (spec[i].specifier == specifier)
		{
			return (spec[i].func(&spec[i], buffer, args));
		}
	}
	if (specifier == '%')
	{
		return (handle_percent(&spec[i], buffer, args));
	}
	append_char(buffer, '%');
	append_char(buffer, specifier);

	char_count = buffer->length - length;
	return (char_count);
}
