#include "main.h"
/**
 * print_char - Prints a char
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width of printed characters
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char c;

	c = (char)va_arg(args, int);
	return (handle_char(c, buffer, flags, width, precision, size));
}
