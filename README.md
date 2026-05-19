*This project has been created as part of the 42 curriculum by joagomes.*
 
# ft_printf
 
## Description
 
`ft_printf` is a re-implementation of the C standard library function `printf()`. The goal is to understand variadic functions in C — functions that accept a variable number of arguments — and to build a robust, extensible library from scratch.
 
The function parses a format string character by character. When it encounters a `%`, it reads the next character to identify the conversion specifier, extracts the corresponding argument from the variadic list using `va_arg`, converts it to text, and writes it to standard output. For any other character, it writes it directly.
 
The library is compiled into a static archive `libftprintf.a` using `ar`.
 
### Supported conversions
 
| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String (prints `(null)` if NULL) |
| `%p` | Pointer address in hexadecimal (prints `(nil)` if NULL) |
| `%d` | Signed decimal integer |
| `%i` | Signed integer in base 10 |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal, lowercase |
| `%X` | Unsigned hexadecimal, uppercase |
| `%%` | Literal percent sign |
 
### Algorithm and data structure justification
 
**Algorithm: recursive digit decomposition**
 
To convert integers to text, a recursive approach is used. The number is divided by its base (10 for decimal, 16 for hexadecimal) on each recursive call until the quotient is less than the base, then digits are written from most significant to least significant on the way back up the call stack. This avoids the need for intermediate buffers or string reversal.
 
**`INT_MIN` handling**
 
Negating `INT_MIN` (-2147483648) directly causes integer overflow because `INT_MAX` is 2147483647. The solution is to cast `n` to `long` before negating, which safely holds the positive value 2147483648.
 
**Variadic arguments**
 
The `va_list` mechanism from `<stdarg.h>` is used to access arguments of unknown type and count. The format specifier tells the program which type to extract with `va_arg`. Note that `char` arguments are always promoted to `int` in variadic calls (C integer promotion rules), so `va_arg(args, int)` must be used for `%c`.
 
**Dispatcher pattern**
 
`ft_format` acts as a dispatcher: it receives the specifier character and calls the appropriate conversion function. Each conversion function returns the number of characters written, which is accumulated in `ft_printf` and returned as the final result — matching the behaviour of the original `printf`.
 
## Instructions
 
### Compilation
 
```bash
make
```
 
This produces `libftprintf.a` at the root of the repository.
 
### Usage in a project
 
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```
 
Include the header in your source files:
 
```c
#include "ft_printf.h"
```
 
### Makefile rules
 
| Rule | Effect |
|------|--------|
| `make` / `make all` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Full recompile |
 
## Resources
 
- `man 3 printf` — official printf documentation
- `man 3 stdarg` — va_list, va_start, va_arg, va_end
- [cppreference — printf format](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference — va_arg](https://en.cppreference.com/w/c/variadic/va_arg)
### AI usage
 
Claude (claude.ai) was used during this project as a learning support tool — to clarify concepts (variadic functions, integer promotion, INT_MIN overflow), to understand error messages, and to verify reasoning before writing code. All code was written and understood by the student; AI was not used to generate final implementations directly.
