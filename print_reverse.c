#include "main.h"

/**
 * print_reverse - writes the str in reverse
 * @arguments: input string
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_reverse(va_list arguments, char *buffer, unsigned int index_buffer)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nill[] = "(llun)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			index_buffer = handle_buffer(buffer, nill[i], index_buffer);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		index_buffer = handle_buffer(buffer, str[j], index_buffer);
	}
	return (i);
}

