#include "main.h"

/**
 * format_spec_array - Create a dynamically allocated
 * array of format specifiers
 *
 * Description: This function creates a dynamic array
 * containing format specifiers and their corresponding handlers.
 * The specifiers array is then copied into the dynamic array,
 * and the dynamic array is returned. If memory allocation fails,
 * NULL is returned.
 *
 * Return: A pointer to the dynamically allocated array
 * of format specifiers.
 * Returns NULL on memory allocation failure.
 */

format_spec *format_spec_array(void)
{
	size_t spec_count;
	format_spec *format_array;

	/* array of format specifiers and their handlers funcs. */
	format_spec specifiers[] = {
		{'s', handle_str},
		{'%', handle_percent},
		{'d', handle_int},
		{'i', handle_int},
		{'c', handle_char},
		{'b', handle_binary}
		/* TODO: add more specifiers and their handler funcs */
		/* {'\0', NULL}*/

	};

	/* Cal specifiers array size */
	spec_count = sizeof(specifiers) / sizeof(specifiers[0]);

	/* Allocate memory for the dynamic array */
	format_array = malloc(sizeof(format_spec) * spec_count);

	if (format_array == NULL)
	{
		return (NULL); /* memory allocation failed */
	}

	/* Copy content of the specifier array to dynamic array */
	_memcpy(format_array, specifiers,
			(sizeof(format_spec) * spec_count));

	return (format_array);
}
