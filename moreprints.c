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
	unsigned int tmp;
	tmp = n;
	int length = 0;
	int r = 1;
	char num;

