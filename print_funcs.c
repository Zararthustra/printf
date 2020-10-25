#include "holberton.h"

/**
  * print_percent - print a percent
  * @cur_arg: the current av arg
  **/
void	print_percent(va_list cur_arg, char **ult)
{
	(void)cur_arg;
	*ult = concat_free(*ult, "%", 1);
}

/**
  * print_s - print a string
  * @cur_arg: the current av arg
  **/
void	print_s(va_list cur_arg, char **ult)
{
	*ult = concat_free(*ult, va_arg(cur_arg, char *), 1);
}

/**
  * print_c - print a char
  * @cur_arg: the current av arg
  **/
void	print_c(va_list cur_arg, char **ult)
{
	int	len;

	len = _strlen(*ult);
	*ult = _realloc(*ult, len, len + 2);
	(*ult)[len] = va_arg(cur_arg, int);
	(*ult)[len + 1] = '\0';
}
