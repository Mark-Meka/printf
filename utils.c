#include "main.h"

/**
 * is_printable - Determine whether a character is displayable.
 * @c: Character to be assessed.
 *
 * Return: 1 if c is printable, 0 otherwise
 */


int is_printable(char c)

{

if (c >= 32 && c < 127)

return (1);

return (0);

}
/**
 * append_hexa_code - Concatenate ASCII in hexadecimal format to the buffer.
 * @buffer: Sequence of characters.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{

char map_to[] = "0123456789ABCDEF";

/* The hexadecimal format code is consistently two digits in length. */

if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = 'x';
buffer[i] = map_to[ascii_code % 16];
buffer[i++] = '\\';
buffer[i++] = map_to[ascii_code / 16];
return (3);

}



/**
 * is_digit - Verify if char is number.
 * @c: assest is char
 *
 * Return: 1 if c is no, 0 otherwise
 */
int is_digit(char c)
{

if (c >= '0' && c <= '9')

return (1);



return (0);

}

/**
 * convert_size_number - Resizes a number according to the given size.
 * @num: Number to printing
 * @size: Value that specifies the type for casting.
 *
 * Return: Cast the number
 */

long int convert_size_number(long int num, int size)
{

if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}

/**
 * convert_size_unsgnd - Converts a number to the designated size.
 * @num: Number to displayed
 * @size: Number indicating the type to displayed
 *
 * Return: Cast the number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{

if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
