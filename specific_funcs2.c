#include "holberton.h"

/**
 * rot13 - rot13 the input string
 * @s: the input string to rot13
 * Return: the rotated string
 **/
char	*rot13(char *s)
{
	int	i;
	char	r[] = "NOPQRSTUVWXYZABCDEFGHIJKLM******nopqrstuvwxyzabcdefghijklm";

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'A' &&  s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
			*(s + i) = r[*(s + i) - 'A'];
		++i;
	}
	return (s);
}

/**
 * _strdup - a function that returns a pointer to a newly allocated \
 * space in memory, which contains a copy of the string given as a parameter
 * @str: the string to dupplicate
 * Return: the newly created duplicate string
 **/
char	*_strdup(char *str)
{
	char	*dup;

	if (!str)
		return (0);
	dup = malloc(_strlen(str) + 1);
	if (!dup)
		return (0);
	*dup = _strcpy(dup, str);
	return (dup);
}
