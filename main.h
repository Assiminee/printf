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
#endif
