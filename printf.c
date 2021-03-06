#include "holberton.h"

/**
 * w_fspec - checks if a char the a format specifier \
 and do appropriate action if so
 * @format: a pointer to the treated char
 * @val_fspec: the array of valid fspec
 * @cur_arg: the current argument
 * @u: the pointer to the ultimate string
 * Return: 0 if normal char, 1 if !valid fspec, 2 if valid \
 format specifier, -1 if error
 **/
int w_fspec(const char *format, fspec_t val_fspec[], va_list cur_arg, char **u)
{
	int	j;

	if (format == 0)
		return (-1);
	if (*format == '%')
	{
		if (*(format + 1) == 0)
			return (1);
		j = 0;
		while (val_fspec[j].c != 0)
		{
			if (*(format + 1) == val_fspec[j].c)
			{
				if (val_fspec[j].f(cur_arg, u) == -1)
					return (-1);
				return (2);
			}
			++j;
		}
		if (print_percent(cur_arg, u) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

/**
 * _printf - our printf function
 * @format: the format string
 *
 * Return: the number of printed char
 **/
int	_printf(const char *format, ...)
{
	char		*ult;
	va_list		cur_arg;
	int		i, k;
	fspec_t		val_fspec[] = {{'d', print_int}, {'i', print_int},
				{'c', print_c}, {'s', print_s},
				{'S', print_S}, {'%', print_percent},
				{'r', print_r}, {'p', print_p},
				{'u', print_u}, {'R', print_R},
				{'o', print_o},
				{'x', print_x},
				{'X', print_X},
				{'b', print_b},
				{0, NULL}
				};

	if (!format)
		return (-1);
	va_start(cur_arg, format);
	ult = create_array(1, 0);
	i = 0;
	while (format[i])
	{
		ult = concat_sbloc(ult, format + i, &i);
		if (format[i] == '%')
		{
			k = w_fspec(format + i, val_fspec, cur_arg, &ult);
			if (k == -1)
			{
				_printf("Error\n");
				free(ult);
				return (-1);
			}
			i += k;
		}
	}
	va_end(cur_arg);
	_putstring(ult);
	i = _strlen(ult);
	free(ult);
	return (i);
}
