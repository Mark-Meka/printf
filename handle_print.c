#include "main.h"


/**
 * handle_print - Depending on the argument's type, prints it
 * @prnt: Formtted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: An array of buffers to handle printing.
 * @flags: Flags that are active are calculated
 * @width: get width
 * @precision: Precision specs
 * @size: specifier sizing
 * Return: 1 or 2;
*/
int handle_print(const char *prnt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int m, unknow_len = 0, printed_chars = -1;
prnt_t prnt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'m', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (m = 0; prnt_types[m].prnt != '\0'; m++)
if (prnt[*ind] == prnt_types[m].prnt)
return (prnt_types[m].fn(list, buffer, flags, width, precision, size));
if (prnt_types[m].prnt == '\0')
{
if (prnt[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (prnt[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*ind);
while (prnt[*ind] != ' ' && prnt[*ind] != '%')
--(*ind);
if (prnt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &prnt[*ind], 1);
return (unknow_len);
}
return (printed_chars);
}
