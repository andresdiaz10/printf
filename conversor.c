#include "holberton.h"

/**
 * convert_c - convert a input to a char and stores in buffer
 * @args: input to be convert
 * @strout: buffer to store the input
 *
 * Return: bytes stored in the buffer
 */
unsigned int convert_c(va_list args, buffer_t *strout)
{
	char c;
	unsigned int bytes_s = 0;

	c = va_arg(args, int);
	bytes_s += _memcpy(strout, &c, 1);
	return (bytes_s);
}

/**
 * convert_s - convert a input to a string and stores in buffer
 * @args: input to be convert
 * @strout: buffer to store the string
 *
 * Return: bytes stored in the buffer
 */
unsigned int convert_s(va_list args, buffer_t *strout)
{
	char *str;
	char *null = "(null)";
	unsigned int bytes_s = 0;

	str = va_arg(args, char*);
	if (!(str))
		return (_memcpy(strout, null, 6));
	while (*str != '\0')
	{
		bytes_s += _memcpy(strout, str, 1);
		str++;
	}
	return (bytes_s);
}

/**
 * convert_per - store a percent in the buffer
 * @args: input to be converted
 * @strout: buffer to store percent
 *
 * Return: always 1
 */
unsigned int convert_per(va_list args, buffer_t *strout)
{
	unsigned int bytes_s = 0;
	char per = '%';

	(void)args;
	bytes_s += _memcpy(strout, &per, 1);
	return (bytes_s);
}
