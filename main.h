#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char *format, ...);
void print_char(char c, int *count);
void print_string(char *s, int *count);
void print_integer(int num, int *count);
int print_args(char format, va_list args, int *count);

#endif
