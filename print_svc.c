#include "main.h"
/**
 * print_svc - prints a string and values of
 * non-printed chars
 * @arguments: input string
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_svc(va_list arguments, char *buffer, unsigned int index_buffer)
{
	unsigned char *str;
	char *hexadecimal, *binary;
	unsigned int i, sum, op;

	str = va_arg(arguments, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			index_buffer = handle_buffer(buffer, '\\', index_buffer);
			index_buffer = handle_buffer(buffer, 'x', index_buffer);
			op = str[i];
			binary = build_binary_array(binary, op, 0, 32);
			hexadecimal = build_hex_array(binary, hexadecimal, 1, 8);
			index_buffer = handle_buffer(buffer, hexadecimal[6], index_buffer);
			index_buffer = handle_buffer(buffer, hexadecimal[7], index_buffer);
			sum += 3;
		}
		else
			index_buffer = handle_buffer(buffer, str[i], index_buffer);
	}
	free(binary);
	free(hexadecimal);
	return (i + sum);
}
