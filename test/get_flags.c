#include "main.h"

/**
 * get_flags - to calculate active flags
 * @format: the formatted string in which to print the arguments
 * @i: to take a parameter.
 * Return: the flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int x, curr_k;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_k = *i + 1; format[curr_k] != '\0'; curr_k++)
	{
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
			if (format[curr_k] == FLAGS_CH[x])
			{
				flags |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CH[x] == 0)
			break;
	}

	*i = curr_k - 1;

	return (flags);
}
