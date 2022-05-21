#include "main.h"
#include <stdio.h>

/**
 * print_char - writes the character c to stdout
 * @arguments: input char
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: On success 1.
 */
int print_char(va_list arguments, char *buffer, unsigned int index_buffer)
{
	char c;

	c = va_arg(arguments, int);
	handle_buffer(buffer, c, index_buffer);

	return (1);
}
