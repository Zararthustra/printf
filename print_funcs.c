#include "holberton.h"

/**
  * print_percent - print a percent
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
void	print_percent(va_list cur_arg, char **ult)
{
	(void)cur_arg;
	*ult = concat_free(*ult, "%", 1);
}

/**
  * print_s - print a string
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
void	print_s(va_list cur_arg, char **ult)
{
	*ult = concat_free(*ult, va_arg(cur_arg, char *), 1);
}

/**
  * print_r - print a string in reverse
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
void	print_r(va_list cur_arg, char **ult)
{
	char	*s;
	char	*r;
	int	l;

	s = va_arg(cur_arg, char *);
	l = _strlen(s);
	r = malloc(l + 1);
	_strncpy(r, s, l + 1);
	rev_string(r);
	*ult = concat_free(*ult, r, 2);
}

/**
  * print_c - print a char
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
void	print_c(va_list cur_arg, char **ult)
{
	char	c;
	int	len;

	len = _strlen(*ult);
	c = va_arg(cur_arg, int);
	if (c)
	{
		*ult = _realloc(*ult, len, len + 2);
		(*ult)[len] = c;
		(*ult)[len + 1] = '\0';
	}
}

/**
 *
  * @ult: the ultimate string
 */
void	print_int(va_list cur_arg, char **ult)
{
	char *s;
	long int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, int);
	len = nb_len(nb, 10);
	s = malloc(len + 1);
	i = len - 1;
	if (nb < 0)
	{
		nb = -(nb);
		s[0] = '-';
	}
	else if (nb == 0)
		s[0] = '0';
	while (nb != 0)
	{
		s[i] = (nb % 10) + '0';
		nb = nb / 10;
		--i;
	}
	s[len] = '\0';
	*ult = concat_free(*ult, s, 2);
}

/**
  * print_u - print a unsigned int
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
void	print_u(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 10);
	s = malloc(len + 1);
	i = len - 1;
	if (nb == 0)
		s[0] = '0';
	while (nb != 0)
	{
		s[i] = (nb % 10) + '0';
		nb = nb / 10;
		--i;
	}
	s[len] = '\0';
	*ult = concat_free(*ult, s, 2);
}

/**
  * print_o - print a unsigned int
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
void	print_o(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 8);
	s = malloc(len + 1);
	i = len - 1;
	if (nb == 0)
		s[0] = '0';
	while (nb != 0)
	{
		s[i] = (nb % 8) + '0';
		nb = nb / 8;
		--i;
	}
	s[len] = '\0';
	*ult = concat_free(*ult, s, 2);
}

/**
  * print_x - print a int in hex
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
void	print_x(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 16);
	s = malloc(len + 1);
	i = len - 1;
	if (nb == 0)
		s[0] = '0';
	while (nb != 0)
	{
		s[i] = i_to_hex(nb % 16, 'x');
		nb = nb / 16;
		--i;
	}
	s[len] = '\0';
	*ult = concat_free(*ult, s, 2);
}

/**
  * print_X - print a unsigned int
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
void	print_X(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 8);
	s = malloc(len + 1);
	i = len - 1;
	if (nb == 0)
		s[0] = '0';
	while (nb != 0)
	{
		s[i] = i_to_hex(nb % 16, 'X');
		nb = nb / 16;
		--i;
	}
	s[len] = '\0';
	*ult = concat_free(*ult, s, 2);
}
