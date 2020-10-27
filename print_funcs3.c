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
	if (!s)
		return (-1);
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

/**
 * print_p - print address
 * @cur_arg: current arg
 * @ult: ultimaaate string
 * Return: -1 if error, 0 toherwise
 */
int	print_p(va_list cur_arg, char **ult)
{
	unsigned long int nb;
	char *s;
	int i, len;

	nb = (unsigned long int)va_arg(cur_arg, void *);
	len = nb_len(nb, 16) + 2;
	printf("len = %d\n", len);
	if (nb == 0)
	{
		*ult = concat_free(*ult, "(nil)", 1);
		if (!(*ult))
		{
			_putstring("Malloc failed\n");
			return (-1);
		}
		return (0);
	}
	s = malloc(len + 1);
	if (!s)
	{
		_putstring("Malloc failed\n");
		return (-1);
	}
	s[0] = '0';
	s[1] = 'x';
	i = len - 1;
	while (nb != 0 && i >= 2)
	{
		s[i] = i_to_hex(nb % 16, 'x');
		nb = nb / 16;
		--i;
	}
	s[len] = '\0';
	*ult = concat_free(*ult, s, 2);
	if (!(*ult))
	{
		_putstring("Malloc failed\n");
		return (-1);
	}
	return (0);
}


int	print_R(va_list cur_arg, char **ult)
{
	char	*s;

	s = _strdup(va_arg(cur_arg, char *));
	if (!s)
		return (-1);
	s = rot13(s);
	*ult = concat_free(*ult, s, 2);
	if (!(*ult))
	{
		_putstring("Malloc failed\n");
		return (-1);
	}
	return (0);
}
