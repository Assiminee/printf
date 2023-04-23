#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
*_strlen:gets length of string
*@s: string to check
*Return: length of string
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
*_printf:prints an input
*@format: argument to print
*Return: length of format
*/
int _printf(const char *format, ...)
{
	int i;
	int c;
	char *s;
	int length;
	va_list args;

	i=0;
	length=0;

	va_start(args,format);
	if(format == NULL)
		return(-1);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	while(format && format[i])
	{
		if(format[i] == '%')
		{
			i++;
			if(format[i] == 's')
			{
				s = va_arg(args, char*);
				if (s == NULL)
				{
					write(1, "(nil)", 5);
					length += 5;
				}
				else
				{
					length+=_strlen(s);
					write(1, s, _strlen(s));
				}
			}	
			else if(format[i] == 'c')
			{
				length++;
				c=va_arg(args, int);
				write(1, &c, 1);
			}
			else if(format[i] == '%')
			{
				length++;
				write(1, &format[i], 1);

			}
			else
			{
				length+=2;
				write(1, "%", 1);
				write(1, &format[i], 1);
				break;
			}
			i++;
		}
		else
		{
			length++;
			write(1, &format[i], 1);
			i++;
		}

	}
	va_end (args);
	return (length);
}
