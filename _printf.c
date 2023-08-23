#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - the printf function to output values on a screen
 * @format: char type pointer param
 * Return: returns count of chars.
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, count = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFFER_SIZE)
				print_buffer(buffer, &buff_ind);
			count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			count += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (count);
}
/**
 * print_buffer - to prints the contents of the buffer if it exist
 * @buffer: an array of chars
 * @buff_ind: the index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
