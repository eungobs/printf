#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_pointer - Prints value of a pointer variable.
 * @types: arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed.
 *
 */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFSIZ - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (fwrite(int 1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;
ind++;
/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
return (print_pointer(buffer, int char * length,
width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa non printable chars
 * @types: arguments
 * @buffer: array to handle print
 * @flags: Calculates flags
 * @width: get width.
 * @precision: specification
 * @size: specifier
 * Return: Number of chars printed
 *
 */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int k = 0, offset = 0;
char *str = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
return (write(1, "(null)", 6));
while (str[i] != '\0')
{
	if (is_printable(str[k]))
	buffer[k + offset] = str[k];
		else
			offset += append_hexa_code(str[k], buffer, k + offset);

		k++;
	}

	buffer[k + offset] = '\0';

return (write(1, buffer, k + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: arguments
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: specification
 * @size: specifier
 * Return: Numbers of chars printed
 *
 */

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int a, out = 0;

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
	for (a = 0; str[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char h = str[a];

		write(1, &h, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: arguments
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: specification
 * @size: specifier
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int g, s
	int count = 0;
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
	for (g = 0; str[g]; g++)
	{
		for (s = 0; in[s]; s++)
		{
			if (in[s] == str[g])
			{
				x = out[s];
				write(1, &x, 1);
				out++;
				break;
			}
		}
		if (!in[s])
		{
			x = str[g];
			write(1, &x, 1);
			out++;
		}
	}
	return (count);
}