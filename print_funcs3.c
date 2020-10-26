#include "holberton.h"

int	_strspelen(char *s)
{
	int	l;

	l = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
			l += 3;
		++s;
		++l;
	}
	return (l);
}

/**
  * print_S -
  **/
int	print_S(va_list cur_arg, char **ult)
{
	char	*s;
	char	*r;
	int	l;
	int	i;

	s = va_arg(cur_arg, char *);
	l = _strspelen(s);
	r = malloc(l + 1);
	if (!r)
	{
		_putstring("Malloc failed\n");
		return (-1);
	}
	i = 0;
	while (*s)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			r[i] = '\\';
			r[++i] = 'x';
			r[++i] = i_to_hex(*s / 16, 'X');
			r[++i] = i_to_hex(*s % 16, 'X');
		}
		else
			r[i] = *s;
		++i;
		++s;
	}
	*ult = concat_free(*ult, r, 2);
	if (!(*ult))
	{
		_putstring("Malloc failed\n");
		free(r);
		return (-1);
	}
	return (0);
}