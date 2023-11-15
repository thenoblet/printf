#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define STDOUT_FILENO 1
#define VALID_SPECIFIER "ibducsSrRxXop"

/**
 * struct dynamic_string - Structure to hold a dynamic string
 *
 * @string: Pointer to the character array
 * @length: Current length of the string
 * @capacity: size/capacity of the char array
 */
typedef struct dynamic_string
{
	char *string;
	size_t capacity;
	size_t length;
} string_buffer;

/* functions for string buffering */
void init_buffer(string_buffer *buffer);
void append_string(string_buffer *buffer, const char *str);
void append_char(string_buffer *buffer, char ch);

/**
 * struct format_spec - Structure to represent format specifiers
 * and their handler function
 *
 * @specifier: The format specifier character (e.g., 'd', 's', etc.)
 * @func: Pointer to a function handling the format specifier, taking a
 *        pointer to a format_spec structure, a string_buffer pointer,
 *        and a va_list of variable arguments.
 */
typedef struct format_spec
{
	char specifier;
	int (*func)(const struct format_spec *, string_buffer *,
			va_list);
} format_spec;


/* format spec function selector */
int get_func(char specifier, format_spec *spec, string_buffer *buffer,
		va_list args);

/* helper function to the _printf function */
int process_format(string_buffer *buffer, const char *format, va_list args);
int valid_specifier(char ch);
int lone_percent(const char *format);

/* write string/char functions */
void write_string(const char *str, size_t len);
int write_char(char c);

/* function that creates an array of format specs */
format_spec *format_spec_array();

/* _printf function prototype */
int _printf(const char *format, ...);

/* specifier handling functions */
int handle_str(const format_spec *spec, string_buffer *buffer, va_list args);
int handle_percent(const format_spec *spec, string_buffer *buffer,
		va_list args);
int handle_int(const format_spec *spec, string_buffer *buffer, va_list args);
int handle_char(const format_spec *spec, string_buffer *buffer, va_list args);
int handle_binary(const format_spec *spec, string_buffer *buffer,
		va_list args);
int handle_unsigned(const format_spec *spec, string_buffer *buffer,
		va_list args);
int handle_octal(const format_spec *spec, string_buffer *buffer,
		va_list args);
int handle_hex_lower(const format_spec *spec, string_buffer *buffer,
		va_list args);
int handle_hex_upper(const format_spec *spec, string_buffer *buffer,
		va_list args);

/* number conversion functions */
void _itob(size_t num, char binary[]);

/* custom string functions*/
void *_memcpy(void *dest, const void *src, size_t n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void reverse(char str[], size_t len);

/* memory alloc. functions */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* custom memory deallocation */
void _free(void **ptr);
#define safefree(p) _free((void **)&(p))


#endif /* MAIN_H */
