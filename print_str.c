#include "main.h"

/**
 * print_str - writes the string to stdout
 * @arguments: input string
 * @buffer: buffer pointer
 * @index_buffer: index for buffer pointer
 * Return: On success 1.
 */
int print_str(va_list arguments, char *buffer, unsigned int index_buffer)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			index_buffer = handle_buffer(buffer, nill[i], index_buffer);
		return (6);
	}
	for (i = 0; str[i]; i++)
		index_buffer = handle_buffer(buffer, str[i], index_buffer);
	return (i);
}

