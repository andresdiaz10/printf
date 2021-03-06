# _printf
Recreation of the C standard function, printf.
# Dependencies
_printf will be compiled on Ubuntu 20.04 LTS using gcc 9.3.0.
# Usage
Example main.c:
```
#include "holberton.h"

int main(void)
{
  _printf("Hello, World!");
  return (0);
}
```
Compilation:
```
$gcc *.c -o out

```
Output:
```
$./out
Hello, World!
$
```
# Description
_printf writes output to standard output, the function is written under the control of a format, that specifies how subsequent arguments  are converted for output.

Prototype: ``` int _printf(const char *format, ...); ```

## Return
_printf returns the numbers of characters printed (excluding the null byte), if an error is found, returns -1.

## Format of the string
Conversion specification is introduced by the character % and ends with a conversion specifier.
- s: character string (string)
- c: character (char)
- d or i: signed integer in base 10 (int)

Example ```main.c```:
```
#include "holberton.h"

int main(void)
{
    _printf("%s, %c, %d", "Hello", 'H', 10);
}
```
Output:
```
Hello, H, 10
```
# Author

- Andres Zapata.
- Mayi Cadavid.
