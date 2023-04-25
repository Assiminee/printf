#include "main.h"
/**
 * _printU - prints an unsigned int
 * @l: A list of variadic arguments
 * Return: length of digits printed
 */
int _printU(va_list l)
{
	int n = va_arg(l, unsigned int);
	unsigned int temp;
	unsigned int r = 1;
	char num;
	int length = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	temp = n;
	while (temp / 10)
	{
		r *= 10;
		temp /= 10;
	}
	while (r)
	{
		num = (n / r) % 10 + '0';
		write(1, &num, 1);
		length++;
		r /= 10;
	}
	return (length);
}
