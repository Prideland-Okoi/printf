#include "main.h"

/**
 * handle_buffer - concatenates the buffer characters
 * @buffer: buffer pointer
 * @c: charcter to concatenate
 * @index_buffer: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int handle_buffer(char *buffer, char c, unsigned int index_buffer)
{
	if (index_buffer == 1024)
	{
		print_buffer(buffer, index_buffer);
		index_buffer = 0;
	}
	buffer[index_buffer] = c;
	index_buffer++;
	return (index_buffer);
}
