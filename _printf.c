#include "main.h"

/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int length = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	while (format[i] == ' ')
		i++;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				length += _printp();
			}
			else
			{
				length += handle_spec(format, i, args);
			}
			i++;
		}
		else
		{
			length += _regchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (length);
}
