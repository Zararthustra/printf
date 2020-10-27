#include "holberton.h"

/**
 * nb_len - calculate the len of a nb
 * @nb: number
 * @base: 10 for int, 8 octal, 16 hex, 2 bin
 * Return: the len of nb (+1 for minus sign)
 */
int nb_len(long int nb, int base)
{
	int len;

	len = 0;
	if (nb <= 0)
	{
		len = len + 1;
	}
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

/**
 * lenbloc - get the length of a string bloc
 * @s: string bloc
 * Return: length
 */

int	lenbloc(const char *s)
{
	int	l = 0;

	if (!s)
		return (0);
	while (s[l] && s[l] != '%')
		++l;
	return (l);
}

/**
 * concat_sbloc - a function that concatenates two
 * allocated strings and free them
 * @ult: first string
 * @rest: second string
 * @i: pointer
 * Return: the newly created concat. string
 **/
char	*concat_sbloc(char *ult, const char *rest, int *i)
{
	char	*cc;
	int	l1;
	int	l2;

	l1 = _strlen(ult);
	l2 = lenbloc(rest);
	*i += l2;
	cc = create_array(l1 + l2 + 1, 0);
	if (!cc)
		return (0);
	cc = _strncpy(cc, ult, l1);
	_strncpy(cc + l1, (char *)rest, l2);
	free(ult);
	return (cc);
}

/**
 * concat_free - a function that concatenates two strings and free them
 * @s1: first allocated string
 * @s2: second allocated string
 * @select: free selector
 * Return: the newly allocated concat. string
 **/
char	*concat_free(char *s1, char *s2, int select)
{
	char	*cc;
	int	l1;
	int	l2;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	cc = malloc(l1 + l2 + 1);
	if (!cc)
		return (0);
	cc = _strncpy(cc, s1, l1);
	_strncpy(cc + l1, s2, l2 + 1);
	if (select == 1)
		free(s1);
	else if (select == 2)
	{
		free(s1);
		free(s2);
	}
	return (cc);
}

/**
 * i_to_hex - convert char to hexadecimal
 * @i: int to convert
 * @x: char selector
 * Return: converted int
 */
char	i_to_hex(int i, char x)
{
	if (i >= 0 && i <= 9)
		return (i + '0');
	else if (i >= 10 && i <= 15)
	{
		if (x == 'X')
			return ('A' + i - 10);
		if (x == 'x')
			return ('a' + i - 10);
	}
	return (0);
}
