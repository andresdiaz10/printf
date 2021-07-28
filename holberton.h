#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct buffer_struct - define a buffer struct
 * @buffer: pointer to a char*
 * @begin: start buffer
 * @size: size of the buffer
 */
typedef struct buffer_struct
{
	char *buffer;
	char *begin;
	unsigned int size;
} buffer_t;

/**
 * struct conversor_struct - define a conversor struct
 * @format: format representation
 * @f: function corresponding to format
 */
typedef struct conversor_struct
{
	unsigned char format;
	unsigned int (*f)(va_list, buffer_t *);
} conversor_t;

int _printf(const char *format, ...);

int read_printf(const char *format, va_list args, buffer_t *strout);

void write_printf(va_list args, buffer_t *strout);

unsigned int (*get_format(const char *format))(va_list, buffer_t *);

unsigned int convert_c(va_list args, buffer_t *strout);

unsigned int convert_s(va_list args, buffer_t *strout);

unsigned int convert_per(va_list args, buffer_t *strout);

unsigned int convert_di(va_list args, buffer_t *strout);

unsigned int _memcpy(buffer_t *strout, const char *src, unsigned int s);

buffer_t *init_buff(void);

void free_buff(buffer_t *strout);

#endif /* HOLBERTON_H */
