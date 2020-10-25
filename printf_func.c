#include "holberton.h"

int _putchar(char a)
{
	return write(1, &a, 1);
}

void print_c(va_list cur_arg)
{
	_putchar(va_arg(cur_arg, int));
}

int is_it_format_spec(const char *format, fspec_t valid_fspec[], va_list cur_arg)
{
	int j;

	if (format == 0)
		return (-1);
	if (*format == '%')
	{
		if (*(format + 1) == 0)
			return (-1);
		j = 0;
		while (valid_fspec[j].c != 0)
		{
			if (*(format + 1) == valid_fspec[j].c)
			{
				valid_fspec[j].f(cur_arg);
				return (1);
			}
			++j;
		}

	}
	return (0);
}

int _printf(const char *format, ...)
{
	va_list cur_arg;
	int i;
	int j;
	fspec_t valid_fspec[] = {
		{'c', print_c},
		/*	{'s', print_s},*/
		{0, NULL}
	};

	va_start(cur_arg, format);
	i = 0;
	while (format[i])
	{
		j = is_it_format_spec(format + i, valid_fspec, cur_arg);
		if (j == -1)
		{
			printf("error\n");
			return (-1);
		}
		else if (j == 1)
			i++;
		else
			_putchar(format[i]);
		++i;
	}
	return (i);
}
