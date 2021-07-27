#include "holberton.h"

/**
 * _strlen - calculate the lenght of a string
 * @str: string to get the lenght
 *
 * Return: the lenght of str
 */

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (*str++)
		length++;

	return (length);
}

/**
 * _strcpy - copies a string pointed to src
 * @dest: buffer to copy the string
 * @src: source string to copy
 *
 * Return: a pointer to the dest string
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}

/**
 * rev_string - reverse a string
 * @str: string to be reverse
 *
 * Return: reverse string
 */

char *rev_string(char *str)
{
	size_t i;
	size_t length = _strlen(str);
	char c;

	if (!(str))
		return (NULL);
	for (i = 0 ; i < (length / 2) ; i++)
	{
		c = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = c;
	}
	return (str);
}

/**
 * base_convert - convert a int to a respective base
 * @i: the number
 * @strout: the out str
 * @base: base to converter
 *
 * Return: a string with the base
 */
char *base_convert(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign =  0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
		*str++ = '-';
	*str = '\0';
	rev_string(strout);
	return (strout);
}
