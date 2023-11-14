#include "main.h"


/**
 * append_char - Appends a character to the string buffer.
 * @buffer: The string buffer to hold the result.
 * @ch: The character to append.
 *
 * This function appends a single character to the given string buffer.
 * If necessary, it dynamically reallocates memory to accommodate
 * the new character.
 */

void append_char(string_buffer *buffer, char ch)
{
	size_t initial_capacity = buffer->capacity;
	char *new_string;

	if (buffer->length + 1 >= buffer->capacity)
	{
		buffer->capacity = (buffer->capacity == 0) ? 1 : buffer->capacity * 2;
		new_string = _realloc(buffer->string, initial_capacity, buffer->capacity);

		if (new_string == NULL)
		{
			fprintf(stderr, "Memory allocation error in append_char\n");
			exit(EXIT_FAILURE); /*error handling*/
		}
		buffer->string = new_string;
	}

	buffer->string[buffer->length] = ch;
	buffer->length++;
	buffer->string[buffer->length] = '\0';
}


/**
 * append_string - Appends a string to the string buffer.
 * @buffer: The string buffer to hold the result.
 * @str: The string to append.
 *
 * This function appends a null-terminated string to the given string buffer.
 */

void append_string(string_buffer *buffer, const char *str)
{
	for (; *str; ++str)
	{
		append_char(buffer, *str);
	}
}

/**
 * init_buffer - Initializes a string buffer.
 * @buffer: The string buffer to initialize.
 *
 * This function initializes the given string buffer, setting initial values.
 */
void init_buffer(string_buffer *buffer)
{
	buffer->string = NULL;
	buffer->capacity = 0;
	buffer->length = 0;
}

