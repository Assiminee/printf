#include "main.h"

/**
 * _printc - prints a single char
 * @l: A list of variadic arguments
 *
 * Return: 1
 */

int _printc(va_list l)
{
	int c;

	c = va_arg(l, int);
	write(1, &c, 1);
	return (1);
}

/**
 * _prints - prints a string
 * @l: A list of variadic arguments
 *
 * Return: number of characters printed
 */

int _prints(va_list l)
{
	char *s;
	int len;

	s = va_arg(l, char *);
	if (s == NULL)
		s = "(null)";
	len = _strlen(s);
	write(1, s, len);
	return (len);
}

/**
 * _printint - prints an int
 * @l: list of variating arguments
 *
 * Return: number of characters printed
 */

int _printint(va_list l)
{
	int n;
	unsigned int temp;
	unsigned int r;
	char num;
	int length;

	n = va_arg(l, unsigned int);
	r = 1;
	length = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		temp = n;
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

/**
 * _invalid_spec - printd invalid specifier
 * @c: Character to print
 *
 * Return: number of characters printed
 */

int _invalid_spec(char c)
{
	return (_printp() + _regchar(c));
}

/**
 * _regchar - prints regular char
 * @c: char to print
 *
 * Return: 1
 */

int _regchar(char c)
{
	write(1, &c, 1);
	return (1);
}
