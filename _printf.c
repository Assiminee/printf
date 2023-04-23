#include "main.h"
int _strlen(char *s);
int _printc(va_list l);
int _prints(va_list l);
/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int j;
	int length = 0;
	operations ops[] = {
		{"c", _printc},
		{"s", _prints},
		{"d", _printint},
		{"i", _printint},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				length++;
			}
			else
			{
				while (ops[j].c)
				{
					if (format[i] == *(ops[j].c))
					{
						length += ops[j].f(args);
						break;
					}
					if (j == 1)
					{
						write(1, "%", 1);
						write(1, &format[i], 1);
						length += 2;
						break;
					}
					j++;
				}
			}
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			length++;
			i++;
		}
	}
	va_end(args);
	return (length);
}
/**
 * _strlen:gets length of string
 * @s: string to check
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

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
	int len = _strlen(s);

	if (s == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, s, len);
	return (len);
}
