#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct fspec_s
{
	char c;
	void (*f)(va_list);
} fspec_t;

int _printf(const char *format, ...);
int is_it_format_spec(const char *format, fspec_t valid_fspec[], va_list cur_arg);
int _putchar(char a);
int _putstring(char *str);
void print_s(va_list cur_arg);
void print_c(va_list cur_arg);

#endif
