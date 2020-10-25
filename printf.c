#include "holberton.h"

int	init_len(const char *s)
{
	int	i = 0;

	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
			return (i);
		++i;
	}
	return (i);
}

/**
 *is_fspec - checks if a char the a format specifier \
 and do appropriate action if so
 * @format: a pointer to the treated char
 * @val_fspec: the array of valid fspec
 * @cur_arg: the current argument
 *
 * Return: 0 if normal char, 1 if a format specifier, -1 if error
 **/
int is_fspec(const char *format, fspec_t val_fspec[], va_list cur_arg, char **ult)
{
	int j;

	if (format == 0)
		return (-1);
	if (*format == '%')
	{
		if (*(format + 1) == 0)
			return (-1);
		j = 0;
		while (val_fspec[j].c != 0)
		{
			if (*(format + 1) == val_fspec[j].c)
			{
				val_fspec[j].f(cur_arg, ult);
				return (1);
			}
			++j;
		}
		return (-1);
	}
	return (0);
}

/**
 * _printf - our printf function
 * @format: the format string
 *
 * Return: the number of printed char
 **/
int _printf(const char *format, ...)
{
	va_list	cur_arg;
	fspec_t	valid_fspec[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_percent},
		{0, NULL}
	};
	int	i;
	char	*ultimate;

	if (!format)
		return (-1);
	va_start(cur_arg, format);
	ultimate = create_array(1, 0);
	i = 0;
	while (format[i])
	{
		ultimate = concat_sbloc(ultimate, format + i, &i);
		if (format[i] == '%')
		{
			if (is_fspec(format + i, valid_fspec, cur_arg, &ultimate) == -1)
			{
				_printf("Error\n");
				return (-1);
			}
			i += 2;
		}
	}
	va_end(cur_arg);
	_putstring(ultimate);
	i = _strlen(ultimate);
	free(ultimate);
	return (i);
}
