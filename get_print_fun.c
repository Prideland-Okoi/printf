#include "main.h"
/**
 * get_print_func - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int)
{
	print_t pr[] = {
		{"c", print_char}, {"s", print_str},
		{"i", print_int}, {"d", print_int},
		{"b", print_binary}, {"u", print_usi},
		{"o", print_oct}, {"x", print_decihexa},
		{"X", print_deci_hexadeci}, {"S", print_svc},
		{"p", print_add}, {"li", printl_int},
		{"ld", printl_int}, {"lu", print_long_usi},
		{"lo", print_long_oct}, {"lx", printlong_decihex},
		{"lX", print_long_decihex}, {"hi", print_si},
		{"hd", print_si}, {"hu", print_susi},
		{"ho", print_long_doct}, {"hx", printshort_hex},
		{"hX", printshort_decihex}, {"#o", print_num_oct},
		{"#x", print_hex_zero}, {"#X", print_num_up},
		{"#i", print_int}, {"#d", print_int},
		{"#u", print_usi}, {"+i", print_plus_int},
		{"+d", print_plus_int}, {"+u", print_usi},
		{"+o", print_oct}, {"+x", print_decihexa},
		{"+X", print_deci_hexadeci}, {" i", print_space_int},
		{" d", print_space_int}, {" u", print_usi},
		{" o", print_oct}, {" x", print_decihexa},
		{" X", print_deci_hexadeci}, {"R", print_rot},
		{"r", print_reverse}, {"%", print_c_stdout},
		{"l", print_c_stdout}, {"h", print_c_stdout},
		{" +i", print_plus_int}, {" +d", print_plus_int},
		{"+ i", print_plus_int}, {"+ d", print_plus_int},
		{" %", print_c_stdout}, {NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].type_arg)
	{
		if (s[index] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (pr[i].f);
}
