#include "main.h"

/**
 * nonPrintableChar - handles non-printable characters
 * @l: A list of variadic arguments
 *
 * Return: number of characters printed
 */

int nonPrintableChar(va_list l)
{
	char *s;
	int i;
	int length;

	s = va_arg(l, char *);
	i = 0;
	length = 0;
	if (s == NULL)
		s = "(null)";
	while (s && s[i])
	{
		if (s[i] > 0 && (s[i] <= 32 || s[i] >= 127))
		{
			write(1, "\\x", 2);
			if (s[i] <= 15)
			{
				write(1, "0", 1);
			}
			_print_in_base(s[i], 16, "0123456789ABCDEF");
			length += 4;
		}
		else
		{
			write(1, &s[i], 1);
			length++;
		}
		i++;
	}
	return (length);
}

/**
 * _printsixteen - prints number in base sixtenn
 * @n: number to print
 * @r: highest power of the given base
 * @tab: character representations of the digits in the given base
 * @base : base in which to convert a given number
 *
 * Return: number of characters printed
 */

int _printsixteen(unsigned int n, int r, char tab[], unsigned int base)
{
	unsigned int i;
	unsigned int num2;
	int length;

	length = 0;
	while (r)
	{
		i = 0;
		num2 = (n / r) % base;
		while (i < base)
		{
			if (i == num2)
			{
				write(1, &tab[i], 1);
				length++;
				break;
			}
			i++;
		}
		r /= base;
	}
	return (length);
}

/**
 * _print_in_base - prints in a base
 * @n: the number to be printed in the specified base
 * @base: the base in which the number n is printed
 * @tab: character representations of the digits in the given base
 *
 * Return: length
 */

int _print_in_base(unsigned int n, unsigned int base, char tab[])
{
	unsigned int tmp;
	int length;
	int r;
	char num;

	tmp = n;
	length = 0;
	r = 1;
	while (tmp / base)
	{
		r *= base;
		tmp /= base;
	}
	if (base == 16)
	{
		length += _printsixteen(n, r, tab, base);
	}
	else if (base == 2 || base == 8)
	{
		while (r)
		{
			num = (n / r) % base + '0';
			write(1, &num, 1);
			length++;
			r /= base;
		}
	}
	return (length);
}
