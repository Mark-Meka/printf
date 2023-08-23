#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - print character
 * @types: list a of arguments
 * @buffer: buffer array to handle_print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char cha = va_arg(types, int);

	return (handle_write_char(cha, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - print string
 * @types: list a of arguments
 * @buffer: buffer array to handle_print
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int lengths = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[lengths] != '\0')
		lengths++;

	if (precision >= 0 && precision < lengths)
		lengths = precision;

	if (width > lengths)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], lengths);
			for (i = width - lengths; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - lengths; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], lengths);
			return (width);
		}
	}

	return (write(1, str, lengths));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - print percent sign
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - print int
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int u = va_arg(types, long int);
	unsigned long int num;

	u = convert_size_number(u, size);

	if (u == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)u;

	if (u < 0)
	{
		num = (unsigned long int)((-1) * u);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - print unsigned number
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: precision specification
 * @size: size specifier
 * Return: numbers of printed characters
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int o, p, i, sum;
	unsigned int arr[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	o = va_arg(types, unsigned int);
	p = 2147483648; /* (2 ^ 31) */
	arr[0] = o / p;
	for (i = 1; i < 32; i++)
	{
		p /= 2;
		arr[i] = (o / p) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += arr[i];
		if (sum || i == 31)
		{
			char b = '0' + arr[i];

			write(1, &b, 1);
			count++;
		}
	}
	return (count);
}
