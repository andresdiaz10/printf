#include "holberton.h"

/**
 * _memcpy - copy the content of the src and store in buffer
 * @strout: buffer, store the copy
 * @src: a string to be copied
 * @s: bytes to copy
 *
 * Return: bytes copied
 */

unsigned int _memcpy(buffer_t *strout, const char *src, unsigned int s)
{
	unsigned int i;

	for (i = 0 ; i < s ; i++)
	{
		*(strout->buffer) = *(src + i);
		(strout->size)++;
		(strout->buffer)++;
	}
	return (s);
}

/**
 * init_buff - init the buffer
 * Return: pointer to the buffer
 */
buffer_t *init_buff(void)
{
	buffer_t *strout;

	strout = malloc(sizeof(buffer_t));
	if (!(strout))
		return (NULL);
	strout->buffer = malloc(sizeof(char) * 1024);
	if (!(strout->buffer))
	{
		free(strout);
		return (NULL);
	}
	strout->begin = strout->buffer;
	strout->size = 0;
	return (strout);
}

/**
 * free_buff - free the buffer
 * @strout: buffer to free
 */
void free_buff(buffer_t *strout)
{
	free(strout->begin);
	free(strout);
}
