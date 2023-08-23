#include "main.h"
/**
 * print_percent - Prints a percent sign
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list args __attribute__((unused)),
		char buffer[] __attribute__((unused)),
		int flags __attribute__((unused)), int width __attribute__((unused)),
		int precision __attribute__((unused)), int size
		__attribute__((unused)))
{
	return (write(1, "%%", 1));
}
