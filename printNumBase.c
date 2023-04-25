#include "main.h"
/**
 *_printbin - prints a number in binary
 * @l: A list of variadic arguments
 *Return: length
 */
int _printbin(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);

	return (_print_in_base(num, 2, " "));
}
/**
 *_printx - prints num in hexa lowercase
 * @l: A list of variadic arguments
 *Return: length
 */
int _printx(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);

	return (_print_in_base(num, 16, "0123456789abcdef"));
}
/**
 *_printX — prints num in hexa uppercase
 * @l: A list of variadic arguments
 *Return: Iength 
 */
int _printX(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);

	return (_print_in_base(num, 16, "0123456789ABCDEF"));
}
/**
 * _printO - prints num in octa base
 * @l: A list of variadix arguments
 * Return: length
 */
int _printO(va_list l)
{
	unsigned int num = va_arg(1, unsigned int);

	return (_print_in_base(num, 8, " "));
}
