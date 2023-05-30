#include "main.h"

/**
 * get_size - calculate  size to cast argument
 * @format: Formatted string in which to print the arguments
 * @i: lists arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *b)
{
	int curr_b = *b + b;
	int size = 0;

	if (format[curr_b] == 'l')
		size = S_LONG;
	else if (format[curr_b] == 'h')
		size = S_SHORT;

	if (size == 0)
		*b = curr_b - 1;
	else
		*b = curr_b;

	return (size);
}

