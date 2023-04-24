#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
typedef struct operations
{
    char *c;
    int (*f)(va_list l);
}operations;
int _printint(va_list l);
int _prints(va_list l);
int _printc(va_list l);
int _strlen(char *s);
int _printp();
int _regchar(char c);
int _invalid_spec(char c);
int handle_spec(const char *format,int i,int length, va_list args);
#endif
