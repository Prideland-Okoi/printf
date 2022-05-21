#include "main.h"
/**
 * print_susi - prints a short unsigned integer
 * @arguments: number to print
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_susi(va_list arguments, char *buffer, unsigned int index_buffer)
{
	unsigned short int int_in, int_temp, i, div;

	int_in = va_arg(arguments, unsigned int);

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		index_buffer = handle_buffer(buffer, ((int_in / div) % 10) + '0', index_buffer);
	}
	return (i);
}


