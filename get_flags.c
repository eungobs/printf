#include "main.h"

/**
 * get_flags - calculates active flags
 * @format: Formatted string  which  prints the arguments
 * @i: takes  parameter.
 * Return: flags:
 */
int get_flags(const char *format, int *a)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int b, curr_a;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_a = *a + 1; format[curr_a] != '\0'; curr_a++)
	{
		for (b = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_a] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[b] == 0)
			break;
	}

	*a = curr_a - 1;

	return (flags);
}

