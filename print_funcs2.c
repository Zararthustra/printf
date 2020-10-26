#include "holberton.h"

/**
  * print_percent - print a percent
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  * Return: percent, else -1
  **/
int	print_percent(va_list cur_arg, char **ult)
{
	(void)cur_arg;
	*ult = concat_free(*ult, "%", 1);
	if (!(*ult))
	{
		_putstring("Malloc failed\n");
		return (-1);
	}
	return (0);
}

/**
  * print_s - print a string
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  * Return: string, else -1
  **/
int	print_s(va_list cur_arg, char **ult)
{
	*ult = concat_free(*ult, va_arg(cur_arg, char *), 1);
	if (!(*ult))
	{
		_putstring("Malloc failed\n");
		return (-1);
	}
	return (0);
}

/**
  * print_r - print a string in reverse
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  * Return: rev string, else -1
  **/
int	print_r(va_list cur_arg, char **ult)
{
	char	*s;
	char	*r;
	int	l;

	s = va_arg(cur_arg, char *);
	l = _strlen(s);
	r = malloc(l + 1);
	if (!r)
	{
		_putstring("Malloc failed\n");
		return (-1);
	}
	_strncpy(r, s, l + 1);
	rev_string(r);
	*ult = concat_free(*ult, r, 2);
	return (0);
}

/**
  * print_c - print a char
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  * Return: character, else -1
  **/
int	print_c(va_list cur_arg, char **ult)
{
	char	c;
	int	len;

	len = _strlen(*ult);
	c = va_arg(cur_arg, int);
	if (c)
	{
		*ult = _realloc(*ult, len, len + 2);
		if (!(*ult))
		{
			_putstring("Malloc failed\n");
			return (-1);
		}
		(*ult)[len] = c;
		(*ult)[len + 1] = '\0';
	}
	return (0);
}

/**
  * print_b - print a unsigned int
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  * Return: unsigned int, else -1
  **/
int	print_b(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 2);
	s = malloc(len + 1);
	if (!s)
	{
		_putstring("Malloc failed\n");
		return (-1);
	}
	i = len - 1;
	if (nb == 0)
		s[0] = '0';
	while (nb != 0)
	{
		s[i] = (nb % 2) + '0';
		nb = nb / 2;
		--i;
	}
	s[len] = '\0';
	*ult = concat_free(*ult, s, 2);
	return (0);
}
