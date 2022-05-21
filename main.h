#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int print_c_stdout(va_list __attribute__((unused)), char *, unsigned int);
int print_char(va_list arguments, char *buffer, unsigned int index_buffer);
int print_str(va_list arguments, char *buffer, unsigned int index_buffer);
int print_int(va_list arguments, char *buffer, unsigned int index_buffer);
int print_binary(va_list arguments, char *buffer, unsigned int index_buffer);
int print_usi(va_list arguments, char *buffer, unsigned int index_buffer);
int print_oct(va_list arguments, char *buffer, unsigned int index_buffer);
int print_decihexa(va_list arguments, char *buffer, unsigned int index_buffer);
int print_deci_hexadeci(va_list arguments, char *buffer, unsigned int index_buffer);
int print_svc(va_list arguments, char *buffer, unsigned int index_buffer);
int print_add(va_list arguments, char *buffer, unsigned int index_buffer);
int print_reverse(va_list arguments, char *buffer, unsigned int index_buffer);
int print_rot(va_list arguments, char *buffer, unsigned int index_buffer);
int printl_int(va_list arguments, char *buffer, unsigned int index_buffer);
int print_long_usi(va_list arguments, char *buffer, unsigned int index_buffer);
int print_long_oct(va_list arguments, char *buffer, unsigned int index_buffer);
int printlong_decihex(va_list arguments, char *buffer, unsigned int index_buffer);
int print_long_decihex(va_list arguments, char *buffer, unsigned int index_buffer);
int print_si(va_list arguments, char *buffer, unsigned int index_buffer);
int print_susi(va_list arguments, char *buffer, unsigned int index_buffer);
int print_long_doct(va_list arguments, char *buffer, unsigned int index_buffer);
int printshort_hex(va_list arguments, char *buffer, unsigned int index_buffer);
int printshort_decihex(va_list arguments, char *buffer, unsigned int index_buffer);
int print_plus_int(va_list arguments, char *buffer, unsigned int index_buffer);
int print_num_oct(va_list arguments, char *buffer, unsigned int index_buffer);
int print_hex_zero(va_list arguments, char *buffer, unsigned int index_buffer);
int print_num_up(va_list arguments, char *buffer, unsigned int index_buffer);
int print_space_int(va_list arguments, char *buffer, unsigned int index_buffer);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ret_print_func(const char *s, int index);
unsigned int handle_buffer(char *buffer, char c, unsigned int index_buffer);
int print_buffer(char *buffer, unsigned int num_buffer);
char *build_binary_array(char *binary, long int int_in, int isneg, int limit);
char *build_oct_array(char *bnr, char *oct);
char *build_long_oct_array(char *bnr, char *oct);
char *build_short_oct_array(char *bnr, char *oct);
char *build_hex_array(char *bnr, char *hex, int isupp, int limit);

#endif
