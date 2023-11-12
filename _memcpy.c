#include "main.h"

/**
 * _memcpy - copies memory area
 *
 * @dest: destination in memory
 * @src: source
 * @n: number of bytes to copy
 *
 * Return: Pointer to @dest
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	char *temp_dest = (char *) dest;
	const char *temp_src = (const char *) src;

	for (i = 0; i < n; i++)
	{
		temp_dest[i] = temp_src[i];
	}
	return (dest);
}
