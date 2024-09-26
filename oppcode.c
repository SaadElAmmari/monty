#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **d, unsigned int cline)
{
	int a, x;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (x = 0; vglo.arg[x] != '\0'; x++)
	{
		if (!isdigit(vglo.arg[x]) && vglo.arg[x] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	a = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(d, a);
	else
		add_dnodeint_end(d, a);
}

/**
 * _pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void _pall(stack_t **d, unsigned int cline)
{
	stack_t *i;
	(void)cline;

	i = *d;

	while (i)
	{
		printf("%d\n", i->n);
		i = i->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pint(stack_t **d, unsigned int cline)
{
	(void)cline;

	if (*d == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*d)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pop(stack_t **d, unsigned int cline)
{
	stack_t *a;

	if (d == NULL || *d == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	a = *d;
	*d = (*d)->next;
	free(a);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _swap(stack_t **d, unsigned int cline)
{
	int n = 0;
	stack_t *f = NULL;

	f = *d;

	for (; f != NULL; f = f->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	f = *d;
	*d = (*d)->next;
	f->next = (*d)->next;
	f->prev = *d;
	(*d)->next = f;
	(*d)->prev = NULL;
}
