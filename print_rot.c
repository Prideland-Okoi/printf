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
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nill[] = "(avyy)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			index_buffer = handle_buffer(buffer, nill[i], index_buffer);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[i] == alf[j])
			{
				k = 1;
				index_buffer = handle_buffer(buffer, rot[j], index_buffer);
				break;
			}
		}
		if (k == 0)
			index_buffer = handle_buffer(buffer, str[i], index_buffer);
	}
	return (i);
}

