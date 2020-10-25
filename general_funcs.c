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
 * _strcat -  a function that concatenates two strings
 *@dest: destination string
 *@src: source string
 *
 * Return: the cat string
 **/
char	*_strcat(char *dest, char *src)
{
	char	*buf;

	if (!dest || !src)
		return (dest);
	buf = dest;
	while (*buf)
		++buf;
	while (*src)
	{
		*buf = *src;
		++buf;
		++src;
	}
	*buf = 0;
	return (dest);
}

/**
 * _strncpy - copy n char of a source string to dest
 *@src: the source string
 *@dest: the destination string
 * @n: the number of elements to copy
 *
 *Return: pointer to the dest string
 **/
char	*_strncpy(char *dest, char *src, int n)
{
	int	i = 0;

	if (!dest || !src)
		return (dest);
	while (i < n)
	{
		dest[i] = *src;
		if (*src)
			++src;
		++i;
	}
	return (dest);
}

/**
 * str_concat - a function that concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: the newly created concat. string
 **/
char	*str_concat(char *s1, char *s2)
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
	return (cc);
}

/**
 * _realloc - a function that reallocates a memory block
 * @ptr: a pointer to the memory previously allocated
 * @os: the old size in bytes of the allocated ptr
 * @ns: the new size in bytes of the new memory block
 *
 * Return: a pointer to the newly allocated block or NULL
 **/
void	*_realloc(void *ptr, unsigned int os, unsigned int ns)
{
	void	*r;

	if (!ptr)
	{
		r = malloc(ns);
		return (r ? r : 0);
	}
	if (os == ns)
		return (ptr);
	if (!ns)
	{
		free(ptr);
		return (0);
	}
	r = malloc(ns);
	if (!r)
		return (0);
	if (ns < os)
		_memcpy(r, ptr, ns);
	else
		_memcpy(r, ptr, os);
	free(ptr);
	return (r);
}

/**
 * _memcpy - copies memory area
 * @dest: the memory to write at
 * @src: the memory to write from
 * @n: the number of bytes to write
 *
 * Return: 0 if error else dest
 **/
char	*_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}
