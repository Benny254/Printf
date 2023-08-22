#include "main.h"

/**
 * print_integer - the function for %d or %i
 *
 * Description: the num and *count
 *
 * Return: the count
 */
int print_integer(int num, int *count)
{
	char buffer[BUFFERSIZE];
	int len = snprintf(buffer, sizeof(buffer), "%d", num);

	if (len < 0 || (size_t)len >= sizeof(buffer))
		return (-1);
	*count += write(1, buffer, len);
	return (*count);
}
