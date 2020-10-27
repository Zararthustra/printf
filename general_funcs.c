#include "holberton.h"

/**
 * _putchar - print a char
 * @a: char to print
 * Return: char to print
 */

int _putchar(char a)
{
	return (write(1, &a, 1));
}

/**
 * _putstring - print a string
 * @str: string to print
 * Return: 1 if ok, -1 if no string
 */

int _putstring(char *str)
{
	if (!str)
		return (-1);
	write(1, str, _strlen(str));
	return (1);
}

/**
 * _strlen - gives the length of a string
 * @s: the string from whitch len is found
 *
 * Return: the len of the string
 **/
int	_strlen(char *s)
{
	int	l = 0;

	if (!s)
		return (0);
	while (*s++)
		++l;
	return (l);
}

/**
 * create_array - a function that creates an array of chars \
 and initializes it with a specific char
 * @size: the size of the array in bytes
 * @c: the char to initialize that array
 *
 * Return: the newly created initialized array
 **/
char	*create_array(unsigned int size, char c)
{
	char	*s;

	if (!size)
		return (0);
	s = malloc(size);
	if (!s)
		return (0);
	while (size > 0)
	{
		s[size - 1] = c;
		--size;
	}
	return (s);
}

/**
 * _strcpy - copy a source string to dest including null terminator
 * @src: the source string
 * @dest: the destination string
 * Return: pointer to the dest string
 **/
char	*_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest + i && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	return (dest);
}
