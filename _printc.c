#include "main.h"
/**
 * _printc - prints a single char
 * @l: A list of variadic arguments
 * Return: 1
 */
int _printc(va_list l)
{
	int c = va_arg(l, int);

	write(1, &c, 1);
	return (1);
}
