#include "holberton.h"

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

/**
 * rev_string - reverse a string
 * @s: the string to reverse
 *
 **/
void	rev_string(char *s)
{
	char *sr;
	char c;

	sr = s;
	if (!s)
		return;
	while (*sr)
		++sr;
	--sr;
	while (s < sr && *s)
	{
		c = *s;
		*s = *sr;
		*sr = c;
		++s;
		--sr;
	}
}

/**
 * _strncpy - copy n char of a source string to dest
 * @src: the source string
 * @dest: the destination string
 * @n: the number of elements to copy
 * Return: pointer to the dest string
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
