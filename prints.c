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
/**
 * _printint - prints an int
 * @l: list of variating arguments
 * Return: length of digits printed
 */
int _printint(va_list l)
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
 * Return: length
 */
int _invalid_spec(char c)
{
	return (_printp() + _regchar(c));
}
/**
 * _regchar - prints regular char
 * @c: char to print
 * Return: 1
 */
int _regchar(char c)
{
	write(1, &c, 1);
	return (1);
}
