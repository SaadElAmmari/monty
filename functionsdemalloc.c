#include "monty.h"
/**
 * _calloc - concatenate tw strings specially
 * @nmemb: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *x = NULL;
	unsigned int na;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	x = malloc(nmemb * size);
	if (x == NULL)
	{
		return (NULL);
	}
	for (na = 0; na < (nmemb * size); na++)
	{
		*((char *)(x) + na) = 0;
	}
	return (x);
}
/**
 * _realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a = NULL;
	unsigned int x;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		a = malloc(new_size);
		if (!a)
			return (NULL);
		return (a);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		a = malloc(new_size);
		if (!a)
			return (NULL);
		for (x = 0; x < old_size; x++)
			a[x] = *((char *)ptr + x);
		free(ptr);
	}
	else
	{
		a = malloc(new_size);
		if (!a)
			return (NULL);
		for (x = 0; x < new_size; x++)
			a[x] = *((char *)ptr + x);
		free(ptr);
	}
	return (a);
}
