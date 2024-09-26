#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *x = NULL;
	stack_t *y = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	x = (*doubly)->next;
	y = *doubly;

	for (; y->next != NULL; y = y->next)
		;

	x->prev = NULL;
	y->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = y;
	*doubly = x;
}

/**
 * _rotr - reverse the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *i = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	i = *doubly;

	for (; i->next != NULL; i = i->next)
		;

	i->prev->next = NULL;
	i->next = *doubly;
	i->prev = NULL;
	(*doubly)->prev = i;
	*doubly = i;
}
