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
int _putchar(char a);

#endif
