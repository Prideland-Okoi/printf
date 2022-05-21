#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, index_buffer = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buffer(buffer, index_buffer), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handle_buffer(buffer, format[i], index_buffer), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, index_buffer);
					i += ret_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handle_buffer(buffer, format[i], index_buffer), len++;
		for (index_buffer = len; index_buffer > 1024; index_buffer -= 1024)
			;
	}
	print_buffer(buffer, index_buffer), free(buffer), va_end(arguments);
	return (len);
}
