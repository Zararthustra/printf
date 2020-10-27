#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct fspec_s - format specifier structure
 * @c: character after the '%'
 * @f: pointer to func
 *
 */

typedef struct fspec_s
{
	char c;
	int (*f)(va_list, char **);
} fspec_t;

int	_printf(const char *format, ...);
int w_fspec(const char *format, fspec_t val_fspec[],
va_list cur_arg, char **ult);
char	*concat_sbloc(char *ult, const char *rest, int *i);
char	*concat_free(char *s1, char *s2, int select);
char	i_to_hex(int i, char x);
int	nb_len(long int nb, int base);

int	print_s(va_list cur_arg, char **ult);
int	print_S(va_list cur_arg, char **ult);
int	print_r(va_list cur_arg, char **ult);
int	print_c(va_list cur_arg, char **ult);
int	print_percent(va_list cur_arg, char **ult);
int	print_int(va_list cur_arg, char **ult);
int	print_p(va_list cur_arg, char **ult);
int	print_u(va_list cur_arg, char **ult);
int	print_o(va_list cur_arg, char **ult);
int	print_x(va_list cur_arg, char **ult);
int	print_X(va_list cur_arg, char **ult);
int	print_b(va_list cur_arg, char **ult);
int	print_R(va_list cur_arg, char **ult);

int	_putchar(char a);
int	_putstring(char *str);
int	_strlen(char *s);
char	*create_array(unsigned int size, char c);
char	*_strncpy(char *dest, char *src, int n);
void	*_realloc(void *ptr, unsigned int os, unsigned int ns);
char	*_memcpy(char *dest, char *src, unsigned int n);
void	rev_string(char *s);
char	*rot13(char *s);
char	*_strdup(char *str);

#endif
