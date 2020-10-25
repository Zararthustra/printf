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
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	return (1);
}

