int	init_len(const char *s)
{
	int	i = 0;

	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
			return (i);
		++i;
	}
	return (i);
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
