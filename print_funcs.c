#include "holberton.h"

void print_s(va_list cur_arg)
{
	_putstring(va_arg(cur_arg, char *));
}

void print_c(va_list cur_arg)
{
	_putchar(va_arg(cur_arg, int));
}

