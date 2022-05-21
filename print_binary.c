#include "main.h"

/**
 * print_binary - prints decimal in binary
 * @arguments: input string
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_binary(va_list arguments, char *buffer, unsigned int index_buffer)
{
	int int_input, count, i, first_one, isnegative;
	char *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;
	if (int_input == 0)
	{
		index_buffer = handle_buffer(buffer, '0', index_buffer);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (32 + 1));
	binary = build_binary_array(binary, int_input, isnegative, 32);
	first_one = 0;
	for (count = i = 0; binary[i]; i++)
	{
		if (first_one == 0 && binary[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			index_buffer = handle_buffer(buffer, binary[i], index_buffer);
			count++;
		}
	}
	free(binary);
	return (count);
}
