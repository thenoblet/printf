#include "main.h"

/**
 * write_string - Writes a string to the standard output.
 *
 * @str: The string to be written.
 * @len: The length of the string to write.
 *
 * This function writes the specified string to the standard output (stdout)
 * using the 'write' system call with the file descriptor STDOUT_FILENO
 *
 * @param [1]: File descriptor for standard output (stdout).
 *
 * Note: This function assumes that 'str' is a null-terminated string,
 * and 'len' indicates the number of characters to write, excluding
 * the null terminator.
 */

void write_string(const char *str, size_t len)
{
	write(1, str, len);
}
