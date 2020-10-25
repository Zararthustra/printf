#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct fspec_s - format specifier structure
 * @c: character after the '%'
 * @f: pointer to func
 *
 */

typedef struct fspec_s
{
	char c;
	void (*f)(va_list);
} fspec_t;

int _printf(const char *format, ...);
int is_fspec(const char *format, fspec_t val_fspec[], va_list cur_arg);

int _putchar(char a);
int _putstring(char *str);

void print_s(va_list cur_arg);
void print_c(va_list cur_arg);
void print_percent(va_list cur_arg);
#endif
