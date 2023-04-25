#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int x, y;
	int f = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (y = *i + 1; format[y] != '\0'; y++)
	{
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
			if (format[y] == FLAGS_CH[x])
			{
				f |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CH[x] == 0)
			break;
	}

	*i = y - 1;

	return (f);
}
