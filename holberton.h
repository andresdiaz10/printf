#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);

/* Utility */
size_t _strlen(const char *str);

char *_strcpy(char *dest, const char *src);

char *rev_string(char *str);

char *base_convert(int i, char *strout, int base);

#endif /* HOLBERTON_H */
