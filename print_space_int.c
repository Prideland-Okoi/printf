#include "main.h"
/**
 * print_space_int - prints int begining with space
 * @arguments: input string
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_space_int(va_list arguments, char *buffer, unsigned int index_buffer)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(arguments, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		index_buffer = handle_buffer(buffer, '-', index_buffer);
	}
	else
	{
		int_in = int_input;
		index_buffer = handle_buffer(buffer, ' ', index_buffer);
	}
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
	return (i + 1);
}
