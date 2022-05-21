#include "main.h"
/**
 * print_long_decihex - prints a long decimal in hexadecimal
 * @arguments: The character to print
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_long_decihex(va_list arguments, char *buffer, unsigned int index_buffer)
{
	long int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, long int);
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = build_binary_array(binary, int_input, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = build_hex_array(binary, hexadecimal, 1, 16);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			index_buffer = handle_buffer(buffer, hexadecimal[i], index_buffer);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}

