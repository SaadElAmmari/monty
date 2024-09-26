#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @aa: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _queue(stack_t **aa, unsigned int cline)
{
	(void)aa;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @aa: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _stack(stack_t **aa, unsigned int cline)
{
	(void)aa;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @aa: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _add(stack_t **aa, unsigned int cline)
{
	int op = 0;
	stack_t *mo = NULL;

	mo = *aa;

	for (; mo != NULL; mo = mo->next, op++)
		;

	if (op < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	mo = (*aa)->next;
	mo->n += (*aa)->n;
	_pop(aa, cline);
}

/**
 * _nop - doesn't do anything
 *
 * @aa: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _nop(stack_t **aa, unsigned int cline)
{
	(void)aa;
	(void)cline;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @aa: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _sub(stack_t **aa, unsigned int cline)
{
	int i = 0;
	stack_t *xa = NULL;

	xa = *aa;

	for (; xa != NULL; xa = xa->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	xa = (*aa)->next;
	xa->n -= (*aa)->n;
	_pop(aa, cline);
}
