#include "main.h"

/********************** PRINT UNSIGNED NUMBER **********************/
/**
 * print_unsigned - print unsigned number
 * @types: list a of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[i--] = (numb % 10) + '0';
		numb /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - prints an unsigned number in octal notation
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[i--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_numb != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - prints an unsigned number in hexadecimal notation
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal notation
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed characters
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - print hexadecimal number in lower or upper
 * @types: list of arguments
 * @map_to: array of values to map the number to
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @flag_ch: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * @size: size specification
 * Return: number of printed characters
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[i--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && init_numb != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
