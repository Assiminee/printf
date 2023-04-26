#include "main.h"

/**
 * _printp - prints the percent sign
 *
 * Return: 1
 */

int _printp(void)
{
	write(1, "%", 1);
	return (1);
}

/**
 * _strlen - gets length of string
 * @s: string to check
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * handle_spec - prints characters according to a specifier
 * @format: string with format specifiers
 * @i: index of format specifier
 * @args: a list of variadic arguments
 *
 * Return: number of characters printed
 */

int handle_spec(const char *format, int i, va_list args)
{
	int l;
	int j;
	operations ops[] = {
		{"c", _printc},
		{"s", _prints},
		{"d", _printint},
		{"i", _printint},
		{"b", _printbin},
		{"x", _printx},
		{"X", _printX},
		{"o", _printO},
		{"u", _printU},
		{"S", nonPrintableChar},
		{"p", _printAdrs};
		{NULL, NULL}
	};

	j = 0;
	l = 0;
	while (ops[j].c)
	{
		if (format[i] == *(ops[j].c))
		{
			l += ops[j].f(args);
			break;
		}
		if (j == 10)
		{
			write(1, "%", 1);
			write(1, &format[i], 1);
			l += 2;
			break;
		}
		j++;
	}
	return (l);
}

/**
 * _printU - prints an unsigned int
 * @l: A list of variadic arguments
 *
 * Return: length of digits printed
 */

int _printU(va_list l)
{
	unsigned int  n;
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
 * _printAdrs - prints an adress of var
 * @l: A list of variadic arguments
 *
 * Return: Length of adrs
 */

int _printAdrs (va_list l)
{
	char buf [8];
	void  *adr = va_arg(l, void*);
	int i;
	i = 0;

	while (i < 2 * sizeof(adr))
	{
		int digit = (val >> ((15 - i) * 4)) & 0xF;
		buf[i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		i++;
	}
	buf[i] = '\0';
	write(1, buf, 2 * sizeof(adr));
	return i;
}
