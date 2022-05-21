#include "main.h"
#include <stdio.h>
/**
 * print_c_stdout - writes the character c to stdout
 * @a: input char
 * @buffer: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int print_c_stdout(va_list a __attribute__((unused)), char *buffer, unsigned int i)
{
	handle_buffer(buffer, '%', i);

	return (1);
}
