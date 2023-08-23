#include "main.h"

/*** PRINT POINTER ***/
/**
 * print_pointer - printing pointer pt variable
 * @types: lst the arg
 * @buffer: bufferring array printer
 * @flags:  calculate the flags
 * @width: knowing the width
 * @precision: precision specs
 * @size: size specs
 * Return: no of chars
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_cha = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, lengths = 2, padd_start = 1;
	unsigned long numb_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	numb_addrs = (unsigned long)addrs;

	while (numb_addrs > 0)
	{
		buffer[ind--] = map_to[numb_addrs % 16];
		numb_addrs /= 16;
		lengths++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_cha = '+', lengths++;
	else if (flags & F_SPACE)
		extra_cha = ' ', lengths++;

	ind++;

	return (write_pointer(buffer, ind, lengths,
		width, flags, padd, extra_cha, padd_start));
}

/*** print the non printables ***/
/**
 * print_non_printable - prints asci codes in non printables
 * @types: lst args
 * @buffer: buffererinng pt
 * @flags:  calculates active flags
 * @width: knowing width
 * @precision: precision specs
 * @size: size specs
 * Return: charc no
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offsets = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offsets] = str[i];
		else
			offsets += append_hexa_code(str[i], buffer, i + offsets);

		i++;
	}

	buffer[i + offsets] = '\0';

	return (write(1, buffer, i + offsets));
}

/**** reverse printing ***/
/**
 * print_reverse - Print the reverse string.
 * @types: ls arg
 * @buffer: buffering print handle
 * @flags:  summation the flags
 * @width: get width
 * @precision: precision specs
 * @size: size specs
 * Return: char printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, counts = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		counts++;
	}
	return (counts);
}
/*** PRINT A STRING IN ROT13 ****/
/**
 * print_rot13string - Print string in rot13.
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char m;
	char *str;
	unsigned int i, j;
	int counts = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				m = out[j];
				write(1, &m, 1);
				counts++;
				break;
			}
		}
		if (!in[j])
		{
			m = str[i];
			write(1, &m, 1);
			counts++;
		}
	}
	return (counts);
}
