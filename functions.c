#include <stdio.h>
#include "main.h"
/**
 * print_char - Prints a char
 * @types:arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates flags
 * @width: Width
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed
 *
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int length = 0, l;
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
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (l = width - length; l > 0; l--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (l = width - length; l > 0; l--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/**
 * print_percent - Prints a percent sign
 * @types: arguments
 * @buffer: array to handle print
 * @flags: Calculates flags
 * @width: get width.
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed
 *
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
/**
 * print_int - Print integer.
 * @types: arguments
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;
	n = convert_size_number(n, size);
	if (n == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	
	while (num > 0)
	
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	
a++;
	return (write_number(is_negative, i , a), buffer, flags, width, precision, size);


/**
 * print_binary - Prints unsigned number
 * @types: arguments
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: specification
 * @size: specifier
 * Return: Numbers of char printed.
 *
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	unsigned int j, k, n, sum;
	unsigned int a[32];
	int count;
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = j / k;
	for (n = 1; n < 32; n++)
	{
		k /= 2;
		a[n] = (j / k) % 2;
	}
	for (n = 0, sum = 0, count = 0; n < 32; n++)
	{
		sum += a[n];
		if (sum || n == 31)
		{
			char v = '0' + a[n];
			write(1, &v, 1);
			count++;
		}
	}
	return (count);
}
