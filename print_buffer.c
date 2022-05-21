#include "main.h"

/**
 * print_buffer - prints buffer
 * @buffer: buffer pointer
 * @num_buffer: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buffer(char *buffer, unsigned int num_buffer)
{
	return (write(1, buffer, num_buffer));
}
