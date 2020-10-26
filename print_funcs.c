#include "holberton.h"

/**
 *
  * @ult: the ultimate string
 */
int	print_int(va_list cur_arg, char **ult)
{
	char *s;
	long int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, int);
	len = nb_len(nb, 10);
	s = malloc(len + 1);
	if (!s)
	{
		_putstring("Malloc failed\n");
		return (-1);
	}	i = len - 1;
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
	return (0);
}

/**
  * print_u - print a unsigned int
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
int	print_u(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 10);
	s = malloc(len + 1);
	if (!s)
	{
		_putstring("Malloc failed\n");
		return (-1);
	}	i = len - 1;
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
	return (0);
}

/**
  * print_o - print a unsigned int
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
int	print_o(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 8);
	s = malloc(len + 1);
	if (!s)
	{
		_putstring("Malloc failed\n");
		return (-1);
	}	i = len - 1;
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
	return (0);
}

/**
  * print_x - print a int in hex
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
int	print_x(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 16);
	s = malloc(len + 1);
	if (!s)
	{
		_putstring("Malloc failed\n");
		return (-1);
	}	i = len - 1;
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
	return (0);
}

/**
  * print_X - print a unsigned int
  * @cur_arg: the current av arg
  * @ult: the ultimate string
  **/
int	print_X(va_list cur_arg, char **ult)
{
	char *s;
	unsigned int nb;
	int i;
	int len;

	nb = va_arg(cur_arg, unsigned int);
	len = nb_len(nb, 8);
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
		s[i] = i_to_hex(nb % 16, 'X');
		nb = nb / 16;
		--i;
	}
	s[len] = '\0';
	*ult = concat_free(*ult, s, 2);
	return (0);
}
