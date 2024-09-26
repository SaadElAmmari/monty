#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @a1: type str compared
 * @a2: type str compared
 * Return: 0 if a1 and a2 are equals.
 *         another value if they are different
 */
int _strcmp(char *a1, char *a2)
{
	int x;

	for (x = 0; a1[x] == a2[x] && a1[x]; x++)
		;
	if (a1[x] > a2[x])
		return (1);
	if (a1[x] < a2[x])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @x: string to review
 * @d: char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *x, char d)
{
	int ap = 0;

	while (x[ap] != '\0')
	{
		if (x[ap] == d)
		{
			break;
		}
		ap++;
	}
	if (x[ap] == d)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @y: string to cut in parts
 * @ado: delimiters
 * Return: first partition
 */
char *_strtoky(char *y, char *ado)
{
	static char *ultimo;
	int f = 0, mmm = 0;

	if (!y)
		y = ultimo;
	while (y[f] != '\0')
	{
		if (_sch(ado, y[f]) == 0 && y[f + 1] == '\0')
		{
			ultimo = y + f + 1;
			*ultimo = '\0';
			y = y + mmm;
			return (y);
		}
		else if (_sch(ado, y[f]) == 0 && _sch(ado, y[f + 1]) == 0)
			f++;
		else if (_sch(ado, y[f]) == 0 && _sch(ado, y[f + 1]) == 1)
		{
			ultimo = y + f + 1;
			*ultimo = '\0';
			ultimo++;
			y = y + mmm;
			return (y);
		}
		else if (_sch(ado, y[f]) == 1)
		{
			mmm++;
			f++;
		}
	}
	return (NULL);
}
