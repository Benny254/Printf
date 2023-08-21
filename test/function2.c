#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - to prints the value of a pointer variable
 * @types: the list of arguments
 * @buffer: the buffer array to handle print
 * @flags:  to calculate active flags
 * @width: to get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int width, int flags, int size, int precision)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(size);
	UNUSED(width);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - to print ascii codes in hexa of non printable chars
 * @types: the list of arguments
 * @buffer: to buffer array to handle print
 * @flags:  to calculate active flags
 * @width: to get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int width, int flags, int size, int precision)
{
	int a = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(width);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(precision);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + offset] = str[a];
		else
			offset += append_hexa_code(str[a], buffer, a + offset);

		a++;
	}

	buffer[a + offset] = '\0';

	return (write(1, buffer, a + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - to print the reverse string.
 * @types: the list of arguments
 * @buffer: to buffer array to handle print
 * @flags:  to calculate the active flags
 * @width: to get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the numbers of chars to be printed
 */

int print_reverse(va_list types, char buffer[],
	int width, int flags, int size, int precision)
{
	char *str;
	int a, count = 0;

	UNUSED(flags);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;
	for (a = a - 1; a >= 0; a--)
	{
		char z = str[a];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - to print a string in rot13.
 * @types: the list of arguments
 * @buffer: the buffer array to handle print
 * @flags:  to calculate active flags
 * @width: to get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the numbers of chars to be printed
 */
int print_rot13string(va_list types, char buffer[],
	int width, int flags, int size, int precision)
{
	char x;
	char *str;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(buffer);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
			{
			if (in[b] == str[a])
			{
				x = out[b];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			x = str[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
