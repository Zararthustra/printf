#include "holberton.h"

int _putchar(char a)
{
	return write(1, &a, 1);
}

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

