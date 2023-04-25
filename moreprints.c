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
 *_printsixteen - prints in base 16
 *@n: number to print
 *@r: digit to be orint next
 *@tab: digits for conversion
 @base : represents the base in which we print
 *Return: Length
 */
int _printsixteen(unsigned int n, int r, char tab[], unsigned int base)
{
	unsigned int i;
	unsigned int num2;
	int length = 0;
	while(r)
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
 *_print_in_base - prints in a base
 *@n: the number to be printed in the specified base
 *@base: the base in which the number n is printed
 *@tab: contains digits for conversion
 *Return: length
 */
int _print_in_base(unsigned int n, unsigned int base, char tab[])
{
	unsigned int tmp = n;
	int length = 0;
	int r = 1;
	char num;
	
	while (tmp / base)
	{
		r *= base;
		tmp /= base;
	}
	if (base == 16)
	{
		_printsixteen(n, r, tab, base);
	}
	else if (base == 2)
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
/**
 * _printbin - prints a number in binary
 * @l: A list of variadic arguments
 * return: length of string printed
 */
int _printbin(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);
	
	return (_print_in_base(num, 2, " "));
}
/**
 * _printx - prints num in hexa lowercase
 * @l: A list of variadic arguments
 * return: length of string printed
 */
int _printx(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);
	
	return (_print_in_base(num, 16, "0123456789abcdef"));
}
