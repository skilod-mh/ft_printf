*This project has been created as part of the 42 curriculum by mohoussa.*
# ft_printf

## Description
`ft_printf` is a simple version of the standar C library `printf` function , compiled into a static library (`libftprintf.a`) using the command tool `ar`.the main goal of this subject is to understand `variadic functions` and how they work,
using the `<stdarg.h>`,and also know default argument promotions.

## Instructions

Clone the repository and run `make` at the root directory to build `libftprintf.a`
using `cc` with `-Wall -Wextra -Werror` and the archive tool `ar` :

```
make
make clean
make fclean

```
main to test 
```
#include "ft_printf.h"
int main ()
{
    int     a;
    char    c;
    char    *s;
    int     *p;

    a = 42;
    c = 'h';
    s = "mohoussa";
    p = &a;
    ft_printf("%cello this project has been created as part of the %d curriculm by %s \n %p" , c, a, s, p);
    return (0);
}
```
## Resources
- Linux `man` pages (`man 3 stdarg`)
### AI usage
- AI was used as a tutor. 
- It helped me understand the Variadic functions how they work and what happens under the hood.
- AI was not used to write the code.
## Algorithm and Data Structure

### Data Structers

* **`va_list` (`<stdarg.h>`) :** Used to traverse the unnamed variadic arguments passed after the fixed `const char *format`parameter.it is initiaalized with `va_start()`,read one argument at a time with `va_arg()`.and cleanup with `va_end()` before `ft_printf()`returns.
### Algorithm
* **Character Counter (`int`) :** Tracks the cumulative number of bytes written via `write()` do `ft_printf()` can return the exact count expected by the caller.
* **Single-pass Parsing :** Iterate through `format` one character at time :
- if the character is not `%`, write it directly to standard output via `write()` and increment the character counter.
- if `%` is encountered , inspect the convesrion specifier and route it to the coreesponding formatting helper.
* **Argument Extraction and Formating :** Retrieve the next argument with `va_arg()` using its promoted type (`int` for `%c`,`%d`,and `%i`, `char *` for `%s`; `void *` for `%p`; `unsigned int` for `%u`, `%x`, and `%X`),handling edge cases such as `NULL` strings.
* **Cleanup and Return :** call `va_end()` to clean up the `va_list`
and return the total character count.