#include "main.h"
/**
 * _prints - prints a string
 * @l: A list of variadic arguments
 * Return: length of string
 */
int _prints(va_list l)
{
	char *s = va_arg(l, char*);
	int len;

	if (s == NULL)
		s = "(null)";
	len = _strlen(s);
	write(1, s, len);
	return (len);
}
