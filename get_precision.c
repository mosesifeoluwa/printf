#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int y = *i + 1;
	int pre = -1;

	if (format[y] != '.')
		return (pre);

	pre = 0;

	for (y += 1; format[y] != '\0'; y++)
	{
		if (is_digit(format[y]))
		{
			pre *= 10;
			pre += format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			pre = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = y - 1;

	return (pre);
}
