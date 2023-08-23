#include "main.h"
/**
 * print_string - Prints a string
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list args, char buffer[] __attribute__((unused)),
		int flags __attribute__ ((unused)), int width __attribute__((unused)),
		int precision __attribute__((unused)), int size __attribute__((unused)))
{
	int len = 0, i;
	char *str;

	str = va_arg(args, char *);
	if( str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "  ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i < 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
