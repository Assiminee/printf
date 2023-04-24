#include "main.h"
/**
 * _printp - prints percent sign
 * return: 1
 */
int _printp()
{
	write(1, "%", 1);
	return (1);
}
/**
 * _printbin - prints a number in binary
 * @l: A list of variadic arguments
 * return: length of string printed
 */
int _printbin(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);
	unsigned int tmp = num;
	int r = 1;
	int length = 0;
	char c;

	while (tmp / 2)
	{
		r *= 2;
		tmp /= 2;
	}
	while (r)
	{
		c = (num / r) % 2 + '0';
		write(1, &c, 1);
		length++;
		r /= 2;
	}
	return (length);
}
