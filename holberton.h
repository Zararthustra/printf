#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct fspec_s
{
	char c;
	void (*f)(va_list, char **);
} fspec_t;

int	_printf(const char *format, ...);
int	w_fspec(const char *format, fspec_t val_fspec[], va_list cur_arg, char **ult);
char	*concat_sbloc(char *ult, const char *rest, int *i);
char	*concat_free(char *s1, char *s2, int select);

void	print_s(va_list cur_arg, char **ult);
void	print_c(va_list cur_arg, char **ult);
void	print_percent(va_list cur_arg, char ** ult);


int	_putchar(char a);
int	_putstring(char *str);
int	_strlen(char *s);
char	*create_array(unsigned int size, char c);
char	*_strncpy(char *dest, char *src, int n);
void	*_realloc(void *ptr, unsigned int os, unsigned int ns);
char	*_memcpy(char *dest, char *src, unsigned int n);

#endif
