#include "main.h"
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
	while (format[i] == ' ')
		i++;
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
					if (j == 3)
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
