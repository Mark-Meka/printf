#include "holberton.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match a[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int m = 0, n, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[m] != '\0')
	{
		n = 13;
		while (n >= 0)
		{
			if (a[n].id[0] == format[m] && a[n].id[1] == format[m + 1])
			{
				len += a[n].f(args);
				m = m + 2;
				goto Here;
			}
			n--;
		}
		_putchar(format[m]);
		len++;
		m++;
	}
	va_end(args);
	return (len);
}
