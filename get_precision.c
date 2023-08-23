#include "main.h"

/**
 * get_precision - calculate the precision for printing
 * @format:formatted string in which to print the arguments
 * @i: list of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int Precision = -1;

	if (format[curr_i] != '.')
		return (Precision);

	Precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			Precision *= 10;
			Precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			Precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (Precision);
}

