# **_printf**

_printf is a challenge project at Holberton School, where we have to code our own printf(3) in C in 4.5 days 

## Usage

```
#include "holberton.h"
int _printf(const char **format*, ...);
```
The format string is composed of zero or more arguments which are converted. Each conversion specification is introduced by the character %, and ends with a conversion specifier.

## Conversion specifier
- [x] **%** - A '%' is written.  No argument is converted. The complete conversion specification is '%%'.
- [x] **d, i** - The *int* argument is converted to signed decimal notation.
- [x] **u** - The *unsigned int* is converted to unsigned decimal notation. 
- [x] **o** - The *unsigned int* is converted to unsigned octal notation.
- [x] **x, X** - The *unsigned int* is converted to unsigned hexadecimal (\fBx\fP and \fBX\fP) notation. The letters **abcdef** are used for **x** conversions; the letters **ABCDEF** are used for **X** conversion.
- [x] **b** - The *unsigned int* argument is converted to **binary**.
- [x] **c** - The *int* argument is converted to a character.
- [x] **s** - The  *const char\** argument is expected to be a pointer to an array of character type (pointer to a string).  Characters from the array  are written up to (but not including) a terminating null byte ('\0').
- [x] **S** - Similar to **s**, prints the non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal.
- [x] **r** - Similar to **s**, prints the string in reverse.
- [x] **p** - The *void \** **pointer** argument is printed in hexadecimal.
- [x] **R** - Similar to **s**, the string is ROT13


## Example
```
#include "holberton.h" 
       
      _printf("Hello,  welcome  to  %s.  We are from the cohort %c %d and we hope getting 200%% for the printf project !", "Holberton School", 'C', 13);
```
```       
       $ Hello, welcome to Holberton School. We are from the C 13 cohort and we hope getting 200% for the printf project !
```       
## Project Requirements

- We were not allowed to use global variables
- No more than 5 functions per file
- Authorized functions :
  - write (man 2 write)
  - malloc (man 3 malloc)
  - free (man 3 free)
  - va_start (man 3 va_start)
  - va_end (man 3 va_end)
  - va_copy (man 3 va_copy)
  - va_arg (man 3 va_arg)
  
  
  
**By [T-SN](https://github.com/TS-N) and [Zararthustra](https://github.com/Zararthustra)**
