#include "monty.h"

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *a, *x;

	if (head == NULL)
		return (NULL);
	a = malloc(sizeof(stack_t));
	if (!a)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	a->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		a->next = *head;
		a->prev = NULL;
		*head = a;
		return (*head);
	}
	x = *head;
	while (x->next)
		x = x->next;
	a->next = x->next;
	a->prev = x;
	x->next = a;
	return (x->next);
}

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *a;

	if (head == NULL)
		return (NULL);
	a = malloc(sizeof(stack_t));
	if (!a)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	a->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		a->next = *head;
		a->prev = NULL;
		*head = a;
		return (*head);
	}
	(*head)->prev = a;
	a->next = (*head);
	a->prev = NULL;
	*head = a;
	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *ya;

	while ((ya = head) != NULL)
	{
		head = head->next;
		free(ya);
	}
}
