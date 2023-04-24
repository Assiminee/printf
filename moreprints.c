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
 */
