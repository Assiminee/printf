#include "main.h"
/**
 * _printint - prints an int
 * @l: list of variating arguments
 * Return: length of digits printed
 */
int _printint(va_list l)
{
	int n = va_arg(l, int);
	int temp;
	int r = 1;
	char num;
	int length = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		length++;
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
