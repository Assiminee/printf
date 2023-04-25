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
 *_printx - prints a number in hexadecimal in lowercase
 * @l: A list of variadic arguments
 * Return: number of characters printed
 */
int _printx(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);

	return (_print_in_base(num, 16, "0123456789abcdef"));
}
/**
 *_printX — prints a number in hexadecimal in uppercase
 * @l: A list of variadic arguments
 *Return: number of characters printed
 */
int _printX(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);

	return (_print_in_base(num, 16, "0123456789ABCDEF"));
}
/**
 * _printO - prints a number in base 8
 * @l: A list of variadix arguments
 * Return: number of characters printed
 */
int _printO(va_list l)
{
	unsigned int num = va_arg(l, unsigned int);

	return (_print_in_base(num, 8, " "));
}
