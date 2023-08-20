#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
  *_printf  - custom printf function
  *@format: - const char type pointer
  *Return: - returns count of characters
  */
int _printf(const char *format, ...)
{
	int count = 0, len = 0;
	char c, *s;
	va_list args;

	va_start(args, format);
	while (*format && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (s[len] != '\0')
					len++;
				write(1, s, len);
				count += len;
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
