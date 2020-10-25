#include "holberton.h"

/**
  * print_percent - print a percent
  * @cur_arg: the current av arg
  **/
void	print_percent(va_list cur_arg)
{
	(void)cur_arg;
	_putchar('%');
}

/**
  * print_s - print a string
  * @cur_arg: the current av arg
  **/
void	print_s(va_list cur_arg)
{
	_putstring(va_arg(cur_arg, char *));
}

/**
  * print_c - print a char
  * @cur_arg: the current av arg
  **/
void	print_c(va_list cur_arg)
{
	_putchar(va_arg(cur_arg, int));
}
