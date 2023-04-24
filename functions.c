#include "main.h"
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
 * handle_spec - handles speifiers
 * @format: string with format specifier
 * i: index of string
 * length: length of printf function
 * va_list args: a list
 * return: length
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
		if (j == 4)
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