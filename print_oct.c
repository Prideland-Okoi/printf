#include "main.h"
/**
 * print_oct - prints decimal number in octal
 * @arguments: input number
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_oct(va_list arguments, char *buffer, unsigned int index_buffer)
{
	int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

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
	octal = malloc(sizeof(char) * (11 + 1));
	octal = build_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			index_buffer = handle_buffer(buffer, octal[i], index_buffer);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}

