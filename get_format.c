#include "holberton.h"

/**
 * get_format - find the format and the function
 * @format: a format conversor
 *
 * Return: if a format match return a pointer to the function
 *	   otherwise null
 */
unsigned int (*get_format(const char *format))(va_list, buffer_t *)
{
	int i;
	conversor_t conversor[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'%', convert_per},
		{0, NULL}
	};

	for (i = 0 ; conversor[i].f ; i++)
	{
		if (conversor[i].format == *format)
			return (conversor[i].f);
	}
	return (NULL);
}
