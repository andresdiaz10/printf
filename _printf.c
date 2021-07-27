#include "holberton.h"

/**
 * _printf - formated string
 * @str: string to print
 *
 * Return: number of character printed
 */

int _printf(const char *str, ...)
{
	va_list vl;
	int i = 0, j = 0;
	char buff[100] = {0};
	char *str_arg;

	va_start(vl, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			switch (str[i])
			{
				case 'c':
				buff[j] = (char)va_arg(vl, int);
				j++;
				break;

				case 's':
				str_arg = va_arg(vl, char*);
				_strcpy(&buff[j], str_arg);
				j += _strlen(str_arg);
				break;
			}
		}
		else
		{
			buff[j] = str[i];
			j++;
		}
		i++;
	}
	write(1, buff, j);
	va_end(vl);
	return (j);
}
