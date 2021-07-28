#include "holberton.h"

/**
 * write_printf - print in the stdout and free memory
 * @args: list argument
 * @strout: buffer struct, string to print
 */
void write_printf(va_list args, buffer_t *strout)
{
	write(1, strout->begin, strout->size);
	va_end(args);
	free_buff(strout);
}

/**
 * read_printf - move into string and search the format
 * @format: string to print
 * @args: list arguments
 * @strout: buffer struct, store the format
 *
 * Return: number of char in strout
 */
int read_printf(const char *format, va_list args, buffer_t *strout)
{
	int i;
	int numc = 0;
	char tmp;
	unsigned int (*f)(va_list, buffer_t *);

	for (i = 0 ; *(format + i) ; i++)
	{
		if (*(format + i) == '%')
		{
			tmp = 0;
			f = get_format(format + i + tmp + 1);
			if ((f))
			{
				i += tmp + 1;
				numc += f(args, strout);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				numc = -1;
				break;
			}
		}
		numc += _memcpy(strout, (format + i), 1);
	}
	write_printf(args, strout);
	return (numc);
}
/**
 * _printf - init the buffer and format
 * @format: string to print
 *
 * Return: number of char to be printed
 */
int _printf(const char *format, ...)
{
	int numc;
	buffer_t *strout;
	va_list args;

	if (!(format))
		return (-1);
	strout = init_buff();
	if (!(strout))
		return (-1);
	va_start(args, format);
	numc = read_printf(format, args, strout);
	return (numc);
}
