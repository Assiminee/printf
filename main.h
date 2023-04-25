#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct operations - Struct operations
 * @c: The conversion specifier
 * @f: The function pointer
 */
typedef struct operations
{
	char *c;
	int (*f)(va_list l);
} operations;
int _printf(const char *format, ...);
int _printint(va_list l);
int _prints(va_list l);
int _printc(va_list l);
int _strlen(char *s);
int _printp(void);
int _regchar(char c);
int _invalid_spec(char c);
int handle_spec(const char *format, int i, va_list args);
int _printsixteen(unsigned int n, int r, char tab[], unsigned int base);
int _print_in_base(unsigned int n, unsigned int base, char tab[]);
int _printx(va_list l);
int _printX(va_list l);
int _printO(va_list l);
int _printbin(va_list l);
int _printU(va_list l);
#endif
