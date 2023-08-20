#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#define BUFF_SIZE 1024
#define UNUSED(M) (void)(M)

/* spec flags */

#define F_PLUS 1
#define F_MINUS 2
#define F_HASH 8
#define F_ZERO 4
#define F_SPACE 16

/* spec sizes */
#define S_SHORT 1
#define S_LONG 2


/**
 * struct prnt - formatting structure
 *
 * @prnt: Formating
 * @fn: This is the associated function.
 */

struct prnt

{

char prnt;

int (*fn)(va_list, char[], int, int, int, int);

};


/**
 * typedef struct prnt prn_f - structured options
 *
 * @prnt: formating structure
 * @fm_t: This is the associated function.
 */

typedef struct prnt prn_f;


int handle_print(const char *prnt, int *i,
int _printf(const char *format, ...);
va_list list, char buffer[], int flags, int width, int precision, int size);


/*  The Funtions that printning strings and charachters */

int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);





int print_hexa(va_list types, char map_to[],

char buffer[], int flags, char flag_ch, int width, int precision, int size);



/* Function to print non printable characters */

int print_non_printable(va_list types, char buffer[],

int flags, int width, int precision, int size);


/* Functions thar printing numbers no */

int print_hexadecimal(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],

int print_binary(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_unsigned(va_list types, char buffer[],

int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],

int flags, int width, int precision, int size);
int flags, int width, int precision, int size);




/* printing memory address function */

int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],


/* specifiers  handling functions */

int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);


/*reversing functions */

int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],


/*string function rot13*/

int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[],

/* handling for width */


int write_pointer(char buffer[], int ind, int length,

int width, int flags, char padd, char extra_c, int padd_start);
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],

int write_unsgnd(int is_negative, int ind,

char buffer[],

int flags, int width, int precision, int size);


/**** UTILS  functions ***/

int append_hexa_code(char, char[], int);
int is_printable(char);
int is_digit(char);

long int convert_size_unsgnd(unsigned long int num, int size);
long int convert_size_number(long int num, int size);



#endif
