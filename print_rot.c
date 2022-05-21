#include "main.h"

/**
 * print_rot - writes the str in ROT13
 * @arguments: input string
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: number of chars printed.
 */

int print_rot(va_list arguments, char *buffer, unsigned int index_buffer)
{

	int i, j;
	char *str = va_arg(arguements, char *);
	char *str2 = malloc(64);
	char tor[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; *(str + i) != '\0'; i++)
		for (j = 0; j < 52; j++)
			if (str[i] == tor[j])
			{
				*(str2 + i) = rot[j];
				break;
			}
			else
				*(str2 + i) = *(str + i);
	for (i = 0; *(str2 + i); i++)
		buffer[index_buffer] = *(str2 + i), index_buffer += 1;
	handle_buffer(str2);
	return (buffer);
}
